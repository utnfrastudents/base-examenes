#include "input.h"

int main()
{
    char string[STRING_MAX];
    char firstString[] = "Hola ";
    char secondString[51];
    
    input_clearScreen();

    if(!input_getString(secondString, "Ingrese su nombre: ", "Intente nuevamente: ", 2, 51))
    {
        if(!input_concatStrings(string, firstString, secondString, 100))
        {
            input_pauseScreen(string);
        }
    }

    return 0;
}
