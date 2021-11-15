#include <stdio.h>
#include <stdlib.h>
#include "circularqueue.h"

#define numnodes 5

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
  return newNode;
}

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

int main(){
  node* list[numnodes];
  for(int i=0; i < numnodes; i++) list[i]=Node(i,NULL);

  //0 is adjacent to 1,2,3 
  append(list[0],1);
  append(list[0],2);
  append(list[0],3);

  //1 is adjacent to 0,2,4
  append(list[1],0);
  append(list[1],4);

  //2 is adjacent to 0 and 1
  append(list[2],0);

  //3 is adjacent to 0, 4
  append(list[3],0);
  append(list[3],4);

  //4 is adjacent to 1 and 3
  append(list[4],1);
  append(list[4],3);

  for(int i=0; i < numnodes; i++) printAdjacencies(list[i]);

  char color[numnodes];
  int distance[numnodes];
  node* pred[numnodes];
  
  bfs(list[2], list, color, distance, pred, numnodes);
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
