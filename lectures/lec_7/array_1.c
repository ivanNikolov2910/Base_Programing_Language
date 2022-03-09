#include "array_1.h"

#define SIZE 10

int main()
{
    int data[SIZE];
    int result[SIZE];
    unsigned cnt;

    generateArray(data, SIZE);
    printArray(data, SIZE);
    cnt = fillArray(result, data, SIZE);
    if (cnt)
    {
        printArray(result, cnt);
    }
    else
    {
        printf("No such data...\n");
    }

    return 0;
}