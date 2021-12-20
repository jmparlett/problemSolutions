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

int solve(int x, int y, int m, int bucket){
  if((bucket + x > m) && (bucket + y > m))
    return bucket; //we cant fill anymore
  else if(bucket + x > m)
    return max(bucket,solve(x,y,m,bucket + y));
  else if(bucket + y > m)
    return max(bucket,solve(x,y,m,bucket + x));
  return max(solve(x,y,m,bucket+x),solve(x,y,m,bucket+y));
}

int main(){
  setio("pails");

  int x,y,m; cin >> x >> y >> m;

  int ans = 0;

  for(int i=0; i < 1001; i++){
    for(int j=0; j < 1001; j++){
      int guess = x*i + y*j;
      if(guess > ans && guess <= m){
        ans = guess;
      }
      if(x*i > m || y*j > m)
        break;
    }
  }
  cout << ans << '\n';


}
