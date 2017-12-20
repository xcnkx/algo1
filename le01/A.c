#include <stdio.h>
#define N 1000

void trace(int *, int);

int main(void){
  
  int n,i,j,key;
  int A[N+1];
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++) scanf("%d",&A[i]);
    
  
  trace( A, n);
  
  for(i=1;i<=n-1;i++){
    
    key = A[i];
    
    j = i -1;
    
    while( j >= 0 && A[j] > key ){
      
      A[j+1] = A[j];
      
      j--;
    }
    
    A[j+1] = key;
    
    trace(A,n);
    
  }

  return 0;
}

void trace( int A[], int n){
  
  int i;
   
  for (i=0;i<n;i++){
    if( i > 0) printf(" ");
    printf("%d",A[i]);
  }
  printf("\n");
}
