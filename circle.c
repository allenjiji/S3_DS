#include<stdio.h>
#include<stdlib.h>
#define max 5
int arr[max],front=-1,rear=-1;
void enq(int n);
void dq();
void display();
int main(void){
  int ty;
  while(1){
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    scanf("%d",&ty);
    if(ty==1){
      int num;
      printf("Enter the element: ");
      scanf("%d",&num);
      enq(num);
    }
    else if(ty==2) dq();

    else if(ty==3) display();
    else if(ty==4) break;
  }
}
void enq(int n){
    if(front==-1 || rear==-1 ){
        front=0;rear=0;
        arr[rear]=n;
    }
    else{
    int srear=(rear+1)%max;
    if(srear==front) printf("Queue Full\n");
    else {
        rear=srear;
        arr[rear]=n;
}
    }
}

void dq(){
    if(front==-1 ||rear==-1) printf("Queue Empty");
    else {
        printf("%d\n",arr[front]);
      if(front==rear) front=-1;
      else front=(front+1)%max;
    }
}

void display(){
    int i;
    if(front==-1 ||rear==-1) printf("Queue Empty");
    else{
        if(front<=rear) for(i=front;i<=rear;i++) printf("%d ",arr[i]);
        else {
            for(i=front;i!=rear;i=(i+1)%max) printf("%d ",arr[i]);
            printf("%d ",arr[i]);
    }
    printf("\n");
}
}
