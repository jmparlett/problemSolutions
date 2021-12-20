#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

int charc[26] = {};
string s;
vector<string> perms;

void setio(string s){
  freopen((s+".in").c_str(), "r", stdin);
	// the following line creates/overwrites the output file
	freopen((s+".out").c_str(), "w", stdout);
	// cin now reads from the input file instead of standard input
}

void genperms(string cur){
  if(s.size()==cur.size()){
    perms.push_back(cur);
    return;
  }
  //each char available will be placed in current position once
  for(int i=0; i < 26; i++){
    if(charc[i]){
      charc[i]--;
      genperms(cur+(char)('a'+i));
      charc[i]++;//undo our move
    }
  }
}


int main(){
  cin >> s;
  //gen count of chars available in string

  for(char c : s)
    charc[c-'a']++;
  
  //using recursion
  // genperms("");

  //using next_permutation()
  sort(s.begin(),s.end());
  do
  {
    perms.push_back(s);
  }
  while (next_permutation(s.begin(), s.end()));
 

  cout << perms.size() << endl;
  for(string p : perms)
    cout << p << endl;

}
