#include<stdio.h>
#include <stdlib.h>
#define MAX 5
int q[MAX];
int front=-1;
int rear=-1;
void enqueue(int data){
  if(rear>=MAX-1){
    printf("QUEUE overflow\n");
    return;
  }
    if(front==-1 && rear==-1){
      front++;
      rear++;
      q[rear]=data;
      return;
    }
    else{
      rear++;
      q[rear]=data;
    }
}

void dequeue(){
  int data;

  if(front==-1 || front>rear){
    printf("QUEUE empty\n");
    return;
  }



  else{
    data=q[front];
    printf("denquued element is %d\n",data);
    if(front==rear) front=rear=-1;
    else front++;
  }
  /*if(front==rear){
    front=rear==-1;
  }*/

}



void display(){
  if (front==-1){
    printf("EMPTY QUEUE\n");

  }
  else{
    for(int i=front;i<=rear;i++){
      printf("%d  ",q[i]);
    }
    printf("\n\n");

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
