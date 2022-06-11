/*
 * library.h
 *
 *  Created on: 9 jun. 2022
 *      Author: Matias
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_



#endif /* LIBRARY_H_ */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


#ifndef LIBRARY_H_
#define LIBRARY_H_

#endif /* LIBRARY_H_ */

/**
 * @brief pide y valida un dato de tipo string
 *
 * @param menInicio tipo char, envie el mensaje con el que pedimos el dato.
 * @param menError tipo char, envie el mensaje con el le volvemos a pedir el dato luego de une error.
 * @param text tipo char puntero, donde se guarda el texto a verificar.
 * @param len tipo int, tamaño del texto a verificar
 * @return int retorna si la funcion se ejecuto correctamente
 */
int validarTexto(char *menInicio, char *menError, char *text, int len);

/**
 * @brief pide y valida un dato flotante
 *
 * @param menInicio tipo char, envie el mensaje con el que pedimos el dato.
 * @param menError tipo char, envie el mensaje con el le volvemos a pedir el dato luego de une error.
 * @param number tipo flotante entero, donde se guarda el numero a verificar.
 * @param min tipo int, tamaño minimo del numero a verificar.
 * @param max tipo int, tamaño maximo del numero a verificar.
 * @return int retorna si la funcion se ejecuto correctamente
 */
int validarFloat(char *menInicio, char *menError, float *number, int min, int max);

/**
 * @brief pide y valida un dato de tipo entero
 *
 * @param menInicio tipo char, envie el mensaje con el que pedimos el dato.
 * @param menError tipo char, envie el mensaje con el le volvemos a pedir el dato luego de une error.
 * @param number tipo int, donde se guarda el numero a verificar.
 * @param min tipo int, tamaño minimo del numero a verificar.
 * @param max tipo int, tamaño maximo del numero a verificar.
 * @return int retorna si la funcion se ejecuto correctamente
 */
int validarInt(char *menInicio, char *menError, int *number, int min, int max);

int validarAlfaNumerico(char *menInicio, char *menError, char *texto, int max);

/**
 * @brief saca el "\n" y lo reemplaza por un "\0"
 *
 * @param vec tipo char, es el vector al que se le va a reemplazar el \n
 * @param len tipo int, es el tamaño del vector
 * @return int retorna si la funcion se ejecuto correctamente
 */
int limpiarBarraN(char vec[]);

/**
 * @brief pasa a minuscula el array y luego modifica el indice 0 por una mayuscula
 *
 * @param array tipo char, es el vector que vamos a ordenar.
 * @return int retorna si la funcion se ejecuto correctamente
 */
int ordenarStrings(char *array);

void validarFecha(int *dia, int *mes, int *anio);
