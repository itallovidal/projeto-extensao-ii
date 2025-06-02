#include "operations/register_new_sale.h"
#include "operations/get_sales_by_day.h"
#include "operations/get_sales_by_month.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main()
{
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));

  int isRunning = 1;

  while (isRunning)
  {
    int option;

    menu();
    scanf("%d", &option);

    clearTerminal();

    switch (option)
    {
    case 1:
      registerNewSale();
      break;
    case 2:
      showDailySales();
      break;
    case 3:
      showMonthlySales();
      break;
    case 4:
      break;
    case 5:
      isRunning = 0;
      break;
    default:
      break;
    }
  }

  return 0;
}