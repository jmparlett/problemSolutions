#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

int main(){
  //12,14s/problem/name/g
  freopen("speeding.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("speeding.out", "w", stdout);
	// cin now reads from the input file instead of standard input

  
  int road[101] = {};

  int n,m; cin >> n >> m;
  int lensofar= 0;
  int rdx = 1;
  for(int i=0; i < n; i++){
    int length, speed; cin >> length >> speed;
    for(; rdx <= lensofar+length; rdx++){
      road[rdx]=speed;
    }
    lensofar+=length;
  }
 

  int largestViolation=0;
  rdx=1;
  lensofar=0;
  for(int i=0; i < m; i++){
    int length, speed; cin >> length >> speed;
    for(; rdx <= length+lensofar; rdx++){
      if((speed-road[rdx]) > largestViolation){
        largestViolation = (speed-road[rdx]);
      }
    }
    lensofar+=length;
  }
  cout << largestViolation << '\n';
}
