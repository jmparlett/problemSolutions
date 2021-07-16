#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <math.h>
#include <numeric>
using namespace std;
using ll = long long int;

void genPerm(string& orig, string& perm){
	if( orig.empty()){cout << perm << '\n'; return;}

	for(int i=0; i < orig.size(); i++){
		string orig2 = orig;
		orig2.erase(i, 1);
		//cout << "orig2: " << orig2 << '\n';
		
		string perm2 = perm;

		perm2 += orig.at(i);
		//cout << "Perm2: " << perm2 << '\n';

		genPerm(orig2, perm2);
	}	
	

}


int main(){
	string s; cin >> s;
	string perm;
	genPerm(s, perm);

}


