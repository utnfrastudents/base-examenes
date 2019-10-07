#include "structs.h"

int structs_isDate(sDate date)
{
    int returnValue = 0;

    if(date.year >= YEAR_MIN && date.year <= YEAR_MAX
        && date.month >= MONTH_MIN && date.month <= MONTH_MAX)
    {
        switch (date.month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if(date.day >= DAY_MIN && date.day <= DAY_31)
                {
                    returnValue = 1;
                }
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if(date.day >= DAY_MIN && date.day <= DAY_30)
                {
                    returnValue = 1;
                }
                break;
            case 2:
                if((date.year % 4 == 0 && date.day >= DAY_MIN && date.day <= DAY_29)
                    || (date.year % 4 != 0 && date.day >= DAY_MIN && date.day <= DAY_28))
                {
                    returnValue = 1;
                }
                break;
        }
    }

    return returnValue;
}

int structs_dateCompare(sDate date1, sDate date2)
{
    int returnValue = -2;

    if(structs_isDate(date1) && structs_isDate(date2))
    {
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
    }

    return returnValue;
}

int structs_swapDate(sDate* date1, sDate* date2)
{
    int returnValue = ERROR;
    sDate aux1;
    sDate aux2;

    aux1 = *date1;
    aux2 = *date2;
    *date1 = *date2;
    *date2 = aux1;

    if(!structs_dateCompare(*date1, aux2) && !structs_dateCompare(*date2, aux1))
    {
        returnValue = OK;
    }

    return returnValue;
}

int structs_personsCompare(sPerson person1, sPerson person2)
{
    int compare = -2;

    /**< Si el ID del primero es menor al ID del segundo, son diferentes y el ID 1 es menor. >*/
    if(person1.idPerson < person2.idPerson)
    {
        compare = 1;
    }
    else
    {
        /**< Si el ID del primero es mayor al ID del segundo, son diferentes y el ID 2 es menor. >*/
        if(person1.idPerson > person2.idPerson)
        {
            compare = -1;
        }
        else
        {
            if(person1.idPerson == person2.idPerson)
            {
                /**< Si sus ID son iguales y tienen el mismo estado, como no pueden repetirse se toman como Personas iguales. >*/
                if(person1.isEmpty == person2.isEmpty)
                {
                    compare = 0;
                }
                else
                {
                    /**< Si sus ID son iguales y la Persona 2 esta inactiva, la Persona 1 es mayor. >*/
                    if(person1.isEmpty == FALSE && person2.isEmpty == TRUE)
                    {
                        compare = 1;
                    }
                    else
                    {
                        /**< Si sus ID son iguales y la Entidad 1 esta inactiva, la Entidad 2 es mayor. >*/
                        if(person1.isEmpty == TRUE && person2.isEmpty == FALSE)
                        {
                            compare = -1;
                        }
                    }
                }
            }
        }
    }

    return compare;
}

int structs_swapPersons(sPerson* person1, sPerson* person2)
{
    int returnValue = ERROR;
    sPerson aux1;
    sPerson aux2;

    if(person1->isEmpty == FALSE && person2->isEmpty == FALSE)
    {
        aux1 = *person1;
        aux2 = *person2;
        *person1 = *person2;
        *person2 = aux1;

        if(!structs_personsCompare(*person1, aux2) && !structs_personsCompare(*person2, aux1))
        {
            returnValue = OK;
        }
    }

    return returnValue;
}

int structs_entitiesCompare(sEntity entity1, sEntity entity2)
{
    int compare = -2;

    /**< Si el ID del primero es menor al ID del segundo, son diferentes y el ID 1 es menor. >*/
    if(entity1.idEntity < entity2.idEntity)
    {
        compare = 1;
    }
    else
    {
        /**< Si el ID del primero es mayor al ID del segundo, son diferentes y el ID 2 es menor. >*/
        if(entity1.idEntity > entity2.idEntity)
        {
            compare = -1;
        }
        else
        {
            if(entity1.idEntity == entity2.idEntity)
            {
                /**< Si sus ID son iguales y tienen el mismo estado, como no pueden repetirse se toman como Entidades iguales. >*/
                if(entity1.isEmpty == entity2.isEmpty)
                {
                    compare = 0;
                }
                else
                {
                    /**< Si sus ID son iguales y la Entidad 2 esta inactiva, la Entidad 1 es mayor. >*/
                    if(entity1.isEmpty == FALSE && entity2.isEmpty == TRUE)
                    {
                        compare = 1;
                    }
                    else
                    {
                        /**< Si sus ID son iguales y la Entidad 1 esta inactiva, la Entidad 2 es mayor. >*/
                        if(entity1.isEmpty == TRUE && entity2.isEmpty == FALSE)
                        {
                            compare = -1;
                        }
                    }
                }
            }
        }
    }

    return compare;
}

int structs_swapEntities(sEntity* entity1, sEntity* entity2)
{
    int returnValue = ERROR;
    sEntity aux1;
    sEntity aux2;

    if(entity1->isEmpty == FALSE && entity2->isEmpty == FALSE)
    {
        aux1 = *entity1;
        aux2 = *entity2;
        *entity1 = *entity2;
        *entity2 = aux1;

        if(!structs_entitiesCompare(*entity1, aux2) && !structs_entitiesCompare(*entity2, aux1))
        {
            returnValue = OK;
        }
    }

    return returnValue;
}
