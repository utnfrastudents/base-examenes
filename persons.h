#ifndef PERSONS_H_INCLUDED
#define PERSONS_H_INCLUDED

#include "menu.h"

/** \brief Funcion que blanquea todas las posiciones de un array de Personas
 *          colocando la bandera isEmpty en TRUE.
 * 
 * \param list[] sPerson Direccion de memoria del inicio del array de Personas.
 * \param length int Longitud del array.
 * \return int
 *      [-1] Si hubo un error.
 *      [0] Si la inicializacion de todas sus posiciones fue realizada con exito.
 *
 */
int initPersons(sPerson list[], int length);

#endif // PERSONS_H_INCLUDED
