// 1. Read and display n numbers
#include<conio.h>
#include<stdio.h>

void getNumbers(int *a,int n){
    int i;
    for(i=0;i<n;i++){
        printf("\n Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }
}

void showNumbers(int *a,int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",a[i]);
    }

}

void main()
{
    int i,n;
    int a[100];
    printf("Enter the number of elements you want to read: ");
    scanf("%d",&n);
    getNumbers(a,n);
    printf("\n The entered numbers are : ");
    showNumbers(a,n);
    getch();      
}