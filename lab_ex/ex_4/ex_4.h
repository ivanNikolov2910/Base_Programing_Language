#ifndef EX4_HEADER_FILE
#define EX4_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// func declaration
int sum(int, int);
void f1(int);
float area_square(float);
float area_rect(float, float);
float area_triangle(float, float);
float area_circle(float);
void swap(int, int);
int sumF_L(int);
int is_prime(int);

// exercises
//  1
void ex_1()
{
    printf("%d\n", sum(5, 7));
}

// 2
void ex_2()
{
    int num = 15;
    f1(num);
    printf("%d\n", num);
}

// 3 func area of cicle arg - R
void ex_3()
{
    double r;
    printf("r = ");
    scanf("%lf", &r);
    printf("Area of circle = %lf\n", area_circle(r));
}

// 4 int = code fig: 1 square, 2 rect, 3 pravoyg tri, 4 okr
void ex_4()
{
    int code;
    printf("code = ");
    scanf("%d", &code);
    float a, b;
    switch (code)
    {
    case 2:
        scanf("%f %f", &a, &b);
        printf("Figure is rectangle with area: %f\n", area_rect(a, b));
        break;
    case 1:
        scanf("%f", &a);
        printf("Figure is square with area: %f\n", area_square(a));
        break;
    case 3:
        scanf("%f %f", &a, &b);
        printf("Figure is right triangle with area: %f\n", area_triangle(a, b));
        break;
    case 4:
        float r;
        scanf("%f", &r);
        printf("Figure is circle with area: %f\n", area_circle(r));
        break;
    default:
        printf("Invalid code");
    }
}

// 5 swap 2 nums
void ex_5()
{
    int a = 5, b = 10;
    printf("original: a = %d, b = %d\n", a, b);
    swap(a, b);
    printf("swaped: a = %d, b = %d\n", a, b);
}

// 6 func return sum of first and last digits of num;
void ex_6()
{
    int num;
    printf("num = ");
    scanf("%d", &num);

    printf("%d\n", sumF_L(num));
}

// 7 print all prime nums between n and m prime_func;
void ex_7()
{
    int start = 0, end = 0;
    scanf("%d %d", &start, end);
    for (int i = start; i <= end; i++)
    {
        if (is_prime(i) == 1)
        {
            printf("%d\n", i);
        }
    }
}

// other functions
int sum(int a, int b)
{
    return a + b;
}

void f1(int a)
{
    a = 300;
}

float area_square(float a)
{
    return a * a;
}

float area_rect(float a, float b)
{
    return a * b;
}

float area_triangle(float a, float b)
{
    return a * b / 2;
}

float area_circle(float r)
{
    return M_PI * r * r;
}

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int sumF_L(int a)
{
    int last = a % 10;
    int first;
    while (a / 10 != 0)
    {
        a /= 10;
        first = a;
    }

    return last + first;
}

int is_prime(int num)
{
    int flag = 0;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

#endif