#include<conio.h>
#include<stdio.h>
int passengerCount=0;

struct Passenger
{
    int passno;
    char name[25];
    float titcketPrice;
}p[5];

// ---------------------------------------------------------
void addPassenger(){
    passengerCount++;
    if(passengerCount<5)
    {
        printf("\nEnter the passenger details:\n");
        printf("Enter Passenger Number: ");
        scanf("%d",&p[passengerCount].passno);
        printf("Enter Name of Passenger: ");
        gets(p[passengerCount].name);
        printf("Enter Ticket Price: ");
        scanf("%f",&p[passengerCount].titcketPrice);

    }
    else {
        printf("\nSorry, No more passengers can be added.");
    } 
}

// ---------------------------------------------------------
void displayPassenger(){
    if(passengerCount>0){
        printf("\n All Passengers");
        for (int i = 0; i < passengerCount-1 ; ++i){
            printf("\n\tPASSENGER %d DETAILS : \n",i+1);
            printf("\tPASSENGER NUMBER : %d ", p[i].passno);
            printf("\n\tNAME OF PASSENGER : %s ", p[i].name);
            printf("\n\tTICKET PRICE      : %.2f", p[i].titcketPrice);
        }
    }
    else{
        printf("\nNo Passengers to Display!");
    }
}

// ---------------------------------------------------------
void searchPassenger()
{
    int search_id;
    if(passengerCount==0)
    {
        printf("\nNo Passengers in Database!\n");
    }
    else
    {
        printf("\nSearch by ID: ");
        scanf("%d", &search_id);
        int found=0;
        for(int i=0; i<passengerCount && !found; i++)
        {
            if(p[i].passno == search_id)
            {
                printf("\n\tPASSENGER %d DETAILS : \n",i+1);
            }
        }
    }
}


// ---------------------------------------------------------



void main()
{
    int opt;
	opt=0;
	while(1)
 {
	printf(" +-----------Menu---------+\n");
	printf(" | 1.Add Passenger        |\n");
	printf(" | 2.Display Passenger    |\n");
	printf(" | 3.Search Passenger     |\n");
	printf(" | 4.Modify Ticket        |\n");
	printf(" | 5.Exit                 |\n");
    printf(" +------------------------+\n");
	printf("Enter your option");
	scanf("%d",&opt);
	switch(opt)
	{
		case 1:addPassenger();break;
		case 2:displayPassenger();break;
		case 3:searchPassenger();break;
		case 4:modifyTicket();break;
		case 5:exit(0);
	}
    getch();

}