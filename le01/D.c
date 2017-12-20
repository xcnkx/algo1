#include <stdio.h>
#define N 200000
int main(void){

  int i,j,n,f[N];
  long minv,maxv=-1000000000;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf("%d",&f[i]);
  }
  
  minv = f[0];

  for(j=1;j<n;j++){
    
    if(maxv<f[j]-minv) maxv = f[j]-minv;
    
    if(minv>f[j]) minv = f[j];

  }
 
  printf("%d\n",maxv);

  return 0;
}
  
    
