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
 * @brief
 *
 * @param list
 * @param len
 * @return int
 */
int menu();

int initPassengers(Passenger *list, int len);

int listarPasajeros(Passenger *list, int len);

int mostrarPasajero(Passenger *list);

int addPassengers(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, int statusFly, char flycode[], int* pId, int indice);

int isEmpty(Passenger list[], int len, int *pIndex);

int findPassengerById(Passenger *list, int len, int id, int *indice);

int removePassenger(Passenger *list, int len, int *flagAdd);

int menuModificar();

int modificarPasajero(Passenger *list, int len);

int sortPassengers(Passenger *list, int len, int criterio);

int sortPassengersByCode(Passenger *list, int len, int criterio);

int hardcodearPasajeros (Passenger* list, int len, int cantidad, int* pId);

int calculosPrecios(Passenger *list, int len);

int informarPasajeros(Passenger* list, int len);

int menuInformar();

