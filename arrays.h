#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

#include "input.h"

/** \brief Funcion de intercambio de numeros enteros.
 * 
 * \param i int* Direccion de memoria del primer numero.
 * \param j int* Direccion de memoria del segundo numero.
 * \return Si el intercambio se realizo devuelve [0] si no [-1].
 * 
 */
int arrays_swapInt(int* i, int* j);

/** \brief Funcion de intercambio de numeros flotantes.
 * 
 * \param i float* Direccion de memoria del primer numero.
 * \param j float* Direccion de memoria del segundo numero.
 * \return Si el intercambio se realizo devuelve [0] si no [-1].
 * 
 */
int arrays_swapFloat(float* i, float* j);

/** \brief Funcion de intercambio de caracteres.
 * 
 * \param i char* Direccion de memoria del primer caracter.
 * \param j char* Direccion de memoria del segundo caracter.
 * \return Si el intercambio se realizo devuelve [0] si no [-1].
 * 
 */
int arrays_swapChar(char* i, char* j);

/** \brief Funcion de intercambio de cadenas de caracteres.
 * 
 * \param string1[] char Primer cadena de caracteres.
 * \param strin2[] char Segunda cadena de caracteres.
 * \return Si el intercambio se realizo devuelve [0] si no [-1].
 * 
 */
int arrays_swapStrings(char string1[], char string2[]);

#endif // ARRAYS_H_INCLUDED
