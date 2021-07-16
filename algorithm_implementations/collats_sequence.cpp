#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <numeric>
#include <math.h>

using namespace std;
using ll = long long int;

ll collats(ll n, ll arr[], ll count=0){

	//test for memoization and fall through if false
//	if(n < 1000000){
//		printf("this is n %n\n", n);
//		if(arr[n] != 0){
//			return count + arr[n];
//		}	
//	}
	if(n==1){
		count++;
		return count;
	}
	else if(n%2==0){
		count++;
		return collats(n/2, arr, count);
	}
	else{
		count++;
		return collats(3*n + 1, arr, count);
	}
}


int main(){
	ll arr[1000000]; for(auto &c : arr){c=0;}

//	printf("test %d \n", collats(13, arr));

	for(int j=1; j < 1000000; j++){
		arr[j]=collats(j, arr);	
	}

	//for(auto c : arr){if(c!=0)cout << c << '\n';}
	
	int max=0, pos=0;

	for(int i=0; i < 1000000; i++){
		if(arr[i] > max){
			max = arr[i];
			pos=i;
		}
	}
	
	printf("collats 13: %d", arr[13]);
	printf("max: %d\n", pos);

	
}


