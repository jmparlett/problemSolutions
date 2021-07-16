#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <math.h>
using namespace std;
using ll = long long int;

ll fib(ll n, vector<ll> meme={}) 
{

	//meme case
	if (meme.size() >= n){
		return meme[n-1];
	}
	//base case 1
	else if(n==0)
	{
		return 0;
	}
	//base case 2
	else if(n==1 or n==2)
	{
		return 1;
	}
	else
	{
		return fib(n-1) + fib(n-2);
	}

}

int main (){

	ll j=0;
	ll n=0;
	ll sum=0;
	while( j < 4*pow(10, 6))
	{
		if( j%2 == 0)
		{
			sum += j;	
			cout << j << '\n';
		}		
		n++;
		j= fib (n);
		
	}
	cout << sum << '\n';	
}
