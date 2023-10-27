//  Without using string builtin functions, reverse the string
#include<conio.h>
#include<stdio.h>

void readString(char *str){
    printf("Enter String : ");
    gets(str);   
}

void reverseString(char *str){
    int len=0,i;
    char revstr[100];
    printf("\nThe Enterd String is : ");
    puts(str);
    for(i=0;str[i]!='\0';i++){
        len++;
    }
    int k;
   
    for(i=0,k=len-1;i<=len;i++){
        revstr[i]=str[k];
        k--;
    }
    printf("Reveresed String is : ");
    puts(revstr);

}

void main(){
    char string[100];
    readString(string);
    reverseString(string);
    getch();
}
