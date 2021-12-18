#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

void pour(pair<int,int>* b1, pair<int,int>* b2){
  //pour from b1 to b2
  if(b1->second > (b2->first - b2->second)){
    b1->second = b1->second - (b2->first - b2->second);
    b2->second = b2->first; //b2 is full
  }  else {
    b2->second += b1->second;
    b1->second = 0; //b1 is empty
  }

}

int main(){
  //12,14s/problem/name/g
  freopen("mixmilk.in", "r", stdin);
	// the following line creates/overwrites the output file
	freopen("mixmilk.out", "w", stdout);
	// cin now reads from the input file instead of standard input
  
  pair<int,int> b1,b2,b3;

  cin >> b1.first >> b1.second;
  cin >> b2.first >> b2.second;
  cin >> b3.first >> b3.second;
  
  int i=0;
  while(i < 100){
    if(i++ < 100)//pour from b1 to b2
      pour(&b1,&b2);
    if(i++ < 100)//pour from b2 to b3
      pour(&b2,&b3);
    if(i++ < 100)//pour from b3 to b1
      pour(&b3,&b1);
  }
  
  cout << b1.second << '\n';
  cout << b2.second << '\n';
  cout << b3.second << '\n';

}
