#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

// int freqs[256] = {};


void setio(string s){
  freopen((s+".in").c_str(), "r", stdin);
	// the following line creates/overwrites the output file
	freopen((s+".out").c_str(), "w", stdout);
	// cin now reads from the input file instead of standard input
}

void getMaxFreqs(pair<string,string> face, int freqs[]){
  int s1freqs[256] = {};
  int s2freqs[256] = {};
  for(int c : face.first){
    s1freqs[c]++;
  }
  for(int c : face.second){
    s2freqs[c]++;
  }
  //take max of freqs
  for(int i='a'; i <= 'z'; i++){
    freqs[i] += max(s1freqs[i],s2freqs[i]);
  }
}

// void getfreq(string s, vector<pair<string,string>> faces){
  // this will take to long :(
  // if(faces.size()==0){//compare freqs
    // int nfreqs[256] = {};
    // for(int c: s){
      // nfreqs[c]++;
    // }
    // compare and take max
    // for(int i='a'; i <= 'z'; i++){
      // if(freqs[i] < nfreqs[i])
        // freqs[i]=nfreqs[i];
    // }
    // return;
  // }

  // pair<string,string> face = faces[faces.size()-1];
  // faces.pop_back();
  // getfreq((s+face.first),faces);
  // getfreq((s+face.second),faces);
// }

int main(){
  setio("blocks");

  //need to count char freqencies and take the max freq of each char over all permutations 
  int n; cin >> n;
  vector<pair<string,string>> faces;
  while(n--){
    string s1,s2; cin >> s1 >> s2;
    faces.push_back({s1,s2});
  }
 
  int freqs[256] = {};
  for(auto face : faces){
    getMaxFreqs(face,freqs); 
  }

  //print required chars
  for(int i='a'; i <= 'z'; i++){
    cout << freqs[i] << '\n';
  }





}
