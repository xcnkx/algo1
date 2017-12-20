#include<stdio.h>


int Partition(int *A,int p,int r){
  int i,x,j,tmp;
  x = A[r];
   
  i = p-1;
  for(j = p;j <= r-1;j++){
    if(A[j] <= x){
      i = i + 1;
      tmp=A[i];
      A[i]=A[j];
      A[j]=tmp;
    }
  }
  tmp=A[i+1];
  A[i+1]=A[r];
  A[r]=tmp;
  return i+1;
}


int main(void){
  int n,i,A[100000],p;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  p=Partition(&A[0],0,n-1);
  printf("%d",A[0]);
  for(i=1;i<n;i++)
    if(i==p)
      printf(" [%d]",A[i]);
    else printf(" %d",A[i]);
  printf("\n");
  return 0;
}
