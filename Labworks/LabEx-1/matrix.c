
#include<conio.h>
#include<stdio.h>

struct worker{
    int id;
    char name[20];
    int workerSchedule[3][3];
}w[100];

void addWorkerData(struct worker * w,int id){
    printf("Enter the ID of Worker %d:\n",id+1);
    scanf("%d",&w->id);
    printf("\nEnter the Name of worker %d\n",id+1);
    scanf("%s",&w->name);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("\nEnter Schedule for day %d and time slot %d\n",i+1,j+1);
            scanf("%d",&w->workerSchedule[i][j]);
            }
        }
}

void showWorkerData(struct worker * w){
    printf("\n-------------Worker %d----------------",w->id);
    printf("\nName : %s \nID   :%d\n",w->name,w->id);
    printf("Day Time Slot Worker Schedule:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("[ %dhrs ]",w->workerSchedule[i][j]);
        }
        printf("\n");
    }
    printf("-------------------------------------\n");

}

void deleteWorkerData(int id, int *workerCount) {
    int i, j;
    printf("%d",*workerCount);

    // Find the index of the worker with the given ID
    int deleteIndex = -1;
    for (i = 0; i < 100; ++i) {
        if (w[i].id == id) {
            deleteIndex = i;
            break;
        }
    }

    if (deleteIndex == -1) {
        printf("Worker Not Found with ID %d\n", id);
        return;
    }

    // Shift the array to remove the deleted worker
    for (j = deleteIndex; j < (*workerCount) - 1; j++) {
        w[j] = w[j + 1];
    }

    // Decrement the count of workers
    (*workerCount)--;

    printf("\nWorker ID %d has been deleted.", id);
}


void addSchedule(struct worker *w1,struct worker *w2){
    printf("\nThe Sum of Hours Worker %d and Worker %d is \n",w1->id,w2->id);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("[%5dhrs]",w1->workerSchedule[i][j]+w2->workerSchedule[i][j]);
        }
        printf("\n");
    }

}

void subtractSchedule(struct worker *w1,struct worker *w2){
    printf("\nThe Difrence of Hours Worker %d and Worker %d is \n",w1->id,w2->id);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("[%5dhrs]",w1->workerSchedule[i][j]-w2->workerSchedule[i][j]);
        }
        printf("\n");
    }

}

void searchWorker(char *searchName){
    int i;
    // perform a linear search on the workers to check the name with search name 
    for (i = 0; i < 5; ++i) {
        if(!strcmp(w[i].name,searchName)){
            printf("\nWorker Found!!");
            showWorkerData(&w[i]);
            return;
        }
    }
    printf("Worker Not Present with Name %s\n",searchName);
}



void main(){
    
    int workerCount=0;
    int choice;

    do{
    choice=0;
    printf("\n+-------------Menu------------+\n");
    printf("| 1.Add Worker                |\n");
    printf("| 2.Show Workers              |\n");
    printf("| 3.Delete Worker             |\n");
    printf("| 4.Search Worker             |\n");
    if(workerCount+1>2){
    printf("| 5.Add Worker Schedule       |\n");
    printf("| 6.Subtract Worker Schedule  |\n"); 

    }
    printf("| 7.Exit Program              |\n");
    printf("+-----------------------------+\n"); 
    printf("\nEnter Choice : ");
    scanf("%d",&choice);

    if(choice==1){
        addWorkerData(&w[workerCount++],workerCount);
    }
    else if(choice==2){
        int i;
        for(i=0;i<workerCount;i++)
            showWorkerData(&w[i]);
    }
    else if(choice==3){
        int delId;
        printf("Enter ID of worker to be deleted : ");
        scanf("%d",&delId);
        deleteWorkerData(delId,&workerCount);
    }

    else if(choice==4){
        char searchName[10];
        printf("Enter name of the worker you want to find : ");
        scanf("%s",&searchName);
        searchWorker(searchName);
    }
    else if(choice==5){
        int addId1,addId2;
        repeatIDsToAdd:
            printf("\nEnter Existing ID of first worker to be Added : ");
            scanf("%d",&addId1);
            printf("\nEnter Existing ID of second worker to be Added : ");
            scanf("%d",&addId2);
            if(addId1>=workerCount+1 || addId1<0 ||addId2>workerCount+1 || addId2<0 ){
                printf("\nInvalid IDs");
                goto repeatIDsToAdd;
            }
            else{
                addSchedule(&w[addId1-1],&w[addId2-1]);  
            }
    }
        else if(choice==6){
        int subId1,subId2;
        repeatIDsToSub:
            printf("\nEnter Existing ID of first worker to be Subtracted : ");
            scanf("%d",&subId1);
            printf("\nEnter Existing ID of second worker to be Subtracted : ");
            scanf("%d",&subId2);
            if(subId1>=workerCount || subId1<0 ||subId2>=workerCount || subId2<0 ){
                printf("\nInvalid IDs");
                goto repeatIDsToSub;
            }
            else{
                subtractSchedule(&w[subId1-1],&w[subId2-1]);  
            }
    }

    }while(choice<7);
}