//  Read and display n*n matrix
#include<conio.h>
#include<stdio.h>

void getMatrix(int( *a)[100],int row,int col){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("\n Enter element [%d][%d] : ",i+1,j+1);
            scanf("%d",&a[i][j]);
        }
    }
}

void showMatrix(int (*a)[100],int row,int col){
    int i,j;
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("%d  ",a[i][j]);
        }
        printf("\n");
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
    printf("\n The entered numbers are : \n");
    showMatrix(a,row,col);
    getch();      
}