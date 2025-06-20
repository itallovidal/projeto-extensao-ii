#include "./register_new_sale.h"

// No registro de uma Nova Venda, nós temos basicamente duas opcões
// A opcão de adicionar a venda como tipo quentinha, e como tipo peso

// No tipo quentinha os valores serão fixos, como consta no PDF.
// No tipo peso os valores variam com base no peso do KG.

SaleType getSaleType()
{
    while (1)
    {
        printf("Qual o tipo de venda?\n");
        printf("1 - Refeição com peso\n");
        printf("2 - Quentinha\n\n");

        char option;

        scanf(" %c", &option);

        if (option == '1')
        {
            return PER_KILO;
        }

        if (option == '2')
        {
            printf("\nAdicionando quentinha de R$20 reais ao pedido.\n");
            return MEAL_BOX;
        }

        printf("\n\nOpção inválida. Digite 1 ou 2.\n\n");
    }
}

int checkIfhasDrink()
{
    while (1)
    {
        printf("\nVocê tem bebida para acrescentar ao pedido?\n");
        printf("1 - Sim\n");
        printf("2 - Não\n\n");

        char option;
        scanf(" %c", &option);

        if (option == '1' || option == '2')
        {
            return (int)option - '0';
        }

        printf("\n\nOpção inválida. Digite 1 ou 2.\n");
    }
}

struct Drink getDrinkData()
{
    struct Drink drink = {
        .id = 0,
        .amount = 0,
        .price = 0.0f,
        .total = 0.0f,
    };

    int drinkType;

    int keepAskingDrink = 1;
    while (keepAskingDrink)
    {
        printf("\nQual bebida foi consumida?\n");

        printf("1 - Refrigerante (R$5,00)\n");
        printf("2 - Cerveja (R$7,00)\n");
        printf("3 - Água (R$3,00)\n");
        printf("4 - Suco (R$6,00)\n\n");

        scanf("%d", &drinkType);

        switch (drinkType)
        {
        case SODA:
            drink.price = 5.00;
            break;
        case BEER:
            drink.price = 7.00;
            break;
        case WATER:
            drink.price = 3.00;
            break;
        case JUICE:
            drink.price = 6.00;
            break;
        default:
            printf("\n\nOpção inválida. Tente novamente.\n");
            break;
        }

        if (drinkType > 0 && drinkType < 5)
        {
            keepAskingDrink = 0;
            drink.id = drinkType;
        }
    }

    while (1)
    {
        printf("\nDigite a quantidade de bebidas:\n");

        scanf("%d", &drink.amount);

        if (drink.amount >= 0)
        {
            printf("\nAdicionando %d bebida(s) ao pedido.\n", drink.amount);
            drink.total = drink.amount * drink.price;

            return drink;
        }

        printf("Quantidade inválida. Tente novamente.\n");
    }
}

struct Food getMealPrice()
{
    struct Food food = {
        .weight = 0.0f,
        .total = 0.0f,
    };

    while (1)
    {
        printf("\nDigite o peso da refeição em gramas:\n");
        scanf("%f", &food.weight);

        if (food.weight > 0.0f)
        {
            float kilos = food.weight / 1000.0f;
            printf("\nPeso da refeição: %.2f gramas / %.2f quilos\n", food.weight, kilos);

            food.total = kilos * KILO_PRICE;

            return food;
        }

        printf("\n\nPeso inválido. Tente novamente.\n");
    }
}

void registerNewSale()
{
    struct Sale sale = {
        .id = rand() % 1000,
        .drink = {
            .amount = 0,
            .id = 0,
            .price = 0.0f,
            .total = 0.0f,
        },
        .food = {
            .weight = 0.0f,
            .total = 0.0f,
        },
        .total = 0.0f,
        .saleType = PER_KILO,
        .date = time(NULL)};

    printf("Registro de nova venda");
    printf("\n\n- - - - - - - - - - \n\n");

    sale.saleType = getSaleType();

    if (sale.saleType == 1)
    {
        sale.food = getMealPrice();
    }

    if (sale.saleType == 2)
    {
        sale.food.total = 20.0f + 0.50f;
    }

    int hasDrink = checkIfhasDrink();

    if (hasDrink == 1)
    {
        sale.drink = getDrinkData();
        printf("Total em bebidas: R$%.2f\n", sale.drink.total);
    }

    sale.total = sale.food.total + sale.drink.total;
    printf("\nTotal da Refeição: R$%.2f\n", sale.total);
    printf("- - - - - - - - - - - -\n");

    saveSale(&sale);

    printf("Venda registrada com sucesso!\n\n");
    printf("Digite qualquer coisa para continuar.\n");


    return;
}
