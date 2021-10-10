#include <stdio.h>

void merge(int A[], int start, int middle, int stop);
void printarr(int A[], int size);
void mergesort(int A[], int start, int stop);
int main(){


  // int A[] = {4, 5, 6, 8, 1, 2, 3};
  // int sizeA=7;

  int B[] = {1, 5, 4, 9, 7, 3, 66, 32, 71};
  int sizeB=9;
  
  // printarr(A, sizeA);
  // merge(A, 0, sizeA/2, sizeA-1);
  // printarr(A, sizeA);

  printarr(B, sizeB);
  mergesort(B, 0, sizeB-1);
  printarr(B, sizeB);
}

void merge(int A[], int start, int middle, int stop){
  //stop is the index of last element not the size so stop=size-1
  //create temp arr copies 
  int n1=middle - start + 1;
  int n2=stop - middle;
  int B[n1], C[n2];

  //lets do this again :( copy array start to middle to B and middle+1 to stop to C
  for(int i=0; i < n1; i++) B[i]=A[i+start];
  printarr(B, n1);
  for(int i=0; i < n2; i++) C[i]=A[i+middle+1];
  printarr(C, n2);
  //middle+1 will be the start of our upper sorted range so sorted lower range is from start to mid inclusive
  //merge arrs into A
  int i,j,g;
  i=0;//B index
  j=0;//C index
  g=start;

  while(i < n1 && j < n2){
    if(B[i] < C[j]) A[g]=B[i++];
    else A[g]=C[j++];
    g++;
  }
  // printarr(B, stop+1);
  // dump the rest of each arr
  while(i < n1){
    A[g]=B[i++];
    g++;
  }
  while(j < n2){
    A[g]=C[j++];
    g++;
  }
  // printarr(B, stop+1);
  //copy B to A
  // for(int i=0; i<= stop; i++) A[i]=B[i];
}

void mergesort(int A[], int start, int stop){
  if(start >= stop) return; //exit

  int middle=(start+stop) >> 1;

  mergesort(A, start, middle);
  mergesort(A,middle+1, stop);
  merge(A, start, middle, stop);
}

void printarr(int A[], int size){
  for(int i=0; i < size; i++) printf("%d ",A[i]);
  printf("\n");
}
