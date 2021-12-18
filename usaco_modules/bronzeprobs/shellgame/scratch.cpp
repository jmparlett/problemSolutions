#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

int main(){
  //12,14s/problem/name/g
  freopen("shell.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("shell.out", "w", stdout);
	// cin now reads from the input file instead of standard input
 
  //simplest simulation, just keep an array of shells [1,2,3], then loop 3 times 1 for each guess
  //assume its 1 everytime she guess 1 (arr[g]==1) we inc her points, after we've processed all guesses
  //we add it to a point array, then we repeat for 2, and 3 and output the max score
  

  int scores[] = {0,0,0,0}; //points for a guess of 1 2 3 (ignore the first pos)
  int shells[] = {0,1,2,3};

  int n; cin >> n;
  for(; n > 0; n--){
    int a,b,g; cin >> a >> b >> g;
    
    //swap a,b
    int tmp = shells[a];
    shells[a] = shells[b];
    shells[b] = tmp;

    scores[shells[g]]++;
  }

  cout << max(max(scores[1],scores[2]),scores[3]) << '\n';
  

}
