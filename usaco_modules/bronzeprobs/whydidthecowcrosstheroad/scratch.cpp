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
  setio("cowqueue");
  
  int n; cin >> n;

  vector<pi> C; C.resize(n);

  for(int i=0; i < n; i++){
    cin >> C[i].first >> C[i].second; 
  }

  sort(all(C));

  int t = 0;
  for(auto p : C){
    if(p.first > t){
      t=(p.first+p.second);
    } else {
      t+=p.second;
    }
  }

  cout << t << endl;
}


/*
 * time at first cow is time of arrival + time to process
 * time at next cow
 *  if time of arrival is less than current time consumed then time += time to process
 *  if time of arrival greater than current time consumed than time = time of arrival + time to process
 */
