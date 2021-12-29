//Author: Jonathan Parlett
//Program Name: sumoftwovals.c
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

  map<int,int> S;

  int n,x; cin >> n >> x;

  vi A; A.resize(n);
  for(int i=0; i < n; i++){
    cin >> A[i];
    S[A[i]]=A[i];
  }

  //if a given num is a solution then its difference with x will be in the array
  for(int i=0; i < n; i++){
    if(S[x-A[i]]==(x-A[i])){//its not the default map val
      //find x-A[i]'s position in the array
      for(int j=i+1; j < n; j++){
        if(A[j]==(x-A[i])){//we found our answer
          cout << i+1 << ' ' << j+1 << endl;
          return 0;
        }
      }
    }
  }
  cout << "IMPOSSIBLE\n";
}
