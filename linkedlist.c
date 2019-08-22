#include<stdio.h>
struct node{
  int data;
  struct node* link;
};

int countnodes(struct node* head){
  inr count=0;
  struct node* temp=head;
  while(temp->link!=NULL){
    count++;
    temp=temp->link;
  }
  return count;
}

void insertion(struct node* head,int pos,int x){
  struct node* newnode=(struct node*)malloc(sizeof(struct node))
  if(pos==1){
    newnode->link=head;
    head=newnode;
  }
  else if(pos=countnodes()){
		            struct node* temp=head;
			    while(temp->link!=NULL){
			      struct node* temp1=temp;
			      temp=temp->link;
			    }
			    temp->link=newnode;
			    newnode->link=NULL;
  }
  else if(pos>1 && pos<countnodes()){
				     struct node* temp=head;
				     set=0;
				     while()
  }
			    
}
  
  
 
 
