#include<stdio.h>
void bubsort(int arr[],int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1-i;j++){
			if(arr[j]>arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}


void main(){
	int i,n,arr[50];
	printf("Enter the size of the array(<50):");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter element %d:",i+1);
		scanf("%d",&arr[i]);	
	}
	bubsort(arr,n);
	printf("Sorted content\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
		}
}

