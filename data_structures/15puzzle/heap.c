#include "solve.h"

#define parent(n) ((n)-1)/2 //parent of a node is at (n-1)/2
#define leftChild(n) ((n)+1)*2-1 //left child of node at index (n+1)*2-1
#define rightChild(n) (n)+1*2 //right child of a node is at (n+1)*2

/* AV compare(a,b);
 * If distance(a) < distance(b) returns negative < 0 
 * If equal returns 0
 * If distance(a) > distance(b) returns postive > 0
 */
  

/************ Priority Queue Start ***********/
typedef struct {
  av** arr;
  unsigned long long size;
  unsigned long long capacity;
} heap;

//constructor
heap* Heap(int size){
  heap* Q = malloc(sizeof(heap));
  Q->arr = malloc(sizeof(av*)*size);
  Q->size=0;
  Q->capacity=size;
  return Q;
};

/* inserting to heap */
void swapH(heap* Q, int pos1, int pos2){
  //swap based on array positions
  av* tmp = Q->arr[pos1];
  Q->arr[pos1] = Q->arr[pos2];
  Q->arr[pos2]=tmp;
}

void upheap(heap* H, int pos){
  //if you are root stop
  if(pos-1 < 0) return;

  //if your greater than your parent stop
  if(avcompare(H->arr[parent(pos)], H->arr[pos]) <= 0) return;

  //else swap with parent and recurse
  swapH(H,pos,parent(pos));
  upheap(H, parent(pos));
}


void insertToHeap(heap* H, av* n){
  //we always insert to last place
  H->arr[H->size]=n;

  upheap(H, H->size);

  H->size++;
  if(H->size==H->capacity){//realloc to increase size
    H->capacity+=1000;
    H->arr = realloc(H->arr,sizeof(av*)*H->capacity);
  }
}
/**** inserting to heap end ****/


/**** deleting from heap *****/
void downheap(heap* H, int pos){
  //if you have no children stop
  if(leftChild(pos) >= H->size) return;

  //if you have only left check if less than and swap with left
  if(rightChild(pos) >= H->size){
    if(avcompare(H->arr[pos], H->arr[leftChild(pos)]) > 0){
    // if(H->arr[pos] > H->arr[leftChild(pos)]){
      swapH(H, leftChild(pos), pos);
      downheap(H, leftChild(pos));
    }
    return; //only had left and were less than it so we can stop
  }


  //if you have both find min of children and swap with that one if greater than it
  int minpos = avcompare(H->arr[leftChild(pos)], H->arr[rightChild(pos)]) < 0 ? leftChild(pos) : rightChild(pos);

  if(avcompare(H->arr[pos], H->arr[minpos]) > 0){
      swapH(H, minpos, pos);
      downheap(H, minpos);
  }
}

av* getMin(heap* H){
 if(H->size == 0) return NULL;
 av* min = H->arr[0];

 //swap min to end and dec size
 swapH(H, 0, --H->size);

 //move root to correct place
 downheap(H, 0);

 return min; //its up to the programmer to free the node returned
}

int isEmptyH(heap* H){
  return H->size==0;
}
/**** deleting from heap end *****/



/************ Priority Queue End ***********/
