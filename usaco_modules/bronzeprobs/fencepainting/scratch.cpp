#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int


int main(){
  freopen("paint.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("paint.out", "w", stdout);
	// cin now reads from the input file instead of standard input

  int a,b,c,d; cin >> a >> b >> c >> d;
  int distance = (b-a) + (d-c);
  int intersection = max(min(b, d) - max(a, c), 0);  // subtract the intersection
}
