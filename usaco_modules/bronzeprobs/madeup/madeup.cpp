//Author: Jonathan Parlett
//Program Name: madeup.c
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


int main(){

  ll n; cin >> n;

  vi A, B, C; 
  A.resize(n);
  B.resize(n);
  C.resize(n);

  for(ll i=0; i < n; i++){
    cin >> A[i]; 
  }
  for(ll i=0; i < n; i++){
    cin >> B[i]; 
  }
  for(ll i=0; i < n; i++){
    cin >> C[i]; 
  }

  ll ans=0;
  //define the mapping
  map<ll,ll> S;
  for(ll i=0; i < n; i++){
    S[B[C[i]-1]]++;
  }

  //check the number of times the element in A occurs in the mapping described by C
  for(ll i=0; i < n; i++){
    ans+=(S[A[i]]);
  }

  cout << ans << endl;
}

/*
 * Naive solutions
 *
 * Check
 *  A[i]==B[C[j]] for j < n
 *
 *  C defines a subset/sub mapping thing of B
 *
 *  we can go through the indices in C and count the occurence of each number polled to by C
 *
 */
