#include "entities.h"

/** \brief Funcion privada que imprime en pantalla
 *      un tipo de dato basado en Entidad.
 * 
 * \param entity sEntity Tipo de Dato basado en Entidad.
 * \return int
 *      [-1] Si hubo un error en la impresion de los datos de la Entidad.
 *      [0] Si la impresion de la Entidad fue exitosa.
 * 
 */
static int printEntity(sEntity entity);

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

int entities_getById(sEntity list[], int length, int id)
{
    int returnValue = ERROR;

    if(list != NULL && length > 0 && length <= ENTITIES_MAX)
    {
        for (int i = 0; i < length; i++)
        {
            if(list[i].idEntity == id && list[i].isEmpty == FALSE)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int entities_selection(char message[], char eMessage[], sEntity entitiesList[], int entitiesLength)
{
    int returnValue = ERROR;
    int auxId = 0;
    int auxIndex = 0;

    if(message != NULL && eMessage != NULL && entitiesList != NULL
        && entitiesLength > 0 && entitiesLength <= ENTITIES_MAX
        && entities_printList(entitiesList, entitiesLength) > 0
        && !inputs_getInt(&auxId, message, eMessage, ID_INIT_ENTITY + 1, ENTITIES_MAX + ID_INIT_ENTITY))
    {
        auxIndex = entities_getById(entitiesList, entitiesLength, auxId);

        if(auxIndex != ERROR)
        {
            returnValue = auxId;
        }
        else
        {
            printf("No se encuentra el ID de la Entidad en el sistema.\n");
        }
    }

    return returnValue;
}

int entities_printList(sEntity entitiesList[], int entitiesLength)
{
    int itemsCounter = 0;
    int flag = 0;

    if(entitiesList != NULL && entitiesLength > 0 && entitiesLength <= ENTITIES_MAX)
    {
        for (int i = 0; i < entitiesLength; i++)
        {
            if(entitiesList[i].isEmpty == FALSE)
            {
                itemsCounter++;

                if(itemsCounter == 1)
                {
                    printf("+======+======================+\n");
                    printf("|  ID  |     Descripcion      |\n");
                    printf("+======+======================+\n");
                }

                if(!printEntity(entitiesList[i]))
                {
                    flag = 1;
                }
                else
                {
                    flag = 0;
                    break;
                }

            }
        }

        if(flag == 1)
        {
            printf("+------+----------------------+\n");
        }
    }

    return itemsCounter;
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

static int printEntity(sEntity entity)
{
    int returnValue = ERROR;

    if(entity.isEmpty == FALSE)
    {
        printf("| %4d | %20s |\n", entity.idEntity,
            arrays_stringToCamelCase(entity.description, ENTITY_NAME_MAX));

        returnValue = OK;
    }

    return returnValue;
}
