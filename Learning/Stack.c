#include<conio.h>
#include<stdio.h>

int stack[10],stackTop=-1,stackMax=10;
void stackPush(){
    if(stackTop== stackMax-1){
        printf("Stack is Full");
        getch();
        return;
    }
    else{
        printf("Enter Data To PUSH\n");
        scanf("%d",&stack[++stackTop]);
    }
}
void stackPop(){
    if(stackTop==-1){
        printf("\nStack is empty");
        getch();
        return;
    }
    printf("The deleted element is %d \n",stack[stackTop--]);

}
void stackDisplay(){
    if(stackTop==-1){
        printf("Stack is Empty\n");
        getch();
        return;
    }
    else{
        printf("STACK--(");
        for (int i = 0; i <=stackTop; i++)
        {printf("[%d]",stack[i]);} 
        printf(")");

    }
}


void main(){
    int subMenuOption;
    do
        {    
        printf("\n\nSTACK\n\n");
        printf("1.Push Element\n");
        printf("2.Pop Element\n");
        printf("3.Display Stack\n");
        printf("4.Back To MainMenu\n");
        printf("Choose Your Option :");
        scanf("%d",&subMenuOption);
        switch (subMenuOption)
            {
                case 1:
                    stackPush();
                    break;
                case 2:
                    stackPop();
                    break;
                case 3:
                    stackDisplay();    
                default:
                    break;
            }
        } while (subMenuOption!=4);
}