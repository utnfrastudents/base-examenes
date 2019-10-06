#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "inputs.h"

/**< Mensaje en pantalla para presionar la tecla Enter y continuar. >*/
#define CONTINUE_MESSAGE "Presione la tecla Enter para continuar..."
/**< Mensaje en pantalla para presionar la tecla Enter y salir del programa. >*/
#define QUIT_MESSAGE "Presione la tecla Enter para salir del programa..."
#define OPTION_MIN 1 /**< Opcion minima en comun de cada menu. >*/
#define MAIN_MAX 5 /**< Opcion maxima del menu principal. >*/

/** \brief Funcion que imprime el menu principal del programa.
 *
 * \param option int* Opcion elegida del menu.
 * \return int Retorna la opcion elegida en el menu.
 *
 */
int menu_main(int* option);

#endif // MENU_H_INCLUDED
