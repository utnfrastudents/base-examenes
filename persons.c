#include "persons.h"

int initPersons(sPerson list[], int length)
{
    int returnValue = -1;
    int i;

    if(list != NULL && length > 0 && length <= PERSONS_MAX)
    {
        for(i = 0 ; i < length; i++)
        {
            list[i].isEmpty = TRUE;
        }

        if(i == length)
        {
            returnValue = 0;
        }
    }

    return returnValue;
}