#include <stdio.h>
#define N 100

int main(void){
  
  int i,j,n=101,tmp,cntr=0;
  int A[N];
  
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(A[j]<A[j-1]){
	tmp = A[j];
	A[j] = A[j-1];
	A[j-1] = tmp;
	cntr++;
      }
    }
  }
  printf("%d\n",A[i/2]);
  return 0;
  
}
  