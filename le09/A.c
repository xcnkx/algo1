#include <stdio.h>
 
int p(int i){ return i / 2;}
int l(int i){ return 2 * i;}
int r(int i){ return 2 * i + 1;}
 
int main(){
  int h[512], size, n, i;
 
  scanf("%d", &size);
  for(i = 1; i <= size; ++i){
    scanf("%d", h + i);
  }
 
  for(i = 1; i <= size; ++i){
    printf("node %d: key = %d, ", i, h[i]);
    if(p(i)) printf("parent key = %d, ", h[p(i)]);
    if(l(i) <= size) printf("left key = %d, ", h[l(i)]);
    if(r(i) <= size) printf("right key = %d, ", h[r(i)]);
    puts("");
  }
  return 0;
}
