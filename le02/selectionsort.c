#include <stdio.h>
#define N 100

int main(void){
  
  int i,j,mini,n,tmp,counter=0;
  int A[N];
  
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&A[i]);
  }
  
  for(i=0;i<n;i++){
    mini = i;
    for(j=i;j<n;j++){
      if(A[j]<A[mini]){
	mini = j;
      }
    }
    tmp = A[i];
    A[i] = A[mini];
    A[mini] = tmp;
    if(mini!=i) counter++;
  }
  
  for(i=0;i<n;i++){
    printf("%d",A[i]);
    if(i!=n-1){
      printf(" ");
    }
  }
  printf("\n");
  printf("%d\n",counter);
  
  return 0;
}
      
    
