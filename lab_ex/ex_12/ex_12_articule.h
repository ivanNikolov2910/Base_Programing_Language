#ifndef EX12_HEADER_FILE
#define EX12_HEADER_FILE

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// zad 1: articules in store each: name, brand, price, quantity n from stdin
// function input for articules, function output avr price, sort by name and print

typedef struct Articule
{
    char name[20];
    char brand[20];
    double price;
    int quantity;
} Articule;

Articule inputArticule();
void inputNewArticule(Articule *, int *);
void printAllArt(Articule *, int);
void printAvrPrice(Articule *, int);
void printNamesSorted(Articule *, int);

void zad_1()
{
    printf("Enter articules count: ");
    int size;
    scanf("%d", &size);
    Articule *articules = (Articule *)malloc(sizeof(Articule) * size);
    for (int i = 0; i < size; i++)
    {
        articules[i] = inputArticule();
    }

    printAllArt(articules, size);
    printf("\n");
    printAvrPrice(articules, size);

    printf("\n");
    printNamesSorted(articules, size);
}

Articule inputArticule()
{
    Articule articule;
    printf("Atricule name: ");
    scanf("%s[^\n]", articule.name);
    printf("Atricule brand: ");
    scanf("%s[^\n]", articule.brand);
    printf("Atricule price: ");
    scanf("%lf", &articule.price);
    printf("Atricule quantity: ");
    scanf("%d", &articule.quantity);
    return articule;
}

void inputNewArticule(Articule *articules, int *size)
{
    ++(*size);
    articules = (Articule *)realloc(articules, *size);
    printf("Atricule name: ");
    scanf("%s[^\n]", articules[*size - 1].name);
    printf("Atricule brand: ");
    scanf("%s[^\n]", articules[*size - 1].brand);
    printf("Atricule price: ");
    scanf("%lf", &articules[*size - 1].price);
    printf("Atricule quantity: ");
    scanf("%d", &articules[*size - 1].quantity);
}

void printAvrPrice(Articule *articules, int size)
{
    double avr_price = 0;
    int quantity_all = 0;
    for (int i = 0; i < size; i++)
    {
        quantity_all += articules[i].quantity;
        avr_price += articules[i].price;
    }
    printf("Average price in store: %.2f\n", avr_price / quantity_all);
}

void printNamesSorted(Articule *articules, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (strcmp(articules[j].name, articules[i].name) < 0)
            {
                Articule temp = articules[i];
                articules[i] = articules[j];
                articules[j] = temp;
            }
        }
    }

    for (int i = 0; i < size; i++)
    {
        printf("%s ", articules[i].name);
    }
}

void printAllArt(Articule *articules, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("Name %s: %s - %.2lflv - Quantity: %d\n", articules[i].name, articules[i].brand, articules[i].price, articules[i].quantity);
    }
}

#endif