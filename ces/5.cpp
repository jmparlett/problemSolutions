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

  ll n; cin >> n;

  if(n == 2 || n == 3) cout << "NO SOLUTION\n";

  else if(n==1) cout << 1 << '\n';

  else{
    if(n&1){ //n odd
      //gen n/2 + 1 odds
      for(ll i=0; i < n/2+1; i++) cout << 2*i+1 << ' ';

      //gen n/2 evens
      for(ll i=1; i < n/2+1; i++) cout << 2*i << ' ';
    } else {

      //gen n/2 odds and evens
      for(ll i=1; i < n/2+1; i++) cout << 2*i << ' ';


      for(ll i=0; i < n/2; i++) cout << 2*i+1 << ' ';
    }

  }

}
