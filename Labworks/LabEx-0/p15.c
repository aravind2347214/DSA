//  Implement bubble sort for n names
#include<conio.h>
#include<stdio.h>

void readNames(char names[][50], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter name %d: ", i + 1);
        scanf("%s", names[i]);
    }
}

// Function to display names
void showNames(char names[][50], int n) {
    printf("Names you entered:\n");
    for (int i = 0; i < n; i++) {
        printf("Name %d: %s\n", i + 1, names[i]);
    }
}

void bubbleSort(char names[][50], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(names[j], names[j + 1]) > 0) {
                // Swap the names if they are out of order
                char temp[50];
                strcpy(temp, names[j]);
                strcpy(names[j], names[j + 1]);
                strcpy(names[j + 1], temp);
            }
        }
    }
}



void main(){
    int n;
    printf("Enter the number of names you want to read: ");
    scanf("%d", &n);
    char names[n][60];
    readNames(names, n);
    bubbleSort(names,n);
    showNames(names, n);
    getch();
}