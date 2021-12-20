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

ll solve(vector<ll> N, ll s1, ll s2){
  if(N.size()==0)
    return abs(s1-s2);
  
  ll n = N[N.size()-1];
  N.pop_back();
  return min(solve(N,s1+n,s2),solve(N,s1,s2+n));
}



int main(){
  int n; cin >> n;
  vector<ll> nums;
  nums.resize(n);
  for(int i=0; i < n; i++){
    cin >> nums[i];
  }
  
  //using recursion
  // ll ans = solve(nums,0,0);

  //using bitsets
  ll ans=(ll)(1e18);
  for(int mask=0; mask < (1 << n); mask++){
    ll s1=0,s2=0;
    //if the bit at pos j is on in the mask we will take it for s1 else it goes to s2
    for(int j=0; j < n; j++){
      if(mask & (1<<j))
        s1+=nums[j];
      else
        s2+=nums[j];
    }
    ans = min(ans,abs(s1-s2));
  }
  cout << ans << '\n';
}
