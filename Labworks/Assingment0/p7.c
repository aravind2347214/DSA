// Calculate the row total of a given matrix
#include<conio.h>
#include<stdio.h>

void getMatrix(int( *a)[100],int row,int col){
    int i,j;
    int rowTotal[10];
    for(i=0;i<row;i++)
        rowTotal[i]=0;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("\n Enter element [%d][%d] : ",i+1,j+1);
            scanf("%d",&a[i][j]);
            rowTotal[i]+=a[i][j];
            
        }
    }

  
    for(i=0;i<row;i++){
        printf("Row %d Total :%d\n",i+1,rowTotal[i]);
    }
}


void main()
{
    int i,row,col;
    int a[100][100];
    printf("Enter the number of Rows");
    scanf("%d",&row);
     printf("Enter the number of Cols");
    scanf("%d",&col);
    getMatrix(a,row,col);
    getch();      
}