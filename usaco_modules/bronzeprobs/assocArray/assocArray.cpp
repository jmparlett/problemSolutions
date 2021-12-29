//Author: Jonathan Parlett
//Program Name: assocArray.c
//Created: 2021-December-28
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

  int q; cin >> q;


  map<ull,ull> S;
  ull t=0, k,v;
  while(q--){
    cin >> t;
    if(t){
      cin >> k;
      cout << S[k] << endl;
    } else {
      cin >> k >> v;
      S[k]=v;
    }
  }


}
