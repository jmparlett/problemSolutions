#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

int main(){
  //12,14s/problem/name/g
  freopen("cowsignal.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("cowsignal.out", "w", stdout);
	// cin now reads from the input file instead of standard input

  //for each line we will have k copies, for char in the line we will have k chars.
  int m, n, k; cin >> m >> n >> k;

  for(int i=0; i < m; i++){
    string s = "";
    string line; cin >> line; //current line to process
      for(int j=0; j < n; j++){
        for(int u=0; u < k; u++){
          s+=line[j];//copy char k times
      }
    }
    for(int u=0; u < k; u++){
      cout << s << '\n';//out line k times
    }
  }
}
