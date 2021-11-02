#include <stdio.h>
#include <stdlib.h>


int compareBST(int nodeset1[], int nodeset2[], int size);

typedef struct node node;
typedef struct node{
 node* left;
 node *right;
 int data;
} node;

typedef struct {
  node* root;
} bst;

node* initNode(int data){
  node* n = malloc(sizeof(node));
  n->left = n->right = NULL;
  n->data = data;
  return n;
}

bst* initBST(){
  bst* tree = malloc(sizeof(bst));
  tree->root=NULL;
  return tree;
}

void insertHelper(node* node, int data){
  //data goes left
  if(node->data > data ){
    if(node->left == NULL)
      node->left = initNode(data);
    else
      insertHelper(node->left, data);
    return;
  }
  //else data goes right
 if(node->right== NULL)
    node->right= initNode(data);
 else
    insertHelper(node->right, data);

}

void insertBST(bst* tree, int data){
  if(tree->root == NULL)
    tree->root = initNode(data);
  else
    insertHelper(tree->root, data);
}



void printBSTPreorder(node* node){
  if(node == NULL) return; //nothing here
  
  printf("%d ", node->data);

  printBSTPreorder(node->left);

  printBSTPreorder(node->right);
}

void printBSTInorder(node* node){
  if(node == NULL) return; //nothing here
  

  printBSTInorder(node->left);

  printf("%d ", node->data);

  printBSTInorder(node->right);

}

void printBSTPostorder(node* node){
  if(node == NULL) return; //nothing here
  

  printBSTPostorder(node->left);

  printBSTPostorder(node->right);

  printf("%d ", node->data);
}
void printBST(bst* tree, void (*order)(node*)){
  order(tree->root);
  printf("\n");
}

node* findmin(node* node){
  if(node->left == NULL)
    return node;
  else
    return findmin(node->left);
}

node* searchHelper(node* node, int data){
  if(node == NULL) return NULL;

  if(node->data == data) return node;

  if(data > node->data)
    return searchHelper(node->right, data);

  else
    return searchHelper(node->left, data);
}

node* searchTree(bst* tree, int data){
  if(tree->root==NULL) return NULL;

  return searchHelper(tree->root, data);
}

//4 cases
//1: No children. Just delete the node
//2: One left child. Just move up left child.
//3: One right child. Just move up right child.
//4: Two right children. Find min of right subtree and swap and delete.

node* deleteHelper(node* node, int data){
  if(node == NULL) return node;

  if(node->data > data)
    node->left = deleteHelper(node->left, data);
  else if(node->data < data)
    node->right = deleteHelper(node->right, data);
  else{ //we have our target
    if(node->left==NULL && node->right==NULL){//no kids
      free(node);
      return NULL;
    } else if(node->left == NULL){//right kid
      struct node* tmp = node->right;
      free(node);
      return tmp; 
    } else if(node->right == NULL){//left kid
      struct node* tmp = node->left;
      free(node);
      return tmp;
    } else {//two children
      //find min of right subtree
      struct node* min = findmin(node->right);
      node->data = min->data;

      node->right = deleteHelper(node->right, min->data);
    }
  }
  return node;
}

void delete(bst* tree, int data){
  //find node
  deleteHelper(tree->root, data);
}

int main(){
  // int arr1[] = {4,5,6,7,1,2,3};
  // int arr2[] = {4,1,2,3,5,6,7};
  // int arr3[] = {4,1,3,2,5,6,7};
  // int arr1[] = {4,5,3,6,2,1,7};
  // int arr2[] = {4,2,1,7,5,3,6};
  // int arr3[] = {4,2,7,1,5,6,3};
  int arr1[] = {4,2,3,1,6,5,7};
  int arr2[] = {4,6,5,7,2,3,1};
  int arr3[] = {4,6,7,5,2,1,3};
  int arr4[] = {4,6,2,1,3,5,7};
  int arr5[] = {4, 1, 8, 10, 9, 10, 8, 10, 6, 5};
  bst* tree = initBST();

  for(int i=0; i < 7; i++) insertBST(tree, arr1[i]);
  printBST(tree, printBSTInorder);

  free(tree);
  tree = initBST();
  for(int i=0; i < 7; i++) insertBST(tree, arr2[i]);
  printBST(tree, printBSTInorder);

  free(tree);
  tree = initBST();
  for(int i=0; i < 7; i++) insertBST(tree, arr3[i]);
  printBST(tree, printBSTInorder);

  free(tree);
  tree = initBST();
  for(int i=0; i < 10; i++) insertBST(tree, arr5[i]);
  printBST(tree, printBSTInorder);

  //bst set compare tests
  // printf("compare bst sets: %d\n", compareBST(arr1,arr2,7));
  // printf("compare bst sets: %d\n", compareBST(arr1,arr3,7));
  // printf("compare bst sets: %d\n", compareBST(arr1,arr4,7));
  // printf("compare bst sets: %d\n", compareBST(arr2,arr3,7));
  // printf("compare bst sets: %d\n", compareBST(arr2,arr4,7));
  // printf("compare bst sets: %d\n", compareBST(arr3,arr4,7));
  // printf("compare bst sets: %d\n", compareBST(arr1,arr5,7));

  // printf("min of root right sub: %d\n", findmin(tree->root->right)->data);
  // delete(tree, 4);
  // printBST(tree,printBSTInorder);

  // delete(tree, 5);
  // printBST(tree,printBSTInorder);

  // delete(tree, 1);//leaf
  // printBST(tree,printBSTInorder);


  // delete(tree, 2);//leaf
  // printBST(tree,printBSTInorder);
}


int compareBST(int seq1[], int seq2[], int size){

  if(size==0) return 1;
  if(seq1[0]!=seq2[0]) return 0;

  int lt1[size-1]; //all elements less than
  int lt2[size-1]; //all elements less than
  int gt1[size-1]; //all elements greater than
  int gt2[size-1]; //all elements greater than

  int slt1, slt2, sgt1, sgt2; slt1=slt2=sgt1=sgt2=0;

  //left tree
  for(int i=1; i<size; i++) if(seq1[i] <= seq1[0]) lt1[slt1++]=seq1[i];
  for(int i=1; i<size; i++) if(seq2[i] <= seq1[0]) lt2[slt2++]=seq2[i];

  //right tree
  for(int i=1; i<size; i++) if(seq1[i] > seq1[0]) gt1[sgt1++]=seq1[i];
  for(int i=1; i<size; i++) if(seq2[i] > seq1[0]) gt2[sgt2++]=seq2[i];
  
  if(slt1==slt2 && sgt1==sgt2){//recurse
   return (compareBST(lt1, lt2, slt1) && compareBST(gt1,gt2,sgt1)); 
  }
  return 0;
}

/* 
1. if the given lists are empty return true
2. check the first elements of a the given lists are they equal? If not return false.
3. take the sets of all elements less than the first and the sets of all elements greater than the first.
4. recurse twice to. First two check the two lists of left descendents and then to checks the two lists of right descendents.
*/
