#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <regex>
#include <math.h>
using namespace std;
using ll = long long int;


int main(){
	vector<vector<int>> grid;
	for(int i=0; i < 20; i++){
		vector<int> gridLine;
		for(int i=0; i < 20; i++){
			int n=0;
			cin >> n;
			gridLine.push_back(n);	
		}
		grid.push_back(gridLine);
	}
	for(auto v : grid){
		for(int n : v){
			cout << n << ' ';
		}
		cout << '\n';
	}

	//box check grid[i][j]
	//checks if not corner case

	//only do horizontal if j+3 < [i].size()
	//horizontal check [i][j]*[i][j+1]*[i][j+2]*[i][j+3]

	//only do vertical if i+3 < grid.size()
	//vertical check [i][j]*[i+1][j]*[i+2][j]*[i+3][j]
	
	//only do left diag if j-3 >= 0 and i+3 < grid.size()
	//left diag check [i][j]*[i+1][j-1]*[i+2][j-2]*[i+3][j-3]
	
	//only do right diag check if j+3 < [i].size() and i+3 < grid.size()
	//right diag check [i][j]*[i+1][j+1]*[i+2][j+2]*[i+3][j+3]

	//implement
	ll largestProduct=1;
	for(int i=0; i < grid.size(); i++){
		for(int j=0; j < grid[i].size(); j++){
			//horizontal check
			if(j+3 < grid[i].size()){
				int check= grid[i][j]* grid[i][j+1]* grid[i][j+2]* grid[i][j+3];				 if (check > largestProduct){largestProduct=check;}
			}
			//vertical check
			if (i+3 < grid.size()){
				int check= grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j];
				if (check > largestProduct){largestProduct=check;}
			}
			//left diag check
			if(j-3 > 0 and i+3 < grid.size()){
				int check = grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3];
				if (check > largestProduct){largestProduct=check;}
	
			}
			//left diag check
			if(j+3 < grid[i].size() and i+3 < grid.size()){
				int check = grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3];
				if (check > largestProduct){largestProduct=check;}
	
			}
			

		}
	}
	cout << largestProduct << '\n';
	


	


}
