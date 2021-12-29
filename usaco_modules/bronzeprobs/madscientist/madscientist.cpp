//Author: Jonathan Parlett
//Program Name: madscientist.c
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
  setio("breedflip");

  //need to count num of contigious sub strings that dont match
  int n; cin >> n;
  string a,b; cin >> a >> b;

  int ans=0;
  bool f=false;
  for(int i=0; i < n; i++){
    if(a[i]!=b[i])
      f=true;
    else if(f){
      f=false;
      ans++;
    }
  }
  if(f)
    ans++;

  cout << ans << endl;
}
