#include "./sort_txt.h"

void sortTXT()
{
    printf("\nReorganizando vendas.. um momento.\n");
    struct SaleList saleList = getAllSales();
    sortSalesByDate(&saleList);

    char file[] = SALES_FILE_PATH;
    remove(file);

    for (int i = 0; i < saleList.count; i++)
    {
        saveSale(&saleList.sales[i]);
    }

    printf("\nVendas reorganizadas por data com sucesso.\n\n");

    printf("\nDigite qualquer coisa para continuar...");

}
