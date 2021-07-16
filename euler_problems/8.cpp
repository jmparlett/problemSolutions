#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <math.h>
using namespace std;
using ll = long long int;



int main(){

	string s, tmp;
	for(int i=0; i < 20; i++){
		cin >> tmp;
		s.append(tmp);
	}
//	for(auto c : s){cout << c << ' ';}
		ll largestProduct=0, product=1;
	for(int i=0; i < s.size(); i++){
		product *= int(s[i]-'0');	
		for(ll j=i+1; j < i+13; j++){
			product *= int(s[j]-'0');	
		}
		if(product > largestProduct){largestProduct=product;}
		product=1;
	//	cout << s[i] << int(s[i]-'0') << '\n';
	}
	cout << largestProduct << '\n';


}
