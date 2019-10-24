#include<stdio.h>
#include<stdlib.h>

typedef struct node(
  int data;
  struct node* right;
  struct node* left;
)node;

node* parent;
node* root=NULL;
node* ptr;

void insert(int data){
  node* newnode=(node*)malloc(sizeof(node));
  newnode->data=data;
  newnode->right=NULL;
  newnode->left=NULL;

  if(newnode==NULL){
    printf("No Space !!");
    return;
  }
  if(root==NULL){
    root=newnode;
  }
  else{
    ptr=root;
    int flag=0;
    while(ptr!=NULL && flag==0){
      if(data>ptr->data){
        parent=ptr;
        ptr=ptr->right;
      }
      else if(data<ptr->data){
        parent=ptr;
        ptr=ptr->left;
      }
      else flag==1;
    }
    if(flag==0){
      if(data>parent->data){
        parent->right=newnode;
      }
      else{
        parent->left=newnode;
      }
    }
    else{
      printf("Element exists!\n");
      return;
    }
  }
}

void delete(int key){
  if(root==NULL){
    printf("BST EMPTY!\n");
    return;
  }
  ptr=root;
  flag=0;
  while(ptr!=NULL && flag==0){
    if(key>ptr->data){
      parent=ptr;
      ptr=ptr->right;
    }
    else if(key<ptr->data){
      parent=ptr;
      ptr=ptr->left;
    }
    else flag==1;
  }
  if (flag==0) {
    printf("Value Not found\n");
    return;
  }

  if (ptr->left==NULL && ptr->right==NULL) int case=1;
  else if (ptr->left!=NULL && ptr->right!=NULL) int case=3;
  else int case=3;

  if(case==1){
    if(parent->right==ptr) parent->right==NULL;
    else parent->left==NULL;
    free(ptr);
  }

  else if (case==2){
    if(parent->left==ptr){
      if(ptr->left==NULL) parent->left=ptr->right;
      else if (ptr->right==NULL) parent->left=ptr->left;
    }
    else if(parent->right==ptr){
      if(ptr->right==NULL) parent->right=ptr->left;
      else if(ptr->left==NULL) parent->right==ptr->right;
    }
  }

  else if (case==3){
    node* succ=ptr->right;
    while(succ->left!=NULL){
      succ=succ->left;
    }
    int i=succ->data;
    delete(succ->data);
    ptr->data=i;
  }
}


void search(int key){
  if(root==NULL){
    printf("No such BST!");
    return;
  }
  ptr=root;
  int flag=0;
  while(ptr!=NULL && flag==0){
    if(key>ptr->data) ptr=ptr->right;
    else if (key<ptr->data) ptr=ptr->left;
    else flag=1;
  }
  if(flag==1) printf("Found\n");
  else printf("NOT Found\n");
}

void preorder(node* n){
  printf("%d  ",n->data);
  preorder(n->left);
  preorder(n->right);
}
void



void traverse(){

}
