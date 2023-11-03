// Without using string builtin functions, calculate the string length

#include<conio.h>
#include<stdio.h>

void readString(char *str){
    printf("Enter String : ");
    gets(str);   
}

void findLength(char *str){
    int len=0,i;
    printf("\nThe Enterd String is : ");
    puts(str);
    for(i=0;str[i]!='\0';i++){
        len++;
    }
    printf("Length is String : %d characters",len);

}

void main(){
    char string[100];
    readString(string);
    findLength(string);
    getch();
}
