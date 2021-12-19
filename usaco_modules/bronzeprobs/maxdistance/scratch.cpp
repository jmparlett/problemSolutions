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
} point;

int distance(point p1,point p2){
  int xdif = p1.x-p2.x;
  int ydif = p1.y-p2.y;
  xdif=xdif*xdif;
  ydif=ydif*ydif;
  return xdif+ydif;
}


int main(){

  int n; cin >> n;
   
  vector<point> points;
  for(int j=0; j < n; j++){
    point p; cin >> p.x;
    points.push_back(p);
  }
  for(int j=0; j < n; j++){
    cin >> points[j].y;
  }

  int maxDist = 0;
  for(int j=0; j < n; j++){
    for(int i=j+1; i < n; i++){
    int d = distance(points[i],points[j]);
    if(d > maxDist) maxDist=d;
    }
  }

  cout << maxDist << '\n';
}
