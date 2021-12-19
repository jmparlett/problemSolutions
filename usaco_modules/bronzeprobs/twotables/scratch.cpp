#include <bits/stdc++.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

typedef struct {
  int x1;
  int y1;
  int x2;
  int y2;
} rect;

// int corners(int x,int y, int bl_x,int bl_y,int tr_x, int tr_y){
  // return (x <= tr_x && x >= bl_x && y <= tr_y && y >= bl_y);
// }
//
// int iarea(rect r1, rect r2){
  // int iw = max(min(r1.x2,r2.x2) - max(r1.x1,r2.x1),0);
  // int ih = max(min(r1.y2,r2.y2) - max(r1.y1,r2.y1),0);
  // return iw*ih;
// }
//
// int iarea3(rect r1, rect r2, rect r3){//intersection of 3 rects
  // int iw = max(min(min(r1.x2,r2.x2), r3.x2) - max(max(r1.x1,r2.x1),r3.x1),0);
  // int ih = max(min(min(r1.y2,r2.y2),r3.y2) - max(max(r1.y1,r2.y1),r3.y1),0);
  // return iw*ih;
// }
//
// int area(rect r){
  // return (r.x2-r.x1)*(r.y2-r.y1);
// }

int main(){
  // freopen("billboard.in", "r", stdin);
	// the following line creates/overwrites the output file
	// freopen("billboard.out", "w", stdout);
	// cin now reads from the input file instead of standard input
  
  int t; cin >> t;
  while(t--){
    int wr,hr; cin >> wr >> hr;

    rect table; cin >> table.x1 >> table.y1 >> table.x2 >> table.y2;
  
    int wt,ht; cin >> wt >> ht;

    //if sum of heights and lengths is greater than height and length of the room then there is no way
    //to place the tables
    //
    //if one of the heights or lengths is greater than the height or length length of the room then there can
    //be no way to place the tables
    int oth = (table.y2-table.y1), otw = (table.x2-table.x1); 
    // bool failcondition = ( (wt+otw > wr && ht+oth > hr) || (wt > wr) || (ht > hr) || (oth > hr) || (otw > wr) );

    // if(failcondition){
      // cout << -1 << '\n';
      // continue;
    // }
    //else there must be some way to place tables to minimize distance
    
    //there should never be a reason to move diagonally
    
    //if moving in y its either above or below
    //if below min distance is height of new table - bottom left corner y
    //if add that distance to the top right and it does not exceed the height of the square then it is valid
    //if above then min distance is top right y - (height of room - minus height of new table)

    int yd,xd;
    if(oth+ht <= hr){//we can move in y
      //place at bottom left
      yd = max(0,(ht-table.y1)); //if neg than they already dont overlap
      //place at top right
      yd = min(yd,max(0,table.y2 - (hr-ht)));
    } else yd = -1;

    if(otw+wt <= wr){//we can move in x
      //bottom left
      xd = max(0,wt-table.x1);
      //top right
      xd = min(xd,max(0,table.x2 - (wr-wt)));
    } else xd = -1;

    cout << fixed << setprecision(9);
    if(xd==-1 && yd==-1)
      cout << -1 << '\n';
    else if(xd==-1)
      cout << double(yd) << '\n';
    else if(yd == -1)
      cout << double(xd) << '\n';
    else
      cout << double(min(xd,yd))<< '\n';
  }
}
