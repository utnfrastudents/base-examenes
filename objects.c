#include "objects.h"

/** \brief Funcion que devuelve un Objeto nulo.
 * 
 * \param void No tiene parametros.
 * \return void No tiene retorno.
 * 
 */
static sObject nullObject();

int objects_getNewId(void)
{
    static int idObject = ID_INIT_OBJECT;
    idObject++;
    return idObject;
}

void objets_hardcode(sObject objectsList[], int objectsLength)
{
    int indexHardcodeMax = 9;

    sObject auxObjects[OBJECTS_MAX] = {
        {objects_getNewId(), 1005, "objeto 01", Tipo2, FALSE},
        {objects_getNewId(), 1002, "objeto 02", Tipo1, FALSE},
        {objects_getNewId(), 1005, "objeto 03", Tipo3, FALSE},
        {objects_getNewId(), 1001, "objeto 04", Tipo2, FALSE},
        {objects_getNewId(), 1004, "objeto 05", Tipo2, FALSE},
        {objects_getNewId(), 1008, "objeto 06", Tipo1, FALSE},
        {objects_getNewId(), 1006, "objeto 07", Tipo2, FALSE},
        {objects_getNewId(), 1007, "objeto 08", Tipo3, FALSE},
        {objects_getNewId(), 1008, "objeto 09", Tipo3, FALSE},
        {objects_getNewId(), 1001, "objeto 10", Tipo1, FALSE}
    };

    if(objectsList != NULL && objectsLength > 0 && objectsLength <= OBJECTS_MAX)
    {
        for (int i = 0; i < objectsLength; i++)
        {
            if(i <= indexHardcodeMax)
            {
                objectsList[i] = auxObjects[i];
            }
            else
            {
                objectsList[i] = nullObject();
            }
        }
    }
}

static sObject nullObject()
{
    sObject aux;

    aux.idObject = -1;
    aux.idPerson = -1;
    aux.type = null;
    strcpy(aux.description, structs_getObjectType(aux));
    aux.isEmpty = TRUE;

    return aux;
}