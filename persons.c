#include "persons.h"

int persons_getNewId(void)
{
    static int idPerson = ID_INIT_PERSON;
    idPerson++;
    return idPerson;
}

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

int persons_getById(sPerson list[], int length, int id)
{
    int returnValue = ERROR;

    if(list != NULL && length > 0 && length <= PERSONS_MAX)
    {
        for (int i = 0; i < length; i++)
        {
            if(list[i].idPerson == id)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int person_add(sPerson list[], int length)
{
    int returnValue = ERROR;
    int newId;
    int emptyIndex;

    if(list != NULL && length > 0 && length <= PERSONS_MAX)
    {
        newId = persons_getNewId();

        if(persons_getById(list, length, newId) == ERROR)
        {
            emptyIndex = persons_getEmptyIndex(list, length);

            if(emptyIndex != ERROR)
            {
                list[emptyIndex].idPerson = newId;
                if(!inputs_getString(list[emptyIndex].name, "Ingrese el Nombre: ", ERROR_MESSAGE, 1, PERSON_NAME_MAX)
                    && !inputs_getString(list[emptyIndex].lastName, "Ingrese el Apellido: ", ERROR_MESSAGE, 1, PERSON_LASTNAME_MAX))
                {
                    list[emptyIndex].isEmpty = FALSE;
                    returnValue = OK;
                }
            }
        }
    }

    return returnValue;
}
