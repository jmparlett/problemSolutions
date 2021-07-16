#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <math.h>
using namespace std;
using ll = long long int;

int main(){

//Eulars method
//y_(n+1) = y_n + dy/dx *delta x
float x, y;
y=1;
x= -.5;

for(int i=0; i < 4; i++){
	x+=.25;
	y= y+(cos(y)*.5);

}

cout << y << '\n';

}
