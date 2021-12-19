#include <bits/stdc++.h>
#include <set>

		
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
  setio("tttt");
  
  // string s = "ttyy";
  // set <char> set_name(s.begin(),s.end());
  // set <char> set_name2(s.begin(),s.end());
  // set <set<char>> charset;
//
  // charset.insert(set_name);
  // charset.insert(set_name2);
//
  // cout << charset.size() << '\n';
  // cout << set_name.size() << '\n';
  // for(auto c : set_name)
    // cout << c << '\n';
    
  set <set<char>> winners;
  
  array<string,3> rows; cin >> rows[0] >> rows[1] >> rows[2];

  //check rows for winners
  for(string r : rows){
    set <char> w(r.begin(),r.end());
    if(w.size()<3)
      winners.insert(w);
  }

  //check cols for winners
  for(int i=0; i<3; i++){
    //make our column
    string c = "";
    c+=rows[0][i];
    c+=rows[1][i];
    c+=rows[2][i];
    set <char> w(c.begin(),c.end());
    if(w.size()<3)
      winners.insert(w);
  }

  //check diags
  string d = "";
  d+=rows[0][2];
  d+=rows[1][1];
  d+=rows[2][0];

  set <char> w1(d.begin(),d.end());
    if(w1.size()<3)
      winners.insert(w1);

  d = "";
  d+=rows[0][0];
  d+=rows[1][1];
  d+=rows[2][2];

  set <char> w2(d.begin(),d.end());
    if(w2.size()<3)
      winners.insert(w2);

  int sc=0,gc=0;
  for(auto w : winners){
    if(w.size()==1)
      sc++;
    else
      gc++;
  }
  cout << sc << '\n' << gc << '\n';

}
