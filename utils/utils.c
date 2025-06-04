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
  printf(" id | Total | Refeição | Bebida Consumida | Quantidade de Bebidas    \n");

  for (int i = 0; i < saleList->count; i++)
  {
    char meal[24] = "";
    char drink[24] = "";

    switch (saleList->sales[i].saleType)
    {
    case PER_KILO:
      sprintf(meal, "%.2f gramas", saleList->sales[i].food.weight);
      break;
    case MEAL_BOX:
      strcpy(meal, "Quentinha");
    default:
      break;
    }

    switch (saleList->sales[i].drink.id)
    {
    case SODA:
      strcpy(drink, "Refrigerante");
      break;
    case BEER:
      strcpy(drink, "Cerveja");
      break;
    case WATER:
      strcpy(drink, "Água");
      break;
    case JUICE:
      strcpy(drink, "Suco");
      break;

    default:
      strcpy(drink, "N/A");
      break;
    }

    printf("%d | R$%.f | %s | %s | %d\n", saleList->sales[i].id, saleList->sales[i].total, meal, drink, saleList->sales[i].drink.amount);
  }
}

void printSalesByMonth(struct Hashmap *monthlyHashmap)
{
  printf("Mês | Total \n");

  for (int i = 0; i < monthlyHashmap->size; i++)
  {
    char monthName[12][20] = {
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio",
        "Junho", "Julho", "Agosto", "Setembro", "Outubro",
        "Novembro", "Dezembro"};

    char month[20];
    strcpy(month, monthName[monthlyHashmap->map[i].id]);

    printf("%s | R$%.2f \n", month, monthlyHashmap->map[i].total);
  }
}

struct tm extractTime(long int timestamp)
{
  time_t rawTime = (time_t)timestamp;
  struct tm formattedDate;

#ifdef _WIN32
  localtime_s(&formattedDate, &rawTime);
#else
  formattedDate = *gmtime(&rawTime);
#endif

  return formattedDate;
}

void printPause()
{
  printf("\nDigite qualquer coisa para continuar...");

  char dummy;
  scanf(" %c", &dummy);
}

int getMapIndex(struct Hashmap *hashmap, int id)
{
  for (int i = 0; i < hashmap->size; i++)
  {
    if (hashmap->map[i].id == id)
    {
      return i;
    }
  }

  return -1;
}