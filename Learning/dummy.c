#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>



void main(){

    int *dynamicArray;
    int size;
    int i=0,sum=0;
    int n;
    printf("Enter Number of Digits");
    scanf("%d",&size);
    dynamicArray =(int *)malloc(size*sizeof(int));
    if (dynamicArray==NULL)
    {
        printf("Memory allocation failed");
    }
    else{
     
        for(i=0;i<size;i++){
            dynamicArray[i]=i+1;
            sum+=dynamicArray[i];
        }
    }

      for(i=0;i<size;i++){
        printf("[ %d ] ",dynamicArray[i]);  
        }
      printf("Sum is : %d",sum); 

    free(dynamicArray);
    getch();
}