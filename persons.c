#include "persons.h"

/** \brief Funcion privada que imprime en pantalla
 *      un tipo de dato basado en Persona.
 * 
 * \param person sPerson Tipo de Dato basado en Persona.
 * \param entitiesList[] sPerson Direccion de memoria del inicio del arreglo de tipo Entidad.
 * \param entitiesLength int Longitud del arreglo de tipo Entidad.
 * \return int
 *      [-1] Si hubo un error en la impresion de los datos de la Persona.
 *      [0] Si la impresion de la Persona fue exitosa.
 * 
 */
static int printPerson(sPerson person, sEntity entitiesList[], int entitiesLength);

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
            if(list[i].idPerson == id && list[i].isEmpty == FALSE)
            {
                returnValue = i;
                break;
            }
        }
    }

    return returnValue;
}

int persons_selection(char message[], char eMessage[], sPerson personsList[], int personsLength, sEntity entitiesList[], int entitiesLength)
{
    int returnValue = ERROR;
    int auxId = 0;
    int auxIndex = 0;

    if(message != NULL && eMessage != NULL && personsList != NULL && entitiesList != NULL
        && personsLength > 0 && personsLength <= PERSONS_MAX && entitiesLength > 0 && entitiesLength <= ENTITIES_MAX
        && persons_printList(personsList, personsLength, entitiesList, entitiesLength) > 0
        && !inputs_getInt(&auxId, message, eMessage, ID_INIT_PERSON + 1, ID_INIT_PERSON + PERSONS_MAX))
    {
        auxIndex = persons_getById(personsList, personsLength, auxId);

        if(auxIndex != ERROR)
        {
            returnValue = auxId;
        }
        else
        {
            printf("No se encuentra el ID de la Persona en el sistema.\n");
        }
    }

    return returnValue;
}

int persons_addNew(sPerson personsList[], int personsLength, sEntity entitiesList[], int entitiesLength)
{
    int returnValue = ERROR;
    int newId;
    int emptyIndex;
    int idEntity;

    if(personsList != NULL && personsLength > 0 && personsLength <= PERSONS_MAX
        && entitiesList != NULL && entitiesLength > 0 && entitiesLength <= ENTITIES_MAX)
    {
        newId = persons_getNewId();

        if(persons_getById(personsList, personsLength, newId) == ERROR)
        {
            emptyIndex = persons_getEmptyIndex(personsList, personsLength);

            if(emptyIndex != ERROR)
            {
                personsList[emptyIndex].idPerson = newId;
                if(!inputs_getString(personsList[emptyIndex].name, "Ingrese el Nombre: ", ERROR_MESSAGE, 1, PERSON_NAME_MAX)
                    && !inputs_getString(personsList[emptyIndex].lastName, "Ingrese el Apellido: ", ERROR_MESSAGE, 1, PERSON_LASTNAME_MAX)
                    && entities_printList(entitiesList, entitiesLength) > 0
                    && !inputs_getInt(&idEntity, "Seleccione una Entidad: ", ERROR_MESSAGE, ID_INIT_ENTITY + 1, ENTITIES_MAX + ID_INIT_ENTITY))
                {
                    if(entities_getById(entitiesList, entitiesLength, idEntity) != ERROR)
                    {
                        personsList[emptyIndex].idEntity = idEntity;
                        personsList[emptyIndex].isEmpty = FALSE;
                        returnValue = OK;
                    }
                }
            }
        }
    }

    return returnValue;
}

int persons_modify(sPerson personsList[], int personsLength, sEntity entitiesList[], int entitiesLength)
{
    int returnValue = ERROR;
    int lifeCycle; /**< Indicador del ciclo de vida de cada menu. >*/
    int optionUpdateMenu; /**< Opcion elegida por el usuario para el menu de modificacion. >*/
    int id; /**< ID del dato buscado. >*/
    int index; /**< Indice del dato buscado. >*/
    int idEntity; /**< ID de Entidad a modificar. >*/

    if(personsList != NULL && personsLength > 0 && personsLength <= PERSONS_MAX
        && entitiesList != NULL && entitiesLength > 0 && entitiesLength <= ENTITIES_MAX)
    {
        id = persons_selection("Indique el ID de la Persona a modificar: ", ERROR_MESSAGE,
            personsList, personsLength, entitiesList, entitiesLength);
        index = persons_getById(personsList, personsLength, id);

        if(id != ERROR && index != ERROR)
        {
            inputs_clearScreen();
            do
            {
                lifeCycle = menu_update(&optionUpdateMenu);

                if(optionUpdateMenu == UPDATE_MAX || optionUpdateMenu == ERROR)
                {
                    break;
                }

                switch (optionUpdateMenu)
                {
                    case 1:
                        if(!inputs_getString(personsList[index].name, "Ingrese el nuevo Nombre: ",
                            ERROR_MESSAGE, 1, PERSON_NAME_MAX))
                        {
                            returnValue = OK;
                        }
                        break;
                    case 2:
                        if(!inputs_getString(personsList[index].lastName, "Ingrese el nuevo Apellido: ",
                            ERROR_MESSAGE, 1, PERSON_NAME_MAX))
                        {
                            returnValue = OK;
                        }
                        break;
                    case 3:
                        idEntity = entities_selection("Seleccione la nueva Entidad: ",
                            ERROR_MESSAGE, entitiesList, entitiesLength);

                        if(idEntity != ERROR
                            && entities_getById(entitiesList, entitiesLength, idEntity) != ERROR)
                        {
                            personsList[index].idEntity = idEntity;
                            returnValue = OK;
                        }
                        break;
                }

            inputs_pauseScreen(CONTINUE_MESSAGE);
            } while (!lifeCycle);
        }
    }

    return returnValue;
}

int persons_print(sPerson person, sEntity entitiesList[], int entitiesLength)
{
    int returnValue = ERROR;

    if(entitiesList != NULL && entitiesLength > 0 && entitiesLength <= ENTITIES_MAX
        && person.isEmpty == FALSE)
    {
        printf("+======+======================+======================+======================+\n");
        printf("|  ID  |        Nombre        |       Apellido       |        Entidad       |\n");
        printf("+======+======================+======================+======================+\n");
        
        if(!printPerson(person, entitiesList, entitiesLength))
        {
            printf("+------+---------------+---------------+-------------+----------------------------+\n");

            returnValue = OK;
        }
    }

    return returnValue;
}

int persons_printList(sPerson personsList[], int personsLenght, sEntity entitiesList[], int entitiesLength)
{
    int itemsCounter = 0;
    int flag = 0;

    if(personsList != NULL && personsLenght > 0 && personsLenght <= PERSONS_MAX
        && entitiesList != NULL && entitiesLength > 0 && entitiesLength <= ENTITIES_MAX)
    {
        for (int i = 0; i < personsLenght; i++)
        {
            if(personsList[i].isEmpty == FALSE)
            {
                itemsCounter++;

                if(itemsCounter == 1)
                {
                    printf("+======+======================+======================+======================+\n");
                    printf("|  ID  |        Nombre        |       Apellido       |        Entidad       |\n");
                    printf("+======+======================+======================+======================+\n");
                }

                if(!printPerson(personsList[i], entitiesList, entitiesLength))
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
            printf("+------+----------------------+----------------------+----------------------+\n");
        }
    }

    return itemsCounter;
}

static int printPerson(sPerson person, sEntity entitiesList[], int entitiesLength)
{
    int returnValue = ERROR;
    int entityIndex;

    entityIndex = entities_getById(entitiesList, entitiesLength, person.idEntity);

    if(person.isEmpty == FALSE && entityIndex != ERROR)
    {
        printf("| %4d | %20s | %20s | %20s |\n", person.idPerson,
            arrays_stringToCamelCase(person.name, PERSON_NAME_MAX),
            arrays_stringToCamelCase(person.lastName, PERSON_LASTNAME_MAX),
            arrays_stringToCamelCase(entitiesList[entityIndex].description, ENTITY_NAME_MAX));

        returnValue = OK;
    }

    return returnValue;
}
