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



ll sumarr(ll [], ll);
ll findmin(ll [], ll , ll , ll );
ll cmpfunc (const void * , const void * );

int main(){

  ll n; cin >> n;

  ll arr[n], i=0; 
  while(i < n){
    ll tmp; cin >> tmp;
    arr[i++]=tmp;
  }

  // for(ll j=0; j < n; j++) cout << arr[j] << ' '; cout << '\n';
  // qsort(arr, n, sizeof(ll), cmpfunc);
  // for(ll j=0; j < n; j++) cout << arr[j] << ' '; cout << '\n';
  cout << findmin(arr, n-1, 0, sumarr(arr, n)) << '\n';
}


ll findmin(ll arr[], ll n, ll g1, ll g2){
  if(n==0) return abs((g2-g1)-g1);   

  return min(findmin(arr, n-1, g1+arr[n], g2), findmin(arr, n-1, g1, g2));    
}


ll cmpfunc (const void * a, const void * b) {
     return ( *(ll*)a - *(ll*)b );
}

ll sumarr(ll arr[], ll n){

  ll sum=0, i=0;
  while(i < n) sum+=arr[i++];
  return sum;
}
