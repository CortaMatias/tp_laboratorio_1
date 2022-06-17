/*
 * library.c
 *
 *  Created on: 9 jun. 2022
 *      Author: Matias
 */

#include "../inc/library.h"

int validarTexto(char *menInicio, char *menError, char *text, int len)
{
    int todoOk = 1;

    char auxText[100];

    if (menInicio != NULL && menError != NULL && text != NULL)
    {

        printf("%s", menInicio);
        fflush(stdin);
        fgets(auxText, len - 1, stdin);
        limpiarBarraN(auxText);
        for (int i = 0; i < len; i++)
        {
            if (auxText[i] != ' ')
            {

                if (isalpha(auxText[i]) == 0)
                {
                    todoOk = 0;
                    break;
                }
                else if (strcmp((auxText + i + 1), "\0") == 0)
                {
                    todoOk = 1;
                    break;
                }
            }
        }

        while (!todoOk)
        {
            todoOk = validarTexto(menError, menError, auxText, len);
        }

        if (todoOk)
        {
            strcpy(text, auxText);
        }
    }
    else
    {
        todoOk = 0;
    }

    return todoOk;
}

int validarFloat(char *menInicio, char *menError, float *number, int min, int max)
{
    int todoOk = 1;
    float auxNumber = 0;
    char auxText[99];
    char *auxNum;
    int contadorDePuntos = 0;

    if (menInicio != NULL && menError != NULL && number != NULL)
    {
        printf("%s", menInicio);
        fflush(stdin);
        fgets(auxText, max, stdin);
        limpiarBarraN(auxText);
        for (int i = 0; i < 99; i++)
        {
            if (auxText[i] == '.' && contadorDePuntos == 0)
            {
                contadorDePuntos++;
            }
            else if (!isdigit(auxText[i]))
            {
                todoOk = 0;
                break;
            }
            else if (!strcmp((auxText + i + 1), "\0"))
            {
                todoOk = 1;
                auxNumber = strtof(auxText, &auxNum);
                break;
            }
        }

        do
        {
            while (!todoOk)
            {
                contadorDePuntos = 0;
                printf("%s", menError);
                fflush(stdin);
                fgets(auxText, max, stdin);
                limpiarBarraN(auxText);
                for (int i = 0; i < 99; i++)
                {
                    if (auxText[i] == '.' && contadorDePuntos == 0)
                    {
                        contadorDePuntos++;
                    }
                    else if (!isdigit(auxText[i]))
                    {
                        todoOk = 0;
                        break;
                    }
                    else if (!strcmp((auxText + i + 1), "\0"))
                    {
                        todoOk = 1;
                        auxNumber = strtof(auxText, &auxNum);
                        break;
                    }
                }
            }

            if (todoOk && auxNumber >= min && auxNumber <= max)
            {
                *number = auxNumber;
                todoOk = 1;
            }
            else
            {
                todoOk = 0;
            }

        } while (todoOk == 0);
    }
    else
    {
        todoOk = 0;
    }
    return todoOk;
}

int validarInt(char *menInicio, char *menError, int *number, int min, int max)
{
    int todoOk = 1;
    int auxNumber;

    if (menInicio != NULL && menError != NULL && number != NULL)
    {
        char auxText[99];
        printf("%s", menInicio);
        fflush(stdin);
        fgets(auxText, 99, stdin);
        limpiarBarraN(auxText);
        for (int i = 0; i < 99; i++)
        {
            if (isdigit(auxText[i]) == 0)
            {
                todoOk = 0;
                break;
            }
            else if (strcmp((auxText + i + 1), "\0") == 0)
            {
                todoOk = 1;
                auxNumber = atoi(auxText);
                break;
            }
        }

        do
        {
            while (!todoOk)
            {
                printf("%s", menError);
                fflush(stdin);
                fgets(auxText, 99, stdin);
                limpiarBarraN(auxText);
                for (int i = 0; i < 99; i++)
                {
                    if (isdigit(auxText[i]) == 0)
                    {
                        todoOk = 0;
                        break;
                    }
                    else if (strcmp((auxText + i + 1), "\0") == 0)
                    {
                        todoOk = 1;
                        auxNumber = atoi(auxText);
                        break;
                    }
                }
            }

            if (todoOk && auxNumber >= min && auxNumber <= max)
            {
                *number = auxNumber;
                todoOk = 1;
            }
            else
            {
                todoOk = 0;
            }
        } while (!todoOk);
    }
    else
    {
        todoOk = 0;
    }
    return todoOk;
}

/*len include \0*/
int validarAlfaNumerico(char *menInicio, char *menError, char *texto, int len)
{
    int todoOk = 0;
    char auxTexto[100];

    if (menInicio != NULL && menError != NULL && texto != NULL)
    {

        printf("%s", menInicio);
        fflush(stdin);
        fgets(auxTexto, 99, stdin);
        limpiarBarraN(auxTexto);
        if (strlen(auxTexto) == len - 1)
        {
            todoOk = 1;
        }
        else
        {
            todoOk = 0;
        }
        while (!todoOk)
        {
            todoOk = validarAlfaNumerico(menError, menError, auxTexto, len);
        }
        strcpy(texto, auxTexto);
    }
    return todoOk;
}

int limpiarBarraN(char *vec)
{
    int todoOk = 0;
    if (vec != NULL)
    {
        for (int i = 0; i < 1000; i++)
        {
            if (vec[i] == '\n')
            {
                vec[i] = '\0';
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarStringsTp3(char *array)
{
    int todoOk = 0;

    if (array != NULL)
    {
        // TIPO
        if (strcmp(array, "Economyclass") == 0)
        {
            strcpy(array, "EconomyClass");
        }
        if (strcmp(array, "Executiveclass") == 0)
        {
            strcpy(array, "ExecutiveClass");
        }
        if (strcmp(array, "Firstclass") == 0)
        {
            strcpy(array, "FirstClass");
        }
        // ESTADO
        if (strcmp(array, "En horario") == 0)
        {
            strcpy(array, "En Horario");
        }
        if (strcmp(array, "En vuelo") == 0)
        {
            strcpy(array, "En Vuelo");
        }
    }
    return todoOk;
}

int ordenarStrings(char *array)
{
    int todoOk = 0;

    if (array != NULL)
    {
        for (int i = 0; i < 99; i++)
        {
            if (!strcmp(array + i, "\0"))
            {
                break;
            }
            else
            {
                array[i] = tolower(array[i]);
            }
        }

        array[0] = toupper(array[0]);
        todoOk = 1;
    }
    return todoOk;
}

void validarFecha(int *dia, int *mes, int *anio)
{
    validarInt("Ingresar mes : \n", "Error ingresar mes valido. \n", mes, 0, 12);

    switch (*mes)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        validarInt("Ingresar dia : \n", "Error ingresar dia valido. \n", dia, 0, 31);
        break;

    case 4:
    case 6:
    case 9:
    case 11:

        validarInt("Ingresar dia : \n", "Error ingresar dia valido. \n", dia, 0, 30);
        break;

    case 2:

        validarInt("Ingresar dia : \n", "Error ingresar dia valido. \n", dia, 0, 28);
        break;
    }
    validarInt("Ingresar anio : \n", "Error ingresar anio valido, 1900/2022 \n", anio, 1900, 2022);
}
