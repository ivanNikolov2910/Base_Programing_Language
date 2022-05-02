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
    FILE *input = fopen("students.txt", "r");
    if (input == NULL)
    {
        perror(NULL);
        fclose(input);
    }
    char buf[100];
    while (fscanf(input, "%s", buf) == 1)
    {
        printf("%s\n", buf);
    }
}