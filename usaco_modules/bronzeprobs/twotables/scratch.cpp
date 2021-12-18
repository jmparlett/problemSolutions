#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

typedef struct {
  ll x1;
  ll y1;
  ll x2;
  ll y2;
} rect;

ll corners(ll x,ll y, ll bl_x,ll bl_y,ll tr_x, ll tr_y){
  return (x <= tr_x && x >= bl_x && y <= tr_y && y >= bl_y); 
}

ll iarea(rect r1, rect r2){
  ll iw = max(min(r1.x2,r2.x2) - max(r1.x1,r2.x1),0LL);
  ll ih = max(min(r1.y2,r2.y2) - max(r1.y1,r2.y1),0LL);
  return iw*ih;
}

ll iarea3(rect r1, rect r2, rect r3){//intersection of 3 rects
  ll iw = max(min(min(r1.x2,r2.x2), r3.x2) - max(max(r1.x1,r2.x1),r3.x1),0LL);
  ll ih = max(min(min(r1.y2,r2.y2),r3.y2) - max(max(r1.y1,r2.y1),r3.y1),0LL);
  return iw*ih;
}

ll area(rect r){
  return (r.x2-r.x1)*(r.y2-r.y1);
}

int main(){
  // freopen("billboard.in", "r", stdin);
	// the following line creates/overwrites the output file
	// freopen("billboard.out", "w", stdout);
	// cin now reads from the input file instead of standard input
  
  rect ws; cin >> ws.x1 >> ws.y1 >> ws.x2 >> ws.y2;
  rect bs1; cin >> bs1.x1 >> bs1.y1 >> bs1.x2 >> bs1.y2;
  rect bs2; cin >> bs2.x1 >> bs2.y1 >> bs2.x2 >> bs2.y2;
  
  if(area(ws) > (iarea(ws,bs1)+iarea(ws,bs2)-iarea3(ws,bs1,bs2)))
      cout << "YES\n";
  else
    cout << "NO\n";
}
