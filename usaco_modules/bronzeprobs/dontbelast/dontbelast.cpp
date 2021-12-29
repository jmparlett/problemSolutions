//Author: Jonathan Parlett
//Program Name: dontbelast.c
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
  setio("notlast");
  

  int n; cin >> n;
  map<string,int> S;

  //init map
  vector<string> cows = {"Bessie", "Elsie", "Daisy", "Gertie", "Annabelle", "Maggie", "Henrietta"};
  
  for(auto c : cows){
    S[c]=0;
  }

  while(n--){
    string s;
    int m;
    cin >> s >> m;
    S[s]+=m;
  }

  vector<pair<int,string>> P;
  for(auto p : S){
    P.push_back({p.second,p.first});
  }
  sort(all(P));

  for(int i=1; i < P.size(); i++){
    // cout << P[i].second << ' ' << P[i].first << endl;
    if(P[i].first != P[i-1].first){//we found a match
      if(i+1<P.size()){
        if(P[i].first == P[i+1].first){//we have tie
        cout << "Tie" << endl;
        return 0;
        }
      }
      cout << P[i].second << endl;
      return 0;
    }
  }
  cout << "Tie" << endl;
}
