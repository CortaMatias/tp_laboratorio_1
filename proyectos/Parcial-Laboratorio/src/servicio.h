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

/**
 * @brief copia la descripcion de la lista de servicios y la guarda en descripcion[]
 * 
 * @param lista tipo eServicio puntero array de servicios
 * @param tam tipo int tamaño de la lista de servicios
 * @param id tipo int id del servicio que queremos la descripcion
 * @param descripcion tipo char puntero donde se guarda la descripcion del servicio
 * @return int int retorna si la funcion se ejecuto correctamente
 */
int cargarDescripcionServicio(eServicio *lista, int tam, int id, char *descripcion);

/**
 * @brief busca el indice donde se encuentra el servicio con el id que le ingresamos 
 * 
 * @param lista tipo eServicio puntero array de la lista servicios 
 * @param tam tipo int tamaño de la lista de servicios
 * @param id tipo int numero de id del servicio que queremos buscar
 * @param pIndice tipo int puntero numero de indice donde coincide el id que buscamos
 * @return int int retorna si la funcion se ejecuto correctamente
 */
int buscarServicio(eServicio *lista, int tam, int id, int *pIndice);

/**
 * @brief lista el array de servicios
 * 
 * @param lista tipo eServicio puntero array de la lista servicios
 * @param tam tipo int tamaño de la lista servicios
 * @return int int retorna si la funcion se ejecuto correctamente
 */
int listarServicios(eServicio *lista, int tam);

/**
 * @brief muestra un servicio 
 * 
 * @param lista tipo eServicio puntero array de la lista servicios
 * @return int int retorna si la funcion se ejecuto correctamente
 */
int mostrarServicio(eServicio *lista);

/**
 * @brief busca el indice donde se encuentra el id del servicio que queremos buscar 
 * 
 * @param lista tipo eServicio puntero array de servicios
 * @param tam tipo int tamaño de la lista de servicios 
 * @param id tipo int id del servicio que queremos buscar 
 * @param pIndice tipo int puntero numero del indice donde se encuentra el servicio que buscamos 
 * @return int int retorna si la funcion se ejecuto correctamente
 */
int buscarIdServicio(eServicio *lista, int tam, int id, int *pIndice);
