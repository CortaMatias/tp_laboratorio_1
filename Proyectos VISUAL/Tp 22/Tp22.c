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

int main(void)
{
	setbuf(stdout, NULL);
	char salir = 'n';
	Passenger list[len];
	int id = 1;
	int flagAdd = 0;
	if (initPassengers(list, len))
	{
		do
		{
			switch (menu())
			{
			case 1:
				
				if (addPassengers(list, len, &id))
				{
					flagAdd++;
					printf("Alta de pasajero cargada con exito.\n");
				}
				else
				{
					printf("Error al agregar pasajero");
				}
				break;

			case 2:
				break;

			case 3:

				break;

			case 4:

				break;

			case 5:
				// listar
				break;

			case 6:

				break;

			case 7:

				break;

			case 8:

				break;

			default:

				break;
			}
		} while (salir == 'n');
	}
	else
	{
		printf("Error al inicializar pasajeros.\n");
	}
	return EXIT_SUCCESS;
}
