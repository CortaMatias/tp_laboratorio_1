/*
 * ArrayPassenger.h
 *
 *  Created on: 22 abr. 2022
 *      Author: Matias
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "biblioteca.h"
#include <ctype.h>
#define UP 1
#define DOWN 0

typedef struct
{
    int id;
    char name[24];
    char lastName[32];
    float price;
    char flycode[10];
    int typePassenger;
    int statusFly;
    int isEmpty;
} Passenger;

#endif /* ARRAYPASSENGER_H_ */

/**
 * @brief muestra el menu principal
 *
 * @return int retorna la opcion elegida por el usuario
 */
int menu();

/**
 * @brief inicializa el array en la seccion is Empty en 1 para avisar que estan disponibles
 * 
 * @param list tipo Passenger, lista donde van a estar cargados los datos de los pasajeros. 
 * @param len tipo int, tamaño del array
 * @return int retorna si la funcion se ejecuto correctamente
 */
int initPassengers(Passenger *list, int len);

/**
 * @brief muestra la lista de pasajeros
 * 
 * @param list tipo Passenger, lista donde van a estar cargados los datos de los pasajeros.
 * @param len tipo int, tamaño del array 
 * @return int retorna si la funcion se ejecuto correctamente
 */
int listarPasajeros(Passenger *list, int len);

/**
 * @brief muestra un pasajero en particular
 * 
 * @param list tipo Passenger, lista donde van a estar cargados los datos de los pasajeros.
 * @return int retorna si la funcion se ejecuto correctamente
 */
int mostrarPasajero(Passenger *list);

/**
 * @brief pide y valida los datos de un pasajero, si esta todo correcto le asigna un id y guarda los datos. 
 * 
 * @param list tipo Passenger, lista donde van a estar cargados los datos de los pasajeros.
 * @param len tipo int, tamaño del array 
 * @param id tipo int, identifica al pasajero con un numero unico
 * @param name tipo char, nombre del pasajero
 * @param lastName tipo char, apellido del pasajero
 * @param price tipo float, precio del vuelo
 * @param typePassenger tipo int, tipo de boleto que compro 1= First Class 2 = Business  3 = Turista
 * @param statusFly tipo int, estado del vuelo 1 = Activo, 2=Demorado, 3= Cancelado
 * @param flycode tipo char, codigo alfanumerico unico de cada vuelo
 * @param pId tipo int puntero, id a asignar y luego de asignarlo lo incrementamos
 * @param indice tipo int, indice del array donde se van a guardar los datos
 * @return int retorna si la funcion se ejecuto correctamente
 */
int addPassengers(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, int statusFly, char flycode[], int* pId, int indice);

/**
 * @brief recorre la lista en busca del primer lugar libre y le pasa por referencia el indice del array que esta disponible 
 * 
 * @param list tipo Passenger, lista donde van a estar cargados los datos de los pasajeros.
 * @param len tipo int, tamaño del array 
 * @param pIndex tipo int puntero, se carga con el valor del indice con espacio disponible 
 * @return int retorna si la funcion se ejecuto correctamente
 */
int isEmpty(Passenger list[], int len, int *pIndex);

/**
 * @brief recorre el array buscando el indice donde el id que ingreso el usuario sea igual a algun id guardado
 * 
 * @param list tipo Passenger, lista donde van a estar cargados los datos de los pasajeros.
 * @param len tipo int, tamaño del array 
 * @param id tipo int, el id que ingresa el usuario el cual vamos a comparar con la list.id
 * @param indice tipo int puntero, se guarda en esta variable el indice donde se encuentra la coincidencia del id que ingreso el usuario con la lista
 * @return int retorna si la funcion se ejecuto correctamente
 */
int findPassengerById(Passenger *list, int len, int id, int *indice);

/**
 * @brief remueve un pasajero de forma logica
 * 
 * @param list tipo Passenger, lista donde van a estar cargados los datos de los pasajeros.
 * @param len tipo int, tamaño del array 
 * @param flagAdd tipo int puntero, disminuye en 1 cuando se elimina un pasajero 
 * @return int retorna si la funcion se ejecuto correctamente
 */
int removePassenger(Passenger *list, int len, int *flagAdd);

/**
 * @brief muestra el menu de modificar pasajero
 * 
 * @return int retorna la opcion elegida por el usuario
 */
int menuModificar();

/**
 * @brief permite al usuario modificar los datos del pasajero 
 * 
 * @param list  tipo Passenger, lista donde van a estar cargados los datos de los pasajeros.
 * @param len tipo int, tamaño del array 
 * @return int 
 */
int modificarPasajero(Passenger *list, int len);

/**
 * @brief ordena el array list por tipo de pasajero y por apellido
 * 
 * @param list  tipo Passenger, lista donde van a estar cargados los datos de los pasajeros.
 * @param len tipo int, tamaño del array 
 * @param criterio 
 * @return int retorna si la funcion se ejecuto correctamente
 */
int sortPassengers(Passenger *list, int len, int criterio);

/**
 * @brief ordena el array list por el codigo  y por el estado de vuelo
 * 
 * @param list  tipo Passenger, lista donde van a estar cargados los datos de los pasajeros.
 * @param len tipo int, tamaño del array 
 * @param criterio 
 * @return int retorna si la funcion se ejecuto correctamente
 */
int sortPassengersByCode(Passenger *list, int len, int criterio);


/**
 * @brief calcula el precio total, el promedio y la cantidad total de pasajeros 
 * 
 * @param list tipo Passenger, lista donde van a estar cargados los datos de los pasajeros.
 * @param len tipo int, tamaño del array 
 * @return int retorna si la funcion se ejecuto correctamente
 */
int calculosPrecios(Passenger *list, int len);


/**
 * @brief muestra el menu de la opcion informar 
 * 
 * @return int retorna si la funcion se ejecuto correctamente
 */
int menuInformar();

/**
 * @brief le pide al usuario que ingrese como desea informar los datos
 * 
 * @param list tipo Passenger, lista donde van a estar cargados los datos de los pasajeros.
 * @param len tipo int, tamaño del array 
 * @return int retorna si la funcion se ejecuto correctamente
 */
int informarPasajeros(Passenger *list, int len);

/**
 * @brief 
 * 
 * @param list tipo Passenger, lista donde van a estar cargados los datos de los pasajeros.
 * @param len tipo int, tamaño del array 
 * @param cantidad tipo int, cantida de pasajeros a hardcodear
 * @param pId tipo int puntero, se incrementa el id luego de cada pasajero agregado
 * @return int retorna si la funcion se ejecuto correctamente
 */
int hardcodearPasajeros(Passenger *list, int len, int cantidad, int *pId);
