#include <stdio.h>
#include <stdlib.h>

//count sort sorts a collection of ints in linear time as long as you know the range of
//values in the collection

void printarr(int arr[], int n);

//takes input and output array, size of input array=n and max num in range=k
void countSort(int input[], int output[], int n, int k){
  //range is [0,k]
  int count[k+1]; for(int j=0; j<k+1; j++) count[j]=0; //zeroize count arr

  //count occurances of nums
  for(int i=0; i < n; i++){
    count[input[i]]++;
  }
  printarr(count,k+1);
  //intuition: How do we know where to put subsequent elements in relation to
  //ones previously inserted? We must know the offset from the last element to
  //place the new. If we have inserted 2 1s than the next number whatever it may be
  //must be 2 places ahead of the 1s. So the index of subseqent elements will
  //end up being the number of times the previous element occured.
  
  //lets make it so the count of each number is the sum of the previous counts
  for(int i=1; i<k+1; i++){
    count[i]+=count[i-1]; 
  }
  printarr(count,k+1);

  //now rotate the array so first element ends up in position 0
  //in this way position 0 is the sum of the occurances of the previous elements
  //and since there are no previous elements it should rightly be 0
  for(int i=k; i>0; i--){
    count[i]=count[i-1];
  }
  count[0]=0;
  printarr(count,k+1);
  //Now we insert each element. Since each repeated element must be placed correctly
  //,one after the other, the index of the repeated element will the index of the previously
  //inserted copy +1
  for(int i=0; i < n; i++){
    //this is real confusing, but just slow down and think about it :)
    output[count[input[i]]]=input[i];
    count[input[i]]++;
  }
}


void printarr(int arr[], int n){
  for(int i=0; i<n; i++) printf("%d ", arr[i]);
  printf("\n");
}

int main(){

  int n=7, k=9;
  int input[] = {1, 4, 1, 2, 7, 5, 2};
  int output[n];

  printarr(input, n);
  countSort(input, output, n, k);
  printarr(output, n);

}
