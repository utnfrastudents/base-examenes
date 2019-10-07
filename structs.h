#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1 /**< Valor booleano de verdadero. >*/
#define FALSE 0 /**< Valor booleano de falso. >*/
#define ERROR -1 /**< Opcion de retorno de error. >*/
#define OK 0 /**< Opcion de retorno OK. >*/
#define DAY_MIN 1 /**< Dia minimo de cada mes. >*/
#define DAY_28 28 /**< Dia maximo de febrero de anio no bisiesto. >*/
#define DAY_29 29 /**< Dia maximo de febrero de anio bisiesto. >*/
#define DAY_30 30 /**< Dia maximo de abril, junio, septiembre y noviembre. >*/
#define DAY_31 31 /**< Dia maximo de enero, marzo, mayo, julio, agosto, octubre y diciembre. >*/
#define MONTH_MIN 1 /**< Mes minimo de cada anio. >*/
#define MONTH_MAX 12 /**< Mes maximo de cada anio. >*/
#define YEAR_MIN 1900 /**< Anio minimo definido por el programa. >*/
#define YEAR_MAX 2500 /**< Anio maximo definido por el programa. >*/
#define PERSONS_MAX 100 /**< Cantidad maxima en un arreglo de tipo de Personas. >*/
#define PERSON_NAME_MAX 21 /**< Longitud maxima del nombre de una Persona. >*/
#define PERSON_LASTNAME_MAX 21 /**< Longitud maxima del apellido de una Persona. >*/
#define ENTITIES_MAX 20 /**< Cantidad maxima en un arreglo de tipo Entidad. >*/
#define ENTITY_NAME_MAX 21 /**< Longitud maxima de la descripcion de una Entidad. >*/
#define OBJECT_NAME_MAX 21 /**< Longitud maxima de la descripcion de un Objeto. >*/
#define OBJECT_TYPE_MAX 21 /**< Longitud maxima de la descripcion de un tipo de Objeto. >*/
#define ASC 1 /**< Metodo para ordenar de forma Ascendente. >*/
#define DESC 0 /**< Metodo para ordenar de forma Descendente. >*/
#define HARDCODE TRUE /**< Indicador de harcoding para propositos de testeo. >*/

/*! \struct sDate
 * \brief Tipo de Dato generico para almacenar una Fecha.
 *
 * \field day int Valor del dia de la Fecha.
 * \field month int Valor del mes de la Fecha.
 * \field year int Valor del anio de la Fecha.
 *
 */
typedef struct
{
    int day; /**< Valor del dia de la fecha. >*/
    int month; /**< Valor del mes de la fecha. >*/
    int year; /**< Valor del anio de la fecha. >*/
} sDate;

/*! \struct sEntity
 * \brief Tipo de dato generico de una Entidad.
 *
 * \field idEntity int Campo ID de una Entidad.
 * \field description[] char Descripcion de la Entidad.
 *
 */
typedef struct
{
    int idEntity; /**< Campo ID de una Entidad. >*/
    char description[ENTITY_NAME_MAX]; /**< Descripcion de la Entidad. >*/
    int isEmpty; /**< Indicador de registro lleno o vacio. >*/
} sEntity;

/*! \struct sPerson
 * \brief Tipo de dato generico de una Persona.
 *
 * \field idPerson int Campo ID de una Persona.
 * \field name[] char Nombre de la Persona.
 * \field lastName[] char Apellido de la Persona.
 * \field date sDate Fecha de la Persona.
 * \field idEntity int Clave foranea del ID de una Entidad.
 * \field isEmpty int Indicador de registro lleno o vacio.
 *
 */
typedef struct
{
    int idPerson; /**< Campo ID de una Persona. >*/
    char name[PERSON_NAME_MAX]; /**< Nombre de la Persona. >*/
    char lastName[PERSON_LASTNAME_MAX]; /**< Apellido de la Persona. >*/
    int idEntity; /**< Clave foranea del ID de una Entidad. >*/
    int isEmpty; /**< Indicador de registro lleno o vacio. >*/
} sPerson;

/*! \enum eObjectsType
 * \brief Enumracion de Tipo de Objeto.
 */
typedef enum
{
    Tipo1,
    Tipo2,
    Tipo3
}eObjectsType;

/*! \struct sObject
 * \brief Tipo de dato generico de tipo Objeto.
 *
 * \field idObject int Campo ID de un Objeto.
 * \field description[] char Descripcion del Objeto.
 *
 */
typedef struct
{
    int idObject; /**< Campo ID de un Objeto.. >*/
    char description[OBJECT_NAME_MAX]; /**< Descripcion del Objeto.. >*/
    int idPerson;  /**< Campo ID de una Persona. >*/
    eObjectsType type; /**< Tipo del Objeto. >*/
    int isEmpty; /**< Indicador de registro lleno o vacio. >*/
} sObject;

/*! \struct sPersonsObjets
 * \brief Tipo de dato que relaciona a Personas con Objetos,
 *      logrando una relacion de muchos a muchos.
 *
 * \field idPersonObject int Campo ID de estructura de relacion de Personas y Objetos.
 * \field idPerson int Clave foranea de ID de Persona.
 * \field idObject int Clave foranea de ID de Objeto.
 *
 */
typedef struct
{
    int idPersonObject; /**< Campo ID de estructura de relacion de Personas y Objetos. >*/
    int idPerson; /**< Clave foranea de ID de Persona. >*/
    int idObject; /**< Clave foranea de ID de Objeto. >*/
    sDate date; /**< Fecha de la relacion. >*/
} sPersonsObjects;

/** \brief Funcion que evalua si la fecha ingresada es válida
 *
 * \param date sDate Fecha a evaluar.
 * \return int
 *      Si es una fecha retorna [1] si no [0].
 *
 */
int structs_isDate(sDate date);

/** \brief Funcion que compara dos fechas.
 *
 * \param date1 sDate Primer fecha.
 * \param date2 sDate Segunda fecha.
 * \return int
 *      Si son iguales retorna [0].
 *      Si la primer fecha es posterior [1].
 *      Si la segunda fecha es posterior [-1].
 *      Si hubo un error [-2].
 *
 */
int structs_dateCompare(sDate date1, sDate date2);

/** \brief Funcion de intercambio de fechas.
 *
 * \param date1 sDate Primer fecha.
 * \param date2 sDate Segunda fecha.
 * \return int
 *      Si el intercambio se realizo devuelve [0] si no [-1].
 *
 */
int structs_swapDate(sDate* date1, sDate* date2);

/** \brief Funcion que compara dos estructuras de tipo Persona
 *      por sus ID que son unicos.
 *
 * \param person1 sPerson Tipo de Dato de Persona.
 * \param person2 sPerson Tipo de Dato de Persona.
 * \return int
 *      [0] Se retorna cuando al menos sus ID son iguales.
 *      [1] Se retorna cuando la Persona 1 tiene ID mayor.
 *      [-1] Se retorna cuando la Persona 2 tiene ID mayor.
 *      [-2] Se retorna cuando hubo un error.
 *
 */
int structs_personsCompare(sPerson person1, sPerson person2);

/** \brief Funcion que intercambia dos estructuras de tipo Persona
 *      por sus ID que son unicos.
 *
 * \param person1 sPerson* Tipo de Dato de Persona.
 * \param person2 sPerson* Tipo de Dato de Persona.
 * \return int
 *      [0] Si el intercambio fue realizado y verificado con exito.
 *      [-1] Si hubo un error al hacer el intercambio.
 *
 */
int structs_swapPersons(sPerson* person1, sPerson* person2);

/** \brief Funcion que compara dos estructuras de tipo Entidad
 *      por sus ID que son unicos.
 *
 * \param entity1 sEntity Tipo de Dato de Entidad.
 * \param entity2 sEntity Tipo de Dato de Entidad.
 * \return int
 *      [0] Se retorna cuando al menos sus ID son iguales.
 *      [1] Se retorna cuando la Entidad 1 tiene ID mayor.
 *      [-1] Se retorna cuando la Entidad 2 tiene ID mayor.
 *      [-2] Se retorna cuando hubo un error.
 *
 */
int structs_entitiesCompare(sEntity entity1, sEntity entity2);

/** \brief Funcion que intercambia dos estructuras de tipo Entidad
 *      por sus ID que son unicos.
 *
 * \param entity1 sEntity* Tipo de Dato de Entidad.
 * \param entity2 sEntity* Tipo de Dato de Entidad.
 * \return int
 *      [0] Si el intercambio fue realizado y verificado con exito.
 *      [-1] Si hubo un error al hacer el intercambio.
 *
 */
int structs_swapEntities(sEntity* entity1, sEntity* entity2);

/** \brief Funcion que obtiene la cadena de caracteres
 *      de un tipo de dato basado en un tipo de Objeto.
 * 
 * \param object sObject Tipo de Dato basado en Objeto.
 * \return char*
 *      Cadena de caracteres del tipo de dato basado en el tipo de Objeto.
 * 
 */
char* structs_getObjectType(sObject object);

#endif // STRUCTS_H_INCLUDED
