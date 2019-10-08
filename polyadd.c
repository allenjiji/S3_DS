#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int coef;
  int exp;
  struct node* link;
}node;

node* phead=NULL;
node* qhead=NULL;
node rhead1;
node* rhead=&rhead1;

//rhead->link=NULL;

void display(node* head){
  node* temp=head;
  printf("\n\n");
  while(temp!=NULL){

    printf("%dx^%d\t",temp->coef,temp->exp);
	  if(temp->link!=NULL) printf(" + ");
      temp=temp->link;


}
  printf("\n\n");
}


node* insert(node* head){
  int deg,coef;
  node* ptr;
  printf("Enter the degree of the polynomial:");
  scanf("%d",&deg);
  for(int i=deg;i>=0;i--){
    printf("Enter the coefficent of x^%d:",i);
    scanf("%d",&coef);
    if(coef!=0){
      node* newnode=(node*)malloc(sizeof(node));
      newnode->coef=coef;
      newnode->exp=i;
      newnode->link=NULL;
      if(head==NULL){
	       head=newnode;
      }
      else{
	       ptr=head;
	        while(ptr->link!=NULL){
	            ptr=ptr->link;
	           }

	        ptr->link=newnode;
      }
    }
  }
    return head;
  }

node* addition(){
  node* rptr=rhead;
  node* pptr=phead;
  node* qptr=qhead;
  while(pptr!=NULL && qptr!=NULL){
    if((pptr->exp)==(qptr->exp)){
      node* newnode=(node*)malloc(sizeof(node));
      newnode->coef=((pptr->coef)+(qptr->coef));
      newnode->exp=pptr->exp;
      newnode->link=NULL;
      rptr->link=newnode;
      pptr=pptr->link;
      qptr=qptr->link;

    }
    else if((pptr->exp)>(qptr->exp)){
      node* newnode=(node*)malloc(sizeof(node));
      newnode->coef=pptr->coef;
      newnode->exp=pptr->exp;
      newnode->link=NULL;
      rptr->link=newnode;
      pptr=pptr->link;
    }
    else if((pptr->exp)<(qptr->exp)){
      node* newnode=(node*)malloc(sizeof(node));
      newnode->coef=qptr->coef;
      newnode->exp=qptr->exp;
      newnode->link=NULL;
      rptr->link=newnode;
      qptr=qptr->link;
    }
    rptr=rptr->link;
  }
  while(pptr!=NULL){
    node* newnode=(node*)malloc(sizeof(node));
    rptr->coef=pptr->coef;
    rptr->exp=pptr->exp;
    //rptr->link=NULL;
    pptr=pptr->link;
    rptr=rptr->link;

  }
  while(qptr!=NULL){
    node* newnode=(node*)malloc(sizeof(node));
    rptr->coef=qptr->coef;
    rptr->exp=qptr->exp;
    //rptr->link=NULL;
    qptr=qptr->link;
    rptr=rptr->link;

  }
}


void main(){
  printf("First Polynimial\n");
  phead=insert(phead);
  display(phead);
  printf("Second polynomial\n");
  qhead=insert(qhead);
  display(qhead);
  addition();
  rhead=rhead->link;
  display(rhead);
}
