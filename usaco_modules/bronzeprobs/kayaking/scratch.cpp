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

void setio(string s){
  freopen((s+".in").c_str(), "r", stdin);
	// the following line creates/overwrites the output file
	freopen((s+".out").c_str(), "w", stdout);
	// cin now reads from the input file instead of standard input
}

int findmin(vector<int> S){
  int ans=0;
  for(int i=1; i < S.size(); i+=2){
   ans+=(S[i]-S[i-1]);
  }
  return ans;
}

int main(){
  
  int n; cin >> n;
  n*=2;

  vi p; p.resize(n);

  for(int i=0; i < n; i++)
    cin >> p[i];

  //find all pairs of min difference
  sort(all(p));

  int ans=1e9;
  
  for(int i=0; i < n; i++){
    for(int j=0; j < n; j++){
      if(i==j) continue;
      vector<int> subset; subset.resize(n-2);
      for(int k=0, l=0; k < n; k++){
        if(k!=i && k!=j)
         subset[l++]=p[k]; 
      }
      ans = min(findmin(subset),ans);
    }
  }

  cout << ans << endl;
}
