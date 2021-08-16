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

  string s; cin >> s;

  // use sliding window to swap chars in the string
  // left pointer starts at begining of string and right starts at end
  // on start check if char at left pointer is at right pointer
  // if not move left pointer until a target char is found and swap it into the place of the right pointer then increment left and right pointers
  // sliding window lit -__-

  ll l, r; 

  for(l=0, r=s.size()-1; l < r; l++){
    if(s[l] != s[r]){
      ll tr=r;
      while(s[l] != s[r] && l+1 < r) r--;
      if(s[l] != s[r]){ cout << "NO SOLUTION\n"; return 0;}
      char ts = s[r];
      s[r] = s[tr];
      s[tr]=ts;
      r=tr;
      r--;
    } else{
      r--;
    }

  }

  cout << s << '\n';
}


// if it is even length the string must have an even number of each letter
// if it is odd it can have one unique letter in the string all others must be even
