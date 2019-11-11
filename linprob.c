#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int a[SIZE],u[SIZE];

int loc;
void insert(int key,int* u){
  loc=key%SIZE;
  int i=loc;
  while(u[i]==1 && i<SIZE){
    i++;
  }
  if(i>=SIZE){
    printf("UPDATE SIZE");
    return;
  }
  u[i]=1;
  a[i]=key;
}


void search(int key, int* u){
  for(int i=0;i<SIZE;i++){
    if (u[i]==1){
      if(a[i]==key){
        printf(" KEY FOUND ");
        return;
      }
    }
  }
  printf(" KEY NOT FOUND ");
}


void display(int* u){
  for(int i=0;i<SIZE;i++){
    if(u[i]==1){
      printf("a[%d]--->%d",i,a[i]);
      printf("\n");
    }
  }
}



void main(){

  for(int j=0;j<SIZE;j++){
    u[j]=0;
  }
  int op,data;
  printf("\tMENU\n");
  while(1){

  printf("\n1.Insert\n2.Traverse\n3.Search\n4.Exit\nSelect the operation:");
  scanf("%d",&op);
  switch (op) {
    case 1: printf("Enter the data to be inserted:");
            scanf("%d",&data);
            insert(data,u);
            break;
    case 2: display(u);
            break;
    case 3: printf("Enter the item to be searched:");
            scanf("%d",&data);
            search(data,u);
            break;
    case 4: exit(0);
            break;
    default: printf("Invalid Selection!\n");
    }
  }
}
