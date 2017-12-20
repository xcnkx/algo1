#include <stdio.h>
#include <stdlib.h>
 
int o[101];
char cm[100];
int top = 0;
 
void push(int x) {
  top++;
  o[top] = x; 
  
}
 
 
int pop() {
  top--;
  return o[top+1];
   
}
 
   
   
 
   
int main() {
  int a,b = 0;
  int result;
  int c;
  int d,e;
   
  while(scanf("%s",cm) != EOF) {
     
    if(cm[0] == '+'){
      push(pop() + pop());
    }
    else if(cm[0] == '-'){
      d = pop();
      e = pop();
      push(e - d);
    } else if(cm[0] == '*') {
      push(pop() * pop());
    }   else {
      push(atoi(cm));
    }
     
  }
 
  printf("%d\n",pop());
 
  return 0;
}
   
