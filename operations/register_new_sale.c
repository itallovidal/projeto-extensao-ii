#include "register_new_sale.h"

struct SaleList loadSales(){
  struct SaleList saleList = {
    .count = 0,
    .sales = malloc(sizeof(struct Sale) * 10),
  };

  FILE *file = fopen(SALES_FILE_PATH, "r");
  if (file == NULL) {
    return saleList;
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

  FILE *file = fopen(SALES_FILE_PATH, "a");
  if (file == NULL) {
    return ;
  }


  fprintf(file, "%d %.2f %.2f %.2f %d %ld \n",
                                      sale->id, 
                                      sale->drinkTotal, 
                                      sale->foodTotal,
                                      sale->total, 
                                      sale->saleType, 
                                      sale->date 
                                    );

  fclose(file);
}

SaleType getSaleType(){
    while (1)
    {
        printf("Qual o tipo de venda?\n");
        printf("1 - Refeição com peso\n");
        printf("2 - Quentinha\n\n");

        char option;

        scanf(" %c", &option);

        if(option == '1'){
            return PER_KILO;
        } 

        if(option == '2'){
            printf("\nAdicionando quentinha de R$20 reais ao pedido.\n");
            return MEAL_BOX;
        }

        printf("\n\nOpção inválida. Digite 1 ou 2.\n\n");
    }
}

int checkIfhasDrink(){
    while (1)
    {
        printf("\nVocê tem bebida para acrescentar ao pedido?\n");
        printf("1 - Sim\n");
        printf("2 - Não\n\n");

        char option;
        scanf(" %c", &option);

        if(option == '1' || option == '2'){
            return (int)option - '0'; 
        } 

        printf("\n\nOpção inválida. Digite 1 ou 2.\n");
    }
}

struct DrinkData getDrinkData(){
    struct DrinkData drink = {
        .amount = 0,
        .price = 0.0f,
        .total = 0.0f
    };

    int drinkType;

    int isDrinkTypeValid = 1;
    while (isDrinkTypeValid)
    {
        printf("\nQual bebida foi consumida?\n");

        printf("1 - Refrigerante (R$5,00)\n");
        printf("2 - Cerveja (R$7,00)\n");
        printf("3 - Água (R$3,00)\n");
        printf("4 - Suco (R$6,00)\n\n");

        scanf("%d", &drinkType);


        switch (drinkType)
        {
        case 1:
            drink.price = 5.00;
            break;
        case 2:
            drink.price = 7.00;
            break;
        case 3:
            drink.price = 3.00;
            break;
        case 4:
            drink.price = 6.00;
            break;
        default:
            printf("\n\nOpção inválida. Tente novamente.\n");
            break;
        }

        if(drinkType > 0 && drinkType < 5){
            isDrinkTypeValid = 0;
        }
    }

    while (1)
    {
        printf("\nDigite a quantidade de bebidas:\n");

        scanf("%d", &drink.amount);

        if(drink.amount >= 0){
            printf("\nAdicionando %d bebida(s) ao pedido.\n", drink.amount);
            return drink;
        } else {
            printf("Quantidade inválida. Tente novamente.\n");
        }
    }
}

float getMealPrice(){
    float weight = 0.0f;

    while (1)
    {
        printf("\nDigite o peso da refeição em gramas:\n");
        scanf("%f", &weight);

        if(weight > 0.0f){
            float kilos = weight / 1000.0f;
            printf("\nPeso da refeição: %.2f gramas / %.2f quilos\n", weight, kilos);

            return kilos * KILO_PRICE;
        } 

        printf("\n\nPeso inválido. Tente novamente.\n");
    }
}

void registerNewSale(){
    struct Sale sale = {
        .id = rand() % 1000, 
        .drinkTotal = 0.0f,
        .foodTotal = 0.0f,
        .total = 0.0f,
        .saleType = PER_KILO ,
        .date = time(NULL)
    };

    printf("Registro de nova venda");
    printf("\n\n- - - - - - - - - - \n\n");
    
    sale.saleType = getSaleType();

    if(sale.saleType == 1){
        sale.foodTotal = getMealPrice();
    } 
    
    if(sale.saleType == 2){
        sale.foodTotal = 20.0f + 0.50f;
    }

    int hasDrink = checkIfhasDrink();

    if(hasDrink == 1){
        struct DrinkData drink = getDrinkData();
        sale.drinkTotal = drink.amount * drink.price;
        printf("Total em bebidas: R$%.2f\n", sale.drinkTotal);
    }

    sale.total = sale.foodTotal + sale.drinkTotal;
    printf("\nTotal da Refeição: R$%.2f\n", sale.total);
    printf("- - - - - - - - - - - -\n");

    saveSale(&sale);

    printf("Venda registrada com sucesso!\n\n");
    printf("Digite qualquer coisa para continuar.\n");
    scanf(" %c");


    return;
}