#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED

#include "input.h"

int arrays_swapInt(int* i, int* j);

int arrays_swapFloat(float* i, float* j);

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