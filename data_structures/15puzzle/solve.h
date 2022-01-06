#include "graph.h"
/****** Prototypes ******/
int* parseFile(int* k, FILE* infile);
int boardSimilarity(int board[], int targetBoard[], int k);
int avcompare(const void* a, const void* b);//compare 2 av nodes by board boardSimilarity to target
int icmpfunc (const void * a, const void * b);
av** adjacentPriorityList(av* alistHead);
vertex* dfs(graph* G, vertex* s, int targetBoard[]);
void writeSolution(vertex* goal, FILE* outfile);
int isSolveable(int board[], int k);
void writeNoSolution(FILE* outfile);
vertex* bfs(graph* G, vertex* s, int targetBoard[]);
int manhattanDistance(int board[], int targetBoard[], int k);
vertex* dijkstra(graph* G, vertex* s, int targetBoard[]);
