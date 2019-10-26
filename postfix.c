#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 25
char a[MAX],b[MAX],stack[MAX];
int top=-1;

void push(char c){
  if(top>MAX){
    printf("An Error Occured! Please update MAX for better Perfomance.\n");
    exit(0);
  }
  else{
    top++;
    stack[top]=c;
  }
}

char pop(){
  if(top==-1) {
    printf("An Error Occured!\n");
    exit(0);
  }
  else{
    char a=stack[top];
    top--;
    return a;
  }
}



void display(){
  for(int i=0;b[i]!='\0';i++){
    printf("%c",b[i]);
  }
}

void insert(){
  scanf("%s",a);
}

int priority(char c){
  if(c=='+' ||c=='-') return 1;
  else if(c=='*' ||c=='/') return 2;
  else if(c=='^') return 3;
  else if(c=='(') return 0;
}

int isoperator(char x){
  if(x=='*'||x=='^'||x=='/'||x=='-'||x=='+') return 1;
  else return 0;
}



void convert(){
  push('(');
  int i;
  for (i=0;a[i]!='\0';i++);
  a[i++]=')';
  a[i]='\0';
  int j=0;
  for (i=0;a[i]!='\0';i++){
    if(isalpha(a[i])){
      b[j++]=a[i];
    }


    else if(a[i]=='(') push(a[i]);

    else if(a[i]==')'){
      while(stack[top]!='('){
        b[j++]=pop();
      }
      char z=pop();
    }
    else if(isoperator(a[i])){
      char c=a[i];
      char d=stack[top];
      while(priority(c)<=priority(d)){
        b[j++]=pop();
      }
      push(c);
    }
  }
  b[j]='\0';
}



void main(){
  while(1){
  printf("Enter the infix expression:");
  insert();
  convert();
  printf("The postfix expression is:");
  display();
  printf("\n");
}
}
