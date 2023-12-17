

#include<conio.h>
#include<stdio.h>
#include<stdlib.h>

struct node{
	int info;
	struct node *right;
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
		if(first==NULL)
		   first=temp=newptr;
		   else
			{
				temp->right=newptr;
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
void display()
{
	
	temp=first;
	printf("forward display:\n");
	while(temp!=NULL)
	{
		printf("[%d]-->",temp->info);
		temp=temp->right;
	}
}

void insert_begining()
{
	newptr=(struct node*) malloc(sizeof(struct node)); 	  	
   printf("\nenter data ");
   scanf("%d",&newptr->info);
   if(first==NULL)
      {first=temp=newptr;
	  first->right=NULL;}
	else
	{
      newptr->right=first;
      first=newptr;
   }
}

void insert_end()
{
	temp=first;
   newptr=(struct node*) malloc(sizeof(struct node)); 	  	
   printf("\nenter data ");
   scanf("%d",&newptr->info);
   if(first==NULL){
	first=temp=newptr;
	first->right=NULL;
   }
   else{
	temp=first;
	newptr->right=NULL;
	while(temp->right!=NULL)
	{
		temp=temp->right;
		last=temp;
	}	      
    last->right=newptr;
	last=newptr;
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
		if(c+1==pos)
		{  
		   next=temp->right;
		   newptr->right=next;
		   temp->right=newptr;
		   break;
		}
		temp=temp->right;
		
		}
}

void delete_begining()
{
	temp=first;
	first=first->right;
	temp->right=NULL;
    printf("\nFirst Element deleted\n");
	free(temp);
}

void delete_end()
{
	temp=first;
	while(temp->right!=NULL)
	{
		prev=temp;
		temp=temp->right;
	}	   
	last= prev->right;
	temp=last;  
	prev->right=NULL;
	last=prev;
    printf("\nLast Element deleted\n");
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
			prev->right=temp->right;
			free(temp);
			break;
		}
		else
		{
			prev=temp;
			temp=temp->right;
		}
	}
	
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

void main()
{
	int opt;
	opt=0;
	first=temp=NULL;
	while(1)
 {
    printf("\n");
	printf(" +----------Menu--------+\n");
	printf(" | 1.Create             |\n");
	printf(" | 2.Display            |\n");
	printf(" | 3.Insert Begining    |\n");
	printf(" | 4.Insert Middle      |\n");
	printf(" | 5.Insert End         |\n");
	printf(" | 6.Delete Begining    |\n");
	printf(" | 7.Delete Middle      |\n");
	printf(" | 8.Delete End         |\n");
	printf(" | 9.Search             |\n");
	printf(" | 10.Exit              |\n");
    printf(" +----------------------+\n");
	printf("enter your option");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:create();break;
		case 2:display();break;
		case 3:insert_begining();break;
		case 4:insert_middle();break;
		case 5:insert_end();break;
		case 6:delete_begining();break;
		case 7:delete_middle();break;
		case 8:delete_end();break;
		case 9:search();break;
		case 10:exit(0);
	}
	getch();
 }
}

