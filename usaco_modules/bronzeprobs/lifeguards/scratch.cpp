#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int
#define INF (1e9)

void setio(string s){
  freopen((s+".in").c_str(), "r", stdin);
	// the following line creates/overwrites the output file
	freopen((s+".out").c_str(), "w", stdout);
	// cin now reads from the input file instead of standard input
}

bool isin(int s1, int e1, int s2, int e2){
  return ((s1 >= s2 && s1 <= e2) || (e1 >= s2 && e1 <= e2));
}

int cover[1001] = {}; //how many lifeguards working at time x

int main(){
  setio("lifeguards");

  int n; cin >> n;
  //need 2 vectors size n
  vector<int> is;//interval start
  vector<int> ie;//interval end

  is.resize(n);
  ie.resize(n);

  for(int i=0; i < n; i++){
    cin >> is[i] >> ie[i];
    for(int j=is[i]; j < ie[i]; j++){
      cover[j]++;
    }
  }

  int ans=0; //max cover
  for(int i=0; i < n; i++){
    int covered = 0;
    for(int j=is[i]; j < ie[i]; j++){
      cover[j]--;
    }
    //calculate time covered
    for(int j=0; j < 1001; j++){
      if(cover[j])covered++;
    }
    //add back the interval
    for(int j=is[i]; j < ie[i]; j++){
      cover[j]++;
    }
    ans=max(ans,covered);
  }
  cout << ans << '\n';
}
