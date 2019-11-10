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
int cas=0;

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

/*void delete(int x){
  //int x,k;
  //printf("Enter the data to be deleted : ");
  //scanf("%d",&x);
struct node *ptr;
  if(root==NULL)
     printf("Empty Treee ");
  else
  {
    ptr=root;
    int flag=0;
    while((ptr!=NULL)&&(flag==0))
   {
     if(x>ptr->data)
     {
       parent=ptr;
       ptr=ptr->right;
     }
    else if(x<ptr->data)
    {
      parent=ptr;
      ptr=ptr->left;
    }
    else
    {
      flag=1;
    }
   }
  if(flag==0)
    printf("Value Not found");
  else if((ptr->left==NULL)&&(ptr->right==NULL))
  {
printf("case 1");
    if(parent->left==ptr)
      parent->left=NULL;
    else
      parent->right=NULL;
    free(ptr);
  }
  else if((ptr->left!=NULL)&&(ptr->right!=NULL))
 {
  node* s=ptr->right;
printf("case 3");
   while(s->left!=NULL)
    {
      s=s->left;
     }
    int i=s->data;

   delete(s->data);
   ptr->data=i;
   //free(ptr);
 }
 else
  {
printf("case 2");
    if(parent->left==ptr)
      {
        if(ptr->left==NULL)
           parent->left=ptr->right;
        else
           parent->left=ptr->left;
      }
     else if(parent->right==ptr)
      {
        if(ptr->left==NULL)
           parent->right=ptr->right;
        else
           parent->right=ptr->left;
      }
     free(ptr);
  }

  }
}*/

void delete(int key){
  if(root==NULL){
    printf("BST EMPTY!\n");
    return;
  }
  ptr=root;
  flag=0;
  while((ptr!=NULL) && (flag==0)){
    if(key>ptr->data){
      parent=ptr;
      ptr=ptr->right;
    }
    else if(key<ptr->data){
      parent=ptr;
      ptr=ptr->left;
    }
    else flag=1;
  }
  if (flag==0) {
    printf("Value Not found\n");
    return;
  }
  if ((ptr->left==NULL) && (ptr->right==NULL)) cas=1;
  else if ((ptr->left!=NULL) && (ptr->right!=NULL)) cas=3;
  else cas=2;

  if (cas==1){
    if(parent->right==ptr) parent->right==NULL;
    else parent->left==NULL;
    free(ptr);
  }

  else if (cas==2){
    if(parent->left==ptr){
      if(ptr->left==NULL) {
         parent->left=ptr->right;
      }
      else{
        parent->left=ptr->left;
      }
    }
    else if (parent->right==ptr){
      if(ptr->right==NULL) {
        parent->right=ptr->left;
      }
      else {
        parent->right==ptr->right;
    }
  }
  free(ptr);
}

  else if(cas==3){
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
  if(n!=NULL){
  printf("%d  ",n->data);
  preorder(n->left);
  preorder(n->right);
  }
}
void inorder(node* n){
  if (n!=NULL){
  inorder(n->left);
  printf("%d  ",n->data);
  inorder(n->right);
  }
}
void postorder(node* n){
  if (n!=NULL){
  postorder(n->left);
  postorder(n->right);
  printf("%d  ",n->data);
  }
}


void traverse(node* n){
  if (n==NULL){
    printf("EMPTY!\n");
    return;
  }
  printf("Preorder:\n");
  preorder(n);
  printf("\n");
  printf("Inorder:\n");
  inorder(n);
  printf("\n");
  printf("Postorder:\n");
  postorder(n);
  printf("\n");

}


void main(){
  int op,data;
  printf("\tMENU\n");
  while(1){

  printf("1.Insert\n2.Delete\n3.Traverse\n4.Search\n5.Exit\nSelect the operation:");
  scanf("%d",&op);
  switch (op) {
    case 1: printf("Enter the data to be inserted:");
            scanf("%d",&data);
            insert(data);
            break;
    case 2: printf("Enter the data to be deleted:");
            scanf("%d",&data);
            delete(data);
            break;
    case 3: traverse(root);
            break;
    case 4: printf("Enter the item to be searched:");
            scanf("%d",&data);
            search(data);
            break;
    case 5: exit(0);
            break;
    default: printf("Invalid Selection!\n");
    }
  }
}
