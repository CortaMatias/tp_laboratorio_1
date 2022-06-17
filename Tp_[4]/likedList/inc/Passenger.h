/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */


#include "../inc/library.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
    int id;
    char nombre[50];
    char apellido[50];
    float precio;
    char codigoDeVuelo[8];
    char tipoPasajero[50];
    char estadoDeVuelo[50];
}Passenger;


Passenger* Passenger_new();
Passenger* Passenger_newParametros(int id,char* nombre,char* apellido, char* precio , char* codigoDeVuelo, char* tipoPasajero,char* estadoDeVuelo);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);

int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);

int Passenger_setPrecio(Passenger* this, float precio);
int Passenger_getPrecio(Passenger* this,float* precio);

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);

int Passenger_setEstadoDeVuelo(Passenger* this,char* codigoDeVuelo);
int Passenger_getEstadoDeVuelo(Passenger* this,char* codigoDeVuelo);

int cargarDescripcionEstado(int estado, char* descripcion);
int cargarDescripcionTipo(int tipo, char* descripcion);




#endif /* PASSENGER_H_ */
