#include<stdio.h>

#include<stdlib.h>

main()

{

    int *a;

    a=(int*)malloc(sizeof(int));

    *a=100;

    printf("*a%d",*a);

    // free(a);

    a=(int*)malloc(sizeof(int));

    *a=200;

    printf("a%p",a);

    *a=200;

    printf("a%d",*a);

}