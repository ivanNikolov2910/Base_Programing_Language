#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int array[], unsigned len)
{
    srand(time(NULL));

    for (int i = 0; i < len; ++i)
    {
        array[i] = rand();
    }
}

void printArray(int array[], unsigned len)
{
    for (int i = 0; i < len; ++i)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

unsigned fillArray(int dest[], int src[], unsigned len)
{
    unsigned j = 0;

    for (int i = 0; i < len; ++i)
    {
        if (src[i] % 10 == src[i] / 10 % 10)
        {
            dest[j++] = src[i];
        }
    }
    return j;
}

int firstDigit(int a)
{
    a = abs(a);
    while (a / 10 != 0)
    {
        a /= 10;
    }

    return a;
}

#endif // ARRAY_H_INCLUDED