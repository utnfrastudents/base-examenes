#include "entities.h"

int entities_getNewId(void)
{
    static int idEntity = ID_INIT_ENTITY;
    idEntity++;
    return idEntity;
}

int entities_init(sEntity list[], int length)
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

void entities_hardcode(sEntity list[], int length, int quantity)
{
    sEntity auxEntity[] = {
        {entities_getNewId(), "entidad 1"},
        {entities_getNewId(), "entidad 2"},
        {entities_getNewId(), "entidad 3"},
        {entities_getNewId(), "entidad 4"},
        {entities_getNewId(), "entidad 5"}
    };

    if(list != NULL && quantity <= ENTITIES_MAX && length >= quantity)
    {
        for (int i = 0; i < quantity; i++)
        {
            list[i] = auxEntity[i];
        }
    }
}