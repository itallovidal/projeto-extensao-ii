#include "./utils.h"

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
  printf("4 - Organizar Vendas por Data\n");
  printf("5 - Sair");
  printf("\n\n- - - - - - - - - - \n\n");
  printf("-> ");
}

void printSales(struct SaleList *saleList)
{
  printf("\tid\t|\tTotal\t|\tRefeição\t|\tBebida\t|\tQtd.\t|\tData e Hora\t\n");

  float total = 0;

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
      break;
    default:
      strcpy(meal, "N/A");
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

    struct tm saleTime = extractTime(saleList->sales[i].date);
    char dateStr[32];
    sprintf(dateStr, "%02d/%02d/%d %02d:%02d",
            saleTime.tm_mday,
            saleTime.tm_mon + 1,
            saleTime.tm_year + 1900,
            saleTime.tm_hour,
            saleTime.tm_min);

    printf("\t%d\t|\tR$%.2f\t|\t%s\t|%-15s|\t%d\t|\t%s\t\n",
           saleList->sales[i].id,
           saleList->sales[i].total,
           meal,
           drink,
           saleList->sales[i].drink.amount,
           dateStr);

    total += saleList->sales[i].total;
  }

  printf("\nO total de vendas até hoje foi de: R$%.2f\n\n", total);
}

void printSalesByMonth(struct Hashmap *monthlyHashmap)
{
  printf("\tMês\t|\tTotal\t\n");

  for (int i = 0; i < monthlyHashmap->size; i++)
  {
    char monthName[12][20] = {
        "Janeiro", "Fevereiro", "Março", "Abril", "Maio",
        "Junho", "Julho", "Agosto", "Setembro", "Outubro",
        "Novembro", "Dezembro"};

    char month[20];
    strcpy(month, monthName[monthlyHashmap->map[i].id]);

    printf("%-18s|\tR$%.2f\t\n", month, monthlyHashmap->map[i].total);
  }
}

struct tm extractTime(long int timestamp)
{
  time_t rawTime = (time_t)timestamp;
  struct tm formattedDate;

#ifdef _WIN32
  formattedDate = *localtime(&rawTime);
#else
  formattedDate = *gmtime(&rawTime);
#endif

  return formattedDate;
}

void printPause()
{
  printf("\nPressione Enter para continuar...");
  getchar();
  getchar();
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
