#include "register_new_sale.h"

SaleType getSaleType(){
    while (1)
    {
        printf("Qual o tipo de venda?\n");
        printf("1 - Refeição com peso\n");
        printf("2 - Quentinha\n");

        char option;

        scanf(" %c", &option);

        if(option == '1'){
            return PER_KILO;
        } 

        if(option == '2'){
            return MEAL_BOX;
        }

        printf("Opção inválida. Digite 1 ou 2.\n");
    }
}

int checkIfhasDrink(){
    while (1)
    {
        printf("Você tem bebida para acrescentar ao pedido?\n");
        printf("1 - Sim\n");
        printf("2 - Não\n");

        char option;
        scanf(" %c", &option);

        if(option == '1' || option == '2'){
            return (int)option - '0'; 
        } else {
            printf("Opção inválida. Digite 1 ou 2.\n");
        }
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
        printf("Qual bebida foi consumida?\n");

        printf("1 - Refrigerante (R$5,00)\n");
        printf("2 - Cerveja (R$7,00)\n");
        printf("3 - Água (R$3,00)\n");
        printf("4 - Suco (R$6,00)\n");

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
            printf("Opção inválida. Tente novamente.\n");
            break;
        }

        if(drinkType > 0 && drinkType < 5){
            isDrinkTypeValid = 0;
        }
    }

    while (1)
    {
        printf("Digite a quantidade de bebidas:\n");

        scanf("%d", &drink.amount);

        if(drink.amount >= 0){
            printf("Adicionando %d bebida(s) ao pedido.\n", drink.amount);
            return drink;
        } else {
            printf("Quantidade inválida. Tente novamente.\n");
        }
    }
}

void registerNewSale(){
    struct Sale sale = {
        .id = rand() % 1000, 
        .drinkTotal = 0.0f,
        .foodTotal = 0.0f,
        .total = 0.0f,
        .saleType = PER_KILO 
    };

    printf("Registro de nova venda");
    printf("\n\n- - - - - - - - - - \n\n");
    
    sale.saleType = getSaleType();

    if(sale.saleType == 1){
        // adicionar lógica para registro com peso
    } 
    
    if(sale.saleType == 2){
        printf("Adicionando quentinha de R$20 reais ao pedido.\n");
        sale.foodTotal = 20.0f + 0.50f;
    }

    int hasDrink = checkIfhasDrink();

    if(hasDrink == 1){
        struct DrinkData drink = getDrinkData();
        sale.drinkTotal = drink.amount * drink.price;
        printf("Total de bebidas: R$%.2f\n", sale.drinkTotal);
    }

    sale.total = sale.foodTotal + sale.drinkTotal;
    printf("Total da venda: R$%.2f\n", sale.total);

    // TODO: salvar no TXT

    return;
}