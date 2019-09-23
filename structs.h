#ifndef STRUCTS_H_INCLUDED
#define STRUCTS_H_INCLUDED

#include "arrays.h"

/** \brief Funcion de intercambio de fechas.
 * 
 * \param date1 sDate Primer fecha.
 * \param date2 sDate Segunda fecha.
 * \return Si el intercambio se realizo devuelve [0] si no [-1].
 * 
 */
int structs_swapDate(sDate* date1, sDate* date2);

#endif // STRUCTS_H_INCLUDED
