// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// #define TRUE 1
// #define FALSE 0
// #define BOOLEAN int

// int main()
// {
//     short temp;
//     short sum = 0;
//     short cnt = 0;
//     short minTemp;
//     short maxNegTemp = SHRT_MIN;
//     short dateNo = -1;
//     BOOLEAN isInit = FALSE;

//     do
//     {
//         printf("Temp:");
//         scanf("%hi", &temp);
//         if (!temp)
//         {
//             break;
//         }
//         if (!isInit)
//         {
//             minTemp = temp;
//             isInit = !isInit; // isInit = TRUE;
//         }
//         else if (minTemp > temp)
//         {
//             minTemp = temp;
//         }
//         if (temp < 0 && maxNegTemp < temp)
//         {
//             maxNegTemp = temp;
//             dateNo = cnt + 1;
//         }
//         sum += temp;
//         cnt++;
//     } while (TRUE);

//     if (cnt == 0)
//     { // !cnt
//         printf("No data...\n");
//     }
//     else
//     {
//         printf("Average T: %g\n", (float)sum / cnt);
//         printf("Min Temp: %hi\n", minTemp);
//         if (maxNegTemp != SHRT_MIN)
//         {
//             printf("Max Neg T: %hi\tDay: %hi\n", maxNegTemp, dateNo);
//         }
//     }
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define BOOLEAN int
#define FALSE 0

int main()
{
    int i;
    long sum = 0;
    long num;
    long minEvenNum;
    BOOLEAN isInit = FALSE;

    srand(time(NULL));

    for (i = 0; i < SIZE; ++i)
    {
        num = (long)(rand() % 50 - 25);
        printf("%li ", num);
        sum += num;
        if (num % 2 == 0)
        {
            if (!isInit)
            {
                minEvenNum = num;
                isInit = !isInit;
            }
            else if (minEvenNum > num)
            {
                minEvenNum = num;
            }
        }
    }
    printf("\nSum = %li\n", sum);
    if (!isInit)
    {
        printf("No even numbers...\n");
    }
    else
    {
        printf("Min even number: %li\n", minEvenNum);
    }
    return 0;
}
