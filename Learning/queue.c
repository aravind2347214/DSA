#include <stdio.h>
int queue[10];
int size = 10;
int front, rear;
front = -1;
rear = -1;

void enqueue()
{
    int data;
    if (rear == size - 1)
    {
        printf("OVERFLOW");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        printf("\nEnter Data :");

        scanf("%d", &data);
        queue[rear++] = data;
    }
}

void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("\nUNDERFLOW");
        return;
    }
    printf("[%d] element is deleted", queue[front++]);
}

void show()
{
    int i;
    if (front == -1)
    {
        printf("\nUNDERFLOW");
        return;
    }
    for (i = front; i < rear; i++)
    {

        printf("[%d] ", queue[i]);
    }
}

void revqueue()
{
    int i;
    for (i = rear - 1; i >= front; i--)
    {
        printf("[%d] ", queue[i]);
    }
}

void sortqueue()
{
    int i, j, bsortTemp;
    for (int i = front; i < rear; i++)
    {
        for (int j = 0; j < rear - i - 1; j++)
        {
            if (queue[j] > queue[j + 1])
            {
                bsortTemp = queue[j];
                queue[j] = queue[j + 1];
                queue[j + 1] = bsortTemp;
            }
        }
    }
}

void main()
{

    int opt;
    opt = 0;
    while (1)
    {
        printf("\n");
        printf(" +--------------Menu-------------+\n");
        printf(" | 1.Add Data Id               |\n");
        printf(" | 2.Delete Data Id            |\n");
        printf(" | 3.Show Data Ids             |\n");
        printf(" | 4.Reverse Queue               |\n");
        printf(" | 5.Sort                        |\n");
        printf(" | 6.Exit                        |\n");
        printf(" +-------------------------------+\n");
        printf("Enter your option");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            show();
            break;
        case 4:
            revqueue();
            break;
        case 5:
            sortqueue();
            break;
        case 6:
            exit(0);
            break;
        }
    }
}
