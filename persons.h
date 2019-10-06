#ifndef PERSONS_H_INCLUDED
#define PERSONS_H_INCLUDED

#define ID_INIT_PERSON 1000 /**< Valor inicial de un ID de tipo Persona. >*/

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
int persons_init(sPerson list[], int length);

/** \brief Funcion para generar un nuevo ID de estructura de tipo Persona.
 *
 * \param void No requiere parametros.
 * \return int
 *      Nuevo ID incremental para cada ID de tipo Persona.
 *
 */
int persons_getNewId(void);

/** \brief Funcion que obtiene el primer indice vacio de un arreglo de tipo Personas.
 * 
 * \param list[] sPerson Direccion de memoria del inicio del arreglo de tipo Persona.
 * \param length int Longitud del array.
 * \return int
 *      [-1] Si no hay ninguna posicion libre del arreglo.
 *      Indice del arreglo donde se encuentra un lugar vacio.
 * 
 */
int persons_getEmptyIndex(sPerson list[], int length);

#endif // PERSONS_H_INCLUDED
