#include "./database.h"

// Toda vez que uma venda é realizada, guardamos no TXT
// as informacões com uma ordem específica. Isso faz com que
// na leitura, consigamos montar um vetor de vendas com mais
// facilidade

void saveSale(struct Sale *sale)
{
    FILE *file = fopen(SALES_FILE_PATH, "a");
    if (file == NULL)
    {
        return;
    }

    fprintf(file, "%d %d %.2f %.2f %d %.2f %.2f %.2f %d %ld \n",
            sale->id,
            sale->drink.id,
            sale->drink.total,
            sale->drink.price,
            sale->drink.amount,
            sale->food.weight,
            sale->food.total,
            sale->total,
            sale->saleType,
            sale->date);

    fclose(file);
}

struct SaleList getAllSales()
{
    struct SaleList saleList = {
        .count = 0,
        .sales = malloc(sizeof(struct Sale) * 10),
    };

    FILE *file = fopen(SALES_FILE_PATH, "r");
    if (file == NULL)
    {
        return saleList;
    }

    struct Sale currentSale;

    int saleTypeTemp;
    int drinkType;

    while (fscanf(file, "%d %d %f %f %d %f %f %f %d %ld",
                  &currentSale.id,
                  &drinkType,
                  &currentSale.drink.total,
                  &currentSale.drink.price,
                  &currentSale.drink.amount,
                  &currentSale.food.weight,
                  &currentSale.food.total,
                  &currentSale.total,
                  &saleTypeTemp,
                  &currentSale.date) == 10)
    {
        currentSale.saleType = (SaleType)saleTypeTemp;
        currentSale.drink.id = (enum DrinkType)drinkType;
        saleList.sales[saleList.count] = currentSale;
        saleList.count++;

        if (saleList.count % 10 == 0)
        {
            saleList.sales = realloc(saleList.sales, sizeof(struct Sale) * (saleList.count + 10));
        }
    }

    fclose(file);

    return saleList;
}