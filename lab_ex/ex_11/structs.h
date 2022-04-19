struct date
{
    int month;
    int day;
    int year;
};

typedef struct Name
{
    char first[20];
    char last[20];
} Name;

typedef struct Person
{
    Name name;
    int age;
} Person;

typedef struct box
{
    float width;
    float length;
    float height;
    float volume;
} Box;

typedef struct Book
{
    char title[50];
    char author[20];
    int year;
    float price;
} Book;