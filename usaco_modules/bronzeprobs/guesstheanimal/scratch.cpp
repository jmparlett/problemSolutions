#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

void setio(string s){
  freopen((s+".in").c_str(), "r", stdin);
	// the following line creates/overwrites the output file
	freopen((s+".out").c_str(), "w", stdout);
	// cin now reads from the input file instead of standard input
}


int main(){
  setio("guess");
  //answer should be length of the longest intesection of two sets+1
  //so if we build sets from each entry and compute all intersections
  //we can take the len of the max

  int n; cin >> n;
  vector<vector<string>> E;
  E.resize(n);
  for(int i=0; i < n; i++){
    string s;//throwaway
    cin >> s;
    int k; cin >> k; //need to read k strings
    E[i].resize(k);
    for(int j=0; j < k; j++){
      cin >> E[i][j];
    }
  }

  //now compute all intersections
  int ans=0;
  for(int i=0; i < n; i++){
    for(int j=0; j < n; j++){
      if(i==j) continue;
      //inclusion exclusion |AUB| = |A| + |B| - |AnB|
      set<string> entries(E[i].begin(),E[i].end());
      for(auto c : E[j]) entries.insert(c);

      int lenint = abs(int(entries.size()) - int(E[i].size()) - int(E[j].size()));

      ans = max(ans,lenint);
    }
  }
  cout << ans + 1 << '\n';
}
