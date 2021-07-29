#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <numeric>
#include <math.h>
#include <limits.h>
#include <ctype.h>
#include <stdlib.h>
		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

int longestwithoutrepeats( string a){

ll l, r, current=0, min=10;

  for(l=0, r=0; r < a.size(); r++){
    current++;
    bool flag=0;
    ll cl=l;
    while(l < r)
      if(a[l++]==a[r]){
        flag = 1;
        break;
      }
    
    if(flag){
        min = ((r-cl+1) < min) ? (r-cl+1) : min;
        r=l;
        current =0;
    } else l=cl;
  }

  return min;
}

//step through chars on each char loop through prev with your left pointer
//if you find the current char with your left pointer then check if min < current index of right+1
//if yes set min if not dont touch min
//then set right pointer to left pointer and restart the process.


int main(){
  string a = "abrexrzx"; //5
  string b = "pwwkew"; //3
  string c = "aav"; //2
  string d = "abdefgabef"; //6
  string e = "bbbb"; //1
  string f = "programming"; //4

  cout << longestwithoutrepeats(a) << '\n';
  cout << longestwithoutrepeats(b) << '\n';
  cout << longestwithoutrepeats(c) << '\n';
  cout << longestwithoutrepeats(d) << '\n';
  cout << longestwithoutrepeats(e) << '\n';
  cout << longestwithoutrepeats(f) << '\n';
}


