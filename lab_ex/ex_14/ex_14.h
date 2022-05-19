#ifndef EX14_HEADER_FILE
#define EX14_HEADER_FILE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NAME_SIZE 50
#define NUM_SIZE 11

typedef struct Phonebook
{
    char name[NAME_SIZE];
    int code;
    char num[NUM_SIZE]
} Phonebook;

// enter while 1 obects type Phonebook(name[], int code, num[]). All info to .txt -> read info to array[] print info

void zad_1()
{
    FILE *fp = fopen("phonebook.txt", "w");
    if (fp == NULL)
        exit(1);

    int cmd;
    printf("1. Enter phone number\n");
    printf("2. stop\n");
    while (1)
    {
        scanf("%d", &cmd);
        if (cmd == 1)
        {
            Phonebook ph;
            fflush(stdin);
            fgets(ph.name, sizeof(ph.name), stdin);
            ph.name[strlen(ph.name) - 1] = '\0';
            fflush(stdin);
            scanf("%d", &ph.code);
            fflush(stdin);
            scanf("%s", ph.num);

            fprintf(fp, "%s;%d;%s\n", ph.name, ph.code, ph.num);
        }
        else if (cmd == 2)
        {
            fclose(fp);
            break;
        }
    }

    fp = fopen("phonebook.txt", "r");
    int size = 0, index = 0;
    char line[100];
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        size++;
    }
    rewind(fp);
    char *token;
    Phonebook *phonebook = (Phonebook *)malloc(sizeof(Phonebook) * size);
    while (fgets(line, sizeof(line), fp) != NULL)
    {
        token = strtok(line, ";");
        strcpy(phonebook[index].name, token);
        token = strtok(NULL, ";");
        int code = atoi(token);
        phonebook[index].code = code;
        token = strtok(NULL, ";");
        strcpy(phonebook[index].num, token);

        ++index;
    }
    fclose(fp);

    for (int i = 0; i < size; i++)
    {
        printf("%s %d %s", phonebook[i].name, phonebook[i].code, phonebook[i].num);
    }
}

// zad_2 program create bin file with data for worker - for each enter ID, moneyPerH, h_for_week, secalyW, max worker 30
// method add new worker/ print selaryW for all/ every h more than 40 is x150% and txes are 3,65%

typedef struct
{
    int id;
    float m_per_h;
    int h_for_week;
    float week_selary;
} Worker;

int max_size = 30;
int current_size = 3;

float calculate_week_selary(float, int);
void add_worker(Worker workers[]);

void zad_2()
{
    Worker workers[max_size];
    for (int i = 0; i < current_size; i++)
    {
        workers[i].id = i;
        scanf("%f", &workers[i].m_per_h);
        scanf("%d", &workers[i].h_for_week);
        workers[i].week_selary = calculate_week_selary(workers[i].m_per_h, workers[i].h_for_week);
    }

    FILE *file = fopen("workers.bin", "wb");
    if (file == NULL)
        exit(1);
    for (int i = 0; i < current_size; i++)
    {
        fwrite(&workers[i], sizeof(workers[i]), 1, file);
    }
    fclose(file);
}

void add_worker(Worker workers[])
{
    current_size++;
    int index = current_size - 1;
    if (current_size >= max_size)
    {
        printf("Max size achieved\n");
        return;
    }
    workers[index].id = index;
    scanf("%f", &workers[index].m_per_h);
    scanf("%d", &workers[index].h_for_week);
    workers[index].week_selary = calculate_week_selary(workers[index].m_per_h, workers[index].h_for_week);
}

float calculate_week_selary(float money, int h)
{
    if (h <= 40)
    {
        return (money * h) - (money * h) * 3.65 / 100;
    }
    else
    {
        int more_h = h - 40;
        return (money * 40 + (money * more_h + money * more_h * 150 / 100)) - (money * 40 + (money * more_h + money * more_h * 150 / 100)) * 3.65 / 100;
    }
}

#endif