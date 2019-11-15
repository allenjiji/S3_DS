#include <stdio.h>
#define size 4
#define max 10
int visited[size];
int stack[max];
int queue[max];
int top=-1,front=-1,rear=-1;
int ar[size][size];
void dfs(int i);
void bfs(int i);
void main()
{
  printf("ENTER THE MATRIX");
  printf("\n");
  for(int i=0;i<size;i++)
    {
      for(int j=0;j<size;j++)
	{
           scanf("%d",&ar[i][j]);
	}
    }
  for(int i=0;i<size;i++)
     visited[i]=0;
   dfs(0);
for(int i=0;i<size;i++)
     visited[i]=0;
 bfs(0);

}
void dfs(int i)
{

  stack[++top]=i;
  int x;
  printf("The DFS RESULT IS: ");
  while(top>=0)
    {
      x=stack[top--];

      if(visited[x]==0)
	{
	  printf("%d ",x);
	  visited[x]=1;

      for(int j=0;j<size;j++)
	{
	  if(ar[x][j]==1)
	    stack[++top]=j;
	}
	}
    }
}
void bfs(int i)
{
  printf("\n\n");
  printf("THE BFS RESULT IS: %d ",i);
   visited[i]=1;
  queue[++rear]=i;
  front++;
  int x;
  while(front<size)
    {

      x=queue[front];
       front++;
      for(int j=0;j<size;j++)
	{
	  if(ar[x][j]==1)
	    {
	      if (visited[j]==0)
                  {
		    printf("%d ",j);
	            queue[++rear]=j;
	             visited[j]=1;
                   }
	    }
	}
    }
}
