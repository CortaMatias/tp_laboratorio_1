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

/**
 * @brief lista el array tipos
 * 
 * @param lista tipo eTipo puntero array de tipos
 * @param tam tipo int tamaño del array tipos
 * @return int retorna si la funcion se ejecuto correctamente 
 */
int listarTipo(eTipo *lista, int tam);

/**
 * @brief muestra un tipo
 * 
 * @param lista tipo eTipo puntero array de tipos
 * @return int retorna si la funcion se ejecuto correctamente 
 */
int mostrarTipo(eTipo *lista);

/**
 * @brief copia la descripcion de la lista de tipos y la guarda en la variable descripcion 
 * 
 * @param lista tipo eTipo puntero array de tipos
 * @param tam tipo int tamaño del array tipos
 * @param id tipo int numero del id del tipo que buscamos
 * @param descripcion tipo int puntero donde se guarda la descripcion que corresponde al id del tipo 
 * @return int retorna si la funcion se ejecuto correctamente 
 */
int cargarDescripcionTipo(eTipo *lista, int tam, int id, char *descripcion);

/**
 * @brief busca el indice donde coinciden los id del tipo que queremos buscar
 * 
 * @param lista tipo eTipo puntero array de tipos
 * @param tam tipo int tamaño del array tipos
 * @param id tipo int numero del id del tipo
 * @param pIndice tipo int puntero donde se guarda el numero del indice donde se encuentra el id del tipo 
 * @return int retorna si la funcion se ejecuto correctamente 
 */
int buscarTipo(eTipo *lista, int tam, int id, int *pIndice);
