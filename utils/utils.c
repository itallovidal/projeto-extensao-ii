#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "../structs/index.h"

void clearTerminal() {
  #ifdef _WIN32
      system("cls");
  #else
      system("clear");
  #endif
}

void menu(){
  clearTerminal();
  printf("\n- - - - Menu - - - - \n\n");      
  printf("1 - Cadastrar uma nova venda\n");
  printf("- - - - - - - - - - - -\n");
  printf("2 - Relatório Diário\n");
  printf("3 - Relatório Mensal\n");
  printf("4 - Relatório Anual\n");
  printf("- - - - - - - - - - - -\n");
  printf("5 - Sair");
  printf("\n\n- - - - - - - - - - \n\n");
  printf("-> ");
}

struct SaleList loadSales(){
  struct SaleList saleList = {
    .count = 0,
    .sales = malloc(sizeof(struct Sale) * 10),
  };

  FILE *file = fopen(SALES_FILE_PATH, "r");
  if (file == NULL) {
    return ;
  }

  struct Sale currentSale;
  
  while (fscanf(file, "%d %f %f %f %d %ld", 
                                          &currentSale.id, 
                                          currentSale.drinkTotal, 
                                          &currentSale.foodTotal,
                                          &currentSale.total, 
                                          &currentSale.saleType, 
                                          &currentSale.date 
                                        ) == 6) {
    saleList.sales[saleList.count] = currentSale;
    saleList.count++;

    if (saleList.count % 10 == 0) {
      saleList.sales = realloc(saleList.sales, sizeof(struct Sale) * (saleList.count + 10));
    }
  }

  fclose(file);

  return saleList;
}

void saveSale(struct Sale *sale){

  FILE *file = fopen(SALES_FILE_PATH, "r");
  if (file == NULL) {
    return ;
  }


  fprintf(file, "%d %f %f %f %d %ld \n",
                                      sale->id, 
                                      sale->drinkTotal, 
                                      sale->foodTotal,
                                      sale->total, 
                                      sale->saleType, 
                                      sale->date 
                                    );

  fclose(file);
}

