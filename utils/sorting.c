#include "./sorting.h"

// selection sort
void sortSalesByDate(struct SaleList *saleList)
{
    for (int i = 0; i < saleList->count; i++)
    {
        int highestNumberPosition = i;
        for (int j = i + 1; j < saleList->count; j++)
        {
            if (saleList->sales[j].date < saleList->sales[highestNumberPosition].date)
            {
                highestNumberPosition = j;
            }
        }

        if (highestNumberPosition != i)
        {
            struct Sale temp = saleList->sales[i];
            saleList->sales[i] = saleList->sales[highestNumberPosition];
            saleList->sales[highestNumberPosition] = temp;
        }
    }
}
void sortMonthSalesByTotal(struct Hashmap *monthlyHashmap)
{
    for (int i = 0; i < monthlyHashmap->size; i++)
    {
        for (int j = 0; j < monthlyHashmap->size - i; j++)
        {
            if (monthlyHashmap->map[j].total < monthlyHashmap->map[j + 1].total)
            {
                struct Map temp = monthlyHashmap->map[j];
                monthlyHashmap->map[j] = monthlyHashmap->map[j + 1];
                monthlyHashmap->map[j + 1] = temp;
            }
        }
    }
}