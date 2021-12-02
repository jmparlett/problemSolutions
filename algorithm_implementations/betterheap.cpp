#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/** structs **/
typedef struct hnode {
  char c;
  float freq;
  struct hnode* left;
  struct hnode* right;
} hNode;

typedef struct {
  int *arr;
  int size;
  int capacity;
} heap;

/* prototypes */
void printHeap(heap* H);
void printArr(int arr[], int n);
//root is always A[0]
//assume n is position of node
#define parent(n) ((n)-1)/2 //parent of a node is at (n-1)/2
#define leftChild(n) ((n)+1)*2-1 //left child of node at index (n+1)*2-1
#define rightChild(n) (n)+1*2 //right child of a node is at (n+1)*2

//heap constructor
heap* Heap(int n){
 heap* H=malloc(sizeof(heap)); 
 H->arr=malloc(sizeof(int)*n);
 H->capacity=n;
 H->size=0;
 return H;
}

/* inserting to heap */
void swap(heap* H, int pos1, int pos2){
  //swap based on array positions
  //xor swap
  H->arr[pos1]^=H->arr[pos2];
  H->arr[pos2]^=H->arr[pos1];
  H->arr[pos1]^=H->arr[pos2];

  // int tmp = H->arr[pos1];
  // H->arr[pos1] = H->arr[pos2];
  // H->arr[pos2]=tmp;
}

void swapIntArr(int arr[], int pos1, int pos2){
  //swap based on array positions
  //xor swap
  arr[pos1]^=arr[pos2];
  arr[pos2]^=arr[pos1];
  arr[pos1]^=arr[pos2];

  // int tmp = H->arr[pos1];
  // H->arr[pos1] = H->arr[pos2];
  // H->arr[pos2]=tmp;
}
void upheap(heap* H, int pos){
  //if you are root stop
  if(pos-1 < 0) return;

  //if your greater than you parent stop
  if(H->arr[parent(pos)] <= H->arr[pos]) return;

  //else swap with parent and recurse
  swap(H,pos,parent(pos));
  upheap(H, parent(pos));
}

void upheapIntArr(int arr[],  int len, int pos){
  //if you are root stop
  if(pos-1 < 0) return;

  //if your greater than you parent stop
  if(arr[parent(pos)] <= arr[pos]) return;

  //else swap with parent and recurse
  swapIntArr(arr,pos,parent(pos));
  upheapIntArr(arr, len, parent(pos));
}
void insertToHeap(heap* H, int n){
  //we always insert to last place
  H->arr[H->size]=n;

  upheap(H, H->size);

  H->size++;
}
/**** inserting to heap end ****/



/**** deleting from heap *****/
void downheap(heap* H, int pos){
  //if you have no children stop
  if(leftChild(pos) >= H->size) return;

  //if you have only left check if less than and swap with left
  if(rightChild(pos) >= H->size){
    if(H->arr[pos] > H->arr[leftChild(pos)]){
      swap(H, leftChild(pos), pos);
      downheap(H, leftChild(pos));
    }
    return; //only had left and were less than it so we can stop
  }


  //if you have both find min of children and swap with that one if greater than it
  int minpos = H->arr[leftChild(pos)] < H->arr[rightChild(pos)] ? leftChild(pos) : rightChild(pos);
  if(H->arr[pos] > H->arr[minpos]){
      swap(H, minpos, pos);
      downheap(H, minpos);
  }
}

int getMin(heap* H){
 if(H->size == 0) return -1;
 int min = H->arr[0];

 //swap min to end and dec size
 swap(H, 0, --H->size);

 //move root to correct place
 downheap(H, 0);

 return min;
}
/**** deleting from heap end *****/


void heapSort(int arr[], int n){

  heap* H = Heap(n);

  //dump into heap
  for(int i=0; i<n; i++) insertToHeap(H,arr[i]);
  //place min into arr and delete from heap
    for(int i=0; i<n; i++){
      printHeap(H);
      arr[i]=H->arr[0];
      getMin(H);
  }

  free(H->arr);
  free(H);
}

int main(){
  int arr[] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  int len=10;

  

  /* heap sort test */
  // heap* H = Heap(len);
  // for(int i=0; i < len; i++){
    // insertToHeap(H,arr[i]);
    // printHeap(H);
  // }
  // heapSort(arr, len);
  // printArr(arr,len);
  

  /* upheap everthing test */
  heap* H = Heap(len);
  H->arr = arr;
  H->size=10;
  // printHeap(H);
  for(int i=len; i>=0; i--){
    downheap(H,i);
    printHeap(H);
  }
  // get min so we can see if this sorted it
  for(int i=0; i<len; i++)
    printf("%d ",getMin(H));

  printf("\n");
}


/********* print funcs *********/
void printHeap(heap* H){
  for(int i=0; i < H->size; i++)
    printf("%d ", H->arr[i]);

  printf("\n");
}

void printArr(int arr[], int n){
  for(int i=0; i < n; i++)
    printf("%d ", arr[i]);

  printf("\n");
}
