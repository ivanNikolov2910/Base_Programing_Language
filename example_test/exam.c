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

void print_all(Student *, int);

int main(int argc, char **argv)
{
    int st_count = 4;
    Student *s = (Student *)malloc(st_count * sizeof(Student));

    FILE *input = fopen("students.txt", "r");
    if (input == NULL)
    {
        perror(NULL);
        fclose(input);
    }
    char buf[200];
    int cnt = 0;

    // fill Student s -->>   DISAAAASTER
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
        f_name[strlen(f_name) - 1] = '\0';
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
        pointer += 7;

        s[cnt].math = (int *)calloc(10, sizeof(int));
        int math_cnt = 0;
        for (int i = pointer; buf[i] != 'B'; i += 2)
        {
            if (buf[i] - '0' <= 6 && buf[i] - '0' >= 2)
            {
                s[cnt].math[math_cnt] = buf[i] - '0';
                math_cnt++;
                pointer += 2;
            }
        }
        pointer += 4;

        // bulgarian
        s[cnt].bulg = (int *)calloc(10, sizeof(int));
        int bulg_cnt = 0;
        for (int i = pointer; buf[i] != 'I'; i += 2)
        {
            if (buf[i] - '0' <= 6 && buf[i] - '0' >= 2)
            {
                s[cnt].bulg[bulg_cnt] = buf[i] - '0';
                bulg_cnt++;
                pointer += 2;
            }
        }
        pointer += 4;

        // programming
        s[cnt].progr = (int *)calloc(10, sizeof(int));
        int progr_cnt = 0;
        for (int i = pointer; i < strlen(buf); i += 2)
        {
            if (buf[i] - '0' <= 6 && buf[i] - '0' >= 2)
            {
                s[cnt].progr[progr_cnt] = buf[i] - '0';
                progr_cnt++;
                pointer += 2;
            }
        }
        cnt++;
    }
    fclose(input);

    // program UI - consol
    char cmd[20];
    do
    {
        scanf("%s", cmd);
        // add grade
        if (strcmp(cmd, "grade") == 0)
        {

            int class_num, grade;
            char subj[10];
            printf("Student's number: ");
            scanf("%d", &class_num);
            printf("Subject: ");
            scanf("%s", subj);
            printf("Grade: ");
            scanf("%d", &grade);
            // printf("%d %d %s", class_num, grade, subj);
            if (strcmp(subj, "math") == 0)
            {
                for (int i = 0; i < st_count; i++)
                {
                    if (s[i].class_num == class_num)
                    {
                        for (int j = 0; j < sizeof(s[i].math) + 2; j++)
                        {
                            if (s[i].math[j] == 0)
                            {
                                s[i].math[j] = grade;
                                break;
                            }
                        }
                    }
                }
            }
            if (strcmp(subj, "progr") == 0)
            {
                for (int i = 0; i < st_count; i++)
                {
                    if (s[i].class_num == class_num)
                    {
                        for (int j = 0; j < sizeof(s[i].progr) + 2; j++)
                        {
                            if (s[i].progr[j] == 0)
                            {
                                s[i].progr[j] = grade;
                                break;
                            }
                        }
                    }
                }
            }
            if (strcmp(subj, "bulg") == 0)
            {
                for (int i = 0; i < st_count; i++)
                {
                    if (s[i].class_num == class_num)
                    {
                        for (int j = 0; j < sizeof(s[i].bulg) + 2; j++)
                        {
                            if (s[i].bulg[j] == 0)
                            {
                                s[i].bulg[j] = grade;
                                break;
                            }
                        }
                    }
                }
            }
        }

        // add student
        if (strcmp(cmd, "student") == 0)
        {
            ++st_count;
            s = realloc(s, sizeof(Student) * st_count);
            int new_stud;
            char fn[16], sn[16], fam[16];
            scanf("%d", &new_stud);
            scanf("%s%s%s", fn, sn, fam);
            strcpy(s[st_count - 1].fi_name, fn);
            strcpy(s[st_count - 1].s_name, sn);
            strcpy(s[st_count - 1].fam_name, fam);
            s[st_count - 1].class_num = new_stud;
            s[st_count - 1].math = (int *)calloc(10, sizeof(int));
            s[st_count - 1].bulg = (int *)calloc(10, sizeof(int));
            s[st_count - 1].progr = (int *)calloc(10, sizeof(int));
        }

        // calculate grade per class
        if (strcmp(cmd, "calc") == 0)
        {
            int avr_math = 0, math_flag = 0, avr_bulg = 0, bulg_flag = 0, avr_progr = 0, progr_flag = 0, class;
            printf("Class: ");
            scanf("%d", &class);
            for (int i = 0; i < st_count; i++)
            {
                if ((int)s[i].class_num / 100 == class)
                {
                    for (int j = 0; j < sizeof(s[i].math) + 2; j++)
                    {
                        if (s[i].math[j] != 0)
                        {
                            math_flag++;
                            avr_math += s[i].math[j];
                        }
                    }

                    for (int j = 0; j < sizeof(s[i].bulg) + 2; j++)
                    {
                        if (s[i].bulg[j] != 0)
                        {
                            bulg_flag++;
                            avr_bulg += s[i].bulg[j];
                        }
                    }

                    for (int j = 0; j < sizeof(s[i].progr) + 2; j++)
                    {
                        if (s[i].progr[j] != 0)
                        {
                            progr_flag++;
                            avr_progr += s[i].progr[j];
                        }
                    }
                }
            }
            avr_math /= math_flag;
            avr_bulg /= bulg_flag;
            avr_progr /= progr_flag;
        }

    } while (strcmp(cmd, "END") != 0);

    // write to bin file:
    FILE *out = fopen("students_out.bin", "wb");
    // char out_buf[255];
    // for (int i = 0; i < st_count; i++)
    // {
    //     char num[6];
    //     itoa(s[i].class_num, num, 10);
    //     strcat(out_buf, num);
    //     strcat(out_buf, ": ");
    //     strcat(out_buf, s[i].fi_name);
    //     strcat(out_buf, " ");
    //     strcat(out_buf, s[i].s_name);
    //     strcat(out_buf, " ");
    //     strcat(out_buf, s[i].fam_name);
    //     strcat(out_buf, "; Mat: ");
    //     char *m_gr = (char *)malloc(10 * sizeof(char));
    //     for (int j = 0; j < sizeof(s[i].math); j++)
    //     {
    //         m_gr[j] = s[i].math[j] + '0';
    //     }
    //     strcat(out_buf, m_gr);
    //     char *b_gr = (char *)malloc(10 * sizeof(char));
    //     for (int j = 0; j < sizeof(s[i].bulg); j++)
    //     {
    //         b_gr[j] = s[i].bulg[j] + '0';
    //     }
    //     strcat(out_buf, " BG: ");
    //     strcat(out_buf, b_gr);
    //     char *p_gr = (char *)malloc(10 * sizeof(char));
    //     for (int j = 0; j < sizeof(s[i].progr); j++)
    //     {
    //         p_gr[j] = s[i].progr[j] + '0';
    //     }
    //     strcat(out_buf, " IT: ");
    //     strcat(out_buf, p_gr);
    //     strcat(out_buf, "\n");
    // }
    // fwrite(out_buf, 255, 1, out);
    for (int i = 0; i < st_count; i++)
    {
        char math[16], bulg[16], progr[16];
        for (int j = 0; j < sizeof(s[i].math); j++)
        {
            math[j] = s[i].math[j] + '0';
        }
        for (int j = 0; j < sizeof(s[i].bulg); j++)
        {
            bulg[j] = s[i].bulg[j] + '0';
        }
        for (int j = 0; j < sizeof(s[i].progr); j++)
        {
            progr[j] = s[i].progr[j] + '0';
        }
        fprintf(out, "%d: %s %s %s; Mat: %s BG: %s IT: %s\n", s[i].class_num, s[i].fi_name, s[i].s_name, s[i].fam_name, math, bulg, progr);
    }
    fclose(out);
}

void print_all(Student *s, int st_count)
{
    for (int i = 0; i < st_count; i++)
    {
        printf("%d: %s %s %s; ", s[i].class_num, s[i].fi_name, s[i].s_name, s[i].fam_name);
        printf("Mat: ");
        for (int j = 0; j < 10; j++)
        {
            if (s[i].math[j] >= 2 && s[i].math[j] <= 6)
            {
                printf("%d ", s[i].math[j]);
            }
        }
        printf("BG: ");
        for (int j = 0; j < 10; j++)
        {
            if (s[i].bulg[j] >= 2 && s[i].bulg[j] <= 6)
            {
                printf("%d ", s[i].bulg[j]);
            }
        }
        printf("IT: ");
        for (int j = 0; j < 10; j++)
        {
            if (s[i].progr[j] >= 2 && s[i].progr[j] <= 6)
            {
                printf("%d ", s[i].progr[j]);
            }
        }
        printf("\n");
    }
}