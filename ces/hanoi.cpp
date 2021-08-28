#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int



int sumarr(int [], int);
int findmin(int [], int , int , int );
int cmpfunc (const void * , const void * );
void hanoi(ll, int, int, int);
int main(){

  ll n; cin >> n;
  
  cout << (1<<n)-1 << '\n';
  hanoi(n, 1, 2, 3); 

}

void hanoi(ll n, int a, int b, int c) 
{
  //a = tower to move from
  //c = tower to move to
  //b = extra tower

  //base case
  if(n==1){
    cout << a << ' ' << c << '\n';
    return;
  }

  hanoi(n-1, a, c, b); 

  cout << a << ' ' << c << '\n';

  hanoi(n-1, b, a, c);
}




int cmpfunc (const void * a, const void * b) {
     return ( *(int*)a - *(int*)b );
}

int sumarr(int arr[], int n){

  int sum=0, i=0;
  while(i < n) sum+=arr[i++];
  return sum;
}
