#include <iostream>
#include <algorithm>
#include <map>
#include <string.h>
		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

void p1(FILE* f){
  
  map<string,int> dirs = {{"forward",0},
                          {"down",0},
                          {"up",0}};

  char dir[20];
  int val=0;
  while(fscanf(f,"%s %d\n",dir, &val) > 0){
    dirs[dir]+=val;
  }
  cout << "[ ";
  for(auto &item : dirs)
    cout << item.first << " : " << item.second;
  cout << " ]\n";

  cout << dirs["forward"]*(dirs["down"]-dirs["up"]) << '\n';
}

void p2(FILE* f){
  
  map<string,int> dirs = {{"forward",0},
                          {"down",0},
                          {"up",0}};

  char dir[20];
  int val=0;
  int depth = 0;
  while(fscanf(f,"%s %d\n",dir, &val) > 0){
    if(!strcmp(dir,"forward")){
      depth += val*(dirs["down"]-dirs["up"]);
    }
    dirs[dir]+=val;
  }
  for(auto &item : dirs)
    cout << item.first << " : " << item.second << '\n';
  cout << "depth: " << depth << '\n';
  cout << dirs["forward"]*(depth) << '\n';
  
}
int main(){
  
  FILE* f = fopen("input","r");

  // p1(f);
  p2(f);
}
