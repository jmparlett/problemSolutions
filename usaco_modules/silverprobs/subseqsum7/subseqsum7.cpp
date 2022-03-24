// Author: Jonathan Parlett
// Program Name: subseqsum7.cpp
// Created: 2022-March-23
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

#define MOD 7

int main(){
  setio("div7");

  
  int n; cin >> n;

  ull cowsum = 0;

  int mostcows = 0;

  vi remainders; remainders.resize(10);

  fill(all(remainders),-1);

  int i=0, tmp; //current index

  for(; i < n; i++){
    cin >> tmp;

    cowsum = ((cowsum + tmp) % MOD);

    if(remainders[cowsum] == -1){//havent seen this remainder yet
      remainders[cowsum]=i;
    } else { //we have seen this remainder before
      mostcows = max(mostcows, i - remainders[cowsum]); 
    }
  }

  cout << mostcows << endl;


}


/*

   The prefixes mod 7 are all that matter

   we want to find collisions of the prefixes that are as far apart in index
   as possible

   so really we only care about the first occurences of a given mod result

   then if we have any collisions later we can compare the difference of the indices
   and take the largest

   we can compute prefixes by just summing new entries as them come in rather
   than storing the whole array
*/
