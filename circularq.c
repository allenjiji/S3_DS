#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int q[MAX];
int front=-1,rear=-1;

void enqueue(int data){
  if(front==((rear+1)%MAX)){
    printf("Queue Full\n");
    return;
  }
  else{
    if (front==-1){
      rear=0;
      front=0;
    }
    else{
      rear=((rear+1)%MAX);
    }
    q[rear]=data;
  }
}

void dequeue(){
  if(front==-1){
    printf("Queue empty \n");
    return;
  }
  else{
    int data=q[front];

    if(front==rear){
      front=rear=-1;
    }
    else{
      front=((front+1)%MAX);
    }
    printf("Dequeued element is:%d\n",data);
  }
}

void traverse(){
  if(front==-1){
    printf("The Queue is Empty\n");
    return;
  }
  else{
    if(front<=rear){
      for (int i=front;i<=rear;i++){
        printf("%d,",q[i]);
      }
      printf("\n");
    }
    else if(front>rear){
      for (int i=front;i<MAX;i++){
        printf("%d,",q[i]);
      }
      for (int i=0;i<=rear;i++){
        printf("%d,",q[i]);
      }
      printf("\n");
    }
  }
}



void main() {
  int op,data;
  printf("\tMENU\n");
  printf("1.Enqueue\n2.Dequeue\n3.Traverse\n4.Exit\n");
  while(1){
    printf("Select any operation:");
    scanf("%d",&op);
    if(op==1) {
      printf("Enter the data to be enqueued:");
      scanf("%d",&data);
      enqueue(data);
    }
    else if(op==2) dequeue();
    else if(op==3) traverse();
    else if(op==4) exit(0);
    else printf("Invalid operation!\n");


  }
}
