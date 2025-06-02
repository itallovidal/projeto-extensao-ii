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

void clearTerminal();
void menu();
void printPause();

void printSales(struct SaleList *saleList);
struct tm extractTime(long int timestamp);
int getMapIndex(struct Hashmap *hashmap, int id);