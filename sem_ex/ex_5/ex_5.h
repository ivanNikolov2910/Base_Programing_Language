#ifndef EX5_HEADER_FILE
#define EX5_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

void zad_1()
{
    int size = 8;
    int arr[8] = {6, 3, 6, 5, 6, 7, 4, 9};

    qsort(arr, size, sizeof(int), compare);
    int previous_len = 1, len = 1, max_l = 0;
    int index;

    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            len++;
            if (len > previous_len)
            {
                previous_len = len;
            }
        }
        else
        {
            previous_len = len;
            len = 1;
        }

        if (len > max_l)
        {
            max_l = len;
            index = i + 2;
            printf("%d\n", index);
        }
    }
    index = index - max_l;
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nplane length = %d\n", max_l);
    printf("start at index: %d", index);
}

void zad_2()
{
    int size = 7;
    int array[7] = {0, 1, 0, 3, 2, 5, 1};
    int cnt = 0, cnt_control = 0;
    for (int i = 1; i < size - 1; i++)
    {
        if (i % 2 != 0 && array[i - 1] < array[i] && array[i > array[i + 1]])
        {
            cnt++;
        }
        if (i % 2 != 0)
        {
            cnt_control++;
        }
    }
    if (cnt == cnt_control)
    {
        printf("TRUE");
    }
}

void zad_3()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    int array[n], result[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    for (int i = 0; i < n; i++)
    {
        result[i] = array[n - i - 1];
        printf("%d ", result[i]);
    }
}

// this ex WROKS...sometimes
void zad_4()
{
    int shift = 3, size = 5;
    int array[5] = {1, 2, 3, 4, 5};
    int sh_ar[size];

    if (shift > 0)
    {
        for (int i = 0; i < size; i++)
        {
            if (i >= shift - 1)
            {
                sh_ar[abs(shift - 1 - i)] = array[i];
            }
        }
        for (int i = 0; i < size; i++)
        {
            if (i >= shift)
            {
                sh_ar[i] = array[abs(shift - i)];
            }
        }

        for (int i = 0; i < size; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", sh_ar[i]);
        }
        printf("\n");
    }
}

#endif