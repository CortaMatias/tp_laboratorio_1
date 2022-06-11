/*
 * estructura1.h
 *
 *  Created on: 10 may. 2022
 *      Author: Matias
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "library.h"
#include "color.h"
#include "tipo.h"
#include "cliente.h"

#ifndef ESTRUCTURA1_H_
#define ESTRUCTURA1_H_
typedef struct
{
	int id;
	char nombre[20];
	eCliente cliente;
	int idTipo;
	int idColor;
	int edad;
	char vacunado;
	int isEmpty;
} eMascota;

#endif /* ESTRUCTURA1_H_ */
/**
 * @brief muestra el menu principal
 * 
 * @return int int retorna la opcion elegida por el usuario
 */
int menu();

/**
 * @brief busca el primer indice disponible en el campo is Empty de la lista de mascotas 
 * 
 * @param lista tipo eMascota lista donde van a estar cargados los datos de las mascotas
 * @param tam tipo int tamaño de la lista 
 * @param pIndice tipo int puntero donde se guarda el indice del espacio disponible 
 * @return int retorna si la funcion se ejecuto correctamente
 */
int isEmpty(eMascota *lista, int tam, int *pIndice);

/**
 * @brief inicializa el array en la seccion is Empty en 1 para avisar que estan disponibles
 * 
 * @param lista tipo eMascota puntero array de las mascotas 
 * @param tam tipo int tamaño de la lista 
 * @return int retorna si la funcion se ejecuto correctamente
 */
int initStruct(eMascota *lista, int tam);

/**
 * @brief muestra una mascota con su informacion 
 * 
 * @param lista tipo eMascota puntero array de las mascotas 
 * @param listaC tipo eColor puntero array de los colores
 * @param tamC tipo int tamaño de la lista de colores
 * @param listaT tipo eTipo puntero array de los tipos
 * @param tamT tipo int tamaño de la lista de los tipos
 * @return int retorna si la funcion se ejecuto correctamente 
 */
int mostrarMascota(eMascota *lista, eColor *listaC, int tamC, eTipo *listaT, int tamT);

/**
 * @brief lista las mascotas y su informacion 
 * 
 * @param lista tipo eMascota puntero array de las mascotas 
 * @param tamM tipo int tamaño de la lista de mascotas
 * @param listaC tipo eColor puntero array de los colores
 * @param tamC tipo int tamaño de la lista de colores
 * @param listaT tipo eTipo puntero array de los tipos
 * @param tamT tipo int tamaño de la lista de los tipos
 * @return int retorna si la funcion se ejecuto correctamente
 */
int listarMascota(eMascota *lista, int tamM, eColor *listaC, int tamC, eTipo *listaT, int tamT);

/**
 * @brief carga el nombre de la mascota del id ingresado en la variable descripcion 
 * 
 * @param lista tipo eMascota puntero array de las mascotas 
 * @param tam tipo int tamaño de la lista de mascotas
 * @param id tipo int numero del id de la mascota
 * @param descripcion tipo char puntero donde se guarda el nombre de la mascota 
 * @return int retorna si la funcion se ejecuto correctamente
 */
int cargarNombreMascota(eMascota *lista, int tam, int id, char *descripcion);


int cargarNombreDueño(eMascota *lista, int tam, int id, char *descripcion);



/**
 * @brief ingresa mascotas de prueba con su respectiva informacion 
 * 
 * @param lista tipo eMascota puntero array de las mascotas 
 * @return int retorna si la funcion se ejecuto correctamente
 */
int hardCodearMascotas(eMascota *lista);

/**
 * @brief agrega una mascota a la lista luego de validar todos los datos ingresados 
 * 
 * @param lista tipo eMascota puntero array de las mascotas 
 * @param tamM tipo int tamaño de la lista de mascotas
 * @param listaC tipo eColor puntero array de los colores
 * @param tamC tipo int tamaño de la lista de colores
 * @param listaT tipo eTipo puntero array de los tipos
 * @param tamT tipo int tamaño de la lista de tipos
 * @param idMascota tipo int puntero numero de id de la mascota
 * @return int  retorna si la funcion se ejecuto correctamente
 */
int addMascota(eMascota *lista, int tamM, eColor *listaC, int tamC,
			   eTipo *listaT, int tamT, int *idMascota, int* idCliente);

/**
 * @brief busca el indice donde se encuentra el id que le ingresamos 
 * 
 * @param lista tipo eMascota puntero array de las mascotas 
 * @param tam tipo int tamaño de la lista de mascotas
 * @param id tipo int numero de id que queremos buscar
 * @param pIndice tipo int puntero numero del indice donde coincide el id buscado 
 * @return int  retorna si la funcion se ejecuto correctamente
 */
int buscarId(eMascota *lista, int tam, int id, int *pIndice);

/**
 * @brief remueve una mascota de la lista buscandola a traves del id y dando de baja el campos isEmpty
 * 
 * @param lista tipo eMascota puntero array de las mascotas 
 * @param tamM tipo int tamaño de la lista de mascotas
 * @param listaC tipo eColor puntero array de los colores
 * @param tamC tipo int tamaño de la lista de colores 
 * @param listaT tipo eTipo puntero array de los tipos
 * @param tamT tipo int tamaño de la lista de tipos 
 * @param flagAdd tipo int puntero bandera que disminuye cuando se elimina una mascota de la lista 
 * @return int retorna si la funcion se ejecuto correctamente
 */
int removeMascota(eMascota *lista, int tamM, eColor *listaC, int tamC, eTipo *listaT, int tamT, int *flagAdd);

/**
 * @brief modifica los datos de el campo de la mascota seleccionado 
 * 
 * @param lista tipo eMascota puntero array de las mascotas 
 * @param tamM tipo int tamaño de la lista de mascotas
 * @param listaC tipo eColor puntero array de los colores
 * @param tamC tipo int tamaño de la lista de colores
 * @param listaT tipo eTipo puntero array de los tipos
 * @param tamT tipo int tamaño de la lista de tipos
 * @return int retorna si la funcion se ejecuto correctamente
 */
int modificarMascota(eMascota *lista, int tamM, eColor *listaC, int tamC, eTipo *listaT, int tamT);
