#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* structs */
typedef struct {
  int weight;
  char *term;
} pair;

typedef struct {
  size_t actualSize;
  size_t allocedSize;
  pair **pairs; //pointer to pair pointer
} dynamicPairArr;

/* prototypes */
pair *initPair();
void printPair(pair *);
dynamicPairArr* initKnowledgeBase();
int pairCompareStr(pair *a, pair *b);
int pairCompareWeight(pair *a, pair *b);
void quicksort(pair**, int , int, int(*compar)(pair*, pair*));//l = left pointer on first call=0 r=right pointer on first call =size-1
int partition(pair**, int , int , int ,int(*)(pair*, pair*));
int biasedBinSearch(pair** A, char* t, int n, int tn, int bias);

/* main */
int main(int argc, char *argv[]){
  // parse args
  if(argc < 3){
    printf("Error: not enough args, expected knowledgebase file and search term");
    return -2;
  }

  // attempt to open provided file name
  FILE* fp;
  if((fp = fopen(*++argv, "r")) == NULL){
    printf("Error: no file provided or file invalid");
    return -2;
  }

  // init search term and find length
  char *searchTerm = *++argv;
  int termSize = strlen(searchTerm);


  // Create our knowledge base from the provided file
  dynamicPairArr *k = initKnowledgeBase(fp); //this is our knowledge base of search terms

  // Sort knowledge base alphabetically
  quicksort(k->pairs, 0, k->actualSize-1, pairCompareStr);

  // attempt to find a range of matchs in the knowledge base
  int rangeStart;
  if((rangeStart = biasedBinSearch(k->pairs, searchTerm, k->actualSize, termSize, 1)) == -1){
      free(k);
      printf("-1");
      return -1; //if no match is found exit the program
  }

  int rangeEnd= biasedBinSearch(k->pairs, searchTerm, k->actualSize, termSize, 0);
  // printf("rangeStart: %d rangeEnd: %d\n", rangeStart, rangeEnd);

  //sort range by weights
  quicksort(k->pairs, rangeStart, rangeEnd, pairCompareWeight);
  
  //print sorted range
  for(; rangeStart <= rangeEnd; rangeStart++) printPair(k->pairs[rangeStart]);

  // we should definitly free all the sub allocations of each pair first but we know this program is a one shot anyway so what evs
  free(k);
}


/* Functions */
pair *initPair(int termSize){// initalizes a pair struct and returns it
  pair *t;
  t=malloc(sizeof(pair));
  t->term=malloc(sizeof(char)*termSize); //given the size of search to be entered
  return t;
}

void printPair(pair *p){//print pair to stdout
  printf("%s,%d\n", p->term, p->weight);
}

dynamicPairArr* initKnowledgeBase(FILE* fp){
  dynamicPairArr *k = malloc(sizeof(*k)); //this will be our knowledge base
  k->actualSize=0;
  k->allocedSize=1000;
  k->pairs=malloc(sizeof(pair*)*1000);
  char *buff=NULL;
  size_t buffsize;

  while( getline(&buff, &buffsize, fp) > 1){
    int termSize=0;
    for(termSize; buff[termSize]!=' '; termSize++);//need to know how large the string portion is to create the pair
    pair *p=initPair(termSize);

    sscanf(buff, "%s %d", p->term, &p->weight);
    k->pairs[k->actualSize++]=p; //store new pair and inc size

    if(k->actualSize >= k->allocedSize){ // need to allocate more space
      k->allocedSize+=1000;
      k->pairs=realloc(k->pairs, k->allocedSize*sizeof(pair*));
    }
  }
  //because of the post incrementation on size it should be one bigger than the largest index as desired
  return k;
}


/******* pair quicksort begin ********/
int pairCompareStr(pair *a, pair *b){
 return strcmp(a->term, b->term); 
}

int pairCompareWeight(pair *a, pair *b){
 return (b->weight - a->weight); //this is reversed so we sort from highest to lowest for weights
}
int partition(pair **A, int l, int r, int p, int(*compar)(pair*, pair*)){
  for(; r < p; r++){
    if((*compar)(A[r],A[p]) <= 0){
       pair tmp=*A[r];
       *A[r]=*A[l];
       *A[l]=tmp;
       l++;
    }
  }
  pair tmp=*A[p];
  *A[p]=*A[l];
  *A[l]=tmp;
  return l;
}

void quicksort(pair** A, int l, int r, int(*compar)(pair*, pair*)){//l = left pointer on first call=0 r=right pointer on first call =size-1
  if(l>=r) return;
  //perform random swap
  int ranIndex=l+rand()%(r-l);
  pair tmp=*A[ranIndex];
  *A[ranIndex]=*A[r];
  *A[r]=tmp;

  int p=partition(A, l, l, r, compar);
  quicksort(A, l, p-1, compar);
  quicksort(A, p+1, r, compar);
}
/******* pair quicksort end ********/


/******* pair binSearch begin ******/
//n=array size, tn=target string size, position(should be -1 to start), bias 1=left, 0=right
int biasedBinSearch(pair** A, char* t, int n, int tn, int bias){
  int l=0, r=n-1; //left and right pointers

  int  mid, lastPositive=-1;
  while(l <= r){
    mid=(l+r)>>1; //nifty midpoint

    int rslt = strncmp(t, A[mid]->term, tn);
    if(rslt < 0){
      r=mid-1;
    } else if(rslt > 0){
      l=mid+1;
    } else if(bias){
      lastPositive=mid; 
      r=mid-1;
    } else {
      lastPositive=mid; 
      l=mid+1;
    }
  }
  return lastPositive; 
} //This might be bad idea since runtime is always worst case but, its still probably better then doing partial linear
/******* pair binSearch end ******/
