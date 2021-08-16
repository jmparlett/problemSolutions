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
using li = long int;
using ui = unsigned int;

int main(){

 ll t; cin >> t;

 for(; t > 0; --t){
    ll y, x;

    cin >> y >> x;

    if(x>y){
      if(x&1) cout << (x*x-(y-1)) << '\n';
      else cout << (x*x-(x-1+(x-y))) << '\n';
    } else {
      if(y&1) cout << ((y-1)*(y-1)+x) << '\n';
      else cout << (y*y-(x-1)) << '\n';
    }

    

  } 
}


/*
  g= (max(x,y)^2) is grid size


  max(y,x)^2 - (min(y, x)-1)
  
*/




