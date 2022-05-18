#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Product
{
    char name[31]; // 30 + '\0'
    int id;
    char exp_date[11];
    float price;
} Product;

void add_new_item(Product *);
Product *check_date(Product *, char exp_date[11]);
void bit_to_txt(Product *);

int size = 1;
#define arr_len (size - 1)
int res_len = 0;

int main(Product *)
{
    // zad 1
    Product *prs = (Product *)malloc(sizeof(Product) * size);
    add_new_item(prs);
    add_new_item(prs);
    add_new_item(prs);

    // zad 2
    // Product *prs = (Product *)malloc(sizeof(Product) * 3);
    // prs[0].id = 128;
    // strcpy(prs[0].exp_date, "2022.05.18\0");

    // prs[1].id = 352;
    // strcpy(prs[1].exp_date, "2022.07.18\0");

    // prs[2].id = 201;
    // strcpy(prs[2].exp_date, "2022.05.18\0");
    // Product *by_date = check_date(prs, "2022.05.18\0");
    // for (int i = 0; i < res_len; i++)
    // {
    //     printf("%d\t", prs[i].id);
    // }

    // zad 3
    bit_to_txt(prs);
}

void add_new_item(Product *prs)
{
    fflush(stdin);
    scanf("%s", prs[size - 1].name);
    fflush(stdin);
    scanf("%d", &prs[size - 1].id);
    fflush(stdin);
    scanf("%s", prs[size - 1].exp_date);
    fflush(stdin);
    scanf("%f", &prs[size - 1].price);

    FILE *out = fopen("in.bin", "ab");
    for (int i = 0; i < size; i++)
    {
        fwrite(&prs[i], sizeof(Product), 1, out);
    }
    size++;
    prs = (Product *)realloc(prs, size);
    fclose(out);
}

Product *check_date(Product *prs, char exp_date[11])
{
    Product *res;
    int first_pr = 1, count = 0;
    for (int i = 0; i < arr_len; i++)
    {
        if (!strcmp(prs[i].exp_date, exp_date))
        {
            printf("Im here");
            if (first_pr == 1)
            {
                first_pr = 0;
                res_len++;
                res = (Product *)malloc(sizeof(Product) * res_len);
                res[count] = prs[i];
            }
            else
            {
                res_len++;
                res[count] = prs[i];
            }

            ++count;
            res = (Product *)realloc(res, res_len + 1);
        }
    }
    if (res_len == 0)
    {
        printf("NO MATCHES!\n");
        return NULL;
    }
    else
    {
        return res;
    }
}

void bit_to_txt(Product *prs)
{
    FILE *out = fopen("out.txt", "w");
    printf("Here");
    for (int i = 0; i < arr_len; i++)
    {
        // fread(&temp, sizeof(Product), 1, in);
        fprintf(out, "%s %d %s %f\n", prs[i].name, prs[i].id, prs[i].exp_date, prs[i].price);
    }
    fclose(out);
}

/*
    word_word2
    wordWord
    WordWord
    word-word
*/