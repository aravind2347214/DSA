#include<stdio.h>
#include<stdlib.h>
int insortList[10],insortlen,insortKey;
void insertionSort(){
    printf("\nEnter the Length of List\n");
    scanf("%d",&insortlen);
    printf("\n Enter %d Elements \n",insortlen);
    for(int i=0 ; i<=insortlen-1;i++){
        scanf("%d",&insortList[i]);
    }

    for(int i=0;i<insortlen;i++){
        insortKey=insortList[i];
        int j = i-1;
        while(j>=0 && insortList[j]>insortKey){
            insortList[j+1]=insortList[j];
            j--;
        }
        insortList[j+1]=insortKey; 
        printf("Iteration %d : ",i+1);
        for(int i=0;i<insortlen;i++){
        printf("[%d] ",insortList[i]);}
        printf("\n");
    }

    printf("The Sorted List is --");
    for(int i=0;i<insortlen;i++){
        printf("[%d] ",insortList[i]);
    }
}

void main(){
    insertionSort();
}