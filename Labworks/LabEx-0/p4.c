// 4. Display maximum number from the set of integers
#include<conio.h>
#include<stdio.h>


void readNumbers(int *a,int n){
    int i;
    for(i=0;i<n;i++){
        printf("\n Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }

}
void main(){
     int i,n;
    int a[100];
    int big;
    printf("Enter the number of elements you want to read: ");
    scanf("%d",&n);
    readNumbers(a,n);
    big = a[0];
    for(i=1;i<n;i++){
        if(a[i]>big)
            big=a[i];
    }
    printf("\nThe Maximum number is %d",big);
    getch(); 
}