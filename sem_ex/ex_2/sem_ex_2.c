#include "sem_ex_2.h"

int main()
{
    // char shape;
    // printf("Enter char: ");
    // scanf("%s", &shape);

    // // 1
    ex_1();

    // // 2
    ex_2();

    // // 3
    ex_3();

    // // 5
    ex_5();

    // // 6
    ex_6();

    // // 8
    // float lev;
    // printf("Enter bgn: ");
    // scanf("%f", &lev);

    // printf("%.2f bgn = %.2f usd\n", lev, lev * 0.58);
    // printf("%.2f bgn = %.2f euro\n", lev, lev * 0.51);
    // printf("%.2f bgn = %.2f gbp\n", lev, lev * 0.43);

    // // 9
    // float a, b, h;
    // printf("side a: ");
    // scanf("%f", &a);
    // printf("side b: ");
    // scanf("%f", &b);
    // printf("hight h: ");
    // scanf("%f", &h);
    // printf("Area is: %.2f", (a + b) * h / 2);

    // // 10
    // float deg, rad;
    // printf("Enter angle in Degrees\n");
    // scanf("%f", &deg);
    // rad = deg * (M_PI / 180.0);

    // printf("sin(%.2f) = %.2f\n", deg, sin(rad));

    // // 11
    // int ax, ay, bx, by;
    // printf("Enter coordinates\n");
    // scanf("%d %d %d %d", &ax, &ay, &bx, &by);
    // int l = abs(ax - bx), w = abs(ay - by);
    // printf("Area of this rectangle is: %d\n", l * w);

    // // 12
    // int ax, ay, bx, by, cx, cy;
    // printf("Enter coordinates\n");
    // scanf("%d %d %d %d %d %d", &ax, &ay, &bx, &by, &cx, &cy);

    // float ab = sqrt(pow((ax - bx), 2) + pow((ay - by), 2));
    // float ac = sqrt(pow((ax - cx), 2) + pow((ay - cy), 2));
    // float bc = sqrt(pow((cx - bx), 2) + pow((cy - by), 2));
    // float p = ab + ac + bc;
    // float area = sqrt(p / 2 * (p / 2 - ab) * (p / 2 - ac) * (p / 2 - bc));
    // printf("Area: %.2f\n", area);

    // 13
    // float w, h;
    // scanf("%f %f", &w, &h);
    // srand(time(NULL));
    // int c = ((rand() % 1) + 1) * w;
    // float area_obj = 0.84;
    // float t_dest = 2 * area_obj;
    // float area_room = w * h;
    // float area_free = area_room - t_dest - c - area_obj;

    // float worckplaces = area_free / area_obj;

    // printf("%.0f\n", worckplaces);

    // // 14 bonus
    // float prPerVeg, prPerFr;
    // scanf("%f %f", &prPerVeg, &prPerFr);

    // float vegPerKilo, frPerKilo;
    // scanf("%f %f", &vegPerKilo, &frPerKilo);

    // printf("Total: %.2f", (vegPerKilo * vegPerKilo + prPerFr * frPerKilo) * 0.54);
}
