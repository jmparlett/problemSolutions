//Author: Jonathan Parlett
//Program Name: fastpower.cpp
//Created: 2022-January-9
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

ull fastpower1(ull a, ull b, ull M){
  ull result = 1;
  while(b){
    if(b&1) result = (result * a); //add the extra power
    a = (a * a);
    b /= 2;
  }
  return result;
}

ull fastpower2(ull a, ull b, ull M){
  //lets try to explore this idea manually so its simpler

  //the idea is to compute a^b using b's binary representation
  //so if b = 11 = 1011 = 2^3 + 2^1 + 2^0, then 3^11 = 3^(2^3 + 2^1 + 2^0) = 3^(2^3) ...
  vector<ull> arr; 

  //compute len of arr by finding last bit on in b
  int i=31;

  while(!(b&(1<<i))) i--;

  arr.resize(i+1);
  //compute successive squares of powers

  arr[0]=a; //a^(2^0)

  for(int j=1; j < arr.size(); j++){
    //each entry is the square of the previous
    arr[j]=arr[j-1]*arr[j-1];
  }
  
  //now we sum only the powers that we care about, that is the positions that
  //match the bits on in b
  ull result = 1;

  for(int j=0; j < arr.size(); j++){
    if(b&(1<<j)) result *= arr[j];
  }
  return result;
}

ull fastpower3(ull a, ull b, ull M){
  //for the actual fast power algorithm we can use the same process but compute
  //everythin mod m since (a*b = (a mod m) * (b mod m) (mod m))

  //the idea is to compute a^b using b's binary representation
  vector<ull> arr; 

  //compute len of arr by finding last bit on in b
  int i=31;

  while(!(b&(1<<i))) i--;

  arr.resize(i+1);
  //compute successive squares of powers

  arr[0]=a; //a^(2^0)

  for(int j=1; j < arr.size(); j++){
    //each entry is the square of the previous
    arr[j]=(arr[j-1]*arr[j-1])%M;
  }
  
  //now we sum only the powers that we care about, that is the positions that
  //match the bits on in b
  ull result = 1;

  for(int j=0; j < arr.size(); j++){
    if(b&(1<<j)) result = (result * arr[j])%M;
  }

  //even though there is a bit of unecessary work it is still a fairly effecient algo
  //for fast powering
  return result;
}

//compute a^(p-2)=1/a
int inverse(int a, int p){
  return fastpower3(a, p-2, 1e9);
}

int main(){
  
  //lets compute 3^11 with both algos
  cout << "algo 1: " << fastpower1(3,11,0) << endl;
  cout << "algo 2: " << fastpower2(3,11,0) << endl;


  cout << "fastpower3 3^218 % 1000: " << fastpower3(3,218,1000) << endl;
}
