
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

    sPerson persons[PERSONS_MAX]; /**< Arreglo de tipos de datos basados en Personas. >*/
    sEntity entities[ENTITIES_MAX]; /**< Arreglo de tipos de datos basados en Personas. >*/

    if(!persons_init(persons, PERSONS_MAX) && !entities_init(entities, ENTITIES_MAX))
    {
        if(HARDCODE == TRUE)
        {
            entities_hardcode(entities, ENTITIES_MAX);
            persons_hardcode(persons, PERSONS_MAX);
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
                    inputs_clearScreen();
                    if(!persons_modify(persons, PERSONS_MAX, entities, ENTITIES_MAX))
                    {
                        printf("Modificacion realizada con exito.\n");
                    }
                    break;
                case 3:
                    inputs_clearScreen();
                    if(!persons_remove(persons, PERSONS_MAX, entities, ENTITIES_MAX))
                    {
                        printf("Persona dada de baja con exito.\n");
                    }
                    break;
                case 4:
                    inputs_clearScreen();
                    if(persons_printList(persons, PERSONS_MAX, entities, ENTITIES_MAX) == 0)
                    {
                        printf("No hay Personas activas en el listado.\n");
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
