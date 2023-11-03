// Read and display a string
#include<conio.h>
#include<stdio.h>

void readString(char *str){
    printf("Enter String : ");
    gets(str);   
}

void showString(char *str){
    printf("\n\nThe Enterd String is : ");
    puts(str);
}

void main(){
    char string[100];
    readString(string);
    showString(string);
    getch();
}