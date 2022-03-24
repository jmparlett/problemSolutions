// Author: Jonathan Parlett
// Program Name: staticrangesum.cpp
// Created: 2022-March-23
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int
using vi = vector<int>;
using vull = vector<ull>;
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
  // setio("problemName");

  /* All of this is the naive implementation
  int n, q, s, e, init;

  cin >> n >> q;

  vi sq; sq.resize(n);

  for(int i=0; i < n; i++) cin >> sq[i];

  for(int i=0; i < q; i++){
  
    init = 0;

    cin >> s >> e;

    cout << accumulate(sq.begin()+s, sq.begin()+e, 0) << endl;

  }
  */

  //now lets use prefix sums
  int n, q, s, e;

  cin >> n >> q;

  vull sq, P; sq.resize(n), P.resize(n);

  for(int i=0; i < n; i++) cin >> sq[i];

  P[0]=sq[0];

  for(int k=1; k < n; k++){
    P[k] = sq[k] + P[k-1];
  }

  for(int i=0; i < q; i++){
    
      cin >> s >> e;

      if(s == 0) cout << P[e-1] << endl;
      else cout << P[e-1]-P[s-1] << endl;

  }

}
