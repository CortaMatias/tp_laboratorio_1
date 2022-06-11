/*
 * trabajo.h
 *
 *  Created on: 8 may. 2022
 *      Author: Matias
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "autos.h"
#include "fecha.h"
#include "servicios.h"
#include "library.h"
#include "autos.h"
#ifndef TRABAJO_H_
#define TRABAJO_H_

typedef struct{
int id;
char patente[7];
int idServicio;
eFecha fecha;
int isEmpty;
}eTrabajo;

#endif /* TRABAJO_H_ */

int altaTrabajo(eAutos* listaA, int tamA, eServicio* listaS, int tamS, eTrabajo* listaT, int tamT, int* idTrabajo, eColor* listaC, int tamC, eMarca* listaM, int tamM);

int initTrabajo(eTrabajo* listaT, int tamT);

int isEmptyTrabajo(eTrabajo* listaT, int tamT, int *pIndice);

int mostrarTrabajo(eTrabajo* listaT, eServicio* listaS, int tamS);

int listarTrabajos(eTrabajo* listaT, int tamT, eServicio* listaS, int tamS);
