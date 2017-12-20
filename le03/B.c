#include<stdio.h>
#include<string.h>
#define LEN 100005
 
typedef struct pp{
  char name[100];
  int t;
}P;
 
P Q[LEN+1];
int h, t, n;
 
void enqueue(P x){
  Q[t] = x;
  if (t + 1 == LEN){
    t = 0;
  }
  else{
    t = t + 1;
  } 
}
 
P dequeue(){
  P tmp = Q[h];
  if (h + 1 == LEN){
    h = 0;
  }
  else{
    h = h + 1;
  }
  return tmp;
}
 
 
int main(){
  int elaps = 0, c;
  int i, q, total = 0;
  P u;
  scanf("%d %d", &n, &q); 
  for ( i = 1; i <= n; i++){   
    scanf("%s", u.name);
    scanf("%d", &u.t);
    enqueue(u);
  }
   
  while(n>0){
    u = dequeue();
    if (u.t <= q){
      elaps += u.t;
      printf("%s %d\n", u.name, elaps);
      n--;
    }   
    else if(u.t>q){
      u.t -= q;
      elaps += q;
      enqueue(u);
    }  
  }
  return 0;
}
