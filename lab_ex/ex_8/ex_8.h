#ifndef EX8_HEADER_FILE
#define EX8_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>

#define PRINT_ARRAY             \
    for (int i = 0; i < n; i++) \
    {                           \
        printf("%d ", arr[i]);  \
    }                           \
    printf("\n");

void zad_0()
{
    int n = 4;
    // MALLOC
    int *p = (int *)malloc(n * sizeof(int));
    printf("malloc test\n");
    for (int i = 0; i < n; i++)
    {
        p[i] = i + 1;
        printf("%d ", p[i]); // for n = 4 => prtint 1 2 3 4
    }
    printf("\ncalloc test\n");

    // CALLOC
    int *p_1 = (int *)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("%d ", p_1[i]); // for n = 4 => prtint 0 0 0 0
    }
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        p_1[i] = i + 1;
        printf("%d ", p_1[i]); // for n = 4 => prtint 1 2 3 4
    }
    printf("\n");

    // REALLOC p_1
    p_1 = (int *)realloc(p_1, n * sizeof(int));
}

void zad_0_malloc()
{
    int count = 4;
    int *ptr = (int *)malloc(count * sizeof(int));
    for (int i = 0; i < count; i++)
    {
        ptr[i] = i + 1;
        printf("%d ", ptr[i]); // for n = 4 => prtint 1 2 3 4
    }
    printf("\n");

    int *nptr;
    nptr = ptr;
    ptr = (int *)malloc(++count * sizeof(int));
    if (ptr == NULL)
    {
        exit(1);
    }
    for (int i = 0; i < count - 1; i++)
    {
        ptr[i] = nptr[i];
    }
    ptr[count - 1] = count;
    for (int i = 0; i < count; i++)
    {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    free(nptr);
    // delete element
    nptr = ptr;
    int x = 3;
    for (int i = x; i < count; i++)
    {
        nptr[i - 1] = nptr[i];
    }

    ptr = (int *)malloc(--count * sizeof(int));
    for (int i = 0; i < count; i++)
    {
        ptr[i] = nptr[i];
        printf("%d ", ptr[i]);
    }
    free(nptr);
}

// sum n elements of scanf, use malloc()
void zad_1()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    PRINT_ARRAY;
    printf("Sum is: %d ", sum);
}

// use realloc set new n
void zad_2()
{
    int n;
    scanf("%d", &n);
    int *arr = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n");
    int new_n;
    scanf("%d", &new_n);

    arr = (int *)realloc(arr, new_n * sizeof(int));
    if (new_n <= n)
    {
        for (int i = 0; i < new_n; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    else
    {
        for (int i = n; i < new_n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < new_n; i++)
        {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
}

// just for fun - add method for array
void add(int *arr, int *size, int num)
{
    // int size_val = *size;
    arr = (int *)realloc(arr, (*size) * sizeof(int));
    arr[*size] = num;
    ++(*size);
}

void zad_just_for_fun()
{
    int size = 3;
    int *arr = (int *)calloc(size, sizeof(int));
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    add(arr, &size, 5);
    add(arr, &size, 6);
    add(arr, &size, 7);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

// dynamically allocate int array[n][m] sum for each column, print max sum
#endif