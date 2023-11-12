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

void insert_begining(){
	newptr = (struct worker *)malloc( sizeof( struct worker ) );
	printf("\nEnter Name of new Worker : ");
	scanf("%s",&newptr->name);
	numberOfNodes++;
	newptr->right=NULL;
	if(first == NULL)
	{
		first=last=newptr;
    }
	else
	{
		newptr->right=first;
		first=newptr;
	}
}

void insert_end(){
	newptr=(struct worker*)malloc(sizeof(struct worker));
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

void insert_middle(){
	int pos,c;c=0;
	newptr=(struct worker*)malloc(sizeof(struct worker));
	printf("Enter Postion for worker to be inserted : ");
	scanf("%d",&pos);
	printf("\nEnter Name of new Worker : ");
	scanf("%s",&newptr->name);
	numberOfNodes++;
	temp= first;
	while (temp!=NULL)
	{
		c++;
		if(c==pos-1){
		   next=temp->right;
		   newptr->right=next;
		   temp->right=newptr;
		   break;
		}
		temp=temp->right;
	}
}

void delete_begining(){
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

void delete_end(){
	if(first==NULL){
		printf("\nThere are no Workers");
		return;
	}
	temp=first;
	while(temp->right!=NULL)
	{
		prev=temp;
		temp=temp->right;
		last=temp;
	}	     
	prev->right=NULL;
	last=prev;
    printf("\nLast Worker deleted\n");
	numberOfNodes--;
	free(temp);
}

void delete_middle(){
    if(first==NULL){
        printf("\nThere are no workers");
    }
    else{
        int pos, c; c = 0;
        printf("Enter the position of the worker you want to delete: ");
        scanf("%d", &pos);

        temp = first;
        while(temp->right != NULL){
            c++;
            if(c == pos - 1){
                prev = temp;
                next = temp->right->right;
                free(temp->right);
                prev->right = next;
                printf("\nWorker at position %d deleted\n", pos);
				numberOfNodes--;
                break;
            }
            temp = temp->right;
        }
    }
}

void search(){
	char search_name[25];
	int pos ,foundFlag=0;pos=0;
	temp = first;
	printf("\nEnter name of the worker you want to find : ");
	scanf("%s",&search_name);
	while(temp!=NULL){
		pos++;
		if(strcmpi(search_name,temp->name)==0){
			foundFlag =1;
			printf("\nWorker Found at %d",pos);
		}
		temp= temp->right;	
	}
	if(foundFlag==0){
		printf("\n\tNo such worker found!");
	}
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
	printf(" | 3.Insert Worker Begining    |\n");
	printf(" | 4.Insert Worker Middle      |\n");
	printf(" | 5.Insert Worker End         |\n");
	printf(" | 6.Delete Worker Begining    |\n");
	printf(" | 7.Delete Worker Middle      |\n");
	printf(" | 8.Delete Worker End         |\n");
	printf(" | 9.Search Worker             |\n");
	printf(" | 10.Exit                     |\n");
    printf(" +-----------------------------+\n");
	printf("enter your option");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:create();break;
		case 2:display();break;
		case 3:insert_begining();break;
		case 4:numberOfNodes>=2?insert_middle():printf("\nNeed More Than 1 Node\n");break;
		case 5:insert_end();break;
		case 6:delete_begining();break;
		case 7:numberOfNodes>=2?delete_middle():printf("\nNeed More Than 1 Node\n");break;
		case 8:delete_end();break;
		case 9:search();break;
		case 10:exit(0);
	}
	getch();
 }
}

