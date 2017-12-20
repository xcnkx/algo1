#include <stdio.h>
 
int pNode(int i);
int lChild(int i);
int rChild(int i);
void maxHeapify(int i);
void buildMaxHeap(void);
 
int A[500001];
int n;
 
main(){
 
    int i;
 
    scanf("%d", &n);
 
    for(i=1; i<=n; i++){
        scanf("%d", &A[i]);
    }
     
    buildMaxHeap();
     
    for(i=1; i<=n; i++){
        printf(" %d", A[i]);
    }
     
    printf("\n");
     
    return 0;
     
}
 
int pNode(int i){
    return (int)i/2;
}
 
int lChild(int i){
    return 2*i;
}
 
int rChild(int i){
    return 2*i+1;
}
 
void maxHeapify(int i){
    int l = lChild(i);
    int r = rChild(i);
    int max, tmp;
     
    if(l <= n && A[l] > A[i]){
        max = l;   
    }else{
        max = i;
    }
    if(r <= n && A[r] > A[max]){
        max = r;   
    }
    if(max != i){
        tmp = A[i];
        A[i] = A[max];
        A[max] = tmp;
        maxHeapify(max);
    }
}
 
void buildMaxHeap(void){
    int i;
    for(i=(int)n/2; i>0; i--)
        maxHeapify(i);
}
