#include<stdio.h>
int workersIds[10];
    int size=10;
    int front,rear;
    int maxElement=0,sum=0;
    float avg;
    front=-1;
    rear=-1;


void enqueue(){
    int data;
    if(rear==size-1){
        printf("OVERFLOW");
    }
    else{
        if(front==-1){
            front=0;
            rear=0;
        }
        printf("\nEnter Worker ID :");

        scanf("%d",&data);
        workersIds[rear++]=data;
        sum=sum+data;
        
    }

}

void dequeue(){
    if(front==-1||front>rear){
        printf("\nUNDERFLOW");
        return;
    }
    sum = sum - workersIds[front];
    printf("[%d] element is deleted",workersIds[front++]);
}

void show(){
    int i;
    if(front==-1){
        printf("\nUNDERFLOW");
        return;
    }
    maxElement=workersIds[front];
    for(i=front;i<rear;i++){
        if(maxElement<workersIds[i]){
            maxElement=workersIds[i];
        }
        printf("[%d] ",workersIds[i]);
        }
    avg=sum/(rear-front);
    printf("\n Sum : %d",sum);
    printf("\n Max Element : %d",maxElement);
    printf("\n Average : %f",avg);
    }

void revqueue(){
    int i;
    for ( i = rear-1; i >=front; i--)
    {
         printf("[%d] ",workersIds[i]);
    } 
}

void sortqueue(){
    int i,j,bsortTemp;
        for(int i=front;i<rear;i++){
        for(int j=0;j<rear-i-1;j++){
            if(workersIds[j]>workersIds[j+1]){
                bsortTemp=workersIds[j];
                workersIds[j]=workersIds[j+1];
                workersIds[j+1]=bsortTemp;
            }
        }
    }
}

void main(){
    
    int opt;
	opt=0;
	while(1)
 {
	printf("\n");
	printf(" +--------------Menu-------------+\n");
	printf(" | 1.Add Worker Id               |\n");
    printf(" | 2.Delete Worker Id            |\n");
	printf(" | 3.Show Worker Ids             |\n");
    printf(" | 4.Reverse Queue               |\n");
    printf(" | 5.Sort                        |\n");
    printf(" | 6.Exit                        |\n");
    printf(" +-------------------------------+\n");
	printf("Enter your option");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:enqueue();break;
        case 2:dequeue();break;
        case 3:show();break;
        case 4:revqueue();break;
        case 5:sortqueue();break;
        case 6:exit(0);break;
	  }
  }
}
