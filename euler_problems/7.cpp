#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <math.h>
using namespace std;
using ll = long long int;



int main(){

	ll n;
	cin >> n;
	deque<ll> digits;
	while(n > 10){
		digits.push_front(n%10);
		n/=10;
	} 
	digits.push_front(n);

	for(auto c : digits){cout << c << " ";}



}
