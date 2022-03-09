#ifndef EX4_HEADER_FILE
#define EX4_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

double get_max(double a, double b)
{
    double const EPS = 1e-6;
    if (fabs(a - b) < EPS)
    {
        return a;
    }
    else if (a > b)
    {
        return a;
    }
    else
        return b;
}

double get_min(double a, double b)
{
    double const EPS = 1e-6;
    if (fabs(a - b) < EPS)
    {
        return a;
    }
    else if (a < b)
    {
        return a;
    }
    else
        return b;
}

void plus_15min(int h, int min)
{
    char str_min[2];
    min += 15;
    if (min >= 60)
    {
        min -= 60;
        ++h;
    }
    if (min / 10 < 1)
    {
        printf("%d:0%d", h, min);
    }
    else
        printf("%d:%d", h, min);
}

void is_3_eq(double a, double b, double c)
{
    double const EPS = 1e-6;
    if (fabs(a - b) < EPS && fabs(a - c) < EPS && fabs(c - b) < EPS)
    {
        printf("yes");
        return;
    }
    printf("no");
}

float get_points(int point1)
{
    float bonus = 0, bonus2 = 0;
    if (point1 <= 100)
    {
        bonus += 5;
    }
    else if (point1 > 100 && point1 <= 1000)
    {
        bonus = point1 * 20 / 100;
    }
    else if (point1 > 1000)
    {
        bonus = point1 * 10 / 100;
    }

    if (point1 % 2 == 0)
    {
        ++bonus2;
    }
    if (point1 % 10 == 5)
    {
        bonus2 += 5;
    }
    printf("%.2f\n", bonus2 + bonus);
    return point1 += bonus + bonus2;
}

void get_time_race(int a, int b, int c)
{
    int sum_sec = a + b + c;
    int min = 0;
    if (sum_sec >= 60)
    {
        ++min;
        sum_sec -= 60;
    }
    if (sum_sec / 10 < 1)
    {
        printf("%d:0%d", min, sum_sec);
    }
    else
        printf("%d:%d", min, sum_sec);
}

double get_cheapest(int n, char time)
{
    float taxi, bus, train;
    if (time == 'D')
    {
        taxi = n * 0.79 + 0.7;
    }
    if (time == 'N')
    {
        taxi = n * 0.9 + 0.7;
    }
    if (n >= 20)
    {
        bus = n * 0.09;
    }
    if (n >= 100)
    {
        train = n * 0.06;
    }
    printf("Taxi: %.2f\n", taxi);
    printf("Bus: %.2f\n", bus);
    printf("Train: %.2f\n", train);

    if (n < 20)
    {
        return taxi;
    }
    if (n > 20 && n < 100)
    {
        return get_min(taxi, bus);
    }
    float min_pr1 = get_min(taxi, bus), min_pr2 = get_min(bus, train);
    if (min_pr1 > min_pr2)
    {
        return min_pr2;
    }
    else
        return min_pr1;
}

void get_freq(int n)
{
    srand(time(NULL));
    int num, p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;
    while (n)
    {
        num = rand() % 1000;
        if (num < 200)
        {
            ++p1;
        }
        else if (num >= 200 && num < 400)
        {
            ++p2;
        }
        else if (num >= 400 && num < 600)
        {
            ++p3;
        }
        else if (num >= 600 && num < 800)
        {
            ++p4;
        }
        else if (num >= 800)
        {
            ++p5;
        }
        n--;
    }
    printf("%d\n", p1);
    printf("%d\n", p2);
    printf("%d\n", p3);
    printf("%d\n", p4);
    printf("%d\n", p5);
}

#endif
