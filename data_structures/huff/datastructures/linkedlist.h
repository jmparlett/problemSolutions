#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct LLnode {
    char c;
    float freq;
    struct LLnode *next;
};

typedef struct LLnode LLNode;

LLNode *initLLNode(char data){
    LLNode *n = malloc(sizeof(LLNode));
    n->c=data;
    n->freq=1; //count is at least 1 when it is inserted to the table
    n->next=NULL;
    return n;
}

typedef struct {
    LLNode* head;
    int size;
} linkedList;

linkedList* initLL(){
    linkedList* L = malloc(sizeof(linkedList));
    L->head=NULL;
    L->size=0;
    return L;
}

void insertLL(linkedList* L,char c){
    LLNode *n = initLLNode(c);
    if(L->head==NULL){
        L->head=n;
    } else {
        n->next = L->head;
        L->head = n;
    } 
    L->size++;
}

// void freeLLNode(node* n){
    // free(n);
// }

void makeNullLL(linkedList* L){
    LLNode *cur = L->head;
    while(cur != NULL){
        LLNode* tmp=cur;
        cur=cur->next;
        free(tmp);
    }
    L->head=NULL;
    //head must be set to null since linked list still exists
}

void printLL(linkedList* L){
    if(L->head==NULL) return;
    LLNode *cur = L->head;
    while(cur != NULL) {
        printf("%c %.2f\n", cur->c, cur->freq); 
        cur=cur->next;
    }
}

LLNode* isMemberLL(linkedList* L, char c){
    LLNode* cur = L->head;
    while(cur != NULL){
        if(c==cur->c) break;
        cur = cur->next;
    }
    return cur;
    //return NULL if target not found else pointer to target
}

// int main(){
//
  // linkedList* L = initLL();
//
  // char A[] = "hey its me mario";
  // int len = strlen(A);
  // for(int i=0; i < len; i++) insertLL(L, A[i]);
//
  // printLL(L);
//
// }
