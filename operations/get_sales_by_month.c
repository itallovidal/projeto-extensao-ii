#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"
#include <string.h>

struct SaleList getSalesByMonth()
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

    while (fscanf(file, "%d %f %f %f %f %d %ld",
                  &currentSale.id,
                  &currentSale.drinkTotal,
                  &currentSale.food.weight,
                  &currentSale.food.total,
                  &currentSale.total,
                  &saleTypeTemp,
                  &currentSale.date) == 7)
    {
        currentSale.saleType = (SaleType)saleTypeTemp;
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

struct Hashmap getSalesByMonthHashmap(struct SaleList *saleList)
{
    struct Hashmap hashmap = {
        .map = malloc(sizeof(struct Map) * (saleList->count + 10)),
        .size = 0,
    };

    for (int i = 0; i < saleList->count; i++)
    {
        struct tm currentSaleTime = extractTime(saleList->sales[i].date);
        int mapIndex = getMapIndex(&hashmap, currentSaleTime.tm_mon);

        if (mapIndex != -1)
        {
            // lógica para quando o mês já existe no hashmap
            hashmap.map[mapIndex].total += saleList->sales[i].total;
            hashmap.map[mapIndex].id = currentSaleTime.tm_mon;
        }
        else
        {
            // lógica para quando o mês não existe no hashmap
            hashmap.map[hashmap.size].id = currentSaleTime.tm_mon;
            hashmap.map[hashmap.size].total = saleList->sales[i].total;
            hashmap.size++;
        }
    }

    return hashmap;
}

void showMonthlySales()
{
    printf("Carregando vendas registradas..");
    printf("\n\n- - - - - - - - - - \n\n");

    struct SaleList saleList = getSalesByMonth();
    struct Hashmap MonthlyHashmap = getSalesByMonthHashmap(&saleList);
    printf("Mês | Total \n");

    for (int i = 0; i < MonthlyHashmap.size; i++)
    {
        char monthName[12][20] = {
            "Janeiro", "Fevereiro", "Março", "Abril", "Maio",
            "Junho", "Julho", "Agosto", "Setembro", "Outubro",
            "Novembro", "Dezembro"};

        char month[20];
        strcpy(month, monthName[MonthlyHashmap.map[i].id]);

        printf("%s | R$%.2f \n", month, MonthlyHashmap.map[i].total);
    }
    printPause();

    return;
}