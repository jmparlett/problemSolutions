#include <stdio.h>
#include <stdlib.h>


//remember we dont actually need nodes because we're just going to identify relations
//by array position
void swap(int arr[], int a, int b){
  int tmp=arr[a];
  arr[a]=arr[b];
  arr[b]=tmp;
}

typedef struct {
  int *arr; //holds tree nodes

  int capacity; //allocated size

  int size; //amount of items in arr

} heap;

//root is always A[0]
//assume n is position of node
//parent of a node is at (n-1)/2
//left child of node at index (n+1)*2-1
//right child of a node is at (n+1)*2

//lets make some functions so we dont have to think about this
int getParent(int n){
  return ((n-1) >= 0 ? (n-1)/2 : -1);
}

int getLeft(int n){
  return ((n+1)*2-1); 
}

int getRight(int n){
  return ((n+1)*2);
}

void printarr(int arr[], int n){
  for(int i=0; i<n; i++) printf("%d ", arr[i]);
  printf("\n");
}

//init function
heap* initHeap(int n){
 heap* H=malloc(sizeof(heap)); 
 H->arr=malloc(sizeof(int)*n);
 H->capacity=n;
 H->size=0;
 return H;
}

void upheap(heap* H, int n){
  int parent = getParent(n);
  //we're root lets stop
  if( parent < 0) return; 

  if(H->arr[parent] < H->arr[n])
    //parent is smaller so lets stop
    return;

  //lets swap the parent
  swap(H->arr, parent, n);

  //and recurse
  upheap(H, parent);
}

void insert(heap* H, int data){
  H->arr[H->size]=data;

  //move element up to appropriate place
  upheap(H, H->size);

  //inc size
  H->size++;
}

void downheap(heap* H, int n){
  //if we have no left child then we have no right
  if(getLeft(n) >= H->size) return; 

  if(getRight(n) >= H->size){//only left child
    int min = getLeft(n);
     //swap min and recurse
     if(H->arr[n] > H->arr[min]){
      swap(H->arr, min, n);
      downheap(H, min);
    }
    return;
  }

  //if both children then find min
  int min = H->arr[getLeft(n)] < H->arr[getRight(n)] ? getLeft(n) : getRight(n);

  //swap min and recurse
  if(H->arr[n] > H->arr[min]){
    swap(H->arr, min, n);
    downheap(H, min);
  }
  return;
}

void deletemin(heap* H){
  //swap last element inserted into root
  swap(H->arr, H->size-1, 0);

  H->size--; //dec size deleting min

  if(H->size == 0) return; //only one element to begin with

  downheap(H, 0); //bubble root to correct place
}

void heapSort(int arr[], int n){

  heap* H = initHeap(n);

  //dump into heap
  for(int i=0; i<n; i++) insert(H,arr[i]);
  //place min into arr and delete from heap
  for(int i=0; i<n; i++){
    printarr(H->arr, H->size); 
    arr[i]=H->arr[0];
    deletemin(H);
  }

  free(H->arr);
  free(H);
}

void printHeap(heap* H, int n){
 printf("%d\n", H->arr[n]);

 if(getLeft(n) > H->size) return; //no children

 if(getRight(n) > H->size){ //if no right just print left

   printHeap(H, getLeft(n));

 } else if(H->arr[getRight(n)] < H->arr[getLeft(n)]){//print right then left

   printHeap(H,getRight(n));
   printHeap(H,getLeft(n));

  } else {//print left than right

   printHeap(H,getLeft(n));
   printHeap(H,getRight(n));

  }
}

int main(){
  int arr[] = {79, 87, 28, 6, 46, 66, 17, 1, 58, 94};

  heap* H = initHeap(15);

  for(int i=0; i < 10; i++) insert(H,arr[i]);
  printarr(H->arr, H->size);
  
 

  for(int i=0; i < 10; i++){
    deletemin(H);
    printarr(H->arr, H->size);
  }

  //heapSort
  int unsorted[] = {7,6,5,4,3,2,1};
  
  heapSort(unsorted, 7);

  printarr(unsorted,7);
}
