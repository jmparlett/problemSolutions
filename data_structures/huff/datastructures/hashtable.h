#include "linkedlist.h"
#include <stddef.h>
#include <stdlib.h>

typedef struct{
    linkedList **table;
    size_t size;
    size_t itemCount;
} hashTable;

hashTable* initHashTable(size_t size){
    hashTable* T = malloc(sizeof(hashTable));
    T->size=size;
    T->itemCount=0;
    T->table=malloc(sizeof(linkedList)*size);
    for(size_t i=0; i < size; i++){
       T->table[i]=malloc(sizeof(linkedList));
       T->table[i]->head=NULL;
    }
    return T;
}

int strsum(char *w, int size){
    int sum = 0;
    for(int i=0; i < size; i++) sum+=w[i];
    return sum;
}

int hash(char c, size_t size){
    //ssize=string size
    c *= 101;
    return c%size;
}

void insertHT(hashTable* T, char c){
    int pos = hash(c, T->size);

    if(isMemberLL(T->table[pos], c)==NULL){
        insertLL(T->table[pos], c);
        T->itemCount++;
    } //no duplicates
}

LLNode* isMemberHT(hashTable* T, char c){
    int pos = hash(c, T->size);
    return isMemberLL(T->table[pos], c);
    //returns pointer to char if it is in list
    //else returns null
}

void printHT(hashTable* T){
    if(T==NULL) return;
    for(size_t i=0; i < T->size; i++) printLL(T->table[i]);
}

void makeNullHT(hashTable* T){
    for(size_t i=0; i < T->size; i++){
        makeNullLL(T->table[i]);
        free(T->table[i]);
    }
    free(T->table);
    //remember for a full deallocation we need to free T outside of the function
}

hashTable* reallocHT(hashTable* oldT, size_t size){
  hashTable* newT = initHashTable(size);
  for(size_t i=0; i < oldT->size; i++){
    if(oldT->table[i]->head != NULL){
      LLNode* cur = oldT->table[i]->head;
      while(cur != NULL){
        insertHT(newT, cur->c);
        cur=cur->next;
      }
    }
  }
  //delete old table
  makeNullHT(oldT);
  free(oldT);
  //return pointer to new
  return newT;
}

// int main(){
//
  // hashTable* T = initHashTable(10);
//
  // char A[] = "hey its me mario";
  // int len = strlen(A);
  // for(int i=0; i < len; i++) insertHT(T, A[i]);
//
  // printHT(T);
//
// }
