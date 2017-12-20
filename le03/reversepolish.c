#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void push(int);
int pop(void);

char s[100];
int top =0;

int main(){
  int x;

  while(scanf("%s", s) != EOF ){
    if ( s[0] == '+' ){
      push(pop()+pop());
      
    } else if ( s[0] == '-' ){
      push(pop()-pop());
  
    } else if ( s[0] == '*' ){
      push(pop()*pop());
      
    } else {
      x = atoi(&s[0]);
      push(x);
    }
    
  }
  printf("%d\n",s[top]);
  return 0;
}

void push(int x){
  top++;
  s[top] = x;
  
}

int pop(){
  return s[top--];
}
