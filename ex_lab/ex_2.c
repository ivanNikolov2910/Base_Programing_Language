#include <stdio.h>
#include <stdlib.h>

int main()
{
    // char s = '1';
    // printf("%c\n", s);
    // printf("%c\n", s + 1);
    // printf("%c\n", s + 2);
    // printf("%c\n", s + 3);
    // printf("%c\n", s + 4);
    // printf("\n\n");

    // s = 'a';
    // printf("%c\n", s);
    // printf("%c\n", s + 1);
    // printf("%c\n", s + 2);
    // printf("%c\n", s + 3);
    // printf("%c\n", s + 4);
    // printf("\n\n");

    // s = 'A';
    // printf("%c\n", s);
    // printf("%c\n", s + 1);
    // printf("%c\n", s + 2);
    // printf("%c\n", s + 3);
    // printf("%c\n", s + 4);
    // printf("\n\n");

    // float a, b;
    // printf("Enter val A:", a);
    // scanf("%f", &a);
    // printf("Enter val B:", b);
    // scanf("%f", &b);
    // printf("Area = a*b = %.2f", a * b);

    // int a = 5;
    // printf("%d\n", a);
    // printf("%d\n", !a);
    // printf("%d\n", !!a);
    // printf("%d\n", !!!a);

    //порграма в която се четат 2 числа и се разменят стойностите на променливите без temp
    int a, b;
    printf("Enter val A:", a);
    scanf("%d", &a);
    printf("Enter val B:", b);
    scanf("%d", &b);
    printf("%d\t%d\n", a, b);
    a += b;
    b = a - b;
    a -= b;
    printf("%d\t%d\n", a, b);

    return 0;
}