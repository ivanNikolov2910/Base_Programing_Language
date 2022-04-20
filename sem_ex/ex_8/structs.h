typedef struct Table
{
    float price;
    int places;
    int count;
} Table;

typedef struct Chair
{
    float price;
    int places;
    int count;
} Chair;

typedef struct Cups
{
    float price;
    int places;
    int count;
} Cups;

typedef struct Dishes
{
    float price;
    int places;
    int count;
} Dishes;

//////////////////////////////////////

typedef struct Product
{
    int id;
    char name[20];
    float price;
} Product;

typedef struct Order
{
    int id_product;
    char address[100];
} Order;