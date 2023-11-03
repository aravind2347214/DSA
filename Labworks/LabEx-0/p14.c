// Read and display n names
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

void main() {
    int n;
    printf("Enter the number of names you want to read: ");
    scanf("%d", &n);
    char names[n][60];
    readNames(names, n);
    showNames(names, n);
    getch();
}