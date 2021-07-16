#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <math.h>
using namespace std;
using ll = long long int;

ll isPalindrome(ll n){

	ll cn=n, rn=0;
	while (cn > 0){
		rn=(rn*10)+(cn%10);
		cn/=10;	
	}
	//cout << "n: " << n << "rn: " << rn << '\n';	
	if(rn == n){
		return n;
	}
	else{return 0;}
}

int main(){

//num is palindrome if it reads same both ways
//rN= 0, nCopy=n
//while nCopy > 0
//rN = (rN*10)+ (nCopy%10)
//nCopy//10
//
//if rN = n then n is a palindrome
	ll largestPalindrome=0;
	for(ll i=100; i < 999; i++){
		for(ll j=100; j < 999; j++){
			ll p=i*j;
			if( (p > largestPalindrome) and (isPalindrome(p)!=0) ){largestPalindrome=p;}
		}
	}
	cout << largestPalindrome << '\n';
}
