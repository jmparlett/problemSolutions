#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node node;
struct node {
    char *word;
    node *next;
};

node *initNode(char *data){
    node *n = malloc(sizeof(node));
    n->word=data;
    n->next=NULL;
    return n;
}

typedef struct {
    node* head;
    int size;
} linkedList;

linkedList* initLL(){
    linkedList* L = malloc(sizeof(linkedList));
    L->head=NULL;
    L->size=0;
    return L;
}

void insertLL(linkedList* L,char* data){
    node *n = initNode(data);
    if(L->head==NULL){
        L->head=n;
    } else {
        n->next = L->head;
        L->head = n;
    } 
    L->size++;
}

void freeLLNode(node* n){
    free(n->word);
    free(n);
}

void makeNullLL(linkedList* L){
    node *cur = L->head;
    while(cur != NULL){
        node* tmp=cur;
        cur=cur->next;
        freeLLNode(tmp);
    }
    L->head=NULL;
    //head must be set to null since linked list still exists
}

void printLL(linkedList* L){
    if(L->head==NULL) return;
    node *cur = L->head;
    while(cur != NULL) {
        printf("%s\n", cur->word); 
        cur=cur->next;
    }
}

node* isMemberLL(linkedList* L, char* word){
    node* cur = L->head;
    while(cur != NULL){
        if(!strcmp(word, cur->word)) break;
        cur = cur->next;
    }
    return cur;
    //return NULL if target not found else pointer to target
}

