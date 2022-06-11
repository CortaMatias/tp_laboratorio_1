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

#ifndef ESTRUCTURA1_H_
#define ESTRUCTURA1_H_
typedef struct
{
	int id;
	char nombre[20];
	int idTipo;
	int idColor;
	int edad;
	char vacunado;
	int isEmpty;
} eMascota;

#endif /* ESTRUCTURA1_H_ */
int menu();
int isEmpty(eMascota *lista, int tam, int *pIndice);
int initStruct(eMascota *lista, int tam);
int mostrarMascota(eMascota *lista, eColor *listaC, int tamC, eTipo *listaT, int tamT);
int listarMascota(eMascota *lista, int tamM, eColor *listaC, int tamC, eTipo *listaT, int tamT);
int cargarNombreMascota(eMascota *lista, int tam, int id, char *descripcion);
int hardCodearMascotas(eMascota *lista);
int addMascota(eMascota *lista, int tamM, eColor *listaC, int tamC, eTipo *listaT, int tamT, int *idMascota);
int buscarId(eMascota *lista, int tam, int id, int *pIndice);
int removeMascota(eMascota *lista, int tamM, eColor *listaC, int tamC, eTipo *listaT, int tamT, int *flagAdd);
int modificarMascota(eMascota *lista, int tamM, eColor *listaC, int tamC, eTipo *listaT, int tamT);
