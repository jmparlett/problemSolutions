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
  hNode* root;
} huffmanTree;

typedef struct {
  hNode **arr;
  int size;
  int capacity;
} heap;

/* prototypes */
void printHeap(heap* H);

//root is always A[0]
//assume n is position of node
#define parent(n) ((n)-1)/2 //parent of a node is at (n-1)/2
#define leftChild(n) ((n)+1)*2-1 //left child of node at index (n+1)*2-1
#define rightChild(n) (n)+1*2 //right child of a node is at (n+1)*2

//heap constructor
heap* Heap(int n){
 heap* H=malloc(sizeof(heap)); 
 H->arr=malloc(sizeof(hNode*)*n);
 H->capacity=n;
 H->size=0;
 return H;
}

hNode* HNode(char c, float freq){
  hNode* n = malloc(sizeof(hNode));
  n->c = c;
  n->freq=freq;
  n->left = NULL;
  n->right = NULL;
  return n;
}


/* inserting to heap */
void swap(heap* H, int pos1, int pos2){
  //swap based on array positions
  hNode tmp = *H->arr[pos1];
  *H->arr[pos1] = *H->arr[pos2];
  *H->arr[pos2]=tmp;
}

void upheap(heap* H, int pos){
  //if you are root stop
  if(pos-1 < 0) return;

  //if your less than you parent stop
  if(H->arr[parent(pos)]->freq <= H->arr[pos]->freq) return;

  //else swap with parent and recurse
  swap(H,pos,parent(pos));
  upheap(H, parent(pos));
}

void insertToHeap(heap* H, hNode* n){
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
    if(H->arr[pos]->freq > H->arr[leftChild(pos)]->freq){
      swap(H, leftChild(pos), pos);
      downheap(H, leftChild(pos));
    }
    return; //only had left and were less than it so we can stop
  }


  //if you have both find min of children and swap with that one if greater than it
  int minpos = H->arr[leftChild(pos)]->freq < H->arr[rightChild(pos)]->freq ? leftChild(pos) : rightChild(pos);
  if(H->arr[pos]->freq > H->arr[minpos]->freq){
      swap(H, minpos, pos);
      downheap(H, minpos);
  }
}

hNode* getMin(heap* H){
 if(H->size == 0) return NULL;
 hNode* min = malloc(sizeof(hNode));
 *min = *H->arr[0];

 //swap min to end and dec size
 swap(H, 0, --H->size);

 //move root to correct place
 downheap(H, 0);

 return min;
}
/**** deleting from heap end *****/


/*** print tree ***/
void printInorder(hNode* n){
  if(n==NULL) return;

  printInorder(n->left);

  if(n->c==0)
    printf("(NULLByte,%.2f)->", n->freq);
  else
    printf("(%c,%.2f)->", n->c, n->freq);

  printInorder(n->right);
}

void printTreeInorder(huffmanTree* T){
  if(T->root == NULL) return; //tree empty

  printInorder(T->root);

  printf("\n");
}
/*** print tree end ***/


// int main(){
 // S 0.05
   // h 0.11
   // l 0.21
   // a 0.05
     // 0.11
     // e 0.21
     // s 0.26
  // char s[] = "Shla es";
  // float freqs[] = {0.05, 0.11, 0.21, 0.05, 0.11, 0.21, 0.26};
  // int len = strlen(s);
  // hNode* nodes[7];
//
  // make some nodes
  // for(int i=0; i<len; i++){
    // nodes[i] = HNode(s[i], freqs[i]);
  // }
//
  // heap* H = Heap(20);
//
  // insert some nodes
  // for(int i=0; i<len; i++){
    // insertToHeap(H, nodes[i]);
  // }
//
  // printHeap(H);
  // hNode* tmp;
  // while((tmp = getMin(H)) != NULL){
    // printf("min node was (%c, %.2f)\n",tmp->c, tmp->freq);
    // printHeap(H);
  // }
//
// }
//
//
void printHeap(heap* H){
  if(H->size == 0) return;
  printf("[");
  int i;
  for(i=0; i<H->size-1; i++){
    printf("(%c,%.2f), ", H->arr[i]->c, H->arr[i]->freq);
  }
  printf("(%c,%.2f)]\n", H->arr[i]->c, H->arr[i]->freq);
}
