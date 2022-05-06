/*
 * biblioteca.h
 *
 *  Created on: 5 may. 2022
 *      Author: Matias
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


int validarTexto(char *menInicio, char *menError, char *text, int len);
int validarFloat(char* menInicio, char* menError, float *number, int min, int max);
int validarInt(char* menInicio, char* menError, int *number, int min, int max);
int limpiarBarraN(char vec[], int len);
void EclipseCls();
int ordenarStrings(char *array);


#endif /* BIBLIOTECA_H_ */
