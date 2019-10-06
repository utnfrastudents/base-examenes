
/***********************************************************************
 * Biblioteca: Bibliotecas ANSI C UTN FRA Students
 *
 * Objetivo:
 *      Tipos de Datos genericos.
 *      Arreglos y Vectores.
 *      Funciones de Validacion de entrada de datos.
 *
 * Autores:
 *      Alan Levy
 *      Christian Grimberg
 *
 ************************************************************************/
#include "persons.h"

int main()
{
    int lifeCycle; /**< Indicador del ciclo de vida de cada menu. >*/
    int optionMainMenu; /**< Opcion elegida por el usuario del menu principal. >*/
    int optionUpdateMenu; /**< Opcion elegida por el usuario para el menu de modificacion. >*/

    sPerson persons[PERSONS_MAX];

    sEntity entities[ENTITIES_MAX];

    if(!persons_init(persons, PERSONS_MAX) && !entities_init(entities, ENTITIES_MAX))
    {
        if(HARDCODE == TRUE)
        {
            entities_hardcode(entities, ENTITIES_MAX, 5);
        }

        do
        {
            lifeCycle = menu_main(&optionMainMenu);

            if(optionMainMenu == MAIN_MAX || optionMainMenu == ERROR)
            {
                inputs_pauseScreen(QUIT_MESSAGE);
                break;
            }

            switch (optionMainMenu)
            {
                case 1:
                    if(!persons_addNew(persons, PERSONS_MAX, entities, ENTITIES_MAX))
                    {
                        printf("Persona agregada con exito.\n");
                    }
                    break;
                case 2:
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
                                break;
                            case 2:
                                break;
                        }
                    inputs_pauseScreen(CONTINUE_MESSAGE);
                    } while (!lifeCycle);
                    break;
                case 3:
                    break;
                case 4:
                    inputs_clearScreen();
                    if(persons_printList(persons, PERSONS_MAX, entities, ENTITIES_MAX) == 0)
                    {
                        printf("No hay Personas en el listado.\n");
                    }
                    break;
            }

            inputs_pauseScreen(CONTINUE_MESSAGE);
        } while (!lifeCycle);
    }
    else
    {
        inputs_pauseScreen("Error de inicialiacion de estructuras.\n");
    }

    return OK;
}
