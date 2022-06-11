/*
 * marca.h
 *
 *  Created on: 8 may. 2022
 *      Author: Matias
 */

#ifndef MARCA_H_
#define MARCA_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

typedef struct{
	int id;
	char descripcion[20];

}eMarca;
#endif /* MARCA_H_ */


int listarMarcas(eMarca* lista, int tamM);
int mostrarMarca(eMarca* lista);
int cargarDescripcionMarca(eMarca* listaM, int tamM, int id, char* descripcion);
int buscarMarca(eMarca* listaM, int tamM, int id, int* pIndice);
