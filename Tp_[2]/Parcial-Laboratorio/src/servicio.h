/*
 * servicio.h
 *
 *  Created on: 11 may. 2022
 *      Author: Matias
 */
#include "fecha.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#ifndef SERVICIO_H_
#define SERVICIO_H_

typedef struct
{
	int id;
	char descripcion[25];
	float precio;
} eServicio;
#endif /* SERVICIO_H_ */

int cargarDescripcionServicio(eServicio *lista, int tam, int id, char *descripcion);
int buscarServicio(eServicio *lista, int tam, int id, int *pIndice);
int listarServicios(eServicio *lista, int tam);
int mostrarServicio(eServicio *lista);
int buscarIdServicio(eServicio *lista, int tam, int id, int *pIndice);
