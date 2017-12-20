#include<stdio.h>
 
main(void){
   
  int s[10000],n,t[500],q,i,count=0,j,temp;
  int l,m,r,value;
 
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d",&s[i]);
     
  }
 
  scanf("%d",&q);
  for(i=0;i<q;i++){
    scanf("%d",&t[i]);
  }
   
  for(i=0;i<n-1;i++){
    for(j=n-1;j>i;j--){
      if(s[j]<s[j-1]){
    temp=s[j];
    s[j]=s[j-1];
    s[j-1]=temp;
      }
    }
  }
     
   
  for(i=0;i<q;i++){
    r=n;
    l=0;
    value=t[i];
    
    while(l<=r){
      m=(l+r)/2;
 
      if(s[m]==value){
    count=count+1;
    break;
      }
 
      else if(s[m]<value)l=m+1;
 
      else r=m -1;
 
    }
  }
   
  printf("%d\n",count);
  return 0;
}
