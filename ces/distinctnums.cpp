#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <numeric>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

		
using namespace std;
#define ll long long int
#define ull unsigned long long int
#define li long int
#define ui unsigned int

// I wrote a whole hashtable for this :(
// Could've done this more easily with a set object in C++

struct Node {
  ull data;
  struct Node* next;
};

typedef struct Node node;

typedef struct {
  node** table;
  ull size;
} table;

ull myhash(ull n, ull size){
  return n%size;
}

void append(node* n1, node *n2){
  if(n1==NULL) return;
  if(n1->data==n2->data) return; //no dups


  while(n1->next != NULL){
    if(n1->data==n2->data) return; //no dups
    n1=n1->next;
  }
  n1->next = n2;
}

bool isNotMember(table* T, ull data){
  node* cur;
  if((cur = T->table[myhash(data, T->size)]) != NULL){
    while(cur != NULL && cur->data != data)
      cur = cur->next;
  }
  return (cur==NULL);
}

void insert(table* T, ull data){
  node* cur;
  node* n = (node *)malloc(sizeof(node));
  n->data = data;
  n->next=NULL;
  if((cur = T->table[myhash(data, T->size)]) != NULL){
    append(cur, n);
    return;
  }
  T->table[myhash(data, T->size)]=n;
}

int main(){
ull n; cin >> n;

// ull *arr = (ull *)calloc(10*10*10*10*10*10*10*10*10+1, sizeof(ull));
table* T = (table *)malloc(sizeof(table));
T->table=(node**)malloc(sizeof(node*)*n);
T->size=n;

ull ucount=0;

for(ull i=0; i < n; i++){
  ull tmp; cin >> tmp;
  if(isNotMember(T,tmp)){
    ucount++;
    insert(T,tmp);
  }
}

cout << ucount << '\n';
free(T);
}
