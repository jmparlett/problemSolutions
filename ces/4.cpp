#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <numeric>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>
		
using namespace std;
using ll = long long int;
using li = long int;
using ui = unsigned int;

int main(){

  li n; cin >> n;
  ll a[n]; 
  for(ll i=0; i < n; ++i){
    ll tmp; cin >> tmp;
    a[i]=tmp;
  }

  ll passes=0;
  for(ll j=0; j < (n-1); ++j){
    if(a[j] > a[j+1]){
      passes += a[j]-a[j+1];
      a[j+1]=a[j];
    }
  }

  cout << passes <<  '\n';
}
