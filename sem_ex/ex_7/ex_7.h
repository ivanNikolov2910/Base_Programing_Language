#ifndef EX7_HEADER_FILE
#define EX7_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void init_array(int n, int m, int array[n][m]);
void print_array(int n, int m, int array[n][m]);
int check_row(int n, int m, int array[n][m]);
int check_col(int n, int m, int array[n][m]);
void add(int *arr, int *size, int num);

void zad_1()
{
    int n, m;
    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);
    int array[n][m];
    init_array(n, m, array);
    print_array(n, m, array);
    int flag_c = 0, flag_r = 0;
    flag_r = check_row(n, m, array);
    flag_c = check_col(n, m, array);
    if (flag_c == 1 && flag_r == 1)
    {
        printf("Everything is good\n");
    }
    else
    {
        printf("Doesn't match the Zustand");
    }
}

// max sum of surrounding elements in array[n][m]
void zad_2()
{
    int n, m;
    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);
    int array[n][m];
    init_array(n, m, array);
    print_array(n, m, array);

    int sum = 0, max_sum = 0, index[2], new_index[2];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int a = -1; a <= 1; a++)
            {
                for (int b = -1; b <= 1; b++)
                {
                    if (i + a >= 0 && i + a < n && j + b >= 0 && j + b < m)
                    {
                        if (a == 0 && b == 0)
                        {
                            index[0] = i;
                            index[1] = j;
                        }
                        else
                        {
                            sum += array[i + a][j + b];
                        }
                    }
                }
            }
            if (sum > max_sum)
            {
                max_sum = sum;
                new_index[0] = index[0];
                new_index[1] = index[1];
            }
            sum = 0;
        }
    }

    printf("\n");
    printf("indexes: array[%d][%d]\n", new_index[0], new_index[1]);
    printf("Max sum is: %d\n", max_sum);
}

void zad_3()
{
    int n, m;
    printf("n = ");
    scanf("%d", &n);
    printf("m = ");
    scanf("%d", &m);
    int array[n][m];
    init_array(n, m, array);
    print_array(n, m, array);
    int max_ind[] = {0, 0}, max = array[0][0];
    int min_ind[] = {0, 0}, min = array[0][0];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (min > array[i][j])
            {
                min = array[i][j];
                min_ind[0] = i;
                min_ind[1] = j;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (max < array[i][j])
            {
                max = array[i][j];
                max_ind[0] = i;
                max_ind[1] = j;
            }
        }
    }
    printf("max element: %d at index: [%d][%d]\n", max, max_ind[0], max_ind[1]);
    printf("min element: %d at index: [%d][%d]\n", min, min_ind[0], min_ind[1]);

    // swap_rows(array, max_ind, min_ind);
    int temp;
    for (int i = 0; i < m; i++)
    {
        temp = array[min_ind[0]][i];
        array[min_ind[0]][i] = array[max_ind[0]][i];
        array[max_ind[0]][i] = temp;
    }
    print_array(n, m, array);
}

void zad_5()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    int *array = (int *)malloc(n * sizeof(int));
    while (1)
    {
        int cmd = 0;
        printf("cmd = ");
        scanf("%d", &cmd);
        if (cmd == 0)
        {
            break;
        }
        else if (cmd == 1)
        {
            int x;
            printf("Add x = ");
            scanf("%d", &x);
            add(array, &n, x);
            for (int i = 0; i < n; i++)
            {
                printf("%d ", array[i]);
            }
            printf("\n");
        }
        else if (cmd == 2)
        {
            int x;
            printf("Delete x = ");
            scanf("%d", &x);
            int count_x = 0;
            for (int i = 0; i < n; i++)
            {
                if (array[i] == x)
                {
                    count_x++;
                }
            }

            // array = (int *)realloc(array, (n-count_x) * sizeof(int));
        }
    }
}

void init_array(int n, int m, int array[n][m])
{
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            array[i][j] = rand() % 100;
        }
    }
}

void print_array(int n, int m, int array[n][m])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int check_row(int n, int m, int array[n][m])
{
    int flag = 0;
    for (int i = 0; i < n - 1; i)
    {
        for (int j = 0; j < m - 1; j)
        {
            if (array[i][j] < array[i + 1][j + 1])
            {
                ++flag;
            }
        }
    }
    if (flag == n - 1)
    {
        return 1;
    }
    return 0;
}
int check_col(int n, int m, int array[n][m])
{
    int flag = 0;
    for (int i = 0; i < n - 1; i)
    {
        for (int j = 0; j < m - 1; j)
        {
            if (array[j][i] < array[j + 1][i + 1])
            {
                ++flag;
            }
        }
    }
    if (flag == m - 1)
    {
        return 1;
    }
    return 0;
}

void add(int *arr, int *size, int num)
{
    // int size_val = *size;
    arr = (int *)realloc(arr, (*size) * sizeof(int));
    arr[*size] = num;
    ++(*size);
}
#endif