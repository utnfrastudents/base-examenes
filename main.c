
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
#include "inputs.h"

#define DEBUG_MODE TRUE /**< Opcion definida desde el pre-procesador para hacer uso del hardcoding y pausar para ver errores de compilacion. >*/

int main()
{
    
    if(DEBUG_MODE == TRUE)
    {
        inputs_pauseScreen("\n--->[BIBLOTECAS ANSI C UTN FRA STUDENTES: DEBUG & HARDCODING MODE]<----\n");
    }
    
    inputs_clearScreen();
    inputs_pauseScreen("Hola Mundo...");

    return 0;
}
