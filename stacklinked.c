#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node* link;
}node;

node* top=NULL;

void push(int data){
  node* newnode=(node*)malloc(sizeof(node));
  if(newnode==NULL){
    printf("NO SPACE\n");
    return;
  }
  if (top==NULL){
    newnode->data=data;
    newnode->link=NULL;
    top=newnode;
    return;
  }
  else{
    newnode->data=data;
    newnode->link=top;
    top=newnode;
    return;
  }
}

void pop(){

  if(top==NULL){
    printf("EMPTY STACK!");
    return;
  }
  else{
     node* temp=top;
     int value=top->data;
     printf("THE VALUE POPED IS:%d",value);
     top=top->link;
     free(temp);
  }
}

void display(){
  if(top==NULL){
    printf("EMPTY STACK!\n");
    return;
  }
  else{
    node* temp=top;
    while(temp!=NULL){
      printf("%d\t",temp->data);
      temp=temp->link;
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
