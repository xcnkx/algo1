#include<stdio.h>
#include<string.h>
typedef struct qs{
  char c;
  int n;
  int h;
}Q;

int main(void){
  int n,i,count=0;
  Q q[100000];

  scanf("%d",&n);

  for(i=0;i<n;i++)
    q[i].h=i;
  for(i=0;i<n;i++)
    scanf(" %c %d",&q[i].c,&q[i].n);

  Quicksort(&q[0],0,n-1);

  for(i=1;i<n;i++)
    if(q[i-1].n==q[i].n && q[i-1].h>q[i].h)
      count++;

  if(count>0)
    printf("Not stable\n");

  else
    printf("Stable\n");

  for(i=0;i<n;i++)
    printf("%c %d\n",q[i].c,q[i].n);

  return 0;
}
int Partition(Q *A,int p,int r){
  int i,x,j,tmp1;
  char tmp2;
  x = A[r].n;
   
  i = p-1;
  for(j = p;j <= r-1;j++){
    if(A[j].n <= x){
      i = i + 1;
      tmp1=A[i].n;
      A[i].n=A[j].n;
      A[j].n=tmp1;
      tmp2=A[i].c;
      A[i].c=A[j].c;
      A[j].c=tmp2;
      tmp1=A[i].h;
      A[i].h=A[j].h;
      A[j].h=tmp1;
    }
  }
  tmp1=A[i+1].n;
  A[i+1].n=A[r].n;
  A[r].n=tmp1;
  tmp2=A[i+1].c;
  A[i+1].c=A[r].c;
  A[r].c=tmp2;
  tmp1=A[i+1].h;
  A[i+1].h=A[r].h;
  A[r].h=tmp1;
  return i+1;
}
void Quicksort(Q *A,int p,int r){
  int q;
  if(p < r){
    q = Partition(A, p, r);
    Quicksort(A, p, q-1);
    Quicksort(A, q+1, r);
  }
}
