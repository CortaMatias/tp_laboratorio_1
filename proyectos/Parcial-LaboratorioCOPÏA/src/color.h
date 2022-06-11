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
/**
 * @brief muestra un color de la lista
 * 
 * @param lista tipo eColor array de la lista de colores
 * @return int retorna si la funcion se ejecuto correctamente
 */
int mostrarColor(eColor *lista);

/**
 * @brief muestra la lista de colores
 * 
 * @param lista tipo eColor array de la lista de colores
 * @param tam tipo int tamaño de la lista
 * @return int retorna si la funcion se ejecuto correctamente
 */
int listarColor(eColor *lista, int tam);

/**
 * @brief copia la descripcion de la lista de colores y la guarda en descripcion[]
 * 
 * @param lista tipo eColor array de la lista de colores
 * @param tam tipo int tamaño de la lista
 * @param id tipo int numero de id del color
 * @param descripcion array donde se guarda la descripcion del color
 * @return int retorna si la funcion se ejecuto correctamente
 */
int cargarDescripcionColor(eColor *lista, int tam, int id, char *descripcion);

/**
 * @brief busca el indice donde coinciden los id del color que queremos buscar
 * 
 * @param lista tipo eColor array de la lista de colores 
 * @param tam tipo int tamaño de la lista 
 * @param id tipo int numero de id del color 
 * @param pIndice tipo int puntero donde se guarda el indice donde se encuentra el id 
 * @return int retorna si la funcion se ejecuto correctamente
 */
int buscarColor(eColor *lista, int tam, int id, int *pIndice);
