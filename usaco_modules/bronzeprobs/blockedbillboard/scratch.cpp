#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

int corners(int x,int y, int bl_x,int bl_y,int tr_x, int tr_y){
  return (x <= tr_x && x >= bl_x && y <= tr_y && y >= bl_y); 
}
int main(){
  freopen("billboard.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("billboard.out", "w", stdout);
	// cin now reads from the input file instead of standard input
  
  int bl1x, bl1y, tr1x, tr1y; cin >> bl1x >> bl1y >> tr1x >> tr1y;
  int bl2x, bl2y, tr2x, tr2y; cin >> bl2x >> bl2y >> tr2x >> tr2y;

  int lmw = (tr1x - bl1x);
  int lmh = (tr1y - bl1y);
  int lmbillarea = lmw*lmh;

  int iw = max(min(tr1x,tr2x) - max(bl1x,bl2x),0);
  int ih = max(min(tr1y,tr2y) - max(bl1y,bl2y),0);
  int iarea = iw*ih;

  //check corners covered
  int covered=0;
  covered += corners(bl1x,bl1y,bl2x,bl2y,tr2x,tr2y);
  covered += corners(tr1x,bl1y,bl2x,bl2y,tr2x,tr2y);
  covered += corners(bl1x,tr1y,bl2x,bl2y,tr2x,tr2y);
  covered += corners(tr1x,tr1y,bl2x,bl2y,tr2x,tr2y);
 
  if(covered > 1)
    cout << lmbillarea - iarea << '\n';
  else
    cout << lmbillarea << '\n';
}
