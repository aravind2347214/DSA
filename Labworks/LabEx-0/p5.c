// 5. Calculate the sum and average of n numbers
#include<conio.h>
#include<stdio.h>

void getNumbers(int *a,int n){
    int i;
    for(i=0;i<n;i++){
        printf("\n Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }
}

void showResult(int *a,int n){
    int sum=0;
    float avg;
    int i;
    for(i=0;i<n;i++){
       sum+=a[i];
    }
    avg=sum/n;
    printf("\nSum : %d",sum);
    printf("\nAverage : %f",avg);
}

void main()
{
    int i,n;
    int a[100];
    printf("Enter the number of elements you want to read: ");
    scanf("%d",&n);
    getNumbers(a,n);
    showResult(a,n);
    getch();      
}