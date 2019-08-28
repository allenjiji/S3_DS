#include <stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node* link;
};

struct node* head=NULL;



int countnodes(){
  struct node* temp=head;
  int count=0;
  while(temp!=NULL){
    count++;
    temp=temp->link;
  }
  return count;
}
void traverse(){
  struct node* temp=head;
  printf("\n\n");
  while(temp!=NULL){
    printf("%d\t",temp->data);
    temp=temp->link;
  }
 printf("No of elements : %d\n",countnodes());
 printf("\n\n");
}

void insert(int x,int pos){
  struct node* newnode=(struct node*)malloc(sizeof(struct node));
  newnode->data=x;
  newnode->link=NULL;


  if(pos==1){
    newnode->link=head;
    head=newnode;

  }
  /*else if (pos==(countnodes()+1)){
    struct node* temp=head;
    struct node* temp1;
    while(temp!=NULL){
      temp1=temp;
      temp=temp->link;
    }
    temp1->link=newnode;
  }*/
  else if((pos<=(countnodes()+1)) && pos>1){
    struct node* temp=head;
    struct node* temp1;
    int loc=1;
    while(pos!=loc){
      temp1=temp;
      temp=temp->link;
      loc++;
    }
    newnode->link=temp1->link;
    temp1->link=newnode;
  }
else printf("\nIMPOSSIBLE!!\n");

}
void delete(int pos){
    if(head==NULL){
      printf("No Such List\n");
    }
    else if(pos==1){
      struct node* p=head;
      head=head->link;
      free(p);
    }
    else if(pos>1 && pos<(countnodes()+1)){
      int loc=1;
      struct node* temp=head;
      struct node* temp1;
      while(pos!=loc){
        temp1=temp;
        temp=temp->link;
        loc++;
      }
      struct node* p=temp1->link;
      temp1->link=temp->link;
      free(p);
    }
    else printf("\nIMPOSSIBLE!!\n");

  }
void search(int key){
    struct node* temp=head;
    while(temp!=NULL){
      if(temp->data==key){
        printf("Element found\n");
        return;
      }
      temp=temp->link;
    }
    printf("Element not found\n");
  }
void main(){
    int op,data,pos,key;


    while(1){
      printf("1.Insertion\n2.Deletion\n3.Searching\n4.Traversal\nSelect the operation:");
      scanf("%d",&op);
      if(op==1){
        printf("Enter the Data:");
        scanf("%d",&data);
        printf("Enter the position to be inserted:");
        scanf("%d",&pos);
        insert(data,pos);
      }
      else if(op==2){
        printf("Enter the position to be deleted:");
        scanf("%d",&pos);
        delete(pos);
      }
    else if(op==3){
      printf("Enter the Elementto be searched:");
      scanf("%d",&key);
      search(key);
    }
    else if(op==4){
      traverse();
    }

    }
  }
