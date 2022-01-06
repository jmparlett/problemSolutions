#include <stdio.h>
#include <stdlib.h>

typedef struct {
  unsigned long long bitPattern;
  char pattern[260];
  int length;
  char c;
} code;

typedef struct {
  code **codes;
  int capacity;
  int size;
} openHashTable;

openHashTable* OpenHashTable(int capacity){
  openHashTable* T = malloc(sizeof(openHashTable));
  T->codes = malloc(sizeof(code*)*capacity);
  T->capacity = capacity;
  T->size = 0;
  for(int i=0; i < capacity; i++) T->codes[i]=NULL;
  return T;
}

int openHash(int capacity, char c){
  return c%capacity; //this is kinda dumb cause its the char will never
  //be greater than the size, but it feels better to have a hash function
  //so we'll do it for the moral
}

void insertToOpenHashTable(openHashTable* T, code* code){
  T->codes[openHash(T->capacity, code->c)]=code;
  T->size++;
}

code* isMemberCHT(openHashTable* T, char c){
   return T->codes[openHash(T->capacity, c)];
}

void printOpenHashTable(openHashTable* T){
  for(int i=0; i < T->capacity; i++)
    if(T->codes[i] != NULL)
      printf("[%c, %lld, %d]\n", T->codes[i]->c, T->codes[i]->bitPattern, T->codes[i]->length);
}
