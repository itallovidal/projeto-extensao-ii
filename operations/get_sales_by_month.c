#include "./get_sales_by_month.h"

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

    struct SaleList saleList = getAllSales();
    struct Hashmap monthlyHashmap = getSalesByMonthHashmap(&saleList);
    sortMonthSalesByTotal(&monthlyHashmap);
    printSalesByMonth(&monthlyHashmap);
    printPause();

    return;
}