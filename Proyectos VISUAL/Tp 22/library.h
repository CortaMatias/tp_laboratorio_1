/*
 * library.h
 *
 *  Created on: 29 abr. 2022
 *      Author: Matias
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>


#endif /* LIBRARY_H_ */

int validarInt(char mensaje[200], char mensajeError[200], int *numero, int minimo, int maximo);

int validarFloat(char mensaje[200], char mensajeError[200], float* numero, int minimo, int maximo);

int validarTexto(char mensaje[200], char mensajeError[200], char *texto, int len);

int limpiarBarraN(char vec[], int len);
