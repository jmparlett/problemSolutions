#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <math.h>
using namespace std;
using ll = long long int;

int main(){
	ll i=2;
	while (true){
		bool flag = 0;
		for(ll c=1; c < 20; c++){
			if(i%c != 0){
				flag=1;
				break;
			}	
		}
		if(flag) {i++; continue;}
		else break;
	}
	cout << i << '\n';

	for(int i=1; i<20; i++){cout << 232792560 <<" mod " << i << " = " << 232792560%i<<'\n';}

}
