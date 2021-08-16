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
#include <unistd.h>
#include <stdio.h>
		
using namespace std;
using ll = long long int;
using li = long int;
using ui = unsigned int;

int main(){

 ll n; cin >> n;

 

 if(((n*(n+1))/2)&1) cout << "NO\n";

 else{
   cout << "YES\n";
   
   if(n&1){
    //n/4 numbers from the back and n/4+1 numbers from the front
    cout << n/2 << '\n';
    ll b=0, f=0;
    while(b++ < n/4) cout << b << ' '; 
    while(f < n/4+1) cout << n-f++ << ' ';

    cout << '\n' <<  n/2+1 << '\n';

    while(b <= (n-f)) cout << b++ << ' ';

    cout << '\n';

  } else {
    //n/4 numbers from the front and n/4 numbers from the back 1, 2, 3,4 s=10 s/2=5=1+4=3+2
    cout << n/2 << '\n';
    ll b=0, f=0;
    while(b++ < n/4) cout << b << ' '; 
    while(f < n/4) cout << n-f++ << ' ';

    cout << '\n' <<  n/2 << '\n';

    while(b <= (n-f)) cout << b++ << ' ';

    cout << '\n';
  }
   
 }
 

 
}


/*
  g= (max(x,y)^2) is grid size


  max(y,x)^2 - (min(y, x)-1)
  
*/




