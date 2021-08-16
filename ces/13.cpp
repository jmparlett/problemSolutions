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
		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int


int main(){
    
  ll n; cin >> n;



  //generate gray codes by first changing the rightmost bit
  //next change the bit to the left of the right most one
  //then repeat never making the same move twice
  //so if you changed the rightmost bit next change bit to left of right most one
  //else change rightmost
  //repeat 2^n times starting at 0
  

  bool lastMove; //0 means we changed rightmost 1 means we changed left of rightmost one
  ll i=0,j=1, bitfield=0;
 
  lastMove=1;

  for(i=0; i < n; ++i){ bool bit; bit = (bitfield&(1<<i)) ? 1 : 0; cout << bit; } cout << '\n';
  while(j++ < (1<<n)){
    if(lastMove){ //flip rightmost
      bitfield^=1;
      lastMove=0;
    } else {
      ll p=0;
      while(!(bitfield&(1<<p++)));
      bitfield^=(1<<p);
      lastMove=1;
    }
    for(i=0; i < n; ++i){ bool bit; bit = (bitfield&(1<<i)) ? 1 : 0; cout << bit; } cout << '\n';
  }

}


