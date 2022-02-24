#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    /*1. Да се прочете от клавиатурата едно целочислено число и да се изведе съобщение, ако то е по-голямо от 6.*/

    // int a;
    // scanf("%d", &a);

    // if (a > 6)
    // {
    //     printf("%d is bigger than 6\n", a);
    // }

    /*2. Да се прочете от клавиатурата едно целочислено число и да се изведе на екрана съобщение, ако остатъкът от делението му с 8 е по-голям от 4.*/

    // int b;
    // scanf("%d", &b);

    // if (b % 8 > 4)
    // {
    //     printf("%d %% 8 is bigger than 4\n", b);
    // }

    /*3. Да се прочетат от клавиатурата 3 числа и да се изведе на екрана най-малкото от тях.*/

    // int a, b, c;
    // scanf("%d %d %d", &a, &b, &c);
    // int min;
    // if (a < b && a < c)
    // {
    //     min = a;
    // }
    // else if (b < c && b < a)
    // {
    //     min = b;
    // }
    // else if (c < a && c < b)
    // {
    //     min = c;
    // }
    // if (a == b && a < c)
    // {
    //     min = a;
    // }
    // else if (a == c && a < b)
    // {
    //     min = a;
    // }
    // else if (b == c && b < a)
    // {
    //     min = b;
    // }
    // else if (a == c && a == b)
    // {
    //     min = a;
    // }

    // printf("%d", min);

    /*4. switch case week*/
    // int d;
    // scanf("%d", &d);
    // switch (d)
    // {
    // case 1:
    //     printf("Monday");
    //     break;
    // case 2:
    //     printf("Tuesday");
    //     break;
    // case 3:
    //     printf("Wednesday");
    //     break;
    // case 4:
    //     printf("Thursday");
    //     break;
    // case 5:
    //     printf("Friday");
    //     break;
    // case 6:
    //     printf("Saturday");
    //     break;
    // case 7:
    //     printf("Sunday");
    //     break;
    // default:
    //     printf("Invalid day");
    // }

    /*Да се напише програма, която прочита от клавиатурата едно цяло число и изкарва числова пирамида:
        1
        2 2
        3 3 3 */
    // int num;
    // scanf("%d", &num);
    // for (int i = 1; i <= num; i++)
    // {
    //     for (int j = 1; j <= i; j++)
    //     {
    //         printf("%d ", i);
    //     }
    //     printf("\n");
    // }

    /*5. Да се напише програма, която прочита от клавиатурата две цели числа и извежда сумата на числата между тези две числа.
    Въведените числа от клавиатурата не е задължително да са в ред по-малко, по-голямо. */

    // int a, b;
    // scanf("%d %d", &a, &b);

    // if (a > b)
    // {
    //     int temp = a;
    //     a = b;
    //     b = temp;
    // }

    // int sum = 0;
    // for (int i = a + 1; i < b; i++)
    // {
    //     sum += i;
    // }
    // printf("%d", sum);

    /*6. Да се напише програма, при която се въвеждат две числа N и К.
    След това се въвеждат още N числа и се извежда броят на числата, които са по-големи от K и се делят на 3.*/

    // int n, k, count = 0;
    // scanf("%d %d", &n, &k);
    // for (int i = 0; i < n; i++)
    // {
    //     int temp;
    //     scanf("%d", &temp);
    //     if (temp > k && temp % 3 == 0)
    //     {
    //         count++;
    //     }
    // }
    // printf("%d\n", count);

    /*Да се напише програма, която прочита от клавиатурата две реални числа и извежда стойностите на фукция f(x) = x*x-4
    за всички стойности в дадения интервал. Стъпката на обхождане е 0.01*/

    float f, l;
    scanf("%f %f", &f, &l);
    for (float i = f; i <= l; i += 0.1)
    {
        printf("%.2f\n", i * i - 4);
    }

    return 0;
}