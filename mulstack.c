#include<stdio.h>
#include<stdlib.h>
int arr[10];
int n=10;
int top1=-1;
int top2=10;

void push(int data,int stno){
  if(top1==top2){
    printf("ARRAY FULL");
    return;
  }
  if(stno==1){
    top1++;
    arr[top1]=data;
  }
  else if(stno==2){
    top2--;
    arr[top2]=data;
  }
}

void pop(int stno){


  if (stno==1){
    if (top1==-1){
      printf("Stack 1 is Empty\n");
      return;
    }
    else{
    printf("The element poped is:%d",arr[top1]);
    top1--;
    return;
  }
  }
  if(stno==2){
    if (top2==n){
      printf("Stack 2 is Empty\n");
      return;
    }
    else{
    printf("The element poped is:%d",arr[top2]);
    top2++;
    return;
  }
  }

}

void display(int stno){

  if (stno==1){
    if (top1==-1){
      printf("Stack 1 is Empty\n");
      return;
    }
    else{
      for(int i=0;i<=top1;i++) printf("%d\t",arr[i]);
    }
  }
  if(stno==2){
    if(top2==n){
      printf("Stack 2 is empty\n");
      return;
    }
    else{
      for(int i=n-1;i>=top2;i--){
        printf("%d\t",arr[i]);
      }
    }
    return;
  }
}


void main(){

  int data,op,stno;
  while(1){
    printf("\n1.PUSH\n2.POP\n3.DISPLAY\n4.Exit\nSelect the operation:");
    scanf("%d",&op);
    if(op==1){

      printf("Enter the element to be pushed:");
      scanf("%d",&data);
      printf("Enter the stack no.(1 or 2):");
      scanf("%d",&stno);
      push(data,stno);
    }
    else if(op==2){
      printf("Enter the stack no.(1 or 2):");
      scanf("%d",&stno);
      pop(stno);
    }
    else if(op==3){
      printf("Enter the stack no.(1 or 2):");
      scanf("%d",&stno);

      display(stno);
    }
    else if(op==4){
      exit(0);
    }
    else printf("INVALID OPERATION!!");

  }
}
