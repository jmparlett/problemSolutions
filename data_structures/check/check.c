#include "hashtable.h"

/* prototypes */
hashTable* readInDict(FILE* fp);
void similarWords(hashTable* T, char word[]);
int invertedLettersMatch(char w1[], char w2[], int len);
int isAlpha(char c);

int main(int argc, char *argv[]){

  FILE* fp;
  if(argc < 2){
    printf("Error: expected a dictionary file\n");
    return -1;
  } else if((fp=fopen(*++argv, "r"))==NULL){
    printf("Error: invalid filename\n");
    return -1;
  }

  // read in dictionary
  hashTable* T = readInDict(fp);
  free(fp); //fopen uses malloc :(

  char *sentence=NULL;
  size_t bufAllocedSize;
  int len; //num of chars read

  printf("Enter text to be spell checked: ");
  while(1){//run until given "exit"
    //read sentence in
    if((len=getline(&sentence, &bufAllocedSize,stdin)) < 2) continue;

    //if user enters exit then exit loop and clean up
    if(!strncmp(sentence, "exit",4)) break;

    char word[1000];//were gonna assume we dont have any record breakingly long words
    
    int i=0, j=0;//j=sentence index, i=word index
   
    //take chars from sentence until we hit somthing non alpha
    while(i < len){
      //check len again because I'd rather not cuase a seg fault if they didn't put a period
      while(isAlpha(sentence[i]) && i<len){
        word[j++]=sentence[i++];
      }
      word[j]='\0'; //delim word
      j=0; //reset for nexttime

      //check if word not in dict 
      if(isMemberHT(T, word)==NULL){
        printf("Mistyped word: %s\n", word);
        //suggest some alts
        printf("Suggested words for mistyped word '%s': ", word);
        similarWords(T, word);
        //prompt to add
        printf("Would you like to add the word to the dictionary? [y/n] ");
        int c;
        while((c=fgetc(stdin))!='y' && c!='n');
        if(c=='y') insertHT(T,word);
      }

      //move to next alpha char
      while((!isAlpha(sentence[i])) && i < len) i++;
    }
    printf("Enter text to be spell checked: ");
  }

  // clean up
  makeNullHT(T);
  free(T);
  free(sentence);

}

/******* Read In Dictionary *******/
hashTable* readInDict(FILE* fp){

  //allocate hashtable sizeof initialIncrement
  int sizeIncrement=50000; //we will increase by this much if A > 5
  hashTable* T = initHashTable(sizeIncrement);

  //allocate buffer for reading lines from file
  int bufsize=1000; //max chars to store in buf
  char* buf=malloc(bufsize);

  //read in lines from file until EOF
  while(fgets(buf,bufsize,fp)!=NULL){
    //we realloc when Access Time > 5
    if(T->itemCount == T->size*5)
      T=reallocHT(T, T->size+sizeIncrement);
    //add words 
    int nlpos=strlen(buf)-1;
    buf[nlpos]='\0'; //dont want to store '\n'
    if(buf[nlpos-1]=='\r') buf[nlpos-1]='\0'; //check for extra carriage return and delete
    insertHT(T, buf);
  }
  free(buf);
  return T;
}
/******** read in dict end ************/


/******** word suggestions **********/
int invertedLettersMatch(char w1[], char w2[], int len){
//expects two words of the same length
  int diff=0, match=0;
  for(int i=0; i < len; i++){
    if(w1[i]!=w2[i]){
      diff++;
      if(i+1<len){
        if(w1[i]==w2[i+1] && w2[i]==w1[i+1])
          match=1;
      }
    }
  }
  return (diff==2 && match==1);
}

// just need to print similar words
void similarWords(hashTable* T, char word[]){
  int len = strlen(word); //we'll calc this here since we'll use it multiple times
  int wordsFound=0;//we stop at 10
  char *matches[10];

  //inverted adjacent
  int pos=hash(word, T->size);

  node* cur = T->table[pos]->head;//tmp for searches

  while(cur!=NULL && wordsFound < 10){
    if(len==strlen(cur->word))
      if(invertedLettersMatch(word,cur->word,len)){
        matches[wordsFound++]=cur->word;
      }
    cur=cur->next;
  }


  //extra begining or end
  char* buf=malloc(strlen(word)+2);//need enough space for +- one char

  //missing begining
  strcpy(++buf, word);
  *--buf='a';
  while(buf[0]<='z' && wordsFound < 10){
    if((cur=isMemberHT(T, buf))!=NULL) 
      matches[wordsFound++]=cur->word;
    buf[0]++;
  }

  //missing end
  strcpy(buf, word);
  *(buf+len)='a'; //recall len=length of incorrect word
  while(buf[len]<='z' && wordsFound < 10){
    if((cur=isMemberHT(T, buf))!=NULL)
      matches[wordsFound++]=cur->word;
    buf[len]++;
  }


  //extra begining
  if(wordsFound < 10){
    buf[len]='\0';//cut off char we added to check end
    buf++; //cut off begining char
    if((cur=isMemberHT(T, buf))!=NULL)
      matches[wordsFound++]=cur->word;
  }

  //extra end
   if(wordsFound < 10){
    buf--; //retrieve begining char
    buf[len-1]='\0';//cut last char
    if((cur=isMemberHT(T, buf))!=NULL)
      matches[wordsFound++]=cur->word;
  }
  //print matches each seperated by a comma and ending in a period
  int i;
  for(i=0; i < wordsFound-1; ++i) printf("%s, ", matches[i]); 
  // print last word and clean up
  if(i < wordsFound) printf("%s.\n", matches[i]);
  free(buf);
}
/******** word suggestions end **********/


/******** utils *******/
int isAlpha(char c){
  return ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'));
}
