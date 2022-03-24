// Author: Jonathan Parlett
// Program Name: grassplanting.cpp
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


int main(){
  setio("planting");
  

  //This is just a graph coloring problem. For a single node of degree n
  //you need n+1 colors to color all nodes.
  
  //To color the tree you just need the max degree + 1, because you can just reuse those
  //same colors for the other nodes.


  int degs[100000] = {};

  int n; cin >> n; n--;

  for(int i=0; i < n; i++){
    int x,y; cin >> x >> y;
    degs[x]++;degs[y]++;
  }

  cout << (*max_element(degs, degs+100000)) + 1 << endl;

}
