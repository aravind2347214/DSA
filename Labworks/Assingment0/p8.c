// Check whether the given matrix is identity matrix or not
#include<conio.h>
#include<stdio.h>

void getMatrix(int( *a)[100],int row,int col){
    int i,j,c=0;
    int rowTotal[10];
    
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            printf("\n Enter element [%d][%d] : ",i+1,j+1);
            scanf("%d",&a[i][j]);
            
        }
    }

    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(i==j){
                if(a[i][j]==1){
                    c=1;
                }
                else{
                    c=0;
                }
            }
            else{
                if(a[i][j]==0){
                    c=1;
                }
                else{
                    c=0;
                }
            }
            
        }
    }

    if(c==1)
        printf("\nIt is a Identity Matrix");
    else
        printf("\nNot Identity Matrix");
      
}


void main()
{
    int i,row,col;
    int a[100][100];
    rowcolReenter:
        printf("Enter the number of Rows");
        scanf("%d",&row);
        printf("Enter the number of Cols");
        scanf("%d",&col);
    if(row!=col){
        printf("\nRow and Col not same please enter same row and col");
        goto rowcolReenter;
    }
    getMatrix(a,row,col);
    getch();      
}

