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
	//Sieve of Eratosthenes Implementation
	bool isPrime[n+1];
	for(ll i=1; i<=n; i++) isPrime[i]=1;
	isPrime[1]=0;
	
	for(ll i=2; i <=n; i++){
		if(!isPrime[i]) continue;

		for(ll j=i*i; j <=n; j+=i) isPrime[j] = 0;
	}
	for(ll i=1; i<=n; i++) if(isPrime[i]) primes.push_back(i);
}

vector<pair<ll, ll> > trial_division(ll n){
	vector<pair<ll, ll> > pf;
	for(ll i=2; i*i <= n; i++) {
		ll count=0;
		while(n%i==0) count++, n/=i;
		if (count) pf.push_back({i, count});
	}
	if(n>1) pf.push_back({n,1});
	return pf;
}
int main (){
	ll n;
	cin >> n;
	auto primes = trial_division(n);
	for(auto c : primes){
		cout << c.first << ',' << c.second << "  ";
	}
	

}
