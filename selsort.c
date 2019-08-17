#include<stdio.h>
void selsort(int arr[],int n){
	for(int i=0;i<n;i++){
		int min=i;
		for(int j=i+1;j<n;j++){
			if(arr[j]<arr[min]){
				min=j;
			}
		}
		if(arr[min]!=arr[i]){
			int temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
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
	selsort(arr,n);
	printf("Sorted content\n");
	for(i=0;i<n;i++){
		printf("%d\t",arr[i]);
		}
}

