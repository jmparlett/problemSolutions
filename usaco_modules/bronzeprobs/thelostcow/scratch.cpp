#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

int main(){
  //12,14s/problem/name/g
  freopen("lostcow.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("lostcow.out", "w", stdout);
	// cin now reads from the input file instead of standard input

  int x,y; cin >> x >> y;

  int c = 1;

  int distance=0;

  int pos;

  while(1){//once we've gone passed y we must've hit the cow on the way there

    pos = x+c;

    if((pos >= y && x <= y) || (y <= x && pos <= y)){
      distance += abs(x-y);
      cout << distance << '\n';
      return 0;
    } else {//distance is double the diff
      distance += abs(2*c);
    }


    //double and negate our constant factor
    c = -2*c;
  }
}
