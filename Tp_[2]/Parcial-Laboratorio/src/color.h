/*
 * estructura3.h
 *
 *  Created on: 10 may. 2022
 *      Author: Matias
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#ifndef ESTRUCTURA3_H_
#define ESTRUCTURA3_H_

typedef struct
{
	int id;
	char descripcion[20];
} eColor;

#endif /* ESTRUCTURA3_H_ */

int mostrarColor(eColor *lista);
int listarColor(eColor *lista, int tam);
int cargarDescripcionColor(eColor *lista, int tam, int id, char *descripcion);
int buscarColor(eColor *lista, int tam, int id, int *pIndice);
