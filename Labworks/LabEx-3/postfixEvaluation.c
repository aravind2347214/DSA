#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

char stack[100];
int top = -1;

void push(char x)
{
    if (top < 99)
    {
        stack[++top] = x;
    }
}

char pop()
{
    if (top >= 0)
    {
        return stack[top--];
    }
    return '\0'; // Return null character for empty stack
}

int evaluatePostfix(char exp[])
{
    int i, result;
    for (i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit(exp[i]))
        {
            push(exp[i] - '0'); // Push operand
        }
        else
        {
            int operand2 = pop();
            int operand1 = pop();
            switch (exp[i])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;

            case '/':
                result = operand1 / operand2;
                break;
            default:
                printf("Invalid operator!\n");
                exit(1);
            }
            push(result); // Push result
        }
    }
    result = pop(); // Result is the only element remaining in the stack
    return result;
}

int main()
{
    int opt;
    opt = 0;
    while (1)
    {
        char exp[100];
        printf("\n");
        printf(" +--------------Menu-------------+\n");
        printf(" | 1.Enter Postfix Expression    |\n");
        printf(" | 2.Evaluate Postfix Expression |\n");
        printf(" | 3.Exit                        |\n");
        printf(" +-------------------------------+\n");
        printf("Enter your option: ");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
        {
            printf("Enter the postfix expression: ");
            scanf("%s", exp);
            break;
        }
        case 2:
        {
            int result = evaluatePostfix(exp);
            printf("The result of the postfix expression is: %d\n", result);
            break;
        }
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid option!\n");
            break;
        }
    }
    return 0;
}