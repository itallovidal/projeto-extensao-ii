#ifndef UTILS_H
#define UTILS_H

#include "../types.h"

struct Map
{
    int id;
    float total;
};

struct Hashmap
{
    struct Map *map;
    int size;
};

int getMapIndex(struct Hashmap *hashmap, int id);
struct tm extractTime(long int timestamp);

void clearTerminal();
void menu();
void printPause();
void printSalesByMonth(struct Hashmap *monthlyHashmap);
void printSales(struct SaleList *saleList);

#endif 
