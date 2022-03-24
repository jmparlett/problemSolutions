// Author: Jonathan Parlett
// Program Name: oddphotos.cpp
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


int main(){
  
  int n; cin >> n;

  
  int odds, evens, tmp;

  odds = evens = 0;

  for(int i = 0; i < n; i++){
      cin >> tmp;
      if (tmp & 1) odds++;
      else evens++;
  }

  //you just want to maximize the amount of odd and even numbers
  
  //the ideal is you have equal odd and evens in which case the number of
  //groups is just n because you can always make them alternate
  //so how many odds do you need to sacrifice to get to this equilibrium point?
  

  while(odds > evens){
    odds -= 2; evens++;
  }

  //what if you have more evens than odds?
  //then the best you can do is twice the number of odds plus one more even group at the end
  if(odds < evens) cout << 2*odds + 1 << endl;
  else cout << odds + evens << endl;
}
