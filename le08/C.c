#include<stdio.h>
#include<stdlib.h>
 
struct node{
  struct node *r;
  struct node *l;
  struct node *p;
  int key;
};
typedef struct node * Node;
#define NIL NULL
 
Node root;
 
Node treeMinimum(Node x){
 
  while (x->l != NIL) {
    x = x->l;
  }
   
  return x;
   
}
 
Node treeSearch(Node x, int k){
   
  if (x == NIL || k == x->key) {
    return x;
  }
   
  if (k < x->key) {
    return treeSearch(x->l, k);
  } else {
    return treeSearch(x->r, k);
  }
   
   
}
 
Node treeSuccessor(Node x){
  Node y;
   
  if (x->r != NIL) {
    return treeMinimum(x->r);
  }
   
  y = x->p;
   
  while (y != NIL && x == y->r) {
    x = y;
    y = y->p;
  }
   
  return y;
   
}
 
void treeDelete(Node z){
  Node y; // node to be deleted
  Node x; // child of y
 
  if (z->l == NIL || z->r == NIL) {
    y = z;
  } else { 
    y = treeSuccessor(z);
  }
   
  if (y->l != NIL) {
    x = y->l;
  } else {
    x = y->r;
  }
   
  if (x != NIL) {
    x->p = y->p;
  }
   
  if (y->p == NIL) {
    root = x;
  } else if (y == y->p->l) {
    y->p->l = x;
  } else {
    y->p->r = x;
  }
   
  if(y != z){
    z->key = y->key;
  }
 
}
 
void insert(int k){
  Node y = NIL;
  Node x = root;
  Node z;
 
  z = malloc(sizeof(struct node));
  z->key = k;
  z->l = NIL;
  z->r = NIL;
  z->p = NIL;
 
  while(x != NIL){
    y = x;
 
    if(z->key < x->key){
      x = x->l;
    } else {
      x = x->r;
    }
  }
 
  z->p = y;
   
  if(y == NIL){
    root = z;
  } else if(z->key < y->key){
    y->l = z;
  } else {
    y->r = z;
  }
   
 
}
 
 
void inorder(Node u){
   
  if(u->l != NIL){
    inorder(u->l);
  }
   
  printf(" %d",u->key);
   
  if(u->r != NIL){
    inorder(u->r);
  }
   
}
 
void preorder(Node u){
 
  printf(" %d",u->key);
     
  if(u->l != NIL){
    preorder(u->l);
  }
   
  if(u->r != NIL){
    preorder(u->r);
  }
   
}
 
  
int main(){
  int n, i, x;
  char com[20];
  scanf("%d", &n);
 
  for ( i = 0; i < n; i++ ){
    scanf("%s", com);
 
    if ( com[0] == 'f' ){
      scanf("%d", &x);
      Node t = treeSearch(root, x);
      if ( t != NIL ) printf("yes\n");
      else printf("no\n");
    } else if ( com[0] == 'i' ){
      scanf("%d", &x);
      insert(x);
    } else if ( com[0] == 'p' ){
      inorder(root);
      printf("\n");
      preorder(root);
      printf("\n");
    } else if ( com[0] == 'd' ){
      scanf("%d", &x);
      treeDelete(treeSearch(root, x));
    }
  }
   
  return 0;
}
