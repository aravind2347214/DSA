#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* top = NULL;

void push() {
    int value;
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    printf("Enter value to push: ");
    scanf("%d", &value);
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    new_node->data = value;
    new_node->next = top;
    top = new_node;
    printf("Pushed: %d\n", value);
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty. Cannot pop.\n");
        return;
    }
    struct node* temp = top;
    top = top->next;
    printf("Popped: %d\n", temp->data);
    free(temp);
}

void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    struct node* current = top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void peep(){
    printf("Topmost Data : %d",top->data);
}

int main() {
    int choice;
    char value;

    while (1) {
        printf("\n----- Stack Menu -----\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4.Peep\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peep();
            break;
        case 5:
            printf("Exiting the program.\n");
            exit(0);
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}
