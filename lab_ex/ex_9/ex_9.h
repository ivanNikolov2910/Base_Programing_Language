#ifndef EX9_HEADER_FILE
#define EX9_HEADER_FILE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* always add one more byte for '\0'
1. char str[] = "Hello world!";     auto add '\0' - term zero
2. char s2[80] = {'H', 'e', 'l', 'l', 'o', '\0' -> required};
values: ['H', 'e', 'l', 'l', 'o', '\0']
index:  [ 0,   1,   2,   3,   4,   5  ]

char s3[20];
s3 = "Python" -> WRONG!!!

Print string;
printf("%s", str); OR printf(str); OR puts(str);
print string[i];
printf("%c", str[0]); -> 'H'

iter with for loop
for (i = 1; st[i] != '\0'; i++){...}
for (i = 1; st[i]; i++){...}

scanf("%s", s3); input -> IvanNikolov
scanf("%[^\n]s", s3); input -> Ivan Nikolov
fgets(s3, sizeof(s3), stdin); -> for string from file
-> write in s3 with size n-1 (one byte for '\0') and standart input or file path;

string.h ->
strcpy(s1, s2); s1 = copy of s2
strcat(s1, s2); s1 += s2
strlen(s1); s1.length (int)
strcpm(s1, s2); -=> 0 if s1==s2; -=> < 0 if s1 < s2; -=> > 0 if s1 > s2
*/

int get_len(char *str);
void is_equal(char *s1, char *s2);

// test strcat, strlen, strcmp, strcpy, puts
void zad_1()
{
    char str[10] = "helloo", str2[10] = "world";
    puts(str);
    printf("%s\n", str2);
    printf("%d\n", strcmp(str, str2)); // -1
    str2[0] = 'W';
    printf("%d\n", strcmp(str, str2)); // 1
    printf("%d\n", strlen(str));

    strcpy(str, str2);
    puts(str);

    strcat(str, "000o");
    puts(str);
}

// func length
void zad_2()
{
    char st[10];
    fgets(st, 10, stdin);
    printf("%d\n", get_len(st));
    puts(st);
}

// word count
void zad_3()
{
    int m_size = 101;
    char string[m_size];
    fgets(string, sizeof(string), stdin);

    int w_count = 1;
    for (int i = 0; i < strlen(string); i++)
    {
        if (string[i] == ' ' && string[i + 1] != ' ')
        {
            ++w_count;
        }
    }
    printf("Word count = %d\n", w_count);
}

// str copmere
void zad_4()
{
    char s1[10] = "qwerty", s2[10] = "qwerty", s3[10] = "asdfgh";
    is_equal(s1, s2);
}

// check in teams

void is_equal(char *s1, char *s2)
{
    if (get_len(s1) != get_len(s2))
    {
        printf("They are not equal\n");
        return;
    }
    for (int i = 0; i < strlen(s1); i++)
    {
        if (s1[i] != s2[i])
        {
            printf("They are not equal\n");
            return;
        }
    }
    printf("They are equal\n");
    return;
}

int get_len(char *str)
{
    int len = 0;
    for (int i = 0; i < str[i] != '\0'; i++)
    {
        ++len;
    }
    return len;
}
#endif