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
  while(n != 1){
    cout << n << ' ';
    n = (n&1) ? (n*3 + 1): n/2;

  }
  cout << n << ' ';


}
