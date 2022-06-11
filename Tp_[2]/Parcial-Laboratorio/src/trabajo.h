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

int initStructTrabajo(eTrabajo *lista, int tam);
int isEmptyTrabajo(eTrabajo *lista, int tam, int *pIndice);
int addTrabajo(eTrabajo *lista, int tamTra, eMascota *listaM, int tamM, eServicio *listaS, int tamS, int *idTrabajo, eColor *listaC, int tamC, eTipo *listaT, int tamT);
int listarTrabajo(eTrabajo *lista, int tamTra, eMascota *listaM, int tamM, eColor *listaC, int tamC, eTipo *listaT, int tamTIPO, eServicio *listaS, int tamS);
void hardCodearTrabajos(eTrabajo *lista);
