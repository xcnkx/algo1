#include <stdio.h>

int GCD(int,int);

int main(void){
  
  int a,b;
  
  scanf("%d%d",&a,&b);
  
  printf("%d\n",GCD(a,b));
  
  return 0;
}

int GCD(int a, int b){
  
  int r;
  
  while(b!=0){
    
    r=b;
    b=a%b;
    a=r;

  }
  return a;
}
