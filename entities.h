#ifndef ENTITY_H_INCLUDED
#define ENTITY_H_INCLUDED

#include "menu.h"

#define ID_INIT_ENTITY 10 /**< Valor inicial de un ID de tipo Entidad. >*/

/** \brief Funcion para generar un nuevo ID de estructura de tipo Entidad.
 *
 * \param void No requiere parametros.
 * \return int
 *      Nuevo ID incremental para cada ID de tipo Entidad.
 *
 */
int entities_getNewId(void);

/** \brief Funcion que blanquea todas las posiciones de un arreglo de Entidad
 *          colocando la bandera isEmpty en TRUE.
 * 
 * \param list[] sEntity Direccion de memoria del inicio del arreglo de tipo Entidad.
 * \param length int Longitud del array.
 * \return int
 *      [-1] Si hubo un error.
 *      [0] Si la inicializacion de todas sus posiciones fue realizada con exito.
 *
 */
int entities_init(sEntity list[], int length);

/** \brief Funcion que obtiene el indice del arreglo de tipo Entidad
 *          del ID ingresado como parametro.
 * 
 * \param list[] sPerson Direccion de memoria del inicio del arreglo de tipo Entidad.
 * \param length int Longitud del array.
 * \param id int Campo ID del Entidad a buscar.
 * \return int
 *      [-1] Si no encuentra el ID ingresado.
 *      Encuentra el indice del Entidad buscado.
 * 
 */
int entities_getById(sEntity list[], int length, int id);

/** \brief Funcion para seleccionar una Entidad existente en un arreglo.
 *
 * \param message[] char Es el mensaje a ser mostrado.
 * \param eMessage[] char Es el mensaje a ser mostrado en caso de error.
 * \param entitiesList[] sPerson Direccion de memoria del inicio del arreglo de tipo Entidad.
 * \param entitiesLength int Longitud del arreglo de tipo Entidad.
 * \return int
 *      [-1] Si hubo un error en la seleccion de la Entidad en la lista.
 *      ID de la Entidad elegida.
 *
 */
int entities_selection(char message[], char eMessage[], sEntity entitiesList[], int entitiesLength);

/** \brief Imprime en pantalla el contenido de la lista del tipo basado en Entidad.
 *
 * \param entitiesList[] sPerson Direccion de memoria del inicio del arreglo de tipo Entidad.
 * \param entitiesLength int Longitud del arreglo de tipo Entidad.
 * \return int La cantidad de elementos impresos del arreglo del tipo basado en Entidad.
 *
 */
int entities_printList(sEntity entitiesList[], int entitiesLength);

/** \brief Funcion que carga valores de muestra a un arreglo de tipo Entidad
 *      dependiendo de la cantidad definida como parametro.
 *
 * \param list[] sEntity Direccion de memoria del inicio del arreglo de tipo Entidad.
 * \param length int Longitud del array.
 * \param quantity unt Cantidad de valores a cargar en el arreglo.
 * \return void No retorna valores.
 *
 */
void entities_hardcode(sEntity list[], int length, int quantity);

#endif // ENTITY_H_INCLUDED
