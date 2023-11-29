#include<stdio.h>
#include<conio.h>

int Cqueue[5],CqueueFront=-1,CqueueRear=-1,CqueueMax=5;
void CqueueInsert(){
    if((CqueueFront==0 && CqueueRear==CqueueMax-1) || (CqueueFront==CqueueRear+1)){
        printf("\nCircular Queue is FULL\n");
        getch();
        return;
    }
    else{
        if(CqueueFront==-1){
            CqueueFront=CqueueRear=0;
        }
        else{
            if(CqueueRear==CqueueMax-1){
                CqueueRear=0;
            }
            else{
                CqueueRear++;
            }

        }
        printf("\nEnter Data to be Inserted\n");
        scanf("%d",&Cqueue[CqueueRear]);

    }
    
}
void CqueueDisplay()
{
    if(CqueueFront==-1){
        printf("The Circular Queue is EMPTY");
        getch();
        return;
    }
    else{
        printf("CIRCULAR QUEUE--[");
        if(CqueueFront<=CqueueRear){
            for(int i=CqueueFront;i<=CqueueRear;i++){
                printf("(%d) ",Cqueue[i]);
            }
        }
        else{
            for(int i=0;i<=CqueueRear;i++){
                printf("(%d) ",Cqueue[i]);
            }
            for(int i=CqueueFront;i<=CqueueMax-1;i++){
                printf("(%d) ",Cqueue[i]);
            }
        }
        printf("]");


    }

}
void CqueueDelete(){
    if(CqueueFront==-1){
        printf("The Circular Queue is EMPTY");
        getch();
        return;
    }
    else{
        printf("The deleted Element is (%d)",Cqueue[CqueueFront]);
        if(CqueueFront==CqueueRear)
        {
            CqueueFront=-1;
            CqueueRear=-1;
        }
        else{
            if(CqueueFront==CqueueMax-1){
                CqueueFront=0;
            }
            else{
                CqueueFront++;
            }
        }
    }

}

void main()
{
     int opt;
	opt=0;
	while(1)
 {
	printf("\n");
	printf(" +-------Menu-----+\n");
	printf(" | 1.Enqueue      |\n");
    printf(" | 2.Dequeue      |\n");
	printf(" | 3.Show Queue   |\n");
    printf(" | 4.Exit         |\n");
    printf(" +----------------+\n");
	printf("Enter your option");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:CqueueInsert();break;
        case 2:CqueueDelete();break;
        case 3:CqueueDisplay();break;
        case 4:exit(0);break;
	  }
  }
}