#ifndef PERSONS_H_INCLUDED
#define PERSONS_H_INCLUDED

#define ID_INIT_PERSON 1000 /**< Valor inicial de un ID de tipo Persona. >*/
#define ERROR_MESSAGE "Error, intente nuevamente: " /**< Mensaje de solicitud de error al validar un dato incorrecto. >*/

#include "entities.h"

/** \brief Funcion para generar un nuevo ID de estructura de tipo Persona.
 *
 * \param void No requiere parametros.
 * \return int
 *      Nuevo ID incremental para cada ID de tipo Persona.
 *
 */
int persons_getNewId(void);

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

/** \brief Funcion que obtiene el indice del arreglo de tipo Persona
 *          del ID ingresado como parametro.
 * 
 * \param list[] sPerson Direccion de memoria del inicio del arreglo de tipo Persona.
 * \param length int Longitud del array.
 * \param id int Campo ID del Empleado a buscar.
 * \return int
 *      [-1] Si no encuentra el ID ingresado.
 *      Encuentra el indice del Empleado buscado.
 * 
 */
int persons_getById(sPerson list[], int length, int id);

/** \brief Funcion que agrega una Persona
 *      en el primer lugar vacio de la lista ingresada.
 * 
 * \param list[] sPerson Direccion de memoria del inicio del arreglo de tipo Persona.
 * \param length int Longitud del array.
 * \param id int ID del Empleado.
 * \return int
 *      [-1] Si hubo un error en la carga de la Persona en la lista.
 *      [0] Si la carga de la Persona en la lista fue exitosa.
 *
 */
int person_add(sPerson list[], int length);

#endif // PERSONS_H_INCLUDED
