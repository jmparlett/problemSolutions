#include <stdio.h>
#include <stdlib.h>
#include "circularqueue.h"

#define numnodes 5

void dfs(node* alist[], int n);
void bfs(node* s, node* arr[], char color[], int distance[], node* pred[], int n);
//remember we dont actually need nodes because we're just going to identify relations
//by array position
void swap(int arr[], int a, int b){
  int tmp=arr[a];
  arr[a]=arr[b];
  arr[b]=tmp;
}


node* Node(int data, node* next){
  node* newNode = malloc(sizeof(node));
  newNode->data = data;
  newNode->next = next;
  newNode->color = 'w';
  newNode->distance = 10000; //really large sentinal val
  newNode->parent = NULL;
  return newNode;
}

/***** Stack Begin ******/
typedef struct {
  node* arr[100];
  int size;
  int capacity;
} stack;

stack* Stack(){
  stack* S = malloc(sizeof(stack));
  S->size = 0;
  S->capacity = 100;
  return S;
}

void push(stack* S, node* n){
  if(S->size < S->capacity)
    S->arr[S->size++]=n; 
}

node* pop(stack* S){
  if(S->size == 0)
    return NULL;

  return S->arr[--S->size];
}

int isEmptyS(stack* S){
  return (S->size == 0);
}
/***** Stack End ******/

void append(node* n, int data){
  if(n->next == NULL)
    n->next = Node(data, NULL);
  else
    append(n->next, data);
}

void printAdjacencies(node* n){
  printf("Node %d is adjacent to: ", n->data);

  node* next=n;
  while((next=next->next) != NULL)
    printf("%d ", next->data);

  printf("\n");
}

void printPathToNode(node* n){

  if(n->parent == NULL){
    printf("path %d ", n->data);
    return;
  } else {
    printPathToNode(n->parent);
    printf("-> %d ", n->data); 
    return;
  }
}


int main(){
  node* list[numnodes];
  for(int i=0; i < numnodes; i++) list[i]=Node(i,NULL);

  //0 is adjacent to 1,2,3 
  append(list[0],1);
  append(list[0],2);
  append(list[0],3);

  //1 is adjacent to 0,4
  append(list[1],0);
  append(list[1],4);

  //2 is adjacent to 0 
  append(list[2],0);

  //3 is adjacent to 0, 4
  append(list[3],0);
  append(list[3],4);

  //4 is adjacent to 1 and 3
  append(list[4],1);
  append(list[4],3);

  for(int i=0; i < numnodes; i++) printAdjacencies(list[i]);

  // char color[numnodes];
  // int distance[numnodes];
  // node* pred[numnodes];
 
  //stack test
  // stack* S = Stack();
  // push(S,list[0]);
  // push(S,list[1]);
  // push(S,list[2]);
  // push(S,list[3]);
  // push(S,list[4]);
//
  // while(!isEmptyS(S)){
    // printf("node popped: %d\n", pop(S)->data);
  // }
  dfs(list, 5);
  printPathToNode(list[4]);
  printf("\n");
}

void dfs(node* alist[], int n){
  
  //set all nodes white
  for(int i=0; i < n; i++)
    alist[i]->color = 'w';

  //source will be first node in list
  alist[0]->distance=0;

  //init stack and add s
  stack* S = Stack();
  push(S,alist[0]);

  //init current source pointer
  node* s;

  //continue until stack is empty
  while(!isEmptyS(S)){
    //get new s from stack
    s = pop(S);
    s->color = 'g';

    //move through ajacency list of s
    node* v = s;
    while((v=v->next) != NULL){
      //if node not explored add to stack for processing
      if(alist[v->data]->color== 'w'){
        alist[v->data]->distance= s->distance+1;
        alist[v->data]->parent = s;
        push(S,alist[v->data]);
      }
    }

    //we are done with s, so blacken it
    s->color = 'b';
}

  //done with stack;
  free(S);
}

void bfs(node* s, node* arr[], char color[], int distance[], node* pred[], int n){
  for(int i=0; i<n; i++){
      //init dist,pred, and color
      color[i]='w';
      distance[i]=1000; //infinity 
      pred[i]=NULL;
    }

    queue* Q = initqueue(n);
    //init source
    color[s->data]='g';
    distance[s->data]=0;
    enqueue(Q, s);

    while(!isEmpty(Q)){//while Q is not empty
      node* u = dequeue(Q); //u == current node
      printf("Current u: %d\n", u->data);

      node* v = u->next;
      while(v != NULL){//iter through neighbors of u
        printf("Current v: %d\n", v->data);
        if(color[v->data]=='w'){//we have not explored this vertex yet
          color[v->data] = 'g';
          distance[v->data]=distance[u->data]+1;
          pred[v->data]=u;
          enqueue(Q,arr[v->data]);
        }
        v=v->next;
      }
      color[u->data]='b';
    }

    for(int i=0; i < n; i++){
      printf("node %d distance from %d is %d\n", i, s->data, distance[i]);
      printf("Its color is %c and its predecessors is node %d\n", color[i], pred[i]==NULL ? -1 : pred[i]->data);
    }
    free(Q);
}
