// Author: Jonathan Parlett
// Program Name: outofplace.cpp
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
  setio("outofplace");


  int n; cin >> n;

  vi arr; 

  int p, t; cin >> p; arr.push_back(p);

  for(int i=1; i < n; i++){
    cin >> t;
    if( t == p ) continue;
   
    p = t; arr.push_back(t);


  }

  // for(auto c : arr) printf("%d ", c);

  int ans = 0;

  bool swapped = 1;

  //this is a pretty bad solution because we basically just did bub sort.
  //We did not take advantage of the fact that we know there is only one element
  //that is out of order.
  while( swapped){
    swapped = 0; 
    for(int i=1; i < arr.size(); i++){
      if(arr[i-1] > arr[i]){
        int tmp = arr[i-1];
        arr[i-1] = arr[i];
        arr[i]=tmp;
        ans++;
        swapped = 1;
      }
    }
  }
  cout << ans << endl;
}
