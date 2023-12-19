#include<stdio.h>
#include<stdlib.h>
int selsortList[10],selsortSmall,selsortTemp,selsortlen;

void selectionSort(){
    printf("\nEnter the Length of List\n");
    scanf("%d",&selsortlen);
    printf("\n Enter %d Elements \n",selsortlen);
    for(int i=0 ; i<=selsortlen-1;i++){
        scanf("%d",&selsortList[i]);
    }

    for(int i=0 ;i<selsortlen-1;i++){
        printf("\n");
        for(int i=0;i<selsortlen;i++){
        printf("(%d)  ",selsortList[i]);
        }
        selsortSmall=i;
        for(int j=i+1;j<selsortlen;j++){
            if(selsortList[j]<selsortList[selsortSmall]){
                selsortSmall=j;
            }
        }
        selsortTemp=selsortList[i];
        selsortList[i]=selsortList[selsortSmall];
        selsortList[selsortSmall]=selsortTemp;

    }

    printf("\n\nThe Sorted List is --[\t");
    for(int i=0;i<selsortlen;i++){
        printf("(%d)  ",selsortList[i]);
    }
    printf("]");

}


void main(){
    selectionSort();
}