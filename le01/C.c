#include <stdio.h>
#include <math.h>

int main(void){
  
  int i,j,k,l,n,p,cntr = 0;
  
  scanf("%d",&n);
  
  for(i=0;i<n;i++){
    
    scanf("%d",&p);
    if(p==2) cntr++;
    else{
      k=0;
      for(j=2;j<=p/j;j++)
	{
	  if(p%j==0)
	    {
	      k++;
	    
	    }
	}
      if(k==0) cntr++;
    }
  }
  printf("%d\n",cntr);
  
  return 0;
}
      
