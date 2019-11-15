#include <stdio.h>
#define max 5
int a[max];
void heapsort( int n);
void heapify( int i,int n);
void main()
{
     printf("Enter the elements of the array : ");
  for(int i=0;i<max;i++)
     scanf("%d",&a[i]);
   
   heapsort(max);
 printf("The sorted array: ");
  for(int i=0;i<max;i++)
     printf("%d ",a[i]);
}

void heapsort(int n)
{
 for(int i= n/2-1  ;i>=0;i--)
 {
   heapify(i,n);
 }
 for(int i=n-1 ;i>=0;i--)
 {
   int temp=a[0];
   a[0]=a[i];
   a[i]=temp;
   heapify(0,i);
 }
}
void heapify( int i,int n)
{ int largest,lc,rc,temp;
  largest=i;
  lc=2*i+1  ;
  rc=2*i + 2;
  if((a[lc]>a[largest])&&(lc<n))
    {
      largest=lc;
    }
  if((a[rc]>a[largest])&&(rc<n))
    {
      largest=rc;
    }
  if(i!=largest)
    {
      temp=a[i];
      a[i]=a[largest];
      a[largest]=temp;
      heapify(largest,n);
    }
  
  
}
