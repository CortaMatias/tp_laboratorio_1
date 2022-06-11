/*
 * trabajo.h
 *
 *  Created on: 11 may. 2022
 *      Author: Matias
 */

#ifndef TRABAJO_H_
#define TRABAJO_H_
#include "fecha.h"
#include "servicio.h"
#include "mascota.h"

typedef struct
{

	int id;
	int idMascota;
	int idServicio;
	eFecha fecha;
	int isEmpty;

} eTrabajo;

#endif /* TRABAJO_H_ */

/**
 * @brief inicializa el campo isEmpty del array trabajo en 1 para que avisar que esta disponible
 * 
 * @param lista tipo eTrabajo puntero array de los trabajos
 * @param tam tipo int tamaño del array trabajo
 * @return int retorna si la funcion se ejecuto correctamente 
 */
int initStructTrabajo(eTrabajo *lista, int tam);

/**
 * @brief busca el primer campo isEmpty disponible y lo guarda en la variable indice 
 * 
 * @param lista tipo eTrabajo puntero array de los trabajos
 * @param tam tipo int tamaño del array trabajo
 * @param pIndice tipo int puntero indice donde hay un lugar disponible 
 * @return int retorna si la funcion se ejecuto correctamente 
 */
int isEmptyTrabajo(eTrabajo *lista, int tam, int *pIndice);

/**
 * @brief agrega un trabajo a lista luego de validar los datos ingresados 
 * 
 * @param lista tipo eTrabajo puntero array de los trabajos
 * @param tamTra tipo int tamaño del array trabajo
 * @param listaM tipo eMascota puntero array de mascotas
 * @param tamM tipo int tamaño del array mascota
 * @param listaS tipo eServicio puntero array de servicio
 * @param tamS tipo int tamaño del array servicio
 * @param idTrabajo tipo int puntero numero de id del trabajo  
 * @param listaC tipo eColor puntero array de colores
 * @param tamC tipo int tamaño del array colores
 * @param listaT tipo eTipo puntero array de los tipos
 * @param tamT tipo int tamaño del array tipo
 * @return int retorna si la funcion se ejecuto correctamente 
 */
int addTrabajo(eTrabajo *lista, int tamTra, eMascota *listaM, int tamM, eServicio *listaS, int tamS, int *idTrabajo, eColor *listaC, int tamC, eTipo *listaT, int tamT);

/**
 * @brief muestra un trabajo y su informacion 
 * 
 * @param lista tipo eTrabajo puntero array de los trabajos
 * @param listaM tipo eMascota puntero array de mascotas
 * @param tamM tipo int tamaño del array mascota
 * @param listaC tipo eColor puntero array de colores
 * @param tamC tipo int tamaño del array colores
 * @param listaT tipo eTipo puntero array de los tipos
 * @param tamTIPO tipo int tamaño del array tipo
 * @param listaS tipo eServicio puntero array de servicio
 * @param tamS tipo int tamaño del array servicio
 * @return int  retorna si la funcion se ejecuto correctamente 
 */
int mostrarTrabajo(eTrabajo *lista, eMascota *listaM, int tamM, eColor *listaC, int tamC, eTipo *listaT, int tamTIPO, eServicio *listaS, int tamS);

/**
 * @brief lista los trabajos y su informacion  
 * 
 * @param lista tipo eTrabajo puntero array de los trabajos
 * @param tamTra tipo int tamaño del array trabajo
 * @param listaM tipo eMascota puntero array de mascotas
 * @param tamM tipo int tamaño del array mascota
 * @param listaC tipo eColor puntero array de colores
 * @param tamC tipo int tamaño del array colores
 * @param listaT tipo eTipo puntero array de los tipos
 * @param tamTIPO tipo int tamaño del array tipo
 * @param listaS  tipo eServicio puntero array de servicio
 * @param tamS tipo int tamaño del array servicio
 * @return int retorna si la funcion se ejecuto correctamente 
 */
int listarTrabajo(eTrabajo *lista, int tamTra, eMascota *listaM, int tamM, eColor *listaC, int tamC, eTipo *listaT, int tamTIPO, eServicio *listaS, int tamS);

/**
 * @brief ingresa trabajos de prueba con sus datos 
 * 
 * @param lista tipo eTrabajo puntero array de los trabajos
 */
void hardCodearTrabajos(eTrabajo *lista);
