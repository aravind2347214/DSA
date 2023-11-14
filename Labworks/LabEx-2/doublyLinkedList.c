#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct worker{
	char name[10];
	struct worker *right;
	struct worker *left;
}*temp,*prev,*first,*last,*newptr,*next;

int numOfNodes = 0;

int create()
{
	char ch;
	while(1)
	{
		newptr=(struct worker*) malloc(sizeof(struct worker));
		if(newptr==NULL){
			printf("Memory allocation error");
			return 0;
		}
		printf("\nEnter Name of worker : ");
		scanf("%s",&newptr->name);
		numOfNodes++;
		newptr->right=NULL;
		newptr->left=NULL;
		if(first==NULL)
		   first=temp=newptr;
		   else
			{
				temp->right=newptr;
				newptr->left=temp;
				temp=temp->right;
			}
		printf("Want to add more Workers(Y/N) : ");
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
void display_forward()
{
	if(first==NULL){
		printf("There are no workers\n");
		return;
	}
	temp=first;
	printf("Forward Display of Workers : \n");
	printf("NULL");
	while(temp!=NULL)
	{
		printf("<--[%s]-->",temp->name);
		temp=temp->right;
	}
	printf("NULL\n");
}

void display_backward()
{
	if(first==NULL){
		printf("There are no workers\n");
		return;
	}
	temp=first;
    printf("Reverse Display of Workers : \n");
	while(temp->right!=NULL)
	{
		temp=temp->right;
		last=temp;
	}
	temp=last;
	printf("NULL");
	while(temp!=NULL)
	{
		printf("<--[%s]-->",temp->name);
		temp=temp->left;	
	}
	// printf("<--[%s]-->",first->name);
	printf("NULL\n");
}

void search(){
	if(first==NULL){
		printf("There are no workers\n");return;
	}
	char search_name[10];
	printf("Enter Worker Name to be Searched : ");
	scanf("%s",&search_name);
	temp = first;
	int pos = 0;
	int foundFlag=0;
		while(temp->right!=NULL)
	   {
		pos++;
		if(strcmpi(search_name,temp->name)==0)
		{

			printf("Worker found at position : %d ",pos);
			foundFlag=1;
			break;
		}
		temp=temp->right;
	}
	if(foundFlag==0){
		printf("Worker is not in List");
	}
	

}

void insert_begining()
{
   newptr=(struct worker*) malloc(sizeof(struct worker)); 
   if(newptr==NULL){
		printf("Memory allocation error");
		return 0;
	}	  	
   printf("\nEnter Worker Name ");
   scanf("%s",&newptr->name);
   numOfNodes++;
   newptr->left=NULL;
   first->left=newptr;
   newptr->right=first;
   first=newptr;
   printf("\nWorker Added At Begining");
}

void insert_end()
{
   newptr=(struct worker*) malloc(sizeof(struct worker)); 
   if(newptr==NULL){
		printf("Memory allocation error");
		return 0;
	}	  	
   printf("\nEnter Worker Name : ");
   scanf("%s",&newptr->name);
   numOfNodes++;
	newptr->right=NULL;
    last->right=newptr;
	newptr->left=last;
	last=newptr;
	printf("\nWorker Added At end");
}

void delete_begining()
{
	if(first==NULL){
		printf("There are no workers\n");return;
	}
	temp=first;
	first=first->right;
	first->left=NULL;
	temp->right=NULL;
	free(temp);
	numOfNodes--;
	printf("\nWorker Deleted from Begining");
}

void delete_end()
{

	if(first==NULL){
		printf("There are no workers\n");return;
	}
	temp=last;
	last=last->left;
	last->right=NULL;
	temp->left=NULL;
	numOfNodes--;
	free(temp);
	printf("\nWorker Deleted from end");

}


void delete_middle(){
    if(first==NULL){
        printf("\nThere are no workers");
    }
    else{
        int pos, c; c = 0;
        printf("Enter the position of the worker you want to delete : ");
        scanf("%d", &pos);

        temp = first;
        while(temp->right != NULL){
            c++;
            if(c == pos){
                prev= temp->left;
				next = temp->right;
				prev->right = next;
				next->left = prev;
				temp->left=NULL;
		        temp->right=NULL;  
				free(temp);
                printf("\nWorker at position %d deleted\n", pos);
				numOfNodes--;
                break;
            }
            temp = temp->right;
        }
    }
}


void insert_middle()
{
	int pos,c;c=0;
	newptr=(struct worker*) malloc(sizeof(struct worker));
	if(newptr==NULL){
		printf("Memory allocation error");
		return 0;
	} 
	printf("\nEnter the position  at which insert Worker : ");
	scanf("%d",&pos);	  	
	printf("\nEnter Worker Name : ");
	scanf("%s",&newptr->name);
	numOfNodes++;
	temp=first;
	while(temp->right!=NULL)
	{
		c++;
		if(c==pos)
		{
			prev=temp->left;
			prev->right=newptr;
			newptr->left=prev;
			temp->left=newptr;
			newptr->right=temp;
		}
		temp=temp->right;
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
	printf(" | 1.Create Workers            |\n");
	printf(" | 2.Display Workers           |\n");
    printf(" | 3.Display Workers Reverse   |\n");
	printf(" | 4.Insert Worker Begining    |\n");
	printf(" | 5.Insert Worker Middle      |\n");
	printf(" | 6.Insert Worker End         |\n");
	printf(" | 7.Delete Worker Begining    |\n");
	printf(" | 8.Delete Worker Middle      |\n");
	printf(" | 9.Delete Worker End         |\n");
	printf(" | 10.Search Worker            |\n");
	printf(" | 11.Exit                     |\n");
    printf(" +-----------------------------+\n");
	printf("Enter your option");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:create();break;
		case 2:display_forward();break;
		case 3:display_backward();break;
		case 4:insert_begining();break;
		case 5:numOfNodes>=2?insert_middle():printf("\nNeed More Than 1 Node\n");break;
		case 6:insert_end();break;
		case 7:delete_begining();break;
		case 8:numOfNodes>=2?delete_middle():printf("\nNeed More Than 1 Node\n");break;
		case 9:delete_end();break;
		case 10:search();break;
		case 11:exit_program();
	}
	getch();
 }
}
