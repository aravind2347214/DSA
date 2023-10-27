// 2. Read and display odd positioned elements
#include<conio.h>
#include<stdio.h>


void readNumbers(int *a,int n){
    int i;
    for(i=0;i<n;i++){
        printf("\n Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }

}

void showOddIndexNumbers(int *a,int n){
    int i;
    printf("\nOdd Position Elements are :  ");
    for( i=0;i<n;i++){
        if(i%2 != 0)
            printf("%d  ",a[i]);
    }

}

void main(){
     int i,n;
    int a[100];
    printf("Enter the number of elements you want to read: ");
    scanf("%d",&n);
    readNumbers(a,n);
    showOddIndexNumbers(a,n);
    getch(); 
}