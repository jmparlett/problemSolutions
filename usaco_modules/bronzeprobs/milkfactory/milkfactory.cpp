// Author: Jonathan Parlett
// Program Name: milkfactory.cpp
// Created: 2022-March-23
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

//max of 100 nodes (easy way to represent a graph)
vi alist[101];
bool visited[101];
int n; 

int bfs(int node){

  int ans = 0;

  int cn;

  stack<int> S;

  //visit start
  visited[node]=1; ans++;

  S.push(node);

  while(!S.empty()){

    cn = S.top(); S.pop();

    //visit all neighbors
    for(auto nei : alist[cn]){
      if(visited[nei]) continue;
      visited[nei]=1;
      ans++;
      S.push(nei);
    }

  }

  // printf("ans: %d\n", ans);
  if(ans == n) return node;
  else return -1;

}

int main(){
  setio("factory");
 

  cin >> n;

  int s,e;
  for(int i=0; i<n-1; i++){
    cin >> s >> e;
    //draw edge from s to e
    alist[e].pb(s); //adjacency in a dag: for an edge (1,2) 2 is called adjacent to 1
  }

  for(int node=1; node <= n; node++){
    fill(all(visited), false);
    if(bfs(node) != -1){
      cout << node << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}
