#ifndef OBJECTS_H_INCLUDED
#define OBJECTS_H_INCLUDED

#include "persons.h"

#define ID_INIT_OBJECT 0 /**< Valor inicial de un ID de tipo Objeto. >*/

/** \brief Funcion para generar un nuevo ID de estructura de tipo Objeto.
 *
 * \param void No requiere parametros.
 * \return int
 *      Nuevo ID incremental para cada ID de tipo Objeto.
 *
 */
int objects_getNewId(void);

/** \brief Funcion que carga valores de muestra a un arreglo de tipo de Objetos
 *      dependiendo de la cantidad definida como parametro.
 *
 * \param objectsList[] sObject Direccion de memoria del inicio del arreglo de tipo Objeto.
 * \param objectsLength int Longitud del arreglo de tipo Objeto.
 * \return void No retorna valores.
 *
 */
void objets_hardcode(sObject objectsList[], int objectsLength);

#endif // OBJECTS_H_INCLUDED
