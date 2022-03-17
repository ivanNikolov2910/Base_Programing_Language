#ifndef EX5_HEADER_FILE
#define EX5_HEADER_FILE

#include <stdio.h>

// func declaration
void swap(int *a, int *b);
void changeif(int *num);

void zad_0()
{
    int a = 10;
    int *p_a = &a;
    printf("addr of a = %xd\n", p_a);
    printf("val a = %d\n", *p_a);
}

// zad 1 - double *p of int x
void zad_1()
{
    // int x;
    // double *p = &x;
    // *p = 24.50;
    // printf("val of x = %d", x);
}

// zad 2 - def 3p (int, double, char) && 3 var (int, double, char), print *p val, p++ and print p val
void zad_2()
{
    int i, *p_i = &i;
    double d, *p_d = &d;
    char c, *p_c = &c;
    *p_i = 10;
    *p_d = 3.156;
    *p_c = 'A';

    printf("val of i = %d\n", *p_i);
    printf("val of d = %lf\n", *p_d);
    printf("val of c = %c\n\n", *p_c);

    printf("p of i = %x\n", p_i);
    printf("p of d = %x\n", p_d);
    printf("p of c = %x\n\n", p_c);

    p_i++;
    p_d++;
    p_c++;

    printf("p of i = %x\n", p_i);
    printf("p of d = %x\n", p_d);
    printf("p of c = %x\n\n", p_c);
}

// zad 3 - swap 2 vars
void zad_3()
{
    int a = 5, b = 10;
    swap(&a, &b);

    printf("swapped: a = %d, b = %d\n", a, b);
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// zad 4 - void func(int a) -> if a < 1000 => *10; == 1000 => +10; > 1000 => /10

void zad_4()
{
    int num;
    scanf("%d", &num);
    printf("%d\n", num);
    changeif(&num);
    printf("%d\n", num);
}

void changeif(int *num)
{
    if (*num < 1000)
    {
        *num *= 10;
    }
    if (*num > 1000)
    {
        *num /= 10;
    }
    if (*num == 1000)
    {
        *num += 10;
    }
}

#endif