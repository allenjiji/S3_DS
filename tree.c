#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int data;
  struct node* right;
  struct node* left;
}node;

node* parent;
node* root=NULL;
node* ptr;
int flag;
int case=0;

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

  if (ptr->left==NULL && ptr->right==NULL) case=1;
  else if (ptr->left!=NULL && ptr->right!=NULL) case=3;
  else case=2;

  if (case==1){
    if(parent->right==ptr) parent->right==NULL;
    else parent->left==NULL;
    free(ptr);
  }

  else if (case==2){
    if(parent->left==ptr){
      if(ptr->left==NULL) parent->left=ptr->right;
      else if (ptr->right==NULL) parent->left=ptr->left;
    }
    else if (parent->right==ptr){
      if(ptr->right==NULL) parent->right=ptr->left;
      else if(ptr->left==NULL) parent->right==ptr->right;
    }
  }

  else if(case==3){
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
void inorder(node* n){
  inorder(n->left);
  printf("%d  ",n->data);
  inorder(n->right);
}

void postorder(node* n){
  postorder(n->left);
  postorder(n->right);
  printf("%d  ",n->data);
}



void traverse(node* n){
  printf("Preorder:\n");
  postorder(n);
  printf("Inorder:\n");
  inorder(n);
  printf("Postorder:\n");
  postorder(n);
}


void main(){
  int op,data;
  printf("\tMENU\n");
  printf("1.Insert\n2.Delete\n3.Traverse\n4.Exit\nSelect the operation:");
  scanf("%d",&op);
  while(1){
  switch (op) {
    case 1: printf("Enter the dta to be inserted:");
            scanf("%d",&data);
            insert(data);
            break;
    case 2: printf("Enter the data to be deleted:");
            scanf("%d",&data);
            delete(data);
            break;
    case 3: traverse(root);
            break;
    case 4: exit(0);
            break;
    default: printf("Invalid Selection!\n");
  }
}
}
