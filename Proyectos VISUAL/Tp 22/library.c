/*
 * library.c
 *
 *  Created on: 29 abr. 2022
 *      Author: Matias
 */

#include "library.h"

int validarInt(char mensaje[200], char mensajeError[200], int *numero, int minimo, int maximo)
{
    int todoOk = 1;
    int auxNumero;

    if (mensaje != NULL && mensajeError != NULL && numero != NULL && strlen(mensaje) < 200 && strlen(mensajeError) < 200)
    {
        char auxTexto[100];
        printf("%s", mensaje);
        fflush(stdin);
        fgets(auxTexto, 99, stdin);
        limpiarBarraN(auxTexto, 100);
        for (int i = 0; i < 100; i++)
        {
            if (!isdigit(auxTexto[i]))
            {
                todoOk = 0;
                break;
            }
            else if (!strcmp((auxTexto + i + 1), "\0"))
            {
                break;
            }
        }
        while (!todoOk)
        {
            validarInt(mensajeError, mensajeError, &auxNumero, minimo, maximo);
        }
        auxNumero = atoi(auxTexto);

        if (todoOk && auxNumero >= minimo && auxNumero <= maximo)
        {
            *numero = auxNumero;
        }
        else
        {
            validarInt(mensajeError, mensajeError, &auxNumero, minimo, maximo);
        }
    }
    else
    {
        todoOk = 0;
    }
    return todoOk;
}

int validarFloat(char mensaje[200], char mensajeError[200], float *numero, int minimo, int maximo)
{
    int todoOk = 1;
    float auxNumero;
    char auxTexto[100];
    char *auxNum;

    if (mensaje != NULL && mensajeError != NULL && numero != NULL && strlen(mensaje) < 200 && strlen(mensajeError) < 200){
    printf("%s", mensaje);
    fflush(stdin);
    fgets(auxTexto, maximo, stdin);
    limpiarBarraN(auxTexto, 100);


    for (int i = 0; i < 100; i++)
    {

        if (auxTexto[i] != '.')
        {
            if (!isdigit(auxTexto[i]))
            {
                todoOk = 0;
                break;
            }
            else if (!strcmp((auxTexto + i + 1), "\0"))
            {
                break;
            }
        }
    }
    while (!todoOk)
    {
        todoOk = validarFloat(mensajeError, mensajeError, &auxNumero, minimo, maximo);
    }
    if (todoOk)
    {
        auxNumero = strtof(auxTexto, &auxNum);
        *numero = auxNumero;
    }
    }
    return todoOk;
}

int validarTexto(char mensaje[200], char mensajeError[200], char *texto, int len)
{
    int todoOk = 1;
    char auxTexto[100];

    if (mensaje != NULL && mensajeError != NULL && texto != NULL && strlen(mensaje) < 200 && strlen(mensajeError) < 200)
    {
        printf("%s", mensaje);
        fflush(stdin);
        fgets(auxTexto, len - 1, stdin);
        limpiarBarraN(auxTexto, len);
        for (int i = 0; i < len; i++)
        {
            if (!isalpha(auxTexto[i]))
            {
                todoOk = 0;
                break;
            }
            else if (!strcmp((auxTexto + i + 1), "\0"))
            {
                break;
            }
        }
        while (!todoOk)
        {
           todoOk = validarTexto(mensajeError, mensajeError, auxTexto, len);
        }
        if (todoOk)
        {
            strcpy(texto, auxTexto);
        }
    }
    else
    {
        todoOk = 0;
    }
    return todoOk;
}

int limpiarBarraN(char vec[], int len)
{
    int todoOk = 0;
    if (vec != NULL && len > 0)
    {
        for (int i = 0; i < len; i++)
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
