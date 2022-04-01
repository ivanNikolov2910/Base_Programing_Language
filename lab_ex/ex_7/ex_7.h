#ifndef EX7_HEADER_FILE
#define EX7_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>

// 1: sq arr[n][n] print [i][i] arr

void zad_1()
{
    int n;
    scanf("%d", &n);
    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
    printf("Elements on main diagonal:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                printf("%d ", arr[i][j]);
            }
        }
        printf("\n");
    }
}

void zad_2()
{
    int n;
    scanf("%d", &n);
    int arr[n][n];
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         scanf("%d", &arr[i][j]);
    //     }
    // }
    printf("old:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("new:\n");
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[n - 1][i] < 0)
        {
            flag = 1;
        }
    }
    if (flag != 0)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i + j == n - 1)
                {
                    arr[i][j] *= 3;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

// min el up main diagonal
void zad_3()
{
    int n;
    scanf("%d", &n);
    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    int min = arr[0][1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i < j && min > arr[i][j])
            {
                min = arr[i][j];
            }
        }
    }

    printf("%d", min);
}

void zad_4()
{
    int n;
    scanf("%d", &n);
    int arr[n][n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    int sum_arr[(n * 2) + 2];
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += arr[i][j];
        }
        sum_arr[i] = sum;
    }
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += arr[j][i];
        }
        sum_arr[i + n] = sum;
    }

    sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                sum += arr[i][j];
            }
        }
    }
    sum_arr[n * 2] = sum;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1)
            {
                sum += arr[i][j];
            }
        }
    }
    sum_arr[1 + n * 2] = sum;
    sum = 0;

    // print sum
    for (int i = 0; i < n * 2 + 2; i++)
    {
        printf("%d ", sum_arr[i]);
    }
    printf("\n");
    // check for magic
    int flag = 0;
    for (int i = 0; i < (n * 2) + 2; i++)
    {
        if (sum_arr[i] == sum_arr[i + 1])
        {
            // printf("%d ", sum_arr[i]);
            flag++;
        }
    }
    printf("\n");
    if (flag == 2 * n + 1)
    {
        printf("It's magic!!");
    }
}

#endif /* EX7_HEADER_FILE */
