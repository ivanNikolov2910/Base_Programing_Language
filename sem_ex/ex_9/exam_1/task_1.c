#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_SIZE 16

typedef struct Artist
{
    char name[NAME_SIZE];
    int age;
    char country[NAME_SIZE];
    long earnings;
    int oscars;
} Artist;

void add_new_artist(Artist *);
void print_to_file(Artist *);
Artist *return_artist_array(Artist *, long);

int size = 1;
int arr_income_size = 1;

int main()
{

    Artist *artists = (Artist *)malloc(sizeof(Artist) * size);
    int curr_len = size - 1;
    int cmd;
    while (1)
    {
        printf("1. add new artist\n");
        printf("2. return artist array with more income than N\n");
        printf("3. print artist to txt file\n");
        printf("4. break\n");
        scanf("%d", &cmd);
        if (cmd == 1)
        {
            add_new_artist(artists, &size);
        }
        else if (cmd == 2)
        {
            long income;
            scanf("%ld", &income);
            Artist *new_arr = return_artist_array(artists, income);
            if (arr_income_size == 1)
            {
                printf("%s\n", new_arr[0].name);
            }
            else
            {
                for (int i = 0; i < arr_income_size - 1; i++)
                {
                    printf("%s\n", new_arr[i].name);
                }
            }
        }
        else if (cmd == 3)
        {
            print_to_file(artists);
        }
        else if (cmd == 4)
        {
            break;
        }
    }
}

void add_new_artist(Artist *ap)
{
    printf("Enter artist name: ");
    fflush(stdin);
    scanf("%s", ap[size - 1].name);
    printf("Enter artist age: ");
    fflush(stdin);
    scanf("%d", &ap[size - 1].age);
    printf("Enter artist country: ");
    fflush(stdin);
    scanf("%s", ap[size - 1].country);
    printf("Enter artist earnings: ");
    fflush(stdin);
    scanf("%ld", &ap[size - 1].earnings);
    printf("Enter artist oscars: ");
    fflush(stdin);
    scanf("%d", &ap[size - 1].oscars);
    ++size;
    ap = (Artist *)realloc(ap, size);
}

void print_to_file(Artist *ap)
{
    int curr_len = size - 1;
    FILE *f = fopen("artist.txt", "w");
    if (f == NULL)
        exit(1);
    for (int i = 0; i < curr_len; i++)
    {
        fprintf(f, "%s;%d;%s;%ld;%d\n", ap[i].name, ap[i].age, ap[i].country, ap[i].earnings, ap[i].oscars);
    }
    printf("\nREADY!\n");
    fclose(f);
}

Artist *return_artist_array(Artist *ap, long income)
{
    int curr_len = size - 1, cnt = 0, flag = 1;
    Artist *result;

    for (int i = 0; i < curr_len; i++)
    {
        if (ap[i].earnings >= income)
        {
            if (flag == 1)
            {
                flag = 0;
                result = (Artist *)malloc(sizeof(Artist));
            }

            result[cnt++] = ap[i];
            result = (Artist *)realloc(result, ++arr_income_size);
        }
    }
    if (result == NULL)
        exit(1);

    return result;
}
