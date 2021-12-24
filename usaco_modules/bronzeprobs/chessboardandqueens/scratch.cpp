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

bool board[8][8];
bool cols[8];
bool ldiags[15]; //left diags are indexed by difference (c-r)
bool rdiags[15]; //right diags are indexed by sum (c+r)
int ans=0;

void printBoard(bool board[8][8]){
  cout << endl;
  for(int i=0; i < 8; i++){
    for(int j=0; j < 8; j++){
      if(board[i][j]==1)
        cout << ".";
      else
        cout << "#";
    }
    cout << endl;
  }
}

void solve(int cr){
  if(cr==8){//we reached last row (1 past the final idx in grid)
    ans++;
    return;
  }

  //place queen 
  for(int i=0; i < 8; i++){
    if(board[cr][i] && cols[i] && ldiags[cr-i+7] && rdiags[cr+i]){//we can place a queen here
      cols[i] = ldiags[cr-i+7] = rdiags[cr+i] = 0;//set cols and diags as occupied
      
      solve(cr+1);

      cols[i] = ldiags[cr-i+7] = rdiags[cr+i] = 1;//set cols and diags as unoccupied
    }
  }
}



int main(){
  for (int i = 0; i < 8; i++) {
		string s; cin >> s;
		for (int j = 0; j < 8; j++){
      board[i][j]=(s[j] == '.');
		}
	}
  //set all cols/diags as unoccupied
  for(int i=0; i < 8; i++)cols[i]=1;
  for(int i=0; i < 15; i++){
    ldiags[i]=1;
    rdiags[i]=1;
  }
  //2 queens cant go on the same row or column so recursion will never go deeper than 8

  solve(0);

  cout << ans << endl;
}

/*
 * 1. place a queen on row i col j
 * 2. mark all diag spots, and col spots
 * 3. recurse on row i+1
 * 4. if you reach row 8 you have placed all queens so return 1 since you made a valid call
 *    else if you stop before row 8 return 0
 * 5. once once child call returns unmark all marked spots and return.
 *
 */
