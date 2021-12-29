//Author: Jonathan Parlett
//Program Name: sleepcowherding.c
//Created: 2021-December-29
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int
using vi = vector<int>;
#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
#define make_uniqe(x) sort(all(x)); x.resize(unique(all(x)) - x.begin());


void setio(string s){
  freopen((s+".in").c_str(), "r", stdin);
	// the following line creates/overwrites the output file
	freopen((s+".out").c_str(), "w", stdout);
	// cin now reads from the input file instead of standard input
}


int main(){
  setio("herding.in");


}


/*
 *if a cow is a front endpoint it can only move back
 *if a cow is back endpoint it can only move forward
 *
 * What is the optimal way to place a front endpoint?
 *  Place it in sorted order, in front of the first number larger then it
 *  if it is the largest dont place it
 *
 * What is the optimal way to place a back endpoint?
 *  Place it in sorted order, behind the first 
 *
 *
 */
