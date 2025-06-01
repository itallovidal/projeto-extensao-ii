#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"

#define KILO_PRICE 50.0f

void registerNewSale();

struct DrinkData{
    int amount;
    float price;
    float total;
};

typedef enum {
    PER_KILO = 1,
    MEAL_BOX,
} SaleType;

struct Sale {
    int id;
    float drinkTotal;
    float foodTotal;
    float total;
    SaleType saleType;
};

