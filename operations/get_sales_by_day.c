#include <stdio.h>
#include <stdlib.h>
#include "../utils/utils.h"

struct SaleList getSalesByDay()
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
                &currentSale.drink.id,
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

void showDailySales()
{
  printf("Carregando vendas registradas..");
  printf("\n\n- - - - - - - - - - \n\n");

  struct SaleList saleList = getSalesByDay();

  printf("Total de %d vendas carregadas com sucesso.\n\n", saleList.count);

  printSales(&saleList);

  printf("Digite qualquer coisa para continuar...");

  char dummy;
  scanf(" %c", &dummy);

  return;
}