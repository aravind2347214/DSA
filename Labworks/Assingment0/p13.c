// Read a string and check whether the given character
//  is present or not. If present, count the number of times, it is repeated
#include<conio.h>
#include<stdio.h>

void readString(char *str){
    printf("Enter String : ");
    gets(str);   
}

void showString(char *str){
    printf("\nThe Enterd String is : ");
    puts(str);
}

void searchChar(char *str ,char ch){
    int count=0,i;
    for(i=0;str[i]!='\0';i++){
        if(ch==str[i]){
            count++;
        }
    }

    if(count!=0)
        printf("\nThe Character '%c' occurs %d times",ch,count);
    else
        printf("\nEntered Character '%c' is not present",ch);

}

void main(){
    char string[100];char ch;
    readString(string);
    printf("Enter Character to search : ");
    scanf("%c",&ch);
    showString(string);
    searchChar(string,ch);
    getch();
}
