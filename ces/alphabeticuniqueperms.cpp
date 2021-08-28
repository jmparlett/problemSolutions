#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <numeric>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

ll fact(ll n){
  if(n == 1) return 1;
  else{
    return n*fact(n-1);
  }
}


void permstring(string a, int l, int r){ // non alphabetical
  if(l == r)
    cout << a << '\n';
  else{

    for(int i = l; i <= r; i++){
      bool flag=1; 
      //check if there is a copy of the current char in front of it
      for(int j=i+1; j <= r; j++) if(a[j] == a[i]){flag = 0; break;}

      //swap char a and char i
      if(flag){
        swap(a[l], a[i]);

      permstring(a, l+1, r);

      //backup!!
      swap(a[i], a[l]);
      }
    }
  }
}

int comparechars(const void *c1, const void *c2){
  return (*(char* )c1 - *(char *)c2);
}

void swapchars(char *a, char *b){ //need a function to swap chars in place
  char tmp = *a;
  *a = *b;
  *b = tmp;
}

int findceil (char s[], char first, int l, int r){//find index of character smallest character greater then first in front of first.
  int idx =l;

  for(int i=l+1; i <= r; i++)
    if(s[i] > first && s[i] < s[idx])
      idx=i;

  return idx;
}

void sortedpermstrings(char s[]){
  

  //implemented from geeksforgeeks
  //https://www.geeksforgeeks.org/lexicographic-permutations-of-string/?ref=rp
  int len = strlen(s);
  qsort(s, len, sizeof(s[0]), comparechars);

  while(1){

    cout << s << '\n'; //print last perm

    //find rightmost char in string that is less than the one to its right
    int i=0;
    for(i=len-2; i >= 0 ; i--){
      if(s[i] < s[i+1]) break;
    }

    

    if(i==-1) break; //found last perm since there is no character in front of i that is less than it

    else {

    //now find smallest char greater then first on the right of first.
    int j = findceil(s, s[i], i+1, len-1);
    swapchars(&s[i], &s[j]);
    qsort(s + i + 1, len - i -1, sizeof(char), comparechars);
    }
  } 
}

int main(){
  char s[8];
  int c, i=0;

  while((c=getchar()) != '\n'){
    s[i++]=c;
  } s[i]='\0';

  qsort(s, strlen(s), sizeof(char), comparechars);
  ll cur=1, dfact=1, perms=fact(strlen(s));
  char p = s[0];
  for(ll i=1; i < strlen(s); i++){
    if(s[i] == p){
      cur++;
      dfact*=cur;
    } else {
      p = s[i];
      cur = 1;
    }
  }

  cout << perms/dfact << '\n';
  sortedpermstrings(s);
}
