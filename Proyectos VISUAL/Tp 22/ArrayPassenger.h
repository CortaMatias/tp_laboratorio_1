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
#include "library.h"
#include <ctype.h>

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

int listarPasajeros(Passenger* list[], int len);

int mostrarPasajero(Passenger* list);

int addPassengers(Passenger *list, int len, int *id);

int isEmpty(Passenger list[], int len, int *pIndex);


