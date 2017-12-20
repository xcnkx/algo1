#include <stdio.h>
#include <string.h>
#define N 200000000
#define INF 2000000001
 
int size;
int h[N];
 
void swap(int* a, int* b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}
 
void maxHeapify(i){
  int l = 2*i;
  int r = 2*i+1;
  int valM;
  if(l <= size && h[l] > h[i]) valM = l;
  else valM = i;
  if(r <= size && h[r] > h[valM]) valM = r;
  if(valM != i){
    swap(&h[i], &h[valM]);
    maxHeapify(valM);
  }
}
 
void hIncreaseKey(int i, int key){
  if(key < h[i]) return;
  h[i] = key;
  while(i>1 && h[i/2]<h[i]){
    swap(&h[i], &h[i/2]);
    i = i/2;
  }
}
 
void maxHeapInsert(int key){
  size++;
  h[size] = -INF;
  hIncreaseKey(size, key);
}
 
int heapExtractMax(){
  int valM;
  if(size < 1) return 0;
  valM = h[1];
  h[1] = h[size--];
  maxHeapify(1);
  return valM;
}
 
int main(){
  char input[20];
  size = 0;
  while(scanf("%s", input)){
    if(!strcmp(input, "end")) break;
    if(!strcmp(input, "extract")) printf("%d\n", heapExtractMax());
    else{
      char val[20];
      scanf("%s", val);
      maxHeapInsert(atoi(val));
    }
  }
  return 0;
}
