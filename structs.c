#include "structs.h"

int structs_dateCompare(sDate date1, sDate date2)
{
    int returnValue;

    if(date1.year > date2.year)
    {
        returnValue = 1;
    }
    else
    {
        if(date1.year < date2.year)
        {
            returnValue = -1;
        }
        else
        {
            if(date1.month > date2.month)
            {
                returnValue = 1;
            }
            else
            {
                if(date1.month < date2.month)
                {
                    returnValue = -1;
                }
                else
                {
                    if(date1.day > date2.day)
                    {
                        returnValue = 1;
                    }
                    else
                    {
                        if(date1.day < date2.day)
                        {
                            returnValue = -1;
                        }
                        else
                        {
                            returnValue = 0;
                        }
                    }
                }
            }
        }
    }

    return returnValue;
}

int structs_swapDate(sDate* date1, sDate* date2)
{
    int returnValue = -1;
    sDate aux1;
    sDate aux2;

    aux1 = *date1;
    aux2 = *date2;
    *date1 = *date2;
    *date2 = aux1;

    if(!structs_dateCompare(*date1, aux2) && !structs_dateCompare(*date2, aux1))
    {
        returnValue = 0;
    }

    return returnValue;
}
