#include "persons.h"

int persons_init(sPerson list[], int length)
{
    int returnValue = ERROR;
    int i;

    if(list != NULL && length > 0 && length <= PERSONS_MAX)
    {
        for(i = 0 ; i < length; i++)
        {
            list[i].isEmpty = TRUE;
        }

        if(i == length)
        {
            returnValue = OK;
        }
    }

    return returnValue;
}

int persons_getNewId(void)
{
    static int idPerson = ID_INIT_PERSON;
    idPerson++;
    return idPerson;
}

int persons_getEmptyIndex(sPerson list[], int length)
{
    int returnValue = -1;

    if(list != NULL && length > 0 && length <= PERSONS_MAX)
    {
        for (int i = 0; i < length; i++)
        {
            if(list[i].isEmpty == TRUE)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}
