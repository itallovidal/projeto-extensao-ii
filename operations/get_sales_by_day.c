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

  while (fscanf(file, "%d %f %f %f %d %ld",
                &currentSale.id,
                &currentSale.drinkTotal,
                &currentSale.foodTotal,
                &currentSale.total,
                &currentSale.saleType,
                &currentSale.date) == 6)
  {
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
  scanf(" %c");

  return;
}