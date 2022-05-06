/*
 ============================================================================
 Name        : Tp22.c
 Author      : Matias Corta
 Version     :
 Copyright   : Your copyright notice
 Description : Tp 2
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayPassenger.h"
#define len 2000

int main(void) {
	setbuf(stdout, NULL);
	char salir = 'n';
	Passenger list[len];
	int id = 1;
	int indice;
	int flagAdd = 0;
	Passenger auxList;
	if (initPassengers(list, len)) {
		do {
			switch (menu()) {
			case 1:
				if (isEmpty(list, len, &indice)) {
					if (indice == -1) {
						printf("\n** No hay espacio disponible ** \n");
					} else {
						if (addPassengers(list, len, auxList.id, auxList.name, auxList.lastName, auxList.price, auxList.typePassenger, auxList.statusFly, auxList.flycode, &id, indice))
						{
							flagAdd++;
							printf("\n **Alta de pasajero cargada con exito** \n");
						}
					}
				} else {
					printf("\n** Ocurrio un problema **");
				}
				break;

			case 2:
				if (flagAdd) {
					if(modificarPasajero(list, len)){
						printf("** Pasajero modificado con exito **");
					}else{
						printf("** Error al modificar el pasajero **");
					}
				}
				break;

			case 3:
				if (flagAdd) {
					if (removePassenger(list, len, &flagAdd)) {
						printf("\n** Baja realizada con exito.**  \n");
					} else {
						printf("\n** Baja cancelada.** \n");
					}
				} else {
					printf("\n** No hay pasajeros en la lista. ** \n");
				}
				break;

			case 4:
				if (flagAdd) {
					if (!informarPasajeros(list, len)) {
						printf("** Error al informar los pasajeros**");
					}
				} else {
					printf("\n** No hay pasajeros en la lista. ** \n");
				}
				break;

			case 5:
				if (hardcodearPasajeros(list, len, 10, &id)) {
					printf("\n** Pasajeros de prueba cargados con exito **\n");
					flagAdd = 10;
				} else {
					printf("\n** Error al cargar los pasajeros de prueba **\n");
				}

				break;

			case 6:
				salir = 's';
				break;
			}
		} while (salir == 'n');
	} else {
		printf("\n**Error al inicializar pasajeros**\n");
	}
	return EXIT_SUCCESS;
}
