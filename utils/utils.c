#include <stdio.h>
#include <stdlib.h>

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