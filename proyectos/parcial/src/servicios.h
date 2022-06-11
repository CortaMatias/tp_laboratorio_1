/*
 * servicios.h
 *
 *  Created on: 8 may. 2022
 *      Author: Matias
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#ifndef SERVICIOS_H_
#define SERVICIOS_H_
typedef struct{
int id;
char descripcion[20];
float precio;


}eServicio;

#endif /* SERVICIOS_H_ */

int mostrarServicio(eServicio* listaS);

int listarServicios(eServicio* listaS, int tamS);

int cargarDescripcionServicio(eServicio* listaS, int tamS, int id, char* descripcion);

int buscarServicio(eServicio* listaS, int tamS, int id, int* pIndice);
