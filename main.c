#include "operations/register_new_sale.h"
#include "operations/get_sales_by_day.h"
#include "operations/get_sales_by_month.h"
#include "utils/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main()
{
  setlocale(LC_ALL, "Portuguese");
  srand(time(NULL));

  int isRunning = 1;

  while (isRunning)
  {
    int option;
    int shouldPause = 0;

    menu();
    scanf("%d", &option);

    clearTerminal();

    switch (option)
    {
   case 1:
      registerNewSale();
      shouldPause = 1;
      break;
    case 2:
      showDailySales();
      shouldPause = 1;
      break;
    case 3:
      showMonthlySales();
      shouldPause = 1;
      break;
    case 4:
      break;
    case 5:
      isRunning = 0;
      break;
    default:
      break;
    }
    
    if (shouldPause)
      printPause();
  }

  return 0;
}
