/*
 * servicio.c
 *
 *  Created on: 11 may. 2022
 *      Author: Matias
 */
#include "servicio.h"

int mostrarServicio(eServicio *lista)
{
	int todoOk = 0;
	if (lista != NULL)
	{
		printf("%-4d  %-13s  %4.3f\n", lista->id, lista->descripcion, lista->precio);
		todoOk = 1;
	}
	return todoOk;
}

int listarServicios(eServicio *lista, int tam)
{
	int todoOk = 0;
	if (lista != NULL && tam > 0)
	{
		printf(" \n\n         ***   Listado de Servicios  ***\n\n");
		printf(" ID     Servicio      Precio \n");
		printf("---------------------------------\n");
		for (int i = 0; i < tam; i++)
		{
			mostrarServicio(lista + i);
		}
		printf("\n\n");
		todoOk = 1;
	}
	return todoOk;
}

int cargarDescripcionServicio(eServicio *lista, int tam, int id, char *descripcion)
{
	int todoOk = 0;
	int indice;

	buscarServicio(lista, tam, id, &indice);

	if (descripcion != NULL && indice != -1 && lista != NULL)
	{
		strcpy(descripcion, lista[indice].descripcion);
		todoOk = 1;
	}
	return todoOk;
}

int buscarServicio(eServicio *lista, int tam, int id, int *pIndice)
{
	int todoOk = 0;
	if (lista != NULL && tam > 0 && pIndice != NULL)
	{
		*pIndice = -1;
		for (int i = 0; i < tam; i++)
		{
			if (lista[i].id == id)
			{
				*pIndice = i;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarIdServicio(eServicio *lista, int tam, int id, int *pIndice)
{
	int todoOk = 0;
	if (lista != NULL && tam > 0 && pIndice != NULL)
	{
		*pIndice = -1;
		for (int i = 0; i < tam; i++)
		{

			if (lista[i].id == id)
			{
				*pIndice = i;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
