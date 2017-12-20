#include <stdio.h>
#include <string.h>

typedef struct{
  
  char suit;
  char value;
  int w;

}Card;

void stablejudge(Card *, int );

int main(void){

  Card C1[100], C2[100],tmp;
  int n, i, j,ch,mini;
  
  scanf("%d%c", &n, &ch);
  for ( i = 0; i < n; i++ ){
    scanf("%c%c%c", &C1[i].suit, &C1[i].value, &ch);
   
    C2[i]=C1[i];
    C2[i].w=i; 
  }
  
  //bubblesort
  
  for(i=0;i<n;i++){
    for(j=n-1;j>i;j--){
      if(strcmp(&C1[j].value,&C1[j-1].value)<0){
	tmp = C1[j];
	C1[j] = C1[j-1];
	C1[j-1] = tmp;
      }
    }
  }
  for(i=0;i<n;i++){
    printf("%c%c",C1[i].suit,C1[i].value);
    if(i!=n-1) printf(" ");    
  }
  printf("\n");
  
  stablejudge(C1,n);
  
  //selectionsort

  for(i=0;i<n;i++){
    mini = i;
    for(j=i;j<n;j++){
      if(strcmp(&C2[j].value,&C2[mini].value)<0){
	mini = j;
      }
    }
    tmp = C2[i];
    C2[i] = C2[mini];
    C2[mini] = tmp;

  }
  
  for(i=0;i<n;i++){
    printf("%c%c",C2[i].suit,C2[i].value);
    if(i!=n-1){
      printf(" ");
    }
  }
  printf("\n");

  stablejudge(C2,n);
  
  return 0;
}

void stablejudge(Card C[],int n){
  
  int i;
  
  for(i=0;i<n;i++){
    if(((C[i].w>C[i+1].w))&&(C[i].value==C[i+1].value)){
      printf("Not stable\n");
      break;
    }
    else {
      printf("Stable\n");
      break;
    }
  }
}
    

  
