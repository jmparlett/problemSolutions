#include <stdlib.h>
#include <stdio.h>
#include <math.h>

/************** Structs **************/
typedef struct adjacentVertex {
  struct adjacentVertex* next;
  int *board;
} av;

typedef struct Vertex {
 char color;
 struct Vertex* pred;//this represents the node that this was discovered from we might not use this
 struct Vertex* next;//this is for the linked list in the hash table and has nothing to do with the graph
 int *board;
 av* alisthead;
} vertex;

typedef struct {
  vertex** V; //set of vertices 
  int size;
  // int capacity;
  int k; //k*k = size of table arr
  int bitlength;//length of bits to read for each number, used to hash the table state
} hashTable;


typedef struct {
  hashTable* V; //set of vertices
} graph;


/************** Prototypes ***************/
void insertHT(hashTable* T, int board[], vertex* pred);
vertex* isMemberHT(hashTable* T, int board[]);
void makeAlist(vertex* v, int k);
hashTable* HashTable(int k);
void printHT(hashTable* T);

/******* Graph Start *******/
vertex* Vertex(int board[], int k, vertex* pred){
  vertex* v = (vertex*)malloc(sizeof(vertex));
  v->color='w';
  v->alisthead=NULL;
  v->pred=pred;
  v->board = (int *)malloc(sizeof(int)*(k*k));
  for(int i=0; i < k*k; i++) v->board[i] = board[i];
  makeAlist(v,k); //draw appropriate adjacencies
  return v;
}

av* Av(int board[], int k){
  av* v = malloc(sizeof(av));
  v->board = malloc(sizeof(int)*(k*k));
  v->next=NULL;
  for(int i=0; i<k*k; i++)
    v->board[i]=board[i];
  return v;
}

void printVertex(vertex* v, int k){
  printf("----------------\n");
  printf("--board--\n");
  for(int i=0; i<k*k; i++){
    printf("%d ", v->board[i]);
    if(!((i+1)%k)) printf("\n");
  }
  printf("\n");
  printf("--adjacencies--\n");
  av* cur = v->alisthead;
  int nc=1;
  while(cur != NULL){
    printf("neighbor %d\n", nc++);
    for(int i=0; i<k*k; i++){
        printf("%d ", cur->board[i]);
        if(!((i+1)%k)) printf("\n");
      }
    cur = cur->next;
  }
  printf("----------------\n");


}

void swap(int arr[], int a, int b){
 //xor swap
 arr[a]^=arr[b];
 arr[b]^=arr[a];
 arr[a]^=arr[b];
}

void makeAlist(vertex* v, int k){
 //len of array is k*k
 int len = k*k;
 int space=0;
 av* tmp;

 //locate empty space
 while(v->board[space]!=0) space++;
 
 //check if left move is in range
 if((space%k)-1 >= 0){
  tmp = Av(v->board, k);
  swap(tmp->board, space, space-1);
  tmp->next = v->alisthead;
  v->alisthead=tmp;
 }
 
 //check if right move is in range
 if((space%k)+1 < k){
  tmp = Av(v->board, k);
  swap(tmp->board, space, space+1);
  tmp->next = v->alisthead;
  v->alisthead=tmp;
 }
 //check if down move is in range
 if(space+k < len){
  tmp = Av(v->board, k);
  swap(tmp->board, space, space+k);
  tmp->next = v->alisthead;
  v->alisthead=tmp;
 }
 //check if up move is in range
 if(space-k > 0){
  tmp = Av(v->board, k);
  swap(tmp->board, space, space-k);
  tmp->next = v->alisthead;
  v->alisthead=tmp;
 }
}

graph* Graph(int k){
  graph* G = malloc(sizeof(graph));
  G->V = HashTable(k);
  return G;
}

vertex* getVertex(graph* G, int board[]){
  return isMemberHT(G->V,board);
}

void addVertex(graph* G, int board[], vertex* pred){
  insertHT(G->V, board, pred);
}

void printGraph(graph* G){
  printHT(G->V);
}
/******* Graph End *******/


/******* Hashtable Start *******/
int factorial(int n){
  int result=1;
  while(n>0) result*=n--; 
  return result;
}


hashTable* HashTable(int k){
  hashTable* T = malloc(sizeof(hashTable));
  T->size = (k < 4 ? factorial(9)/20 : factorial(9)*k);
  T->V = malloc(sizeof(vertex*)*T->size);
  T->k=k;
  T->bitlength = (int)ceil((log((double)k*k)/log(2.0)));//log conversion, just want lg(k^2) rounded up
  return T;
}

int hash(hashTable* T, int board[]){
  unsigned long long sum =0;
  int bitfield =0; //bit field len 32

  int fidx=0; //field index
  for(int i=0; i < T->k*T->k; i++){
    for(int j=0; j < T->bitlength; j++){
      if(fidx==32){//we've read enough bits
        sum+=bitfield*193; //random prime const num1
        fidx=0;
        bitfield=0;
      }
      bitfield |= ((board[i]>>j)&1<<fidx++);//add to our bitfield and inc the bitfield index
    }
  }
  return (sum*769)%T->size;
}

int compareBoards(int board1[], int board2[], int k){
  for(int i=0; i<k*k; i++){
   if(board1[i]^board2[i]) return 0; 
  }
  return 1;
}

void insertHT(hashTable* T, int board[], vertex* pred){
  vertex* v = Vertex(board, T->k, pred);
  int pos = hash(T, board);
  v->next=T->V[pos];
  T->V[pos]=v;
}

vertex* isMemberHT(hashTable* T, int board[]){
  vertex* cur = T->V[hash(T,board)];
  while(cur != NULL){
    if(compareBoards(cur->board,board, T->k)) break;
    cur = cur->next;
  }
  return cur;
}

void printHT(hashTable* T){
  vertex* v;
  for(int i=0; i < T->size; i++){
    if(T->V[i]!=NULL){
      v=T->V[i];
      while(v != NULL){
        printVertex(v, T->k);
        v = v->next;
      }
    }
  }
}
/******* Hashtable End *******/

void printArr(int arr[], int n){
  printf("[");
  for(int i=0; i < n; i++)printf(" %d ",arr[i]); 
  printf("]\n");
}

// int main(){
  // hashtable test
  // hashTable* T = HashTable(3);
//
  // int board1[] = {1,2,8,4,5,0,7,6,3};
  // int board2[] = {1,2,0,4,5,8,7,6,3};
  // int board3[] = {1,0,2,4,5,8,7,6,3};
  // int board4[] = {1,5,2,4,0,8,7,6,3};
  // int board5[] = {1,5,2,4,8,0,7,6,3};
//
  // insertHT(T,board1, NULL);
  // insertHT(T,board2, NULL);
  // insertHT(T,board3, NULL);
  // insertHT(T,board4, NULL);

  // printHT(T);

  // printf("b1 isMember %d\n", isMemberHT(T,board1)!=NULL);
  // printf("b2 isMember %d\n", isMemberHT(T,board2)!=NULL);
  // printf("b3 isMember %d\n", isMemberHT(T,board3)!=NULL);
  // printf("b4 isMember %d\n", isMemberHT(T,board4)!=NULL);
  // printf("b5 isMember %d\n", isMemberHT(T,board5)!=NULL);
//
  // graph test
  // graph* G = Graph(3);
//
  // addVertex(G,board1, NULL);
  // addVertex(G,board2, NULL);
  // addVertex(G,board3, NULL);
  // addVertex(G,board4, NULL);
//
  // printGraph(G);
//
  // printf("b1 isMember %d\n", getVertex(G,board1)!=NULL);
  // printf("b2 isMember %d\n", getVertex(G,board2)!=NULL);
  // printf("b3 isMember %d\n", getVertex(G,board3)!=NULL);
  // printf("b4 isMember %d\n", getVertex(G,board4)!=NULL);
  // printf("b5 isMember %d\n", getVertex(G,board5)!=NULL);
//
// }
