#include <windows.h>
#include "utils/utils.h"
#include "operations/register_new_sale.h"

int main()
{
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
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
      break;
    case 3:
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