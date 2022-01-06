// #include "graph.h"
// #include "heap.c"
// #include "solve.h"
#include "heap.c"

//globals
int* targetBoard; //target board state (the sorted board state)
int k; // board size, we're gonna use this everywhere so might as well be global
int MAXDEPTH; //best guess at max depth


int main(int argc, char *argv[]){

  if(argc != 3){
    printf("Error: expected input and output file args\n");
    return 0;
  } 

  FILE* infile;

  if((infile = fopen(*++argv, "r")) == NULL){
      printf("Error: cannot open input file\n");
      return 0;
  }

  FILE* outfile;
  if((outfile = fopen(*++argv, "w")) == NULL){
      printf("Error: cannot open output file\n");
      return 0;
  }

  //remember k is global
  int* initialBoard = parseFile(&k, infile);
  printf("Info: parsed file\n");
  //if problem is not solveable exit immediately
  if(!isSolveable(initialBoard,k)){
    writeNoSolution(outfile);
    free(initialBoard);
    return 0;
  }
  printf("Info: solution possible\n");

  //make our graph and add the first node
  graph* G = Graph(k);
  addVertex(G,initialBoard, NULL); //pred is NULL since its first node in graph
  vertex* source = getVertex(G,initialBoard);//start node for out search
 

  //intialBoard becomes target board
  qsort(initialBoard, k*k, sizeof(int), icmpfunc);
  //bubble up 0
  for(int i=1; i < k*k; i++) swap(initialBoard,i,i-1);

  //lets rename it so its less confusing later
  targetBoard = initialBoard; //this will be global
  initialBoard = NULL;
  free(initialBoard);
 
  //search the graph
  MAXDEPTH=manhattanDistance(source->board,targetBoard,k)+5; //lets make a best guess about what the right depth is based on our heuristic
  //with a little bit of an offset since the heuristic is an underestimate
  // printf("Info: attempting to solve using DFS with max depth %d\n",MAXDEPTH);
  printf("Info: attempting to solve using BFS with priority queue (dijkstras?)\n");
  vertex* goal = dfs(G,source,targetBoard);
  // vertex* goal = bfs(G,source,targetBoard); //could use bfs but it always performs worse
  dijkstra(G,source,targetBoard);

  printf("Info: Solution found, writing solution\n");

  //now lets output our solution
  writeSolution(goal,outfile);

  printf("Info: Program executed sucessfully\n");
  free(G);//so linter will shutup. I'm not making cleanup functions *_*
  return 0;
}


/************ Processing Start ***************/
//parse file, storing k to the given int and returning the intial board state
int* parseFile(int* k, FILE* infile){
  char buf[200]; //each line wont be more than 200 chars
  int len=200;

  fgets(buf, len, infile);//first line is just comment
  fgets(buf, len, infile);//this line is k
  *k = atoi(buf);//store k
  fgets(buf, len, infile);//third line is just comment
  int* board = malloc(sizeof(int)*((*k)*(*k)));

  //need to write each val in buf to board int array
  for(int i=0; i<((*k)*(*k)); i++){
    fscanf(infile, " %d",&board[i]);
  }
  return board;
}

int boardSimilarity(int board[], int targetBoard[], int k){
  int diffCount = 0; //how many cells are different from our target

  for(int i=0; i < k*k; i++)
    if(board[i]!=targetBoard[i])
      diffCount++;

  return diffCount;
}

int manhattanDistance(int board[], int targetBoard[], int k){
  int mDist = 0; //how many cells are different from our target

  //for each item calc distance from correct place
  for(int i=0; i < k*k; i++){
    //calc correct col
    int correctCol = board[i]%k;

    
    //calc current col
    int currentCol = (i+1)%k;

    //calc correct row
    int correctRow=1;
    while(board[i] > k*correctRow) correctRow++;

    //calc current row
    int currentRow=1;
    while((i+1) > k*currentRow) currentRow++;

    //calc distance to correct position
    mDist += abs(correctCol-currentCol) + abs(correctRow-currentRow);
  }

  return mDist;
}
int avcompare(const void* a, const void* b){//compare 2 av nodes by board boardSimilarity to target
  return (manhattanDistance(((av*)a)->board, targetBoard, k) - manhattanDistance(((av*)b)->board, targetBoard, k));
}

av** adjacentPriorityList(av* alistHead){
  //lets keep this simple and just exploit the fact that there will only be at most 4 neighbors
  av** arr = malloc(sizeof(av*)*5);
  for(int i=0; i<5; i++)arr[i]=NULL;//last null is sentinal

  int j=0;
  while(alistHead!=NULL){
    arr[j++] = alistHead;
    alistHead = alistHead->next; 
    // printf("sim: %d\n", boardSimilarity(arr[j-1]->board, targetBoard,k));
  }
  //now j is size of arr
  //insertion sort because its only 4 elements and I'm lazy
  for(int i=1; i < j; i++){
    for(int l=i; (l > 0 && avcompare(arr[l-1],arr[l]) > 0); l--){
    // boardSimilarity(arr[l-1]->board, targetBoard, k) > boardSimilarity(arr[l]->board, targetBoard, k)
      av tmp = *arr[l];
      *arr[l] = *arr[l-1];
      *arr[l-1]=tmp;
    }
  } 
  return arr;
}

//int compare for qsort
int icmpfunc (const void * a, const void * b) {
     return ( *(int*)a - *(int*)b );
}
/************ Processing End ***************/

/************ Search Start   **************/
int dfsVisit(graph* G, vertex* s, int targetBoard[], int depth){
  if(compareBoards(s->board,targetBoard,k)){
      // printArr(s->board,k*k);
      return 1;
  }
  if(depth > MAXDEPTH){
    return 0; //thats far enough
  }
  s->color = 'g';

  //first lets order our ajacency list
  av** plist = adjacentPriorityList(s->alisthead);

  //now lets step through it in order
  int i=0;
  while(plist[i]!=NULL){
    if(getVertex(G,plist[i]->board)==NULL)
      addVertex(G,plist[i]->board, s);

    vertex* v = getVertex(G,plist[i]->board);
    // printVertex(v,k);
    if(v->color=='w'){//explore it
      if(dfsVisit(G,v,targetBoard, depth+1)==1){
          // printArr(s->board,k*k);
          return 1;
        }
    }
    i++;
  }
  s->color='b';
  return 0;
}

vertex* dfs(graph* G, vertex* s, int targetBoard[]){
  //any vertex that exists upon each call has already been intialized
  //so we can skip that step
  s->color='g'; //no loops

  //first lets order our ajacency list
  av** plist = adjacentPriorityList(s->alisthead);

  //now lets step through it in order
  int i=0;
  while(plist[i]!=NULL){
    if(getVertex(G,plist[i]->board)==NULL){
      addVertex(G,plist[i]->board, s);
    }
    vertex* v = getVertex(G,plist[i]->board);
    if(v->color=='w'){//explore it
      if(dfsVisit(G,v,targetBoard, 1)==1){
          return getVertex(G,targetBoard);
        }
    }
    i++; //inc counter
  }
  s->color='b';
  return NULL; //if we ever get here be very afraid
}

//This bfs doesn't work (its not really bfs anyway)
vertex* bfs(graph* G, vertex* s, int targetBoard[]){
  //if we are at target board we can stop
  if(compareBoards(s->board,targetBoard, k)) return s; 
  s->color='g';


  //first lets order our ajacency list
  av** plist = adjacentPriorityList(s->alisthead);

  //now lets step through it in order coloring as we go
  int i=0;
  vertex* v;
  while(plist[i]!=NULL){
    if(getVertex(G,plist[i]->board)==NULL){
      addVertex(G,plist[i]->board, s);
    }
    v = getVertex(G,plist[i]->board);
    if(v->color=='w'){//lets mark it grey
      v->pred=s;
      v->color='g';
    }
    i++; //inc counter
  }
  //now blacken S since we have discovered all its neighbors
  s->color='b';
  i=0;
  while(plist[i]!=NULL){
    if((v=getVertex(G,plist[i]->board))->color!='b'){
      v=bfs(G, v,targetBoard);
      if(v!=NULL) return v;//found our target
    }
    i++; //inc counter
  }


  return NULL;
}


vertex* dijkstra(graph* G, vertex* s, int targetBoard[]){//this only reason this has s as a parameter is for consistency its not actually used
  //init priority queue
  heap* Q = Heap(2000); //inital size

  //add source node
  insertToHeap(Q,Av(s->board,k)); //the dynamics of adjacency list nodes vs actual nodes is super weird

  s->color='g'; //color source gray

  while(!isEmptyH(Q)){//while we still have stuff in the heap

    //new source
    s = getVertex(G, getMin(Q)->board);

    if(compareBoards(s->board,targetBoard,k)==0) return s; 

    //add adjacent nodes to Q and color them gray
    av* u = s->alisthead;
    while(u != NULL){
      if(getVertex(G,u->board) == NULL){//haven't seen this node before
        addVertex(G,u->board, s);
        getVertex(G,u->board)->color='g';
        insertToHeap(Q,u);
        // printf("Q size: %d\n",Q->size);
      }
      u=u->next;
    }
    s->color='b'; //done with s
  }
  //clean up
  free(Q->arr);
  free(Q);
  return getVertex(G,targetBoard);
}
/************ Search End **************/


/************ Print Solution/No Solution Begin **********/

int countInversions(int board[], int k){
  int count=0;
  for(int i=0; i<k*k; i++){
    //how many numbers infront of current are less than current not including our blank
    for(int j=i+1; j<k*k; j++){
      if(board[i] && board[j] && board[i] > board[j])
        count++;
    }
  }
  return count;
}

int blankInEvenRow(int board[], int k){
  int i=0;
  //move to blank
  while(board[i]!=0 && i < k*k){
    i++;
  }

  //find current row
  int currentRow=1;
  while((i+1)>k*currentRow) currentRow++;

  return (currentRow%2);//need to know if in even row from bottom so invert result from top, if current row from top is even
  //then it is odd from bottom
}

int isSolveable(int board[], int k){
  //k odd and inversions even
  if(k&1){
    if(countInversions(board,k)%2==0)
      return 1;
    else return 0;
  }
  
  //k even inversions blank on even row and inversions odd
  if(blankInEvenRow(board,k)){
      if(countInversions(board,k)&1)
        return 1;
      else return 0;
  }

  //blank on odd row and inversions even
  if(!blankInEvenRow(board,k)){
      if(countInversions(board,k)%2==0)
        return 1;
      else return 0;
  }
  return 0;
}

void writeNoSolution(FILE* outfile){
  fprintf(outfile,"#number of moves\n");
  fprintf(outfile,"0\n");
  fprintf(outfile,"#moves\n");
  fprintf(outfile,"no solution\n");
}

int getDifference(vertex* u, vertex* v){//returns move made between two consecutive boards
  for(int i=0; i<k*k; i++){
    if(v->board[i]!=u->board[i]){//return whichever isn't 0
      return (v->board[i]!=0 ? v->board[i] : u->board[i]);
    }
  }
  return -1; //somthing went wrong
}

int getNumMoves(vertex* goal){
  int c=0;
  while(goal->pred != NULL){
    goal=goal->pred;
    c++;
  }
  return c;
}

void getMoves(vertex* goal, FILE* outfile){
  if(goal->pred == NULL){
    return;//reached the start node
  }

  getMoves(goal->pred, outfile);
  fprintf(outfile, "%d ", getDifference(goal,goal->pred));
}

//take in the ending node and write relavant information to out file
void writeSolution(vertex* goal, FILE* outfile){
  fprintf(outfile, "#number of moves\n");

  fprintf(outfile,"%d\n",getNumMoves(goal));

  fprintf(outfile, "#moves\n");

  getMoves(goal, outfile);
  fgetc(outfile); //delete extra space
  fprintf(outfile, "\n");
}
/************ Print Solution/No Solution End **********/


