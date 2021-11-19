#include <stdlib.h>
#include <stdio.h>

/* How to store our graph?
   Need to know
   1. vertices connected to a given vertex (edges incident in/out)
   2. color of vertex
   3. distance from source
   4. predecessor node

   edges we will store edges incident from in a nodes alist
*/


/****** Graph Start ******/
typedef struct Anode{
 int vertex; //index of node in actual list
 struct Anode* next; //pointer to next node in alist
} anode; //adjacent node pointer needs less information

//anode constructor
anode* Anode(int vertex){
  anode* n = malloc(sizeof(anode));
  n->vertex = vertex;
  n->next=NULL;
  return n;
}

typedef struct Vertex {
 int id; //label/index of node
 char color;
 int distance; //distance from source node
 int finish;
 int discovered;
 struct Vertex* pred; //predecessor node
 anode* alisthead;
} vertex; //actul node object

//node constructor
vertex* Vertex(int id){
  vertex* v = malloc(sizeof(vertex));
  v->id=id;
  v->color='w';
  v->distance=100000; //large sentinal, distance is same as discover time
  v->finish=0; //time turned black
  v->discovered=0; //time turned black
  v->pred=NULL;
  v->alisthead=NULL;
  return v;
}

typedef struct {
  int size; //num nodes in graph
  int capacity;
  vertex* V[100]; //array of vertices in graph
} graph;

//graph constructor
graph* Graph(){
  graph* G = malloc(sizeof(graph));
  G->size=0;
  G->capacity=100;
  for(int i=0; i < G->capacity; i++) G->V[i] = NULL;
  return G;
}

void addEdge(graph* G, int src, int dest){
  //if src vertex doesn't exist lets create it
  //this way we could create a graph just from a list of edges
  if(G->V[src] == NULL){
    G->V[src] = Vertex(src);
    G->size++;
  }

  //create new alist entry and add it to src's alist
  anode* n = Anode(dest);
  n->next = G->V[src]->alisthead;
  G->V[src]->alisthead = n;
}

void printGraph(graph* G){
  for(int i=0; i<G->size; i++){
    printf("%d: ", G->V[i]->id);
    anode* c = G->V[i]->alisthead;
    while(c != NULL){
      printf("%d ",c->vertex);
      c = c->next;
    }
    // printf("\ncolor: %c pred: %d timeS: %d timeF: %d", G->V[i]->color, (G->V[i]->pred == NULL ? -1 : G->V[i]->pred->id), G->V[i]->discovered, G->V[i]->finish);
    //newline for the neatness
    printf("\n");
  }
}

void transpose(graph* G){
  //If there is an edge (v,u)
  //add an edge (u,v) and remove (v,u)
  
  anode* arr[G->size];

  for(int i=0; i<G->size; i++){
    //all current vertices need to be removed
    arr[i] = G->V[i]->alisthead;
    G->V[i]->alisthead=NULL;
  }

  //now we can invert just the edges that were there before the call
  for(int i=0; i<G->size; i++){
    if(arr[i] == NULL) continue;
    anode* head = arr[i];
    while(head != NULL){
      addEdge(G, head->vertex, G->V[i]->id);
      anode* tmp = head;
      head = head->next;
      free(tmp);
    }
    free(head);
    // printGraph(G);
  }
}

int cmpVertices(const void* a, const void* b){
  return (((vertex*)b)->finish - ((vertex*)a)->finish);
}

/****** Graph End ******/

/****** Queue Start *****/
typedef struct {
  vertex* arr[10000];
  int head;
  int tail;
  int size;
  int capacity;
} queue;

queue* Queue(){
  queue* Q = malloc(sizeof(queue));
  Q->size=0;
  Q->tail=0;
  Q->head=0;
  Q->capacity=10000;
  return Q;
} 

void enqueue(queue* Q, vertex* v){
  if(Q->head == Q->tail+1) return; //queue full

  Q->size++;

  Q->arr[Q->tail++] = v; 

  if(Q->tail == Q->capacity){
    Q->tail=0;
  }
}

vertex* dequeue(queue* Q){
  if(Q->head == Q->tail) return NULL; //queue empty

  //were gonna return something so save it
  vertex* tmp = Q->arr[Q->head];

  if(Q->head+1 == Q->capacity) Q->head=0;
  else Q->head++;

  Q->size--;
  return tmp;
}

void printQueue(queue* Q){
  for(int i=Q->head; i != Q->tail; i++){
    if(i==Q->capacity) i = 0;

    printf("%d ", Q->arr[i]->id);
  }

  printf("\n");
}
/****** Queue End *****/

/****** BFS Begin *****/

int bfs(graph* G, vertex* s){

  if(s == NULL) return 0;

  //init queue
  queue* Q = Queue();

  int blackCount=0; //count of black nodes

  anode* c = s->alisthead;
  while(c != NULL){
    if(G->V[c->vertex]->color == 'w'){
      G->V[c->vertex]->color = 'g';
      enqueue(Q,G->V[c->vertex]);
    }
    c = c->next;
  }
  
  //blacken s were done with it
  s->color = 'b';
  blackCount++;
  //check all neighbors
  while(Q->size != 0)
    blackCount += bfs(G, dequeue(Q));

  free(Q);
  return blackCount;
}

int isConnected(graph* G, int src){

  //set all vertices white and pred NULL
  for(int i=0; i < G->size; i++){
    G->V[i]->color = 'w';
    G->V[i]->pred = NULL;
  }
 
  //select source vertex
  vertex* s = G->V[src]; //select source vertex
  s->color = 'g';

  //call bfs main 
  int blackCount=bfs(G, s); //count of black nodes
  printf("bc %d size: %d\n", blackCount, G->size);

  return (blackCount == G->size);
}
/****** BFS End*****/

/****** DFS Start*****/

int dfsVisit(graph* G, vertex* v, int time){

  v->color = 'g';
  v->discovered = ++time;

  //check all adjacent neighbors
  anode* c = v->alisthead;
  while(c != NULL){
    if(G->V[c->vertex]->color == 'w'){
      G->V[c->vertex]->pred=v;
      time+=dfsVisit(G, G->V[c->vertex], time);
    }
    c = c->next;
  }
  v->color = 'b';
  v->finish = ++time;
  return time;
}

void dfs(graph* G){

  for(int i=0; i<G->size; i++){
    G->V[i]->color='w';
    G->V[i]->pred=NULL;
  }
  int time =0;


  for(int i=0; i<G->size; i++){
    vertex* v;
    if((v=G->V[i])->color=='w')//lets visit
      time = dfsVisit(G, v, time);
  }
}


int dfsVisitTimeCentric(graph* G, vertex* v, int time){

  v->color = 'g';
  v->discovered = ++time;

  //check all adjacent neighbors
  anode* c = v->alisthead;
  while(c != NULL){
    if(G->V[c->vertex]->color == 'w'){
      printf("->%d", c->vertex);
      G->V[c->vertex]->pred=v;
      time+=dfsVisitTimeCentric(G, G->V[c->vertex], time);
    }
    c = c->next;
  }
  v->color = 'b';
  v->finish = ++time;
  return time;
}
void dfsTimeCentric(graph* G){

  //need a sorted list of nodes to look through but dont want to disturb the topology of the graph
  //since node label = array index
  vertex* V2[G->size];
  for(int i=0; i<G->size; i++) V2[i]=G->V[i];
  qsort(V2, G->size, sizeof(vertex*), cmpVertices);

  for(int i=0; i<G->size; i++) printf("id: %d finishTime: %d\n",V2[i]->id, V2[i]->finish);
  printf("\n");

  for(int i=0; i<G->size; i++){
    G->V[i]->color='w';
    G->V[i]->pred=NULL;
  }
  int time =0;
  
  int tc=1;

  for(int i=0; i<G->size; i++){
    vertex* v;
    if((v=G->V[V2[i]->id])->color=='w'){//lets visit
      printf("dfs tree %d: Root %d", tc++, v->id);
      time = dfsVisitTimeCentric(G, v, time);
      printf("\n");
    }
  }
}
/****** DFS End*****/

void printPath(vertex* src, vertex* dst){
  //this will absolutely crash if there is no path between src and dest
  if(src==dst)
    printf("path %d ", src->id);
  else {
    printPath(src->pred, dst);
    printf("-> %d ", src->id);
  }
}


int main(){
  
  graph* G = Graph();

  //sub component 1
  // addEdge(G,0,1);
  // addEdge(G,1,2);
  // addEdge(G,2,1);
  

  addEdge(G,0,1);
  addEdge(G,1,4);
  addEdge(G,1,5);
  addEdge(G,1,2);
  addEdge(G,4,0);
  addEdge(G,4,5);
  addEdge(G,5,6);
  addEdge(G,6,5);
  addEdge(G,6,7);
  addEdge(G,7,7);
  addEdge(G,2,3);
  addEdge(G,3,2);
  addEdge(G,3,7);

  // printGraph(G);
  // if(isConnected(G, 5) == 1)
    // printf("True\n");
  // else
    // printf("False\n");
    
  dfs(G);
  printGraph(G);
  printPath(G->V[7],G->V[0]);
  printf("\n");

  transpose(G);
  printGraph(G);

  dfsTimeCentric(G);
}

/*
 * a b c d e f g h
 * 0 1 2 3 4 5 6 7
 * a-b 0-1
 * b-e 1-4
 * b-f 1-5
 * b-c 1-2
 * e-a 4-0
 * e-f 4-5
 * f-g 5-6
 * g-f 6-5
 * g-h 6-7
 * h-h 7-7
 * c-d 2-3
 * d-c 3-2
 * d-h 3-7
 *
 * If a dfs can lead you back to your source node then it is a cycle and by definition all
 * nodes are connected. If a cycle exists in a digraph that it constitutes a SCC. Furthermore
 * an SCC cannot exist outside of a cycle.
 *
 * A back edge between 2 nodes indicates the closing of a cycle.
 *
 * 1. call dfs on graph to get finishing times
 * 2. invert all the edges
 * 3. call dfs on each node again but consider vertices in order of finishing time ascending
 * 4. one dfs call gives you one tree, run until you have no more white nodes
 */
