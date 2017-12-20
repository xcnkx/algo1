#include<stdio.h>
#include<stdlib.h>
#define NIL NULL
 
typedef struct node{
  struct node *l;
  struct node *r;
  struct node *p;
  int key;
}*Node;
 
Node root;
 
/*Node treeMinimum(Node x){
 
}
*/
Node treeSearch(Node u, int k){
  while(u!=NIL && k!=u->key){
    if(k < (u->key)){
      u = u->l;
    }
    else{
      u = u->r;
    }
  }
  return u;
}
/*
     
Node treeSuccessor(Node x){
 
 
}
 
void treeDelete(Node z){
  Node y; // node to be deleted
  Node x; // child of y
 
 
 
}
*/
void insert(int k){
  Node y = NIL;
  Node x = root;
  Node z;
  z = malloc(sizeof(struct node));
  z->key = k;
  z->l = NIL;
  z->r = NIL;
  while(x!=NIL){
    y = x;
    if(z->key<x->key){
      x = x->l;
    }
    else{
      x =x->r;
    }
  }
  z->p= y;
  if(y==NIL){
    root = z;
  }
  else if(z->key<y->key){
    y->l =z;
  }
  else{
    y->r =z;
  }
   
  }
 
void inorder(Node u){
  if(u != NIL){
    inorder(u->l);
    printf(" %d",u->key);
    inorder(u->r);
  }
}
 
void preorder(Node u){
  if(u!=NIL){
    printf(" %d",u->key);
    preorder(u->l);
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
    }/* else if ( com[0] == 'd' ){
        scanf("%d", &x);
        treeDelete(treeSearch(root, x));
        }*/
  }
   
  return 0;
}
