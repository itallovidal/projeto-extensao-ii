#include "./get_sales_by_day.h"

void showDailySales()
{
  printf("Carregando vendas registradas..");
  printf("\n\n- - - - - - - - - - \n\n");

  struct SaleList saleList = getAllSales();

  printf("Total de %d vendas carregadas com sucesso.\n\n", saleList.count);

  printSales(&saleList);

  printf("Digite qualquer coisa para continuar...");
  printPause();
  return;
}
