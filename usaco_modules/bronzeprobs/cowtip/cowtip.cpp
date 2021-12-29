//Author: Jonathan Parlett
//Program Name: cowtip.c
//Created: 2021-December-29
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define make_uniqe(x) sort(all(x)); x.resize(unique(all(x)) - x.begin());


void setio(string s){
  freopen((s+".in").c_str(), "r", stdin);
	// the following line creates/overwrites the output file
	freopen((s+".out").c_str(), "w", stdout);
	// cin now reads from the input file instead of standard input
}

void flip(vector<vi> &grid, int r, int c){
  //flip from o to r and 0 to c
  for(int i=0; i <= r; i++){
    for(int j=0; j <= c; j++){
      grid[i][j]=!grid[i][j];
    }
  }
}

int main(){
  setio("cowtip");

  int n; cin >> n;

   vector<vi> grid;
   grid.resize(n);

   for(int i=0; i < n; i++){
    grid[i].resize(n);
    string s; cin >> s;
    for(int j=0; j < n; j++){
      grid[i][j] = s[j]-'0';
    }
   }

  int ans=0;

  for(int r=n-1; r>=0; r--){
    for(int c=n-1; c>=0; c--){
      if(grid[r][c]){
        flip(grid,r,c);
        ans++;
      }
    }
  }
  cout << ans << endl;
}
