#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*STRUCTURE EX
class with no func

definition:
struct <name>
{
    properties;
    // <type> <name1>;
    // <type> <name2>;
    // <type> <name3>;
};
*/

struct date
{
    int month;
    int day;
    int year;
};

// zad 0
/*int main()
{
    typedef struct date Date;

    struct date today;
    scanf("%d",&today.day);
    today.month = 4;
    today.year = 2022;

    struct date next_day = today;
    next_day.day = next_day.day + 1;

    printf("%d.%d.%d\n", today.day, today.month, today.year);
    printf("%d.%d.%d\n", next_day.day, next_day.month, next_day.year);

    Date date2 = {5,15,2022};
    printf("%d.%d.%d\n", date2.day, date2.month, date2.year);

    Date days[5];


    return 0;
}*/

typedef struct Name
{
    char first[20];
    char last[20];
}Name;

typedef struct Person
{
    Name name;
    int age;
}Person;

// zad 0_2
/*int main()
{
    Person per1 = {{"Ivan", "Nikolov"}, 20};
    printf("%s %s age: %d\n\n", per1.name.first, per1.name.last, per1.age);

    Person *per2;
    per2 = (Person*)malloc(sizeof(Person));
    strcpy(per2 -> name.first, "Ivan");
    strcpy(per2 -> name.last, "Nikolov");
    per2 -> age = 20;
    printf("%s %s age: %d", per2 -> name.first, per2 -> name.last, per2 -> age);

}
*/

// zad_1: struct box -> width, length, height, volume
// define array boxes[5] fill array form scanf() print info for min and max volume;
 typedef struct box
 {
     float width;
     float length;
     float height;
     float volume;
 }Box;

 int main()
 {
     Box boxes[5];
     for (int i = 0; i < 5; i++)
     {
         scanf("%f", &boxes[i].width);
         scanf("%f", &boxes[i].length);
         scanf("%f", &boxes[i].height);
         boxes[i].volume = boxes[i].width*boxes[i].length*boxes[i].height;
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


