#include "input.h"

/** \brief Funcion que evalua si una cadena ingresada por teclado
 *  es un numero decimal.
 *
 * \param stringValue char* Direccion de la cadena a evaluar
 * \return int Si es un numero decimal retorna [0] si no [-1]
 *
 */
static int isNumber(char* stringValue);

/** \brief Funcion que evalua si una cadena ingresada por teclado
 *  es un numero flontante.
 *
 * \param stringValue char* Direccion de la cadena a evaluar
 * \return int Si es un numero flotante retorna [0] si no [-1]
 *
 */
static int isFloat(char* stringValue);

void input_clearBuffer()
{
    /**< Mientras que en el buffer no exista un Enter
    la funcion getchar toma sus valores */
    while (getchar() != ENTER_CHARACTER)
    {
        /**< No requiere implementacion */
    }
}

void input_clearScreen()
{
    #if defined (__unix__) || defined (__APPLE__) || defined (__MACH__)
    {
        system("clear");
    }
    #else
    {
        system("cls");
    }
    #endif
}

void input_pauseScreen(char message[])
{
    printf("%s...", message);
    
    /**< Metodo para parar la ejecucion del programa
    hasta presionar Enter para diferentes SO */
    setbuf(stdin, NULL);

    getchar();
}

int input_getInt(int* input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    int returnValue = -1;
    int counter = 0;
    int numberIndicator = -1;
    int convertedNumber;

    char stringNumber[STRING_AS_NUMBER_MAX];

    if(hiLimit >= lowLimit && lowLimit >= INT32_MIN && hiLimit <= INT32_MAX
        && input != NULL && message != NULL && eMessage != NULL)
    {
        do
        {
            counter++;

            if(counter == 1)
            {
                printf("%s: ", message);
            }
            else
            {
                if(counter > 1)
                {
                    printf("%s: ", eMessage);
                }
            }

            scanf("%s", stringNumber);
            numberIndicator = isNumber(stringNumber);

            if(!numberIndicator)
            {
                convertedNumber = atoi(stringNumber);
            }
        } while(numberIndicator ||
            (!numberIndicator && (convertedNumber < lowLimit || convertedNumber > hiLimit)));

        if(convertedNumber >= lowLimit && convertedNumber <= hiLimit)
        {
            *input = convertedNumber;
            returnValue = 0;
        }
    }

    return returnValue;
}

int input_getFloat(float* input, char message[], char eMessage[], float lowLimit, float hiLimit)
{
    int returnValue = -1;
    int counter = 0;
    int numberIndicator = -1;

    float convertedNumber;

    char stringNumber[STRING_AS_NUMBER_MAX];

    if(hiLimit >= lowLimit && lowLimit >= FLT_MIN && hiLimit <= FLT_MAX
        && input != NULL && message != NULL && eMessage != NULL)
    {
        do
        {
            counter++;

            if(counter == 1)
            {
                printf("%s: ", message);
            }
            else
            {
                if(counter > 1)
                {
                    printf("%s: ", eMessage);
                }
            }

            scanf("%s", stringNumber);
            numberIndicator = isFloat(stringNumber);

            if(!numberIndicator)
            {
                convertedNumber = atof(stringNumber);
            }
        } while(numberIndicator ||
            (!numberIndicator && (convertedNumber < lowLimit || convertedNumber > hiLimit)));

        if(convertedNumber >= lowLimit && convertedNumber <= hiLimit)
        {
            *input = convertedNumber;
            returnValue = 0;
        }
    }

    return returnValue;
}

int input_getChar(char* input, char message[], char eMessage[], char lowLimit, char hiLimit)
{
    int returnValue = -1;
    int counter = 0;
    char charValue;

    if(input != NULL && message != NULL && eMessage != NULL
        && (int)hiLimit >= (int)lowLimit
        && isalpha(lowLimit) && isalpha(hiLimit))
    {
        do
        {
            counter++;

            if(counter == 1)
            {
                printf("%s: ", message);
            }
            else
            {
                if(counter > 1)
                {
                    printf("%s: ", eMessage);
                }
            }

            scanf("%c", &charValue);
            input_clearBuffer();
        } while((int)charValue < (int)lowLimit || (int)charValue > (int)hiLimit);

        if((int)charValue >= (int)lowLimit && (int)charValue <= (int)hiLimit)
        {
            *input = charValue;
            returnValue = 0;
        }
    }

    return returnValue;
}

int input_getString(char* input, char message[], char eMessage[], int lowLimit, int hiLimit)
{
    int returnValue = -1;
    int counter = 0;
    int sizeScan = 0;
    char auxMessage[STRING_MAX];

    if(input != NULL && message != NULL && eMessage != NULL
        && hiLimit >= lowLimit && hiLimit <= STRING_MAX && lowLimit > 0)
    {
        do
        {
            counter++;

            if(counter == 1)
            {
                printf("%s", message);
            }
            else
            {
                if(counter > 1)
                {
                    printf("%s", eMessage);
                }
            }

            if(scanf("%[^\n]s", auxMessage))
            {
                sizeScan = strlen(auxMessage);
            }
            else
            {
                continue;
            }

            input_clearBuffer();

            printf("\n*** [debug] String size: %d\n", sizeScan);
        } while(sizeScan < lowLimit || sizeScan > hiLimit);

        if(sizeScan >= lowLimit && sizeScan <= hiLimit
            && sizeScan > 0 && hiLimit <= STRING_MAX)
        {
            strcpy(input, auxMessage);
            returnValue = 0;
        }
    }

    return returnValue;
}

int input_getNumberType(float number)
{
    int returnEvaluation; /**< Se almacena el tipo numerico */
    float floorNumber; /**< Se almacena la parte entera de un numero */

    floorNumber = floor(number); /**< Se obtiene la parte entera del numero */

    /**< Diferencias en un numero con decimales y su parte entera */
    if (number - floorNumber != 0.0f)
    {
        returnEvaluation = 2; /**< Indica tipo de dato flotante */
    }
    else
    {
        /**< Igualdad de numero decimal con su parte entera, incluyendo el cero */
        if (number == floorNumber || (float)number == 0)
        {
            returnEvaluation = 1; /**< Indica tipo de dato entero */
        }
        else /**< No se puede determinar el tipo de numero */
        {
            returnEvaluation = 0;
        }
    }

    return returnEvaluation;
}

void input_printNumberByType(char message[], float number)
{
    switch (input_getNumberType(number))
    {
        case 1:
            /**< Se imprime en consola el numero como entero */
            printf("%s %.0lf\n", message, number); 
            break;
        case 2:
            /**< Se imprime en consola el numero como flotante con tres decimales */
            printf("%s %.3lf\n", message, number);
            break;
    }
}

static int isNumber(char* stringValue)
{
    int returnValue = -1;
    char charAux;
    int i = 0;

    while(stringValue[i] != (int)EXIT_BUFFER)
    {
        charAux = stringValue[i];
        if(i == 0 && (charAux == '-' || charAux == '+'))
        {
            i = 1;
        }

        if((int)charAux >= (int)'0' && (int)charAux <= (int)'9')
        {
            returnValue = 0;
        }
        else
        {
            returnValue = -1;
            break;
        }
        i++;
    }

    return returnValue;
}

static int isFloat(char* stringValue)
{
    int returnValue = -1;
    int pointerCounter = 0;
    int i = 0;

    while(stringValue[i] != (int)EXIT_BUFFER)
    {
        if(i == 0 && ((int)stringValue[0] == (int)'-'
        || (int)stringValue[0] == (int)'+'))
        {
            i = 1;
        }

        if(stringValue[i] == '.')
        {
            pointerCounter++;
        }
        else
        {
            if((int)stringValue[i] >= (int)'0'
                && (int)stringValue[i] <= (int)'9' && pointerCounter <= 1)
            {
                returnValue = 0;
            }
            else
            {
                returnValue = -1;
                break;
            }
        }
        i++;
    }

    return returnValue;
}
