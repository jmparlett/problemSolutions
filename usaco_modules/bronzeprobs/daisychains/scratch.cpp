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
  
  int n; cin >> n;
  int ans=0; //each single flower is its own average
  vector<int> flowers;
  while(n--){
    int tmp; cin >> tmp;
    flowers.push_back(tmp);
  }

  for(int i=0; i < flowers.size(); i++){
    int sum=0, count=0,j;
    for(j=i; j < flowers.size(); j++){
      sum+=flowers[j];
      count++;
      for(int k=i; k <= j; k++)
        if(flowers[k]*count == sum){
          ans++;
          break;
      }
    }
    
  }
  cout << ans << '\n';

}
