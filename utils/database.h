#ifndef DATABASE_H
#define DATABASE_H

#include "../types.h"

struct SaleList getAllSales();
void saveSale(struct Sale *sale);

#endif