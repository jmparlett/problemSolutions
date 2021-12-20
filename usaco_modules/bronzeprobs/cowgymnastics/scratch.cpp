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
  setio("gymnastics");

  int k, n; cin >> k >> n;
  vector<vector<int>> S;
  S.resize(k);
  for(int i=0; i < k; i++){
    vector<int> s;
    s.resize(n);
    for(int j=0; j < n; j++){
      cin >> s[j];
    }
    S[i]=s;
  }
  
  int ans = 0;
  for(int i=1; i <= n; i++){
    for(int j=1; j <= n; j++){
      if(i==j) continue;
      //check if i comes before j in every training session
      bool sflag=true;
      for(auto s : S){
        bool fi=false;
        for(auto c : s){
          if(c==j && !fi) break;
          if(c==i) fi=true;
        }
        if(!fi){
          sflag=false;
          break;
        }
      }
      if(sflag)ans++;
    }
  }
  cout << ans << '\n';
}
