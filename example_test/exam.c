#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Student
{
    char fi_name[16]; // до 15 знака + '\0'
    char s_name[16];
    char fam_name[16];
    int class_num;
    int *math;
    int *bulg;
    int *progr;
} Student;

int main(int argc, char **argv)
{
    int st_count = 3;
    Student *s = (Student *)malloc(st_count * sizeof(Student));

    FILE *input = fopen("students.txt", "r");
    if (input == NULL)
    {
        perror(NULL);
        fclose(input);
    }
    char buf[200];
    int cnt = 0;

    while (fgets(buf, sizeof(buf), input) != NULL)
    {
        int pointer = 0;
        // set class_nums
        char num[6];
        for (int i = 0; i < 5; i++)
        {
            num[i] = buf[i];
        }
        pointer = 7;
        int class_num = strtol(num, NULL, 10);
        s[cnt].class_num = class_num;

        // set names
        char names[50];
        int name_ind = 0;
        for (int i = pointer; buf[i] != ';'; i++)
        {
            names[name_ind] = buf[i];
            ++name_ind;
        }
        // split names
        char fi_name[16];
        char s_name[16];
        char f_name[16];
        char *ptr = strtok(names, " ");
        strcpy(fi_name, ptr);
        ptr = strtok(NULL, " ");
        strcpy(s_name, ptr);
        ptr = strtok(NULL, " ");
        strcpy(f_name, ptr);
        strcpy(s[cnt].fi_name, fi_name);
        strcpy(s[cnt].s_name, s_name);
        strcpy(s[cnt].fam_name, f_name);

        // set grades
        // math
        pointer = 0;
        for (int i = 0; buf[i] != ';'; i++)
        {
            pointer = i + 1;
        }
        // printf("%c\t%d\n", buf[pointer], pointer);
        pointer += 7;
        // for (int i = pointer; i < strlen(buf); i++)
        // {
        //     printf("%c", buf[i]);
        // }
        int *math = (int *)calloc(10, sizeof(int)), math_cnt = 0;
        for (int i = pointer; buf[i] != 'B'; i++)
        {
            printf("%c", buf[i]);
        }

        printf("\n");

        cnt++;
    }
}