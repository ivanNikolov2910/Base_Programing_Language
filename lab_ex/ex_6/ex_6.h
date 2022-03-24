#ifndef EX6_HEADER_FILE
#define EX6_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>

// func declaration
float avr_arr(int arr[], int size);

// 1 program - input 7 int (-100; 100) in arr[], output print max
void zad_1()
{
    int size = 7;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        int num;
        scanf("%d", &num);
        if (num < 100 && num > -100)
        {
            arr[i] = num;
        }
        else
        {
            printf("num in interval (-100; 100)\n");
            i--;
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    printf("max in interval is %d\n", max);
}

// 2 func return avr for [i] > 0
void zad_2()
{
    int arr[5] = {1, 1, -1, 2, 2};
    printf("Arg of all > 0 elements is %.2f\n", avr_arr(arr, 5));
}

// 3 a[0] > a[1] > a[2]...
void zad_3()
{
    int arr[5] = {8, 7, 4, 5, 4};
    int cnt = 0, size = 5;
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            cnt++;
        }
    }
    if (cnt == size - 1)
    {
        printf("True");
    }
    else
    {
        printf("False");
    }
}

float avr_arr(int arr[], int size)
{
    int cnt = 0;
    float sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > 0)
        {
            sum += arr[i];
            cnt++;
        }
    }

    return (sum / cnt);
}
#endif /* EX6_HEADER_FILE */