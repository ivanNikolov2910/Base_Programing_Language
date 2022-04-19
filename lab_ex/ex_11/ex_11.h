#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

/*STRUCTURE EX
class with no func

definition:
struct <name>
{
    properties;
    // <type> <name1>;
    // <type> <name2>;
    // <type> <name3>;
};*/

// zad 0
int zad_0()
{
    typedef struct date Date;

    struct date today;
    scanf("%d", &today.day);
    today.month = 4;
    today.year = 2022;

    struct date next_day = today;
    next_day.day = next_day.day + 1;

    printf("%d.%d.%d\n", today.day, today.month, today.year);
    printf("%d.%d.%d\n", next_day.day, next_day.month, next_day.year);

    Date date2 = {5, 15, 2022};
    printf("%d.%d.%d\n", date2.day, date2.month, date2.year);

    Date days[5];

    return 0;
}

// zad 0_2
int zad_0_2()
{
    Person per1 = {{"Ivan", "Nikolov"}, 20};
    printf("%s %s age: %d\n\n", per1.name.first, per1.name.last, per1.age);

    Person *per2;
    per2 = (Person *)malloc(sizeof(Person));
    strcpy(per2->name.first, "Ivan");
    strcpy(per2->name.last, "Nikolov");
    per2->age = 20;
    printf("%s %s age: %d", per2->name.first, per2->name.last, per2->age);

    return 0;
}

// zad_1: struct box -> width, length, height, volume
// define array boxes[5] fill array form scanf() print info for min and max volume;

int zad_1()
{
    Box boxes[5];
    for (int i = 0; i < 5; i++)
    {
        scanf("%f", &boxes[i].width);
        scanf("%f", &boxes[i].length);
        scanf("%f", &boxes[i].height);
        boxes[i].volume = boxes[i].width * boxes[i].length * boxes[i].height;
    }
    float min_vol = boxes[0].volume, max_vol = boxes[0].volume;

    for (int i = 0; i < 5; i++)
    {
        if (min_vol > boxes[i].volume)
        {
            min_vol = boxes[i].volume;
        }
        if (max_vol < boxes[i].volume)
        {
            max_vol = boxes[i].volume;
        }
    }

    printf("Max volume: %.2f\tMin volume: %.2f", max_vol, min_vol);
}

// zad_2 book program, for each book -> title, author, year, price.
// fill with func, print all after 2005 func, search by author from scanf()
void initBooks(Book books[], int size)
{
    for (int i = 0; i < size; i++)
    {
        fflush(stdin);
        scanf("%[^\n]s", &books[i].title);
        fflush(stdin);
        scanf("%[^\n]s", &books[i].author);
        fflush(stdin);
        scanf("%d", &books[i].year);
        fflush(stdin);
        scanf("%f", &books[i].price);
        // printf("Next book: index %d\n", i);
    }
}

void printBooks(Book books[], int size, int year)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        if (books[i].year >= year)
        {
            printf("%s - %s\n%d\n%.2f lev", books[i].title, books[i].author, books[i].year, books[i].price);
        }
        printf("\n\n");
    }
}

int getAuthor(Book books[], int size, char name[])
{
    for (int i = 0; i < size; i++)
    {
        if (strcmp(books[i].author, name) == 0)
        {
            return i;
        }
    }
    return -1;
}

int zad_2()
{
    int size = 3;
    Book books[size];

    initBooks(books, size);
    printBooks(books, size, 2005);
    int book1 = getAuthor(books, size, "a");
    printf("%s -> %s\n", books[book1].title, books[book1].author);
}