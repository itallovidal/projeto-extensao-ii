#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include "utils/utils.h"

int main()
{
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);
  
  int isRunning = 1;

  while (isRunning)
  {
    int option;

    menu();
    scanf("%d", &option);

    switch (option)
    {
    case 1:
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