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

  ll t, a, b; cin >> t;
  for(t; t > 0; t--){
  cin >> a >> b;

  if(((a+b)%3 == 0 &&  abs(a-b) <= a && abs(a-b) <= b )) cout << "YES\n";
  else cout << "NO\n";
  }
}

// if a and b are even then there is no effecient solution
// this only works for multiples of 3
//
// you have 2 piles of things and you are taking a total of 3 things from the combined pile each turn
// it makes sense that the piles must be multiples of 3
//
// so a and b sum to a multiple of three and their difference isn't greater then either
