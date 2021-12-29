//Author: Jonathan Parlett
//Program Name: whereami.c
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
  setio("whereami");

  
  int n; cin >> n;
  string s; cin >> s;
  for(int k=1; k <= n; k++){

    set<string> S; //set of substrings of length k
    bool flag=true; 
    for(int i=0; i+k <= n; i++){
      string sub = s.substr(i,k);
      if(S.count(sub)!=0){
        flag=false;
        break;
      } else {
        S.insert(sub);
      }
    }
    if(flag){
      cout << k << endl;
      return 0;
    }
  }

}
