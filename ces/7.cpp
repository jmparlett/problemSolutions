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
#include <stdio.h>
		
using namespace std;
using ll = long long int;
using ull = unsigned long long int;
using li = long int;
using ui = unsigned int;

int main(){

  ll n, k; cin >> n;

  for(k=1; k <= n; ++k){
    ll r ,s;

    if(k < 3) cout << ((k*k)*(k*k-1)/2) << '\n'; 

    else{
      r=((k*k)*(k*k-1)/2);
  
      s=(4*(k-1)*(k-2));

      r-=s;

      cout << r << '\n';
    }
  }
}


// two from all edges -8 spaces
// two from 3 edges -6 spaces
// two from 2 edges -4
// else -2:
//
//
// number of different ways you place two identicle objects on a board of size n*n is n*n(n*n-1)/2
//
//
