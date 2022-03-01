#ifndef SEM_EX2_HEADER_FILE
#define SEM_EX2_HEADER_FILE
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void ex_1()
{
    for (int i = 1; i <= 10; i++)
    {
        printf("%d ", i);
    }
}

void ex_2()
{
    for (int i = 0; i < 10; i++)
    {
        for (int j = 1; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void ex_3()
{
    for (int i = 0; i < 10; i++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < 3; i++)
    {
        printf("-");
        for (int j = 0; j < 8; j++)
        {
            printf(" ");
        }
        printf("-\n");
    }
    for (int i = 0; i < 10; i++)
    {
        printf("-");
    }
    printf("\n");
}

void ex_5()
{
    double inch;
    printf("Enter inches: ");
    scanf("%lf", &inch);
    printf("enter 1 for mm\n");
    printf("enter 2 for cm\n");
    printf("enter 3 for dm\n");
    printf("enter 4 for m\n");
    printf("enter 0 for stop\n");

    char cmd;
    while (1)
    {
        scanf("%s", &cmd);
        if (cmd == '0')
        {
            break;
        }
        else if (cmd == '1')
        {
            printf("%lf inch = %lf mm\n", inch, inch * 25.4);
        }
        else if (cmd == '2')
        {
            printf("%lf inch = %lf cm\n", inch, inch * 2.54);
        }
        else if (cmd == '3')
        {
            printf("%lf inch = %lf dm\n", inch, inch * 0.254);
        }
        else if (cmd == '4')
        {
            printf("%lf inch = %lf mm\n", inch, inch * 0.0254);
        }
        else
        {
            printf("wrong input command\n");
        }
        printf("Enter inches: ");
        scanf("%lf", &inch);
    }
}

void ex_6()
{
    float fahr;
    float cel;

    printf("enter celsius:");
    scanf("%f", &cel);
    printf("C\tF\n");

    fahr = cel * 9. / 5 + 32;
    printf("%d\t%.2f\n", cel, fahr);

    // 7
    float deg, rad;
    printf("Enter angle in Degrees\n");
    scanf("%f", &deg);
    rad = deg * (M_PI / 180.0);

    printf("%.2fdeg = %.4frad\n", deg, rad);
}

#endif