
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

    sPerson persons[PERSONS_MAX];

    if(!persons_init(persons, PERSONS_MAX))
    {
        do
        {
            lifeCycle = menu_main(&optionMainMenu);

            if(optionMainMenu == MAIN_MAX || optionMainMenu == ERROR)
            {
                inputs_pauseScreen(QUIT_MESSAGE);
                break;
            }

            inputs_pauseScreen(CONTINUE_MESSAGE);
        } while (!lifeCycle);
        
    }

    return 0;
}
