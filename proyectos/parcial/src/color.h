/*
 * color.h
 *
 *  Created on: 8 may. 2022
 *      Author: Matias
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#ifndef COLOR_H_
#define COLOR_H_

typedef struct{
int id;
char descripcion[20];

}eColor;


#endif /* COLOR_H_ */

int mostrarColor(eColor* lista);

int listarColores(eColor* lista, int tamC);

int cargarDescripcionColor(eColor* listaC, int tamC, int id, char* descripcion);

int buscarColor(eColor* listaC, int tamC, int id, int* pIndice);
