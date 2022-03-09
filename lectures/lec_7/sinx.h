#ifndef SINX_H_INCLUDED
#define SINX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define EPS 1e-6
#define DELTA 0.01

double sinx(double x)
{
    double sum = 0;
    double member = x;
    unsigned fact = 3;

    for (int i = 1; i < 1000; ++i, fact += 2)
    {
        sum += member;
        member *= -x * x / ((fact - 1) * fact);
    }

    return sum;
}

double sinxAE(double x)
{
    double sum = 0;
    double member = x;
    double member1 = 0;
    unsigned fact = 3;
    int cnt = 0;

    while (fabs(member - member1) >= EPS)
    {
        sum += member;
        member1 = member;
        member *= -x * x / ((fact - 1) * fact);
        fact += 2;
        cnt++;
    }

    printf("counter: %d\n", cnt);
    return sum;
}

double sinxRE(double x)
{
    double sum = 0;
    double member = x;
    double member1 = 0;
    unsigned fact = 3;
    int cnt = 0;

    while (fabs((member - member1) / member) >= DELTA)
    {
        sum += member;
        member1 = member;
        member *= -x * x / ((fact - 1) * fact);
        fact += 2;
        cnt++;
    }

    printf("counter: %d\n", cnt);
    return sum;
}

#endif // SINX_H_INCLUDED