#include<stdio.h>
#include<conio.h> 
int bsearchList[10],bsearchMid,bsearchFirst,bsearchLast,bsearchlen,bsearchdata,bsearchflag=0;
void binarySearch(){
    printf("\nEnter the Length of List\n");
    scanf("%d",&bsearchlen);
    printf("\n Enter %d Eleements \n",bsearchlen);
    for(int i=0 ; i<=bsearchlen-1;i++){
        scanf("%d",&bsearchList[i]);
    }
    printf("\nEnter the Data To be Searched\n");
    scanf("%d",&bsearchdata);

    bsearchFirst=0;
    bsearchLast=bsearchlen-1;

    while(bsearchFirst<bsearchLast){
        bsearchMid=(bsearchFirst+bsearchLast)/2;

        if(bsearchdata>bsearchList[bsearchMid]){
            bsearchFirst=bsearchMid+1;
        }
        else if(bsearchdata<bsearchList[bsearchMid]){
            bsearchLast=bsearchMid-1;
        }
        else if (bsearchdata==bsearchList[bsearchMid]){
            printf("\nSearched Data is Present at Position : %d\n",bsearchMid+1);
            bsearchflag=1;
            return;
        }
        else
            break;
        
    }
    if(bsearchflag==0)
    printf("Element is Not Present in List(Press Enter To Continue)");
    getch();

}


void main(){
    binarySearch();
}