#include "./utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


void clearTerminal()
{
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

void menu()
{
  clearTerminal();
  printf("\n- - - - Menu - - - - \n\n");
  printf("1 - Cadastrar uma nova venda\n");
  printf("- - - - - - - - - - - -\n");
  printf("2 - Relatório Diário\n");
  printf("3 - Relatório Mensal\n");
  printf("- - - - - - - - - - - -\n");
  printf("5 - Sair");
  printf("\n\n- - - - - - - - - - \n\n");
  printf("-> ");
}

void printSales(struct SaleList *saleList)
{
  printf(" id | Total | Refeição  \n");

  for (int i = 0; i < saleList->count; i++)
  {
    char meal[24] = "";

    switch (saleList->sales[i].saleType)
    {
    case PER_KILO:
      // TODO: implementar print de refeições por kilo
      break;
    case MEAL_BOX:
    strcpy(meal, "Quentinha");
    default:
      break;
    }


    printf("%d | R$%.f | \n", saleList->sales[i].id, saleList->sales[i].total, meal);
  }
}
