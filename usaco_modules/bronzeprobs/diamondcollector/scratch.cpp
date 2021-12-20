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
  setio("diamond");

  int n,k; cin >> n >> k;
  vector<int>diamonds;
  while(n--){
    int tmp; cin >> tmp;
    diamonds.push_back(tmp);
  }
  
  sort(diamonds.begin(),diamonds.end());
  int ans=0;
  //select one diamond and see how many we can display with it
  for(int i=0; i < diamonds.size(); i++){
    int count=1;//our first diamond
    for(int j=i+1; j<diamonds.size(); j++){
      if(abs(diamonds[j]-diamonds[i])<=k) count++;//we can store these diamonds together 
    }
    ans = max(ans,count);
  }
  cout << ans << '\n';
}
