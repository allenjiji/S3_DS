#include<stdio.h>
int linsearch(int* ar,int n,int key){
	for(int i=0;i<n;i++){
		if(ar[i]==key){
			return (i+1);
			break;
		}
	
	}
	return 0;	
}
void main(){
	int arr[50],i,n,key;
	printf("Enter the size of the array(<50):");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter element %d:",i+1);
		scanf("%d",&arr[i]);	
	}
	printf("Enter the element to be searched:");
	scanf("%d",&key);
	int a=linsearch(arr,n,key);
	if(a==0) printf("Element not found\n");
	else printf("Element found at position %d \n",a); 
	

	
		
}


