#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct worker{
    char name[10];
    struct worker *right;
}*newptr,*first,*last,*temp,*prev,*next;

int numberOfNodes=0;


int create(){
    char ch;
	while(1)
	{
		newptr=(struct worker*) malloc(sizeof(struct worker));
		if(newptr==NULL){
				printf("Memory allocation error");
				return 0;
			}
		printf("\nEnter Name of worker");
		scanf("%s",&newptr->name);
		numberOfNodes++;
		newptr->right=NULL;
		if(first==NULL)
		   first=temp=newptr;
		   else
			{
				temp->right=newptr;
				temp=temp->right;
			}
		printf("want to add more workers(Y/N)");
		ch=getch();
		if(ch=='n'||ch=='N')
         return(0);	
	temp=first;
	while(temp->right!=NULL)
	{
		temp=temp->right;
		last=temp;
	}	      
  }
}


void display(){
    temp= first;
    if(temp==NULL){
        printf("There are no workers\n"); 
        return;
    }
    while(temp != NULL) {
        printf("[%s]--->",temp -> name );
        temp = temp-> right ;
    }
	printf("NULL \n");
}

void enqueue(){
	newptr=(struct worker*)malloc(sizeof(struct worker));
	if(newptr==NULL){
		printf("Memory allocation error");
		return;
	}
	printf("\nEnter Name of new Worker : ");
	scanf("%s",&newptr->name);
	numberOfNodes++;
	newptr->right=NULL;
	temp= first;
	while(temp!=NULL){
		last=temp;
		temp=temp->right;
	}
	last->right=newptr;
	newptr->right=NULL;
}

void dequeue(){
	if(first==NULL){
		printf("\nThere are no Workers");
	}
	else{
		temp = first;
		first = first -> right;
		free(temp);
		numberOfNodes--;
		printf("\nFirst Worker deleted\n");


	}
}

void exit_program(){
    temp = first;
    while (temp != NULL) {
        struct worker* nextNode = temp->right;
        free(temp);
        temp = nextNode;
    }
	exit(0);
}


void main()
{
	int opt;
	opt=0;
	first=temp=NULL;
	while(1)
 {
    printf("\n");
	printf(" +---------Worker-Menu---------+\n");
	printf(" | 1.Create Workers Queue      |\n");
	printf(" | 2.Display Workers Queue     |\n");
	printf(" | 3.Enqueue Workers           |\n");
	printf(" | 4.Dequeue Workers           |\n");
	printf(" | 5.Exit                      |\n");
    printf(" +-----------------------------+\n");
	printf("enter your option");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:create();break;
		case 2:display();break;
		case 3:enqueue();break;
		case 4:dequeue();break;
		case 10:exit_program();
	}
	getch();
 }
}

