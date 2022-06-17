
#include "../inc/parser.h"
#include <stdio.h>
#include <stdlib.h>

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE *pFile, LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	int cant;

	if (pFile != NULL && pArrayListPassenger != NULL)
	{
		while (!feof(pFile))
		{
			Passenger *pasajero = Passenger_new();
			if (pasajero != NULL)
			{
				cant = fscanf(pFile, "%d,%[^,],%[^,],%f,%[^,],%[^,],%[^\n]\n", &pasajero->id,
						pasajero->nombre,pasajero->apellido,
						&pasajero->precio,pasajero->codigoDeVuelo,
						pasajero->tipoPasajero, pasajero->estadoDeVuelo);
				if (cant != 7)
				{
					break;
				}
				ll_add(pArrayListPassenger, pasajero);
			}
			todoOk = 1;
		}
	}
	return todoOk;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE *pFile, LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	int cant;

	if (pFile != NULL && pArrayListPassenger != NULL)
	{
		while (!feof(pFile))
		{
			Passenger *pasajero = Passenger_new();
			if (pasajero != NULL)
			{
				cant = fread(pasajero, sizeof(Passenger), 1, pFile);
				if (cant != 1)
				{
					break;
				}
				ll_add(pArrayListPassenger, pasajero);
			}
			todoOk = 1;
		}
	}
	return todoOk;
}
