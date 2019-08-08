#include<stdio.h>
void sort(int *ar,int n){
	int temp;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(ar[j]>ar[j+1]){
				temp=ar[j];
				ar[j]=ar[j+1];
				ar[j+1]=temp;	
				}
			}				
		}
	}
int binsearch(int *ar,int low,int upp,int key){
	while(low<=upp){	
		int mid=(low+upp)/2;
		if(key>ar[mid]) low=mid+1;
		else if(key<ar[mid]) upp=mid-1;
		else return (mid+1);
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
	
	/*sort(arr,n);
	for(i=0;i<n;i++){
		printf("element %d:%d\n",i+1,arr[i]);
		}*/

	
	sort(arr,n);	
	printf("Enter the element to be searched:");
	scanf("%d",&key);
	int a=binsearch(arr,0,n-1,key);
	if(a==0) printf("Element not found\n");
	else printf("Element found at position %d \n",a);
}
