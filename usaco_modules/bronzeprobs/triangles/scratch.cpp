#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

void setio(string s){
  freopen((s+".in").c_str(), "r", stdin);
	// the following line creates/overwrites the output file
	freopen((s+".out").c_str(), "w", stdout);
	// cin now reads from the input file instead of standard input
}

typedef struct {
  int x;
  int y;
} pnt;

int main(){
  setio("triangles");

  int n; cin >> n;
  vector<pnt> P;
  P.resize(n);
  for(int i=0; i < n; i++){
    cin >> P[i].x >> P[i].y;
  }

  int maxarea=0;
  for(int i=0; i < n; i++){
    for(int j=0; j < n; j++){
      for(int k=0; k < n; k++){
        if(P[i].y==P[j].y && P[j].x==P[k].x){//these points form a valid triangle
          int area = abs(P[i].x-P[j].x)*abs(P[j].y-P[k].y);
          maxarea=max(maxarea,area);
        }
      }
    }
  }
  cout << maxarea << '\n';
}
