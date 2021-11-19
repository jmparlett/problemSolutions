#include <stdio.h>
#include <stdlib.h>

//both head and tail start at 0
typedef struct Node {
  int data;
  char color;
  int distance;
  struct Node* next;
  struct Node* parent;
} node;

typedef struct {
  node** arr;
  int tail;
  int head;
  int length;
} queue;

int enqueue(queue* q, node* data){
  if(q->head == q->tail+1){// queue is full
    return -1;
  } else q->arr[q->tail]=data;
  
  if(q->tail==q->length){
    q->tail=0;
  } else {
    q->tail++;
  }
  return 0;
}

node* dequeue(queue* q){
  node* item = q->arr[q->head];
  if(q->tail == q->head){//queue is empty
    return NULL;
  } else if(q->head == q->length){
      q->head=0;
  } else q->head++;
  return item;
}

int isEmpty(queue* q){
  //return 1 if queue empty 0 otherwise
  return (q->tail == q->head);
}

queue* initqueue(int len){
  queue* q=malloc(sizeof(queue));
  q->arr = malloc(sizeof(node*)*len);
  q->head=q->tail=0;
  q->length=len;
  return q;
}

// int main(){
  // queue *q = initqueue(10);
  // printf("%d\n", q->head);
  // printf("%d\n", q->tail);
  // enqueue(q, 10);
  // enqueue(q, 9);
  // enqueue(q, 8);
  // enqueue(q, 8);
  // enqueue(q, 8);
  // enqueue(q, 8);
  // enqueue(q, 8);
  // enqueue(q, 8);
  // enqueue(q, 8);
  // enqueue(q, 8);
//
  // for(int i=0; i < 10; i++) printf("%d ", dequeue(q));
  // free(q);
// }
