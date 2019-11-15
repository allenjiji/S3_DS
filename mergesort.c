#include<stdio.h>
void mergesort(int arr[],int l,int r);
void merge(int arr[],int l,int mid,int r);
int main(void){
    int arr[10],n;
    printf("Enter the number of elements to be Inserted\n");
    scanf("%d",&n);
    printf("Enter the elements of array\n");
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
}

void mergesort(int arr[],int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

void merge(int arr[],int l,int mid,int r){
    int i=l,j=mid+1,temp[r-l+1],k=0;
    while(i<=mid && j<=r){
        if(arr[i]>=arr[j]){
            temp[k]=arr[j];
            k++;
            j++;
        }
        else{
            temp[k]=arr[i];
            k++;
            i++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        i++;
        k++;
    }
    while(j<=r){
        temp[k]=arr[j];
        j++;
        k++;
    }
    i=0;
    j=l;
    while(i<k){
        arr[j]=temp[i];
        i++;
        j++;
    }
}