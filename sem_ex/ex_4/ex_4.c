#include "ex_4.h"

int main()
{
    // 1
    // printf("Max is %.4lf", get_max(1.12, 1.13));
    // printf("Max is %.4lf", get_min(1.1, 0.85));
    double num, a, b, max = 0, min = 0;
    do
    {
        scanf("%lf", &num);
        a = num;
        if (a == 0)
        {
            break;
        }
        scanf("%lf", &num);
        b = num;
        if (b == 0)
        {
            break;
        }
        if (get_max(a, b) > max)
        {
            max = get_max(a, b);
        }
        if (get_min(a, b) < min)
        {
            min = get_min(a, b);
        }
    } while (num);
    printf("Max is %.4lf", max);
    printf("Min is %.4lf", min);

    // 2
    plus_15min(0, 1);

    // 3
    is_3_eq(1.12, 1.10, 1.10);
    is_3_eq(1.10, 1.10, 1.10);

    // 4

    int point;
    scanf("%d", &point);
    printf("%.2f", get_points(point));

    // 5
    get_time_race(22, 7, 34);

    // 7

    char day = 'D', night = 'N';
    printf("%.2f", get_cheapest(50, day));

    // 10
    get_freq(15);

    return 0;
}
