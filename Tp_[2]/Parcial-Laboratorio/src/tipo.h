/*
 * estructura2.h
 *
 *  Created on: 10 may. 2022
 *      Author: Matias
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#ifndef ESTRUCTURA2_H_
#define ESTRUCTURA2_H_

typedef struct
{
	int id;
	char descripcion[20];
} eTipo;

#endif /* ESTRUCTURA2_H_ */

int listarTipo(eTipo *lista, int tam);
int mostrarTipo(eTipo *lista);
int cargarDescripcionTipo(eTipo *lista, int tam, int id, char *descripcion);
int buscarTipo(eTipo *lista, int tam, int id, int *pIndice);
