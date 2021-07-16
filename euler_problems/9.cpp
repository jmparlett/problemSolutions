#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <math.h>
using namespace std;
using ll = long long int;



int main(){

//enumerate all combinations of nums under 1000 equal to 1000 and test if they are a pythagorean
//triple
vector<pair<int ,int>> ab;
	for(int a=1; a < 1000; a++){
		for(int b=a+1; b < 1000-a; b++){
			for(int c=b+1; c < 1000-b; c++){
				if(a+b+c==1000){
					if((a*a + b*b) == c*c){
						cout << a <<" + " << b <<" + "<< c << " = " << a+b+c;
					}
				}
			}	
		}
	}
	for(auto c : ab){cout << "(a,b) = (" << c.first << "," << c.second << ")";}
}
