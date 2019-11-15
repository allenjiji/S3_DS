#include<stdio.h>
#include<stdlib.h>
#define max 10
void insert(int n);
int search(int n);
int display();
typedef struct node{
    int data;
    struct node* link;
}node;
node* arr[max];
int main(void){
    for(int i=0;i<max;i++) arr[i]=NULL;
    int ty,k,t;
    printf("\tMENU\n");
    while(1){
        printf("1.INSERT\n2.SEARCH\n3.TRAVERSE\n");
        scanf("%d",&ty);
        switch(ty){
            case 1:{
                k=0;
                printf("Enter the element to be Inserted\n");
                scanf("%d",&t);
                if(search(t)!=-1) printf("The element already Exists\n");
                else insert(t);
                break;
            }
            case 2:{
                printf("Enter the element to be searched\n");
                scanf("%d",&t);
                k=search(t);
                if(k==-1) printf("Element not found\n");
                else printf("Element found at index %d\n",k);
                break;
            }
            case 3:{
                k=display();
                if(k==-1) printf("Array empty");
                printf("\n");
                break;
            }
        }
    }
}

void insert(int n){
    int mod=n%10;
    node* newnode=malloc(sizeof(node*));
    newnode->data=n;
    newnode->link=NULL;
    node* temp=arr[mod];
    if(temp==NULL) arr[mod]=newnode;
    else {
        while(temp->link!=NULL) temp=temp->link;
        temp->link=newnode;
    }
}

int search(int n){
    int mod=n%10;
    node* temp=arr[mod];
    while(temp!=NULL){
        if(temp->data==n) return mod;
        temp=temp->link;
    }
    return -1;
}

int display(){
    int i=0,flag=0;
    node* temp;
    while(i<max){
        temp=arr[i];
        printf("[%d] ",i);
        while(temp!=NULL){
            printf("%d -->",temp->data);
            flag=1;
            temp=temp->link;
        }
        printf("\n");
        i++;
    }
    if(flag==1) return 1;
    else return -1;
}
