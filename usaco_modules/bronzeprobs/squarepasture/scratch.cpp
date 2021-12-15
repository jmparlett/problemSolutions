#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int


int main(){
  freopen("square.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("square.out", "w", stdout);
	// cin now reads from the input file instead of standard input
  
  int bl1x, bl1y, tr1x, tr1y; cin >> bl1x >> bl1y >> tr1x >> tr1y;
  int bl2x, bl2y, tr2x, tr2y; cin >> bl2x >> bl2y >> tr2x >> tr2y;
  

  int minw = max(tr1x,tr2x) - min(bl1x,bl2x);
  int minh= max(tr1y,tr2y) - min(bl1y,bl2y);
  
  int sqlen = max(minw,minh);
  int tarea = sqlen*sqlen;
  
  int iw = max(min(tr1x,tr2x) - max(bl1x,bl2x),0);
  int ih = max(min(tr1y,tr2y) - max(bl1y,bl2y),0);
  int iarea = iw*ih;

  cout << tarea - iarea << '\n';
}
