#include<stdio.h>
#include<stdlib.h>


typedef struct node{
  int coef;
  int exp;
  struct node* link;
}node;


node* phead=NULL;
node* qhead=NULL;
node rhead;
node* rptr=&rhead;
node* bhead;


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

void display(node* head){
  node* temp=head;
  printf("\n\n");
  while(temp!=NULL){

    printf("%dx^%d",temp->coef,temp->exp);
    if(temp->link!=NULL) printf(" + ");
      temp=temp->link;


}
  printf("\n\n");
}


node* multiply()
{
	int k=1;
	struct node *rhead,*shead,*pptr,*qptr,*rptr,*sptr,*tptr,*newnode;
	pptr=phead;
	qptr=qhead;
	while(pptr!=NULL)
	{
		qptr=qhead;
		while(qptr!=NULL)
		{
			newnode=(struct node*)malloc(sizeof(struct node));
			newnode->coef=pptr->coef * qptr->coef;
			newnode->exp=pptr->exp + qptr->exp;
			newnode->link=NULL;
			if(k==1)
			{
				k++;
				shead=newnode;
				sptr=shead;
				qptr=qptr->link;
			}
			else
			{
				sptr->link=newnode;
				sptr=newnode;
				qptr=qptr->link;
			}
		}
		pptr=pptr->link;
	}
	k=shead->exp;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->coef=shead->coef;
	newnode->exp=shead->exp;
	newnode->link=NULL;
	rhead=newnode;
	rptr=rhead;
	while((--k)!=-1)
	{
		int sum=0;
		newnode=(struct node*)malloc(sizeof(struct node));
		rptr->link=newnode;
		rptr=newnode;
		sptr=shead->link;
		while(sptr!=NULL)
		{
			if(sptr->exp == k)
				sum=sum+ sptr->coef;
			sptr=sptr->link;
		}
		rptr->coef=sum;
		rptr->exp=k;
		rptr->link=NULL;
	}
	return rhead;
}


void main(){
  printf("First Polynimial\n");
  phead=insert(phead);
  display(phead);
  printf("Second polynomial\n");
  qhead=insert(qhead);
  display(qhead);
  node* rptr=multiply();

  display(rptr);
}
