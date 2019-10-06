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
 * \param id int Campo ID de la Persona a buscar.
 * \return int
 *      [-1] Si no encuentra el ID ingresado.
 *      Encuentra el indice de la Persona buscada.
 * 
 */
int persons_getById(sPerson list[], int length, int id);

/** \brief Funcion que agrega una Persona
 *      en el primer lugar vacio de la lista ingresada.
 * 
 * \param personsList[] sPerson Direccion de memoria del inicio del arreglo de tipo Persona.
 * \param personsLength int Longitud del arreglo de tipo Persona.
 * \param entitiesList[] sPerson Direccion de memoria del inicio del arreglo de tipo Entidad.
 * \param entitiesLength int Longitud del arreglo de tipo Entidad.
 * \param id int ID del Empleado.
 * \return int
 *      [-1] Si hubo un error en la carga de la Persona en la lista.
 *      [0] Si la carga de la Persona en la lista fue exitosa.
 *
 */
int person_add(sPerson personsList[], int personsLength, sEntity entitiesList[], int entitiesLength);

/** \brief Imprime en pantalla el contenido de la lista del tipo basado en Personas.
 *
 * \param personsList[] sPerson Direccion de memoria del inicio del arreglo de tipo Persona.
 * \param personsLength int Longitud del arreglo de tipo Persona.
 * \param entitiesList[] sPerson Direccion de memoria del inicio del arreglo de tipo Entidad.
 * \param entitiesLength int Longitud del arreglo de tipo Entidad.
 * \return int La cantidad de elementos impresos del arreglo del tipo basado en Personas.
 *
 */
int persons_printList(sPerson personsList[], int personsLenght, sEntity entitiesList[], int entitiesLength);

#endif // PERSONS_H_INCLUDED
