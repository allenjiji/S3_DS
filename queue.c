#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node* link;
}node;

node* front=NULL;
node* rear=NULL;
node* temp;

void enqueue(int data){
  node* newnode=(node*)malloc(sizeof(node));
  newnode->data=data;
  newnode->link=NULL;
  if(front==NULL || rear==NULL){
    front=newnode;
    rear=newnode;
    return;
  }
  else{
    rear->link=newnode;
    rear=newnode;
  }
}

void dequeue(){

  if(front==NULL || rear==NULL){
    printf("EMPTY QUEUE!");
    return;
  }
  else{
    int val=front->data;
    printf("THE VALUE AT FRONT IS:%d",val);
    temp=front;
    front=front->link;
    free(temp);
  }
}

void display(){
  if(front==NULL || rear==NULL){
    printf("EMPTY QUEUE!");
    return;
  }
  else{
    temp=front;
    while(temp!=NULL){
      printf("%d\t",temp->data);
      temp=temp->link;
    }
  }
}

void main(){
  int data,op;
  while(1){
    printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.Exit\nSelect the operation:");
    scanf("%d",&op);
    if(op==1){
      printf("Enter the element to be enqueued:");
      scanf("%d",&data);
      enqueue(data);
    }
    else if(op==2){
      dequeue();
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
