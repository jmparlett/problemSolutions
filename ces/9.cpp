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
using ull = unsigned long long int;
using li = long int;
using ui = unsigned int;

int main(){

 ull n; cin >> n;


 ull r=1,mod = (pow(10,9)+7);


 // you can think of this like any time you are taking the mod of somthing you are saying subtract this
 // thing from that thing until it is no longer bigger than this thing.
 // this means that if we do the subtraction as we are multiplying it doesn't change the result.
 while(n--){ r=(r<<1)%mod;}
 cout << r << '\n';


 
}
