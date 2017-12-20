#include <stdio.h>
#define MAX 100001

typedef struct tree{
  int parent,left,right;
}Node;

Node T[MAX];

int depth(int);
void print_degree(int);

int main(void){
  
  int n,i,j,k,id,child,sibling,tmp2;

  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    T[i].parent=T[i].left=T[i].right=-1;
  }
  for(i=0;i<n;i++){
    scanf("%d %d",&id,&k);
    for(j=0;j<k;j++){
      scanf("%d",&child);
      T[child].parent=id;
      if(j==0){
	T[id].left=child;
      }
      else {
	T[sibling].right=child;
      }
      sibling = child;
    }
  }

  for(i = 0; i < n; i++){
    printf("node %d: parent = %d, depth = %d, ",i,T[i].parent,depth(i));
    if(T[i].parent == -1)
      printf("root, [");
    else if(T[i].left == -1)
      printf("leaf, [");
    else
      printf("internal node, [");
    print_degree(T[i].left);
    printf("]\n");
  }
  
  return 0;
}

int depth(int node){
    if(T[node].parent == -1){
      return 0;
    }
    else {
      return depth(T[node].parent) + 1;
    }
  }
  
void print_degree(int i){
  
  if(i != -1){
    if(T[i].right == -1)
      printf("%d",i);
    else printf("%d, ",i);
  print_degree(T[i].right);
  }
}
