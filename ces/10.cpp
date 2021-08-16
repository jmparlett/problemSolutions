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

  ll n, a=0, i=5; cin >> n;

  //z = zero count; a = accumulator 
  while(n >= i){
    
    a+=n/i;
    i*=5;
  }
  cout << a << '\n';
}

// factors 2 and 5 produce a zero. Find number of 2s and 5s in result
// how many numbers will have 2 as factor in the sequence from 1 to n
// how many numbers will have 5 as factor in the sequence from 1 to n
// 1 2 3 4 5 6 7 8 9 10
// 2 4 6 8 10; 8 2s
// 2 5s
// always less 5s then twos so count 5s


