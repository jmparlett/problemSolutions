#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <math.h>
using namespace std;
using ll = long long int;
vector<ll> primes;
void sieve(ll n){
	bool nums[n+1];
	for(ll i=2; i <= n; i++){nums[i]=1;}
	//increment over each prime and remove all its multiples by incrementing by the value
	//of the prime each time
	for(ll i=2; i <= n; i++){
		if(nums[i]==1){
			for(ll j=i*i; j <= n; j+=i){
				nums[j]=0;
			}
		}
	} 
	for(ll i=2; i <= n; i++){if(nums[i]==1){primes.push_back(i);}}
}

int main(){

ll n, sum=0;
cin >> n;
sieve(n);

for(auto c : primes){cout << c << ' ';}


cout << '\n';

}
