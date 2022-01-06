#include "datastructures/hashtable.h"
#include "datastructures/heap_htree.h"
#include "datastructures/openhashtable.h"

/**************** Prototypes ********************/
int getFrequencies(FILE* fp, hashTable* T, heap* Q);
hNode* buildHuffmanTreeFromQueue(heap* Q);
code traverse(code C, huffmanTree* HTree, char c);
void buildCodeTable(openHashTable* codeTable, hashTable* freqTable, huffmanTree* HTree, FILE* ofp);
int encodeFile(FILE* infp, FILE* ofp, openHashTable* codeTable);
void decodeFile(FILE* infp, FILE* ofp, huffmanTree* HTree);
huffmanTree* buildHuffmanTreeFromFile(FILE* infp);


typedef struct {
  char c;
  float freq;
} charData;


int main(int argc, char* argv[]){

  if(argc < 5){
    printf("Error: expected additional arguments\n");
    return 0;
  } else if(!strcmp(argv[1], "encode")){//encoding block
    
    FILE* plainText;
    if((plainText = fopen(argv[2], "r")) == NULL) return 0; //failed to open file

    FILE* codeTable;
    if((codeTable = fopen(argv[3], "w")) == NULL) return 0; //failed to open file

    FILE* encodedText;
    if((encodedText = fopen(argv[4], "w")) == NULL) return 0; //failed to open file

    
    //hashtable for storing and looking up freqencies
    hashTable* freqTable = initHashTable(50); 
    //there arent more than 256 ascii chars so size 50 means access time should be within O(5)

    //priority queue 300 should be fine since not more than 256 ascii chars
    heap* Q = Heap(300);

    int totalSize= getFrequencies(plainText, freqTable, Q); //store freqs in hash table and insert to priority queue
    totalSize*=8; //num of bytes * 8 gives size in bits

    //lets build our tree
    huffmanTree* T = malloc(sizeof(huffmanTree));
    T->root = buildHuffmanTreeFromQueue(Q);

    //now lets build our code table
    openHashTable* codeLookupTable = OpenHashTable(300);//all ascii char should hash to unique locations
    buildCodeTable(codeLookupTable, freqTable, T, codeTable);

    fclose(plainText);
    plainText = fopen(argv[2], "r"); //reopen file
    int compressedSize = encodeFile(plainText, encodedText, codeLookupTable);

    printf("Original: %d bits\n", totalSize);
    printf("Compressed: %d bits\n", compressedSize);
    printf("Compression Ratio: %d%%\n", (compressedSize*100)/totalSize);

    //cleanup 
    makeNullHT(freqTable);
    free(freqTable);
    free(Q->arr);
    free(Q);
    free(codeLookupTable->codes);
    free(codeLookupTable);
    free(T); //we need to make a recursive function to free all pointers for the tree
    fclose(plainText);
    fclose(encodedText);
    fclose(codeTable);
    return 0;
  } else {//decoding

    FILE* codeTable;
    if((codeTable = fopen(argv[2], "r")) == NULL) return 0; //failed to open file

    FILE* encodedText;
    if((encodedText = fopen(argv[3], "r")) == NULL) return 0; //failed to open file

    FILE* plainText;
    if((plainText = fopen(argv[4], "w")) == NULL) return 0; //failed to open file
    
    huffmanTree* T = buildHuffmanTreeFromFile(codeTable);
    
    decodeFile(encodedText,plainText,T);

    //cleanup
    free(T);
    fclose(codeTable);
    fclose(plainText);
    fclose(encodedText);
    return 0;
  }
}

int getFrequencies(FILE* fp, hashTable* T, heap* Q){
  //iter though chars in file and dump to HT. If already in HT inc frequency
  //also return num of chars in file
  char c; //current char
  float total=0; //total chars in file
  LLNode* cur; //used in loops

  while((c=fgetc(fp)) != EOF){
    if((cur=isMemberHT(T, c)) != NULL){
      cur->freq++;
    } else insertHT(T, c); //insert new char
    total++; //total is inced no matter what
  }

   //iter through all chars in HT and calculate frequencies before pushing to priority Queue
   for(size_t i=0; i < T->size; i++){
     if((cur = T->table[i]->head) != NULL){
       while(cur != NULL){
          cur->freq = cur->freq/total; //actually calc the freqency now
          insertToHeap(Q, HNode(cur->c, cur->freq));
          cur = cur->next;
        }
     }
   }
   return total;
}

hNode* buildHuffmanTreeFromQueue(heap* Q){
  while(Q->size > 1){
    //grab 2 nodes from the top
    hNode* x = getMin(Q);
    hNode* y = getMin(Q);

    //create parent node whos freq is x and y's freq sum
    //its char will be the null byte. Our sentinal.
    hNode* z = HNode(0, x->freq+y->freq);

    //set left and right children and put back in priority queue
    z->left = x;
    z->right = y;
    insertToHeap(Q, z);
  }
  return getMin(Q); //the head of our tree
}


void buildCodeTable(openHashTable* codeTable, hashTable* freqTable, huffmanTree* HTree, FILE* ofp){
  //build code table and print to file returning file at end of routine
   LLNode* cur;
   for(size_t i=0; i < freqTable->size; i++){
     if((cur = freqTable->table[i]->head) != NULL){
       while(cur != NULL){
         code* charCode = malloc(sizeof(code));
         code C;
         C.bitPattern=0;
         C.length=0;
         C.c=cur->c;
         C = traverse(C, HTree, cur->c);         
         *charCode = C;
         insertToOpenHashTable(codeTable, charCode);
         fprintf(ofp, "%c,%s,%.2f\n",C.c, C.pattern, cur->freq);
         // printf("pattern: %llu length: %d char: %c\n", C.bitPattern, C.length, C.c);
         cur = cur->next;
        }
     }
   } 
}

code traverseHelper(code C, hNode* n, char c, int turn){
  if(n==NULL){
    C.c = 0; //this branch failed
    return C;
  }
  C.pattern[C.length]=turn+'0';
  C.length++;
  C.pattern[C.length]='\0';
  if(n->c == c) return C;

  code C2;
  if((C2=traverseHelper(C, n->left, c, 0)).c == 0)//this branch failed return the other
    return traverseHelper(C, n->right, c, 1);
  else return C2; //we found it
}

code traverse(code C, huffmanTree* HTree, char c){
 code C2;
  if((C2=traverseHelper(C, HTree->root->left, c, 0)).c == 0)//this branch failed return the other
    return traverseHelper(C, HTree->root->right, c, 1);
  else return C2; //we found it
}


int encodeFile(FILE* infp, FILE* ofp, openHashTable* codeTable){

  char c=0; //this will be in char
  int total =0; //num of chars in compressed

  while((c=fgetc(infp))!=EOF){
    //get bit pattern for current char
    code C = *isMemberCHT(codeTable,c);
    // printf("[%c, %d, %s]\n", C.c, C.length, C.pattern);
    for(int i=0; i<C.length; i++){
      fputc(C.pattern[i], ofp);
    }
    total += C.length;
  }
  return total;
}



void decodeFile(FILE* infp, FILE* ofp, huffmanTree* HTree){
  //traverse tree based on which char we read from file
  char c=0;
  int totalSize=0;
  int compressedSize=0;

  hNode* cur = HTree->root;
  while((c=fgetc(infp)) != EOF){
  //traverse tree based on which char we read from file
    if(c=='1'){//right
      cur = cur->right;
    } else {//left
      cur = cur->left;
    }
    if(cur->c != 0){
      fputc(cur->c, ofp);
      cur = HTree->root;
      totalSize++;
    }
    compressedSize++;
  }
  totalSize*=8; //this is real messy to print here
  printf("Original: %d bits\n", totalSize);
  printf("Compressed: %d bits\n", compressedSize);
  if(totalSize!=0) printf("Compression Ratio: %d%%\n", (compressedSize*100)/totalSize);
}

huffmanTree* buildHuffmanTreeFromFile(FILE* infp){
  char c=0; //current char
  float f=0; //current freq
  char code[260]; //current char code
  char buff[300]; //buffer for current line
  huffmanTree* T = malloc(sizeof(huffmanTree));
  T->root=HNode(0, 1);

  hNode* cur = T->root;

  //get char from file and save to c
  //get another char to discard the next comma
  //use scanf to get the rest of the info
  //process info
  //repeat
  
  while((c=fgetc(infp)) != EOF){
   fgetc(infp); //discard comma
   fgets(buff, 300, infp); //read rest of line to buffer
   sscanf(buff, "%[^,],%f\n", code,&f);
   int len = strlen(code);
   for(int i=0; i < len; i++){
     if(code[i] == '0'){//left
      if(cur->left==NULL) cur->left=HNode(0,0);
      cur = cur->left;
     } else {
      if(cur->right==NULL) cur->right=HNode(0,0);
      cur = cur->right;
     }
    }
    cur->c=c;
    cur->freq=f;
    cur = T->root;
  }
  return T;
}
