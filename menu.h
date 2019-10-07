#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include "inputs.h"

/**< Mensaje en pantalla para presionar la tecla Enter y continuar. >*/
#define CONTINUE_MESSAGE "Presione la tecla Enter para continuar..."
/**< Mensaje en pantalla para presionar la tecla Enter y salir del programa. >*/
#define QUIT_MESSAGE "Presione la tecla Enter para salir del programa..."
#define PERSON_STRUCT "Persona" /**< Aplicacion de la estructura en el programa. >*/
#define ENTITY_STRUCT "Entidad" /**< Aplicacion de la estructura en el programa. >*/
#define OPTION_MIN 1 /**< Opcion minima en comun de cada menu. >*/
#define MAIN_MAX 5 /**< Opcion maxima del menu principal. >*/
#define UPDATE_MAX 4 /**< Opcion maxima de menu para modificar una estructura de tipo Persona. >*/

/** \brief Funcion que imprime el menu principal del programa.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [-1] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_main(int* option);

/** \brief Funcion que imprime un menu en pantalla
 *      para que el usuario modifique la carga
 *      de una estructura de tipo Persona.
 *
 * \param option int* Opcion elegida del menu.
 * \return int
 *      [-1] Si hubo un error.
 *      Retorna la opcion elegida en el menu.
 *
 */
int menu_update(int* option);

#endif // MENU_H_INCLUDED
