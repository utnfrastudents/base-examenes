#include "arrays.h"

int arrays_swapInt(int* i, int* j)
{
    int returnValue = -1;
    int aux1;
    int aux2;

    aux1 = *i;
    aux2 = *j;
    *i = *j;
    *j = aux1;

    if(*i == aux2 && *j == aux1)
    {
        returnValue = 0;
    }

    return returnValue;
}

int arrays_swapFloat(float* i, float* j)
{
    int returnValue = -1;
    float aux1;
    float aux2;

    aux1 = *i;
    aux2 = *j;
    *i = *j;
    *j = aux1;

    if(*i == aux2 && *j == aux1)
    {
        returnValue = 0;
    }

    return returnValue;
}

int arrays_swapChar(char* i, char* j)
{
    int returnValue = -1;
    char aux1;
    char aux2;

    aux1 = *i;
    aux2 = *j;
    *i = *j;
    *j = aux1;

    if(*i == aux2 && *j == aux1)
    {
        returnValue = 0;
    }

    return returnValue;
}

int arrays_swapStrings(char string1[], char string2[])
{
    int returnValue = -1;
    char aux1[STRING_MAX];
    char aux2[STRING_MAX];

    if(string1 != NULL && string2 != NULL)
    {
        strcpy(aux1, string1);
        strcpy(aux2, string2);
        strcpy(string1, string2);
        strcpy(string2, aux1);

        if(!strcmp(string1, aux2) && !strcmp(string2, aux1))
        {
            returnValue = 0;
        }
    }

    return returnValue;
}
