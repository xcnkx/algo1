#include  <stdio.h>
 
int main(void)
{      
  int n,i,j,temp1,x1[100],x2[100],x3[100],mini,count=0,temp3;

  char c1[100],c2[100],temp2;

  scanf("%d",&n);

  for(i=0;i<n;i++){
    scanf(" %c%d",&c1[i],&x1[i]);
  }

  for(i=0;i<n;i++){
    c2[i]=c1[i];
    x2[i]=x1[i];
    x3[i]=i;
  }
   
   
  for (i=0;i<n;i++){
    for (j=n-1;j>=i+1;j--){
      if (x1[j-1]>x1[j]){
	temp1=c1[j];     
	c1[j]=c1[j-1];
	c1[j-1]=temp1;
	temp1=x1[j];     
	x1[j]=x1[j-1];
	x1[j-1]=temp1;
      }
    }  
  }

  for(i=0;i<n;i++){
    if(i==n-1)
      printf("%c%d\n",c1[i],x1[i]);
    else
      printf("%c%d ",c1[i],x1[i]);
  }

  printf("Stable\n");
  for (i=0;i<n;i++){
    mini=i;
    for (j=i;j<n;j++){
      if (x2[j]<x2[mini]){
	mini=j;
      }
    }

    temp2 = c2[i];       
    c2[i] = c2[mini];
    c2[mini]= temp2;
    temp1 = x2[i];       
    x2[i] = x2[mini];
    x2[mini]= temp1;
    temp3=x3[i];
    x3[i]=x3[mini];
    x3[mini]=temp3;
  }

  for(i=0;i<n;i++){
    if(i>0 && x2[i-1]==x2[i] && x3[i-1]>x3[i])
      count++;
    if(i==n-1)
      printf("%c%d\n",c2[i],x2[i]);
    else
      printf("%c%d ",c2[i],x2[i]);
  }

  if(count>0)
    printf("Not stable\n");
  else
    printf("Stable\n");
  return 0;
}
