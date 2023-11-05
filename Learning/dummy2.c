#include<conio.h>
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void main(){
    float *dynamicArray;
    int oldsize,newsize;
    int i=0;float sum=0;
    int n;
    printf("Enter Number of Digits");
    scanf("%d",&oldsize);
    dynamicArray =(float *)malloc(oldsize*sizeof(float));
    if (dynamicArray==NULL)
    {
        printf("Memory allocation failed");
    }
    else{
     
        for(i=0;i<oldsize;i++){
            dynamicArray[i]=i+1;
            sum+=dynamicArray[i];
        }
    }

      for(i=0;i<oldsize;i++){
        printf("[ %d ] ",dynamicArray[i]);  
        }
      printf("Sum is : %d",sum);

    printf("Enter Number of Digits");
    scanf("%d",&newsize);
    dynamicArray =(float *)realloc(dynamicArray,oldsize*sizeof(float));
    if (dynamicArray==NULL)
    {
        printf("Memory allocation failed");
    }
    else{
     
        for(i=0;i<oldsize;i++){
            dynamicArray[i]=(i+1)*2;
            sum+=dynamicArray[i];
        }
    }

      for(i=0;i<oldsize;i++){
        printf("[ %d ] ",dynamicArray[i]);  
        }
      printf("Sum is : %d",sum);  

    free(dynamicArray);
    getch();
 

}