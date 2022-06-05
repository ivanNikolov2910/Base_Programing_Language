#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// task 1
typedef struct Car
{
    char name[36];
    char r_num[9];
    float price;
    int priority;
} Car;

int c_size = 1;
void add_car(Car *);
void avr_price(Car *);
void by_reg_num(char r_num[]);

int main()
{
    // task 1
    Car *cars = (Car *)malloc(sizeof(Car) * c_size);
    if (cars == NULL)
        exit(1);
    FILE *file = fopen("autoTxt.txt", "w");
    if (file == NULL)
        exit(1);
    fclose(file);

    add_car(cars);
    add_car(cars);
    add_car(cars);

    // task 2
    avr_price(cars);

    // task 3
    by_reg_num("AS1234CD");
}

// task 1
void add_car(Car *cars)
{
    FILE *file = fopen("autoTxt.txt", "a");
    if (c_size == 1)
    {
        fflush(stdin);
        scanf("%s", cars[0].name);
        fflush(stdin);
        scanf("%s", cars[0].r_num);
        fflush(stdin);
        scanf("%f", &cars[0].price);
        fflush(stdin);
        scanf("%d", &cars[0].priority);

        fprintf(file, "%d;%s;%s;%.2f;%d\n", strlen(cars[0].name), cars[0].name, cars[0].r_num, cars[0].price, cars[0].priority);
        ++c_size;
    }
    else
    {
        cars = (Car *)realloc(cars, c_size);
        if (cars == NULL)
            exit(1);
        fflush(stdin);
        scanf("%s", cars[c_size - 1].name);
        fflush(stdin);
        scanf("%s", cars[c_size - 1].r_num);
        fflush(stdin);
        scanf("%f", &cars[c_size - 1].price);
        fflush(stdin);
        scanf("%d", &cars[c_size - 1].priority);

        fprintf(file, "%d;%s;%s;%.2f;%d\n", strlen(cars[c_size - 1].name), cars[c_size - 1].name, cars[c_size - 1].r_num, cars[c_size - 1].price, cars[c_size - 1].priority);
        ++c_size;
    }
    fclose(file);
}

// task 2
void avr_price(Car *cars)
{
    float avr = 0;
    for (int i = 0; i < c_size; ++i)
    {
        avr += cars[i].price;
    }
    avr /= c_size;

    for (int i = 0; i < c_size; ++i)
    {
        if (cars[i].price > avr)
        {
            printf("%s - %.2f\n", cars[i].r_num, cars[i].price);
        }
    }
}

// task 3
void by_reg_num(char r_num[])
{
    FILE *file = fopen("auto.bin", "rb");
    if (file == NULL)
        exit(1);
    /*... и тука, който е писал условието е заспал на клавиетурата и се е събудел след поне 2:30 дрямка,
    осъзнавайки безмислеността на материалното съществуване и факта, че изпита започва след 10 минути, а условието не е дописано...*/
    Car temp;
    while (fread(&temp, sizeof(Car), 1, file))
    {
        if (strcmp(temp.r_num, r_num) == 0)
        {
            printf("%s\n", temp.r_num);
        }
    }
    fclose(file);
}