    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>

    struct Node {
        char name[10];
        int priority;
        struct Node* next;
    };

    struct Node* front = NULL;

    void NodeEnqueue() {
        struct Node* newptr = (struct Node*)malloc(sizeof(struct Node));
        if (newptr == NULL) {
            printf("Memory allocation error!!");
            return;
        }

        printf("\nEnter Name of new Node: ");
        scanf("%s", newptr->name);

        printf("Enter Priority of new Node: ");
        scanf("%d", &newptr->priority);

        newptr->next = NULL;

        if (front == NULL || newptr->priority < front->priority) {
            newptr->next = front;
            front = newptr;
        } else {
            struct Node* temp = front;
            while (temp->next != NULL && temp->next->priority <= newptr->priority) {
                temp = temp->next;
            }
            newptr->next = temp->next;
            temp->next = newptr;
        }

        printf("\nNode Enqueued with Priority %d!\n", newptr->priority);
    }

    void NodeDequeue() {
        if (front == NULL) {
            printf("\nThere are no Nodes in the Priority Queue!\n");
        } else {
            struct Node* temp = front;
            front = front->next;
            free(temp);
            printf("\nHighest Priority Node Dequeued!\n");
        }
    }

    void peekPriorityQueue() {
        struct Node* temp = front;

        if (temp == NULL) {
            printf("Priority Queue is Empty!\n");
            return;
        }

        printf("Priority Queue: ");
        while (temp != NULL) {
            printf("[%s, Priority: %d] <-- ", temp->name, temp->priority);
            temp = temp->next;
        }
        printf("NULL\n");
    }

    void showHighestPriorityItem(){
        printf("Highest Priority Node : %s",front->name);
    }

    int main() {
        int opt;

        while (1) {
            printf("\n");
            printf(" +-------Priority-Queue-Menu-------+\n");
            printf(" | 1. Enqueue Node with Priority |\n");
            printf(" | 2. Dequeue Highest Priority     |\n");
            printf(" | 3. Display Priority Queue       |\n");
            printf(" | 4. Show Highest Priority Item   |\n");
            printf(" | 5. Exit                         |\n");
            printf(" +---------------------------------+\n");
            printf("Enter your option : ");
            scanf("%d", &opt);

            switch (opt) {
                case 1:
                    NodeEnqueue();
                    break;
                case 2:
                    NodeDequeue();
                    break;
                case 3:
                    peekPriorityQueue();
                    break;
                case 4:
                    showHighestPriorityItem();
                    break;
                case 5:
                    exit(0);
                default:
                    printf("Invalid Option! Please try again.\n");
            }
        }

        return 0;
    }
