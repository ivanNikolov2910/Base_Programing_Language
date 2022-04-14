#ifndef EX10_HEADER_FILE
#define EX10_HEADER_FILE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPolindrome(char[]);

// dynamically allocated memory for char array, itre the stingto find first interval - print after first interval
void zad_1()
{
    int size = 50 * sizeof(char);
    char *input = (char *)malloc(size);
    fgets(input, size, stdin);
    // printf("%s", input);
    int index_interval = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == ' ')
        {
            index_interval = i;
            break;
        }
    }
    for (int i = index_interval + 1; i < strlen(input); i++)
    {
        printf("%c", input[i]);
    }
}

// print string backwards
void zad_2()
{
    int size = 20 * sizeof(char);
    char *input = (char *)malloc(size);
    fgets(input, size, stdin);
    for (int i = strlen(input) - 2; i >= 0; i--)
    {
        printf("%c", input[i]);
    }
}

// print count (, . -) in 3 vars
void zad_3()
{
    int size = 50 * sizeof(char);
    char *input = (char *)malloc(size);
    fgets(input, size, stdin);
    int cnt_p = 0, cnt_c = 0, cnt_d = 0;
    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == '.')
        {
            cnt_p++;
        }
        else if (input[i] == ',')
        {
            cnt_c++;
        }
        else if (input[i] == '-')
        {
            cnt_d++;
        }
    }

    printf("Points - %d\tCommas - %d\tDashes - %d\n", cnt_p, cnt_c, cnt_d);
}

// char[bigger size] concetenate n-count string input "quit" || bigstr.size < bigstr.size+new_str
void zad_4()
{
    int maxSize = 50 * sizeof(char);
    char *bigString = (char *)malloc(maxSize);
    char *input = (char *)malloc(maxSize);
    fgets(input, maxSize, stdin);
    strcpy(bigString, input);
    while (1)
    {
        // printf("%s", bigString);

        fgets(input, maxSize, stdin);
        if (strcmp(input, "quit\n\0") == 0 || strlen(input) + strlen(bigString) > maxSize)
        {
            break;
        }
        strcat(bigString, input);
    }
    printf("\nOUTPUT:\n");
    printf("%s\n", bigString);
}

// function isPolindrome
void zad_5()
{
    int size = 50 * sizeof(char);
    char *input = (char *)malloc(size);
    scanf("%[^\n]s", input);
    printf("%d", isPolindrome(input));
}
int isPolindrome(char input[])
{

    int flag = 0;
    for (int i = 0; i < (strlen(input)) / 2; i++)
    {
        if (input[i] == input[strlen(input) - 1 - i])
        {
            flag += 1;
        }
    }
    // printf("%d\n", strlen(input) / 2);
    // printf("%d: ", flag);
    if (flag == (strlen(input)) / 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// guess the word
void zad_6()
{
    char word[] = "concatenation";
    char guess[] = "_____________";
    int cnt = 0;
    while (cnt <= 15)
    {
        cnt++;
        char c;
        scanf("%c", &c);
        for (int i = 0; i < strlen(guess); i++)
        {
            if (c == word[i])
            {
                guess[i] = c;
            }
        }
        printf("%s\n", guess);

        int flag = 0;
        for (int i = 0; i < strlen(guess); i++)
        {
            if ('_' == guess[i])
            {
                ++flag;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

#endif