#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <numeric>
#include <math.h>

using namespace std;
using ll = long long int;

int nlsum(int n){
	if(n < 20){
		switch(n){
			case 0: //zero means we dont translate that value
				return 0;
			case 1:
				return 3;
			case 2:
				return 3;
			case 3:
				return 5;
			case 4:
				return 4;
			case 5:
				return 4;
			case 6:
				return 3;
			case 7:
				return 5;
			case 8:
				return 5;
			case 9:
				return 4;
			case 10:
				return 3;
			case 11:
				return 6;
			case 12:
				return 6;
			case 13:
				return 8;
			case 14:
				return nlsum(n%10) + 4;
			case 15:
				return 7;
			case 16:
				return nlsum(n%10) + 4;
			case 17:
				return nlsum(n%10) + 4;
			case 18:
				return nlsum(n%10) + 3;
			case 19:
				return nlsum(n%10) + 4;



				
		}
	} else if(n < 100){ // if n is a two digit num
		int x=n/10, y = n%10;
		switch(x){
			case 2:
				return 6 + nlsum(y); //twenty
			case 3:
				return 6 + nlsum(y); //thirty
			case 4:
				return 5 + nlsum(y); //forty
			case 5:
				return 5 + nlsum(y); //fifty
			case 6:
				return 5 + nlsum(y); //sixty
			case 7:
				return 7 + nlsum(y); //seventy
			case 8:
				return 6 + nlsum(y); //eighty
			case 9:
				return 6 + nlsum(y); //ninety
				
		}
	} else if(n < 1000){
		if(n%100 > 0){
			return (nlsum(n/100) + 10 + nlsum(n%100)); // x hundred and y
		} else {
			return (nlsum(n/100) + 7); //x hundred
		}
		
	} else {
		return 11;	
	       }
	return 0;
}

int main(){
	// n < 100; x-ty y
	// 100 < n < 1000; z hundred and x-ty y
	int charcount=0;
	for(int i=1; i <= 1000; i++){
		charcount += nlsum(i);
		printf("%d chars in %d\n", nlsum(i), i);
	}

	printf("%d characters in number letter sum [1-1000]\n", charcount);
	return 0;
}
