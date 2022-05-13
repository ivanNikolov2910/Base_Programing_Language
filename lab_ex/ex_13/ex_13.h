#ifndef EX13_HEADER_FILE
#define EX13_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
// functions to search in string
#include <ctype.h>

#define SIZE_BUFF_255 255
#define SIZE_BUFF_1024 1024
// fputs & fgets read 5 strings stdin then write in txt. Read the file and print
void zad_1()
{
    FILE *fp = fopen("zad_1.txt", "w");
    if (fp == NULL)
        exit(1);
    char buff[SIZE_BUFF_255];
    printf("Input:\n");
    for (int i = 0; i < 5; i++)
    {
        fgets(buff, SIZE_BUFF_255, stdin);
        fputs(buff, fp);
    }
    printf("\n\nOutput:\n");
    fclose(fp);
    fp = fopen("zad_1.txt", "r");
    while (fgets(buff, SIZE_BUFF_255, fp) != NULL)
    {
        printf("%s", buff);
    }
}

// write in bin 50 ints, enter n to shown in console
void zad_2()
{
    srand(time(NULL));
    FILE *fp = fopen("zad_2.bin", "wb");
    if (fp == NULL)
        exit(1);

    for (int i = 0; i < 50; i++)
    {
        int random = rand() % 100 + 1;
        fwrite(&random, sizeof(int), 1, fp);
    }
    fclose(fp);
    fp = fopen("zad_2.bin", "rb");
    int pos_n;
    printf("Enter nth position: ");
    scanf("%d", &pos_n);
    pos_n -= 1;
    fseek(fp, pos_n, SEEK_SET);
    int search_num;
    fread(&search_num, sizeof(int), 1, fp);
    printf("Number is %d\n", search_num);
}

// find cnt words and sentences with 2 functions
int cnt_words(FILE *fp);
int cnt_sentences(FILE *fp);

void zad_3()
{
    FILE *fp = fopen("zad_3.txt", "w");
    char buff[SIZE_BUFF_1024];
    fgets(buff, SIZE_BUFF_1024, stdin);
    fputs(buff, fp);
    fclose(fp);

    fp = fopen("zad_3.txt", "r");
    int cnt_w = cnt_words(fp);
    fp = fopen("zad_3.txt", "r");
    int cnt_sen = cnt_sentences(fp);
    printf("Count of words: %d\n", cnt_w);
    printf("Count of sentences: %d\n", cnt_sen);
}

int cnt_words(FILE *fp)
{
    int cnt_words = 0;
    char buff[SIZE_BUFF_1024];
    while (fgets(buff, SIZE_BUFF_1024, fp) != NULL)
    {
        for (int i = 0; i < SIZE_BUFF_1024 - 1; i++)
        {
            if (buff[i] == ' ' && buff[i + 1] != ' ')
            {
                cnt_words++;
            }
        }
    }
    fclose(fp);
    return cnt_words;
}
int cnt_sentences(FILE *fp)
{
    int cnt_sent = 0;
    char buff[SIZE_BUFF_1024];
    while (fgets(buff, SIZE_BUFF_1024, fp) != NULL)
    {
        for (int i = 0; i < SIZE_BUFF_1024 - 1; i++)
        {
            if ((buff[i] == '.' && buff[i + 1] != '.') || buff[i] == '!' || buff[i] == '?')
            {
                cnt_sent++;
            }
        }
    }
    fclose(fp);
    return cnt_sent;
}

// create bin file with numbers => find count of odd/even nums => write in txt each row sorted

int find_odds(FILE *);
int find_evens(FILE *);
void printInFile(FILE *);

void zad_4()
{
    FILE *fp = fopen("zad_4_bin.bin", "wb+");
    if (fp == NULL)
        exit(1);

    srand(time(NULL));
    int arr_size = rand() % 20 + 1;
    fwrite(&arr_size, sizeof(int), 1, fp);
    for (int i = 0; i < arr_size; i++)
    {
        int num = rand() % 100 + 1;
        fwrite(&num, sizeof(int), 1, fp);
    }
    int cnt_odd = find_odds(fp);
    int cnt_even = find_evens(fp);
    rewind(fp);
    // print all nums
    for (int i = 0; i < arr_size + 1; i++)
    {
        int cur_n;
        fread(&cur_n, sizeof(int), 1, fp);
        if (i == 0)
            printf("SIZE %d -> ", cur_n);
        else
            printf("%d ", cur_n);
    }
    printf("\n");
    printf("\n");

    printf("Odds: %d\t Evens: %d\n", cnt_odd, cnt_even);

    rewind(fp);
    printInFile(fp);
    fclose(fp);
}

int find_odds(FILE *fp)
{
    rewind(fp);
    int cnt_odd = 0, num, flag = 0;

    while (fread(&num, sizeof(int), 1, fp) == 1)
    {
        if (flag == 0)
        {
            ++flag;
            continue;
        }
        if (num % 2 != 0)
        {
            cnt_odd++;
        }
    }
    return cnt_odd;
}

int find_evens(FILE *fp)
{
    rewind(fp);
    int cnt_even = 0, num, flag = 0;
    while (fread(&num, sizeof(int), 1, fp) == 1)
    {
        if (flag == 0)
        {
            ++flag;
            continue;
        }
        if (num % 2 == 0)
        {
            cnt_even++;
        }
    }
    return cnt_even;
}

void printInFile(FILE *fp)
{
    FILE *out = fopen("zad_4_out.txt", "w");
    int num, flag = 0;
    // char buff[SIZE_BUFF_255];
    while (fread(&num, sizeof(int), 1, fp) == 1)
    {
        fprintf(out, "%d ", num);
    }
}

#endif