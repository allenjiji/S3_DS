#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node{
  char character;
  struct node *link;
}node;
typedef struct eval{
  int number;
  struct eval *link;
}eval;
node *top=NULL;
node *front=NULL,*rear=NULL;
eval *start=NULL;
char infix[50];
void convert()
{
  printf("\n");
  for (int i=0;infix[i]!='\0';i++)
  {
    if (isalpha(infix[i]))
    {
        node *newnode; newnode=(node*)malloc(sizeof(node));
	newnode->link=NULL;
	if (front==NULL)
	{
	  front=rear=newnode;
	}
	else
	{
	  rear->link=newnode;
	  rear=newnode;
	}
	newnode->character=infix[i];
    }
    else if (infix[i]=='(')
    {
        node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
	if (top==NULL)
 	{
	  top=newnode;
	}
	else
	{
	  newnode->link=top;
	  top=newnode;
	}
	newnode->character=infix[i];
    }
    else if (infix[i]==')')
    {
      while (top->character!='(')
      {
	node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
	if (front==NULL)
	{
	  front=rear=newnode;
	}
	else
	{
	  rear->link=newnode;
	  rear=newnode;
	}
	newnode->character=top->character;
	top=top->link;
      }
      top=top->link;
    }
    else if (infix[i]=='+'||infix[i]=='-')
    {
      int flag=0;
      if (top==NULL)
	flag=1;
      while(flag==0)
      {
	if (top->character=='+'||top->character=='-'||top->character=='*'||top->character=='/'||top->character=='^')
	{
	  node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
	  newnode->character=top->character;
	  if (front==NULL)
 	  {
	    front=rear=newnode;
	  }
	  else
	  {
	    rear->link=newnode;
	    rear=newnode;
	  }
	  top=top->link;
	  if (top==NULL)flag=1;
	}
	else
	  flag=1;
      }
      node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
      newnode->character=infix[i];
      if(top==NULL){
	top=newnode;
      }
      else{
	newnode->link=top;
	top=newnode;
      }
    }
    else if(infix[i]=='*'||infix[i]=='/')
    {
      int flag=0;
      if (top==NULL)flag=1;
      while(flag==0)
      {
	if (top->character=='*'||top->character=='/'||top->character=='^')
 	{
	  node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
	  newnode->character=top->character;
	  if (front==NULL)
	  {
	    front=rear=newnode;
	  }
	  else
	  {
	    rear->link=newnode;
	    rear=newnode;
	  }
	  top=top->link;
	  if (top==NULL)flag=1;
	}
	else
	  flag=1;
      }
      node *newnode;
      newnode=(node*)malloc(sizeof(node));
      newnode->link=NULL;
      newnode->character=infix[i];
      if(top==NULL)
      {
	top=newnode;
      }
      else
      {
	newnode->link=top;
	top=newnode;
      }
    }
    else if(infix[i]=='^')
    {
      int flag=0;
      if (top==NULL)flag=1;
      while(flag==0)
      {
	if (top->character=='^')
	{
	  node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
	  newnode->character=top->character;
	  if (front==NULL)
	  {
	    front=rear=newnode;
	  }
	  else
	  {
	    rear->link=newnode;
	    rear=newnode;
	  }
	  top=top->link;
	  if (top==NULL)flag=1;
	}
	else
	  flag=1;
      }
      node *newnode;
      newnode=(node*)malloc(sizeof(node));
      newnode->link=NULL;
      newnode->character=infix[i];
      if(top==NULL)
      {
	top=newnode;
      }
      else
      {
	newnode->link=top;
	top=newnode;
      }
    }
    else
    {
      printf("Invalid Expression\n");
      exit(0);
    }
  }
  while(top!=NULL)
  {
    node *newnode; newnode=(node*)malloc(sizeof(node)); newnode->link=NULL;
    newnode->character=top->character;
    rear->link=newnode;
    rear=newnode;
    top=top->link;
  }
}
void evl()
{
  printf("\n");
  node *t;
  int a,b,r;
  for (t=front;t!=NULL;t=t->link){
    if (isalpha(t->character)){
      eval *newnode; newnode=(eval*)malloc(sizeof(eval)); newnode->link=NULL;
      printf("Enter value of %c: ",t->character);
      scanf("%d",&newnode->number);
      if (start==NULL)
	start=newnode;
      else{
	newnode->link=start;
	start=newnode;
      }
    }
    else if (t->character=='+'||t->character=='-'||t->character=='*'||t->character=='/'||t->character=='^'){
      a=start->number;
      start=start->link;
      b=start->number;
      start=start->link;
      if (t->character=='+')
	r=a+b;
      else if(t->character=='-'){
	r=b-a;
      }
      else if(t->character=='*'){
	r=b*a;
      }
      else if(t->character=='/'){
	r=b/a;
      }
      else{
	r=1;
	for(int i=0;i<a;i++)
	  r=r*b;
      }
      eval *newnode; newnode=(eval*)malloc(sizeof(eval)); newnode->link=NULL;
      newnode->number=r;
      if (start==NULL)
	start=newnode;
      else{
        newnode->link=start;
	start=newnode;
      }
    }
    /*printf("%c| ",t->character);
    for(eval *print=start;print!=NULL;print=print->link)
      printf("%d ",print->number);
    printf("\n");*/
  }
}
int main(){
  printf("Enter expression: ");
  scanf("%s",infix);
  convert();
  node *t;
  printf("Postfix: ");
  for (t=front;t!=NULL;t=t->link)
    printf("%c",t->character);
  printf("\n");
  evl();
  printf("\nResult: %d",start->number);
  printf("\n");
  return 0;
}
