#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
    char data[10];
    struct Node *right;
}*newptr,*first,*last,*temp,*prev,*next;

int numberOfNodes=0;


int create(){
    char ch;
	while(1)
	{
		newptr=(struct Node*) malloc(sizeof(struct Node));
		if(newptr==NULL){
				printf("Memory allocation error");
				return 0;
			}
		printf("\nEnter data of Node");
		scanf("%s",&newptr->data);
		numberOfNodes++;
		newptr->right=NULL;
		if(first==NULL)
		   first=temp=newptr;
		   else
			{
				temp->right=newptr;
				temp=temp->right;
			}
		printf("want to add more Nodes(Y/N)");
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
        printf("There are no Nodes\n"); 
        return;
    }
    while(temp != NULL) {
        printf("[%s]--->",temp -> data );
        temp = temp-> right ;
    }
	printf("NULL \n");
}

void enqueue(){
	newptr=(struct Node*)malloc(sizeof(struct Node));
	if(newptr==NULL){
		printf("Memory allocation error");
		return;
	}
	printf("\nEnter data of new Node : ");
	scanf("%s",&newptr->data);
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
		printf("\nThere are no Nodes");
	}
	else{
		temp = first;
		first = first -> right;
		free(temp);
		numberOfNodes--;
		printf("\nFirst Node deleted\n");


	}
}

void exit_program(){
    temp = first;
    while (temp != NULL) {
        struct Node* nextNode = temp->right;
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
	printf(" +---------Node-Menu---------+\n");
	printf(" | 1.Create Nodes Queue      |\n");
	printf(" | 2.Display Nodes Queue     |\n");
	printf(" | 3.Enqueue Nodes           |\n");
	printf(" | 4.Dequeue Nodes           |\n");
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

