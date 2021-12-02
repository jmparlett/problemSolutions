#include <iostream>
#include <algorithm>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

void p1(FILE* f){
  int current=0;
  int prev=0;
  int count=0;

  fscanf(f, "%d\n",&prev);

  while(fscanf(f, "%d\n",&current) > 0){
   if(current > prev) count++;
   cout << prev << '\n';
   prev=current;
  }
  cout << count << '\n';
}

void p2(FILE* f){
  int size=2000; 
  int input[size],c,i=0, count=0;

  while(fscanf(f, "%d\n",&c) > 0) input[i++]=c;
  cout << i << '\n';
  //sliding window
  i=0;

  while(i+3 < size){
    cout << input[i] << '\n';
    int s1,s2; s1=s2=0;
    for(int j=i, k=i+1; k<i+4; j++, k++){
     s1+=input[j];
     s2+=input[k];
    }
    if(s2 > s1) count++;
    i++;
  }
  cout << count << '\n';
}

int main(){

  FILE* f = fopen("input2", "r");

  p2(f);
}
