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

int hash(char* w, size_t size){
    //ssize=string size
    int sum = strsum(w, strlen(w));
    sum *= 101;
    return sum%size;
}

void insertHT(hashTable* T, char word[]){
    char* newWord = malloc(strlen(word)+1);
    strcpy(newWord,word);
    int pos = hash(newWord, T->size);

    if(isMemberLL(T->table[pos], newWord)==NULL){
        insertLL(T->table[pos], newWord);
        T->itemCount++;
    } //no duplicates
}

node* isMemberHT(hashTable* T, char* word){
    int pos = hash(word, T->size);
    return isMemberLL(T->table[pos], word);
    //returns pointer to word if it is in list
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
      node* cur = oldT->table[i]->head;
      while(cur != NULL){
        insertHT(newT, cur->word);
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
