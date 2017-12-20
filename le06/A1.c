#include<stdio.h>

int A[2000001];

void CountingSort(int n){
  int k=10000,i,j,B[2000001],C[10001];
  for(i=0;i<k;i++)
    C[i]=0;
  for(j=0;j<n;j++){
    C[A[j]]++;
  }

  for(i=1;i<k;i++)
    C[i] = C[i] + C[i-1];
  
  for(j=n-1;j>=0;j--){
    B[C[A[j]]] = A[j];
    C[A[j]]--;
  }
  for(i=1;i<n;i++)
    printf("%d ",B[i]);
  printf("%d\n",B[n]);
}
 
main(){
  int i,n;
  scanf("%d",&n);
  for(i=0;i<n;i++)
    scanf("%d",&A[i]);
  CountingSort(n);
  return 0;
}
