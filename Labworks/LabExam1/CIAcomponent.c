#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct process{
	int priority;
	char state[10];
	int pid;
	struct process *right;
}*first,*temp,*newptr,*last,*next,*prev,*curr;

void insertProcess(){
	
	newptr=(struct process*)malloc(sizeof(struct process));
	if(newptr==NULL){
		printf("\nMemory Allocation Error!!");
		return;
	}
	else{
		printf("Enter Process ID : ");
		scanf("%d",&newptr->pid);
		
		printf("Enter Process State : ");
		scanf("%s",&newptr->state);
		
        priorityCheck:
            printf("Enter Process Priority : ");
            scanf("%d",&newptr->priority);
            if(newptr->priority<0){
                printf("\nInvalid Input! Enter a positive number.\n");
                goto priorityCheck;
            }
            
		newptr->right=NULL;
		
		if(first==NULL||newptr->priority<first->priority){
			newptr->right=first;
			first=newptr;
		}
		else{
			temp=first;
			while(temp!=NULL){
				if(first->right==NULL){
					first->right=newptr;
					newptr->right=NULL;
					break;
				}
				else if(temp->right!=NULL && newptr->priority<=temp->right->priority){
					newptr->right=temp->right;
					temp->right=newptr;
					break;
				}
				else if(temp->right==NULL){
					temp->right=newptr;
					break;
				}
				else{
					temp=temp->right;
				}
				
			}
		}
	}
	
}

void displayProcesses(){
	temp=first;
	printf("\n[Process ID | Process State | Process Priority]\n\n");
	while(temp!=NULL){
		printf("[%d | %s |%d]\n",temp->pid,temp->state,temp->priority);
		temp=temp->right;
	}
	
}

void displayHighestPriorityProcess(){
	printf("\nProcess With Highest Priority");
	printf("\n[%d | %s |%d]",first->pid,first->state,first->priority);
}

void killDeadProcess(){
	
	temp=first->right;
	while(temp->right!=NULL){
		prev=temp;
	    next=temp->right->right;
		if(strcmpi(temp->right->state,"dead")==0){
			temp->right=next;	
		}
		temp=temp->right;
	}
	
	temp=first;
	if(strcmpi(first->state,"dead")==0){
		first=first->right;
		free(temp);
	}
	displayProcesses();
		
}


int main(){
	
	int opt;
	char ch;
	while(1)
	{
		printf("\n------Menu--------");
		printf("\n1.Add Process");
		printf("\n2.Display Process");
		printf("\n3.Display Process with Highest Priority");
	    printf("\n4.Kill Dead Process");
		printf("\n4.Exit");
		printf("\n---------------------");
		printf("\nEnter Option : ");
		scanf("%d",&opt);
		switch(opt){
			case 1:insertProcess();break;
			case 2:displayProcesses();break;
			case 3:displayHighestPriorityProcess();break;
			case 4:killDeadProcess();break;
			case 5:exit(0);
		}
	}
	return 0;
}