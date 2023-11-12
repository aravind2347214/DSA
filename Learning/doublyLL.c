#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *right;
	struct node *left;
}*temp,*prev,*first,*last,*newptr,*next;

int create()
{
	char ch;
	while(1)
	{
		newptr=(struct node*) malloc(sizeof(struct node));
		printf("\nenter data");
		scanf("%d",&newptr->info);
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
		printf("want to add more elements");
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
	temp=first;
	printf("forward display:\n");
	while(temp!=NULL)
	{
		printf("%d  ",temp->info);
		temp=temp->right;
	}
}
void display_backward()
{
	temp=first;
	while(temp->right!=NULL)
	{
		temp=temp->right;
		last=temp;
	}
	temp=last;
	while(temp!=first)
	{
		printf("%d  ",temp->info);
		temp=temp->left;	
	}
	printf("<--[%d]-->",first->info);
}

void search(){
   
	int data;
	printf("Enter data to be Searched");
	scanf("%d",&data);
	temp = first;
	int pos = 0;
	int foundFlag=0;
		while(temp->right!=NULL)
	   {
		pos++;
		if(temp->info==data)
		{

			printf("Data found at position : %d ",pos);
			foundFlag=1;
			break;
		}
		temp=temp->right;
	}
	if(foundFlag==0){
		printf("Data is not in List");
	}
	

}

void insert_begining()
{
   newptr=(struct node*) malloc(sizeof(struct node)); 	  	
   printf("\nenter data ");
   scanf("%d",&newptr->info);
   newptr->left=NULL;
   first->left=newptr;
   newptr->right=first;
   first=newptr;
}

void insert_end()
{
   newptr=(struct node*) malloc(sizeof(struct node)); 	  	
   printf("\nenter data ");
   scanf("%d",&newptr->info);
	newptr->right=NULL;
   last->right=newptr;
	newptr->left=last;
	last=newptr;
}

void delete_begining()
{
	temp=first;
	first=first->right;
	first->left=NULL;
	temp->right=NULL;
	free(temp);
}

void delete_end()
{
	temp=last;
	last=last->left;
	last->right=NULL;
	temp->left=NULL;
	free(temp);
}

void delete_middle()
{
	int data;
	printf("enter data to be deleted");
	scanf("%d",&data);
	temp=first;
	while(temp->right!=NULL)
	{
		if(temp->info==data)
		{
			prev=temp->left;
			next=temp->right;
			prev->right=next;
			next->left=prev;
		   temp->left=NULL;
		   temp->right=NULL;
			free(temp);
			break;
		}
		temp=temp->right;
	}
	
}

void insert_middle()
{
	int pos,c;c=0;
	newptr=(struct node*) malloc(sizeof(struct node)); 
	printf("\nenter the position  at which data is to be entered");
	scanf("%d",&pos);	  	
	printf("\nenter data to be entered");
	scanf("%d",&newptr->info);
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
void main()
{
	int opt;
	opt=0;
	first=temp=NULL;
	while(1)
 {
	printf(" +-----------Menu---------+\n");
	printf(" | 1.Create               |\n");
	printf(" | 2.DisplayForward       |\n");
	printf(" | 3.DisplayBackward      |\n");
	printf(" | 4.Insert Begining      |\n");
	printf(" | 5.Insert Middle        |\n");
	printf(" | 6.Insert End           |\n");
	printf(" | 7.Delete Begining      |\n");
	printf(" | 8.Delete Middle        |\n");
	printf(" | 9.Delete End           |\n");
    printf(" | 10.Search Node         |\n");
	printf(" | 11.Exit                |\n");
    printf(" +------------------------+\n");
	printf("Enter your option");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:create();break;
		case 2:display_forward();break;
		case 3:display_backward();break;
		case 4:insert_begining();break;
		case 5:insert_middle();break;
		case 6:insert_end();break;
		case 7:delete_begining();break;
		case 8:delete_middle();break;
		case 9:delete_end();break;
		case 10:search();break;
		case 11:exit(0);
	}
	getch();
 }
}
