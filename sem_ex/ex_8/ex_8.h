#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "structs.h"

void zad_1()
{
    int guests;
    printf("Guests count: ");
    scanf("%d", &guests);

    int cnt_table = 0, cnt_chairs = 0, cnt_dishes = 0, cnt_cups = 0;
    // printf("Enter count of tables, chairs, dishes and cups:\n");
    // scanf("%d%d%d%d", &cnt_table, &cnt_chairs, &cnt_dishes, &cnt_cups);
    // printf("%d %d %d %d", cnt_table, cnt_chairs, cnt_dishes, cnt_cups);
    char cmd[10];
    scanf("%s", cmd);
    while (strcmp(cmd, "PARTY") != 0)
    {
        if (!strcmp(cmd, "t"))
        {
            cnt_table++;
        }
        else if (!strcmp(cmd, "ch"))
        {
            cnt_chairs++;
        }
        else if (!strcmp(cmd, "c"))
        {
            cnt_cups++;
        }
        else if (!strcmp(cmd, "d"))
        {
            cnt_dishes++;
        }
        else
            printf("Unknown articule\n");

        scanf("%s", cmd);
    }
    Table table = {42.00, 8, cnt_table};
    Chair chair = {13.99, 1, cnt_chairs};
    Dishes dishes = {21.02, 6, cnt_dishes};
    Cups cups = {5.98, 6, cnt_cups};

    // printf("%d Tables\n", cnt_table);
    // printf("%d Chairs\n", cnt_chairs);
    // printf("%d Cups\n", cnt_cups);
    // printf("%d Dishes\n", cnt_dishes);

    // needed articules
    int nd_table = 0, nd_chairs = 0, nd_dishes = 0, nd_cups = 0;
    while (table.places * (table.count + table.count * nd_table) < guests || chair.places * (chair.count + chair.count * nd_chairs) < guests || cups.places * (cups.count + cups.count * nd_cups) < guests || dishes.places * (dishes.count + dishes.count * nd_dishes) < guests)
    {
        if (table.places * (table.count + table.count * nd_table) < guests)
        {
            nd_table++;
            // printf("%d\n", nd_table);
        }
        if ((chair.count + chair.places * nd_chairs) < guests)
        {
            nd_chairs++;
            printf("%d\n", nd_chairs);
        }
        if (cups.places * (cups.count + cups.count * nd_cups) < guests)
        {
            nd_cups++;
            // printf("%d\n", nd_cups);
        }
        if (dishes.places * (dishes.count + dishes.count * nd_dishes) < guests)
        {
            nd_dishes++;
            // printf("%d\n", nd_dishes);
        }
    }
    float total_price = table.price * nd_table + chair.price * nd_chairs + cups.places * nd_cups + dishes.price * nd_dishes;
    printf("%.2f\n", total_price);
    printf("%d Tables\n", nd_table);
    printf("%d Chairs\n", nd_chairs);
    printf("%d Cups\n", nd_cups);
    printf("%d Dishes\n", nd_dishes);
}

void zad_2()
{
    Product *products = (Product *)malloc(sizeof(Product));
    Order *orders = (Order *)malloc(sizeof(Order));
    int pr_counter = 1;
    int ord_counter = 1;
    char comm[5];
    fflush(stdin);
    scanf("%s", comm);
    while (strcmp(comm, "END"))
    {
        // add new product or order
        if (!strcmp(comm, "p"))
        {
            Product newProd;
            fflush(stdin);
            scanf("%[^\n]s", newProd.name);
            fflush(stdin);
            scanf("%f", &newProd.price);
            fflush(stdin);
            scanf("%d", &newProd.id);
            products[pr_counter - 1] = newProd;
            ++pr_counter;
        }
        if (!strcmp(comm, "o"))
        {
            Order newOrder;
            fflush(stdin);
            scanf("%[^\n]s", newOrder.address);
            fflush(stdin);
            scanf("%d", newOrder.id_product);
        }
        int ord_poss, pr_poss, flag = 0;
        for (int i = 0; i < ord_counter; i++)
        {
            for (int j = 0; j < pr_counter; j++)
            {
                if (orders[i].id_product == products[j].id)
                {
                    printf("Client %s orderd %s\n", orders[i].address, products[j].name);
                    ord_poss = i;
                    pr_poss = j;
                    flag = 1;
                }
            }
        }

        // delete shiped orders
        if (flag == 1)
        {
            for (int i = ord_poss - 1; i < ord_counter - 1; i++)
            {
                orders[i] = orders[i + 1];
            }
            ord_counter--;
            for (int i = pr_poss - 1; i < pr_counter - 1; i++)
            {
                products[i] = products[i + 1];
            }
            pr_counter--;
            flag = 0;
        }

        // print orders and products
        printf("Products:\n");
        for (int i = 0; i < pr_counter - 1; i++)
        {
            printf("ID: %d, Name: %s\n", products[i].id, products[i].name);
        }
        printf("\nOrders:\n");
        for (int i = 0; i < ord_counter - 1; i++)
        {
            printf("Addres: %s Id_prod: %d\n", orders[i].address, orders[i].id_product);
        }

        // next command
        scanf("%s", comm);
    }
}