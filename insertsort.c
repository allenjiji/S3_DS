#include<stdio.h>
void insort(int arr[],int n){
	for(int i=1;i<n;i++){
		int j=i-1;
		int key=arr[i];
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;		


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
	insort(arr,n);
	printf("Sorted content\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
		}
}

