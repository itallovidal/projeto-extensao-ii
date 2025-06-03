#define KILO_PRICE 50.0f
#define SALES_FILE_PATH "sales.txt"
#include <time.h>

struct Drink
{
    int amount;
    float price;
    float total;
    int id;
};

struct Food
{
    float weight;
    float total;
};

typedef enum
{
    PER_KILO = 1,
    MEAL_BOX,
} SaleType;

struct Sale
{
    int id;
    struct Drink drink; 
    struct Food food;
    float total;
    SaleType saleType;
    time_t date;
};

struct SaleList
{
    int count;
    struct Sale *sales;
};