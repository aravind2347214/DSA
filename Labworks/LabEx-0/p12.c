// Without using string builtin functions, copy one string into other

#include<conio.h>
#include<stdio.h>

void readString(char *str){
    printf("Enter String : ");
    gets(str);   
}

void copyString(char *str){
    int len=0,i;
    char newstr[100];
    printf("\nThe Enterd String is : ");
    puts(str);
    for(i=0;str[i]!='\0';i++){
        len++;
    }
    
    for(i=0;i<=len;i++){
        newstr[i]=str[i];
    }
    printf("New String :");
    puts(newstr);

}

void main(){
    char string[100];
    readString(string);
    copyString(string);
    getch();
}
