
#include<conio.h>
#include<stdio.h>

// creation of a worker structure 
struct worker{
    int id;
    char name[20];
    int workerSchedule[3][3];//3 time 3 day hours of working
}w[100];

// Function to add a new worker
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

// Function to show the data of a single worker
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

// To delete a particular worker based on ID
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

// Add Schedule of 2 Workers 2D array addition
void addSchedule(struct worker * w1,struct worker * w2){
    printf("\nThe Sum of Hours Worker %d and Worker %d is \n",w1->id,w2->id);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("[%5dhrs]",w1->workerSchedule[i][j]+w2->workerSchedule[i][j]);
        }
        printf("\n");
    }

}

// Subtract schedule of 2 Workers 2D array subtraction
void subtractSchedule(struct worker *w1,struct worker *w2){
    printf("\nThe Difrence of Hours Worker %d and Worker %d is \n",w1->id,w2->id);
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            printf("[%5dhrs]",w1->workerSchedule[i][j]-w2->workerSchedule[i][j]);
        }
        printf("\n");
    }

}

// To perform Linear Search on the Array of structures
void searchWorker(char *searchName,int workerCount){
    int i;
    for (i = 0; i < workerCount; ++i) {
        if(!strcmp(w[i].name,searchName)){
            printf("\nWorker Found!!");
            showWorkerData(&w[i]);
            return;
        }
    }
    // when given ID does not match
    printf("Worker Not Present with Name %s\n",searchName);
}

struct worker * checkIdPresence(int searchId,int workerCount){
    int i;
    for (i = 0; i < workerCount; ++i) {
        if(w[i].id==searchId){
            return &w[i];
        }
    }
    return NULL;
}



void main(){
    
    int workerCount=0;
    int choice;

    do{
    choice=0;
    // Menu on worker management
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


    // choice based if-else-if ladder
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
        searchWorker(searchName,workerCount);
    }
    else if(choice==5){
        // obtaining 2 IDs to perform addition
        int addId1,addId2;
            printf("\nEnter Existing ID of first worker to be Added : ");
            scanf("%d",&addId1);
            struct worker *aw1 = checkIdPresence(addId1,workerCount);
            printf("\nEnter Existing ID of second worker to be Added : ");
            scanf("%d",&addId2);
            struct worker *aw2 = checkIdPresence(addId2,workerCount);

            if(aw1&&aw2)
                addSchedule(aw1,aw2);  
            else
                printf("\nInvalid IDs");
            


    }
    else if(choice==6){
         // obtaining 2 IDs to perform subtraction
        int subId1,subId2;
            printf("\nEnter Existing ID of first worker to be Subtracted : ");
            scanf("%d",&subId1);
            struct worker *sw1 = checkIdPresence(subId1,workerCount);
            printf("\nEnter Existing ID of second worker to be Subtracted : ");
            scanf("%d",&subId2);
            struct worker *sw2 = checkIdPresence(subId2,workerCount);

             if(sw1&&sw2)
                subtractSchedule(sw1,sw2);  
            else
                printf("\nInvalid IDs");

    }
    // do-while running till exit condition of (7)
    }while(choice<7);
}