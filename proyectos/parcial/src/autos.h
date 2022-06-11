/*
 * autos.h
 *
 *  Created on: 8 may. 2022
 *      Author: Matias
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "library.h"
#include "marca.h"
#include "color.h"

#ifndef AUTOS_H_
#define AUTOS_H_

typedef struct{
int id;
char patente[7];
int idMarca;
int idColor;
int modelo;
int isEmpty;

}eAutos;

#endif /* AUTOS_H_ */

int menu();

int addAuto(eAutos* lista, int tamA, int* idAuto, eMarca* listaM, int tamM, eColor* listaC, int tamC);

int initAutos(eAutos *lista, int tamA);

int isEmpty(eAutos* lista, int tamA, int *pIndice);

int mostrarAuto(eAutos* lista, eColor* listaC, int tamC, eMarca* listaM, int tamM);

int listarAutos(eAutos* lista, int tamA, eColor* listaC, int tamC, eMarca* listaM, int tamM);

int removeAuto(eAutos* lista, int tamA, int *flagAdd, eColor* listaC, int tamC, eMarca* listaM, int tamM);

int findAutoByPatente(eAutos *lista, int tamA, char* patente, int *indice);

int modificarAuto(eAutos* lista, int tamA, eColor* listaC, int tamC, eMarca* listaM, int tamM);

int menuModificar(eAutos* lista, eColor* listaC, int tamC,eMarca* listaM, int tamM);

int buscarPatente(eAutos* listaA, int tamA, char* patente, int* pIndice);

int validarPatente(eAutos* listaA, int tamA, char* patente);



void hardCodearAutos(eAutos* lista, int tamA);
