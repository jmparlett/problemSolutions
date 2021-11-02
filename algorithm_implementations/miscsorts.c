#include <stdio.h>
#include <stdlib.h>

void swap(int a, int b, int arr[]){
  int tmp = arr[a];
  arr[a]=arr[b];
  arr[b]=tmp;
}

void printarr(int arr[], int n){
  for(int i = 0; i < n; i++) printf("%d ", arr[i]); 
  printf("\n");
}
void bubSort(int arr[], int n){
  
  int i, swapped=1;
  while(swapped == 1){
    swapped=0;
    i=1;
    while( i < n){
     if(arr[i-1] > arr[i]){
       swap(i, i-1, arr);
       swapped=1;
     }
     i++;
    }
    n--;
  }
}

void bubSortFor(int arr[], int n){
  int size=n;
  for(int i=0; i < n; ++i){
    for(int j=1; j < size; j++){
      if(arr[j-1] > arr[j])
       swap(j, j-1, arr);
    }
    size--;
  }
}


void insertionSort(int arr[], int n){
  for(int i=1; i < n; i++){
    for(int j=i; (j > 0 && arr[j-1] > arr[j]); j--){
      swap(j,j-1,arr); 
    }
  } 
}

void selectionSort(int arr[], int n){
  int start=0;
  while(start<n){
    int minp=start;
    for(int i=start; i < n; i++){
      if(arr[i] < arr[minp]) minp=i;
    }
    swap(minp,start++,arr);
  }
}
int main(){
  
  int arr[] = {7,6,5,4,3,2,1};

  printarr(arr, 7);

  // bubSort(arr, 7);
  // bubSortFor(arr,7);
  // insertionSort(arr,7);
  selectionSort(arr,7);
  printarr(arr, 7);

}
