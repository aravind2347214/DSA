// undirected Graph Representation AdjWorkerMatrixacency Matrix
#include <stdio.h>
// n vertices and m connections
int adjWorkerMatrix[20][20], n,m, q[20],visitedWorkers[20],f=-1,r=-1;
//connection representation
struct connection
{
	int s,d;
};
struct connection e[20];
// Function to create AdjWorkerMatrixacency Matrix

void createadjWorkerMatrix( struct connection e[])
{
    int i,j,x,y;
	// Initialise all value to this AdjWorkerMatrixacency matrix to zero
    for ( i = 0; i < n ; i++) {
  
        for (j = 0; j < n ; j++) {
            adjWorkerMatrix[i][j] = 0;
        }
    }
  
    // Traverse the array of connections
    for (i = 0; i < m; i++) 
	{
        // Find X and Y of connections as source and destination of the connections
         x = e[i].s;
        y = e[i].d;
       // Update value to 1
        adjWorkerMatrix[x][y] = 1;
        adjWorkerMatrix[y][x] = 1;//not required in case of directed graph
   }
    for (i = 0; i < n ; i++) 
   {
   		 for (j = 0; j < n ; j++) 
		    printf("%d ", adjWorkerMatrix[i][j]);
         printf("\n");
    }
        
    }
  
void bfs(int v) 
{
       int i;
       for (i=0;i<n;i++)                                // check all the vertices in the graph
       {
               if(adjWorkerMatrix[v][i] != 0 && visitedWorkers[i] == 0) // adjWorkerMatrixacent to v and not visitedWorkers
              {
                       r=r+1;
                       q[r]=i;                       // insert them into queue
                       visitedWorkers[i]=1;          // mark the vertex visitedWorkers
                       printf("%d  ",i);
              }
      }
      f=f+1;                             // remove the vertex at front of the queue
      if(f<=r)                           // as long as there are elements in the queue
            bfs(q[f]);                  // peform bfs again on the vertex at front of the queue
}
  

int main()
{
  int i, j,v;
  char ch='y';
  m=0;i=0;
  printf("Enter no of Workers: ");
  scanf("%d", &n);
  
 while(ch=='y')
 {
   	printf("Enter source worker id of connection: ");
   	scanf("%d", &e[i].s);
   	printf("Enter destination worker id of connection: ");
   	scanf("%d", &e[i].d);
    printf("do you want to add connection: ");
    fflush(stdin);
    scanf("%c", &ch);
    m=m+1;
    i++;
  }


    // Function call to create AdjWorkerMatrixacency Matrix
    createadjWorkerMatrix(e);
  
     
  
    for (i=0;i<n;i++)                   // mark all the vertices as not visitedWorkers
    {
        visitedWorkers[i]=0;
    }
    printf("\n Enter the starting worker id:");
    scanf("%d",&v);
    f=r=0;
    q[r]=v;
    printf("\n BFS traversal of worker is:\n");
    visitedWorkers[v]=1;                                     // mark the starting vertex as visitedWorkers
    printf("%d   ",v);
   
    bfs(v);
    if(r != n-1)
        printf("\n BFS is not possible");
  
  
  
}