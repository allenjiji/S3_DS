#include<stdio.h>
#include<stdlib.h>
int max=100;
int arr[100];
int top=-1;

void push(int data){
  if(top>max){
    printf("Impossible to push!!");
    return ;
  }
  top++;
  arr[top]=data;
  return;
}

void pop(){
  if (top<0){
    printf("Empty stack!!");
  }
  else{
  int a=arr[top];
  top--;
  printf("The element poped is:%d",a);
  }
}

void display(){
  if (top<0)
    printf("Empty stack!!");
  else{
  printf("The current stack is:\n");
  for(int i=0;i<top+1;i++){
    printf("%d\t",arr[i]);
    }
  }
}


void main(){
  int data,op;
  while(1){
    printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.Exit\nSelect the operation:");
    scanf("%d",&op);
    if(op==1){
      printf("Enter the element to be pushed:");
      scanf("%d",&data);
      push(data);
    }
    else if(op==2){
      pop();
    }
    else if(op==3){

      display();
    }
    else if(op==4){
      exit(0);
    }
    else printf("INVALID OPERATION!!");

  }
}
