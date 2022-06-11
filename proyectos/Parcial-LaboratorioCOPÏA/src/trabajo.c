/*
 * trabajo.c
 *
 *  Created on: 11 may. 2022
 *      Author: Matias
 */

#include "trabajo.h"
#include "servicio.h"
#include "mascota.h"

int initStructTrabajo(eTrabajo *lista, int tam)
{
	int todoOk = 0;

	if (lista != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			lista[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int isEmptyTrabajo(eTrabajo *lista, int tam, int *pIndice)
{
	int todoOk = 0;
	if (lista != NULL && tam > 0 && pIndice != NULL)
	{

		*pIndice = -1;
		for (int i = 0; i < tam; i++)
		{
			if (lista[i].isEmpty)
			{
				*pIndice = i;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int addTrabajo(eTrabajo *lista, int tamTra, eMascota *listaM, int tamM, eServicio *listaS, int tamS, int *idTrabajo, eColor *listaC, int tamC,
			   eTipo *listaT, int tamT)
{
	int todoOk = 0;
	int indice1;
	int indice;
	int indice2;
	eTrabajo auxTrabajos;
	if (lista != NULL && tamTra > 0 && listaS != NULL && tamS > 0 && listaM != NULL && tamM > 0 && idTrabajo != NULL && listaC != NULL && tamC > 0 && listaT != NULL && tamT > 0)
	{
		if (isEmptyTrabajo(lista, tamTra, &indice))
		{
			listarMascota(listaM, tamM, listaC, tamC, listaT, tamT);
			validarInt("\nIngresar el id de la mascota\n", "\nError al ingresar el id, ingrese un id valido\n", &auxTrabajos.idMascota, 1, 2002);
			buscarId(listaM, tamM, auxTrabajos.idMascota, &indice1);
			while (indice1 == -1)
			{
				validarInt(
					"\nError. no se encontro una mascota con ese ID. Reingrese un id valido: \n",
					"\nError. Reingrese un id valido\n", &auxTrabajos.idMascota, 1, 2000);
				buscarId(listaM, tamM, auxTrabajos.idMascota, &indice1);
			}
			listarServicios(listaS, tamS);
			validarInt("\nIngrese el id del servicio;  \n", "\nError. reingrese un id valido", &auxTrabajos.idServicio, 20000, 20002);
			buscarIdServicio(listaS, tamS, auxTrabajos.idServicio, &indice2);
			while (indice2 == -1)
			{
				validarInt(
					"\nError. no se encontro una mascota con ese ID. Reingrese un id valido: \n",
					"\nError. Reingrese un id valido\n", &auxTrabajos.idServicio, 20000, 20002);
				buscarIdServicio(listaS, tamS, auxTrabajos.idServicio, &indice2);
			}
			validarFecha(&auxTrabajos.fecha.dia, &auxTrabajos.fecha.mes, &auxTrabajos.fecha.anio);
			auxTrabajos.id = *idTrabajo;
			lista[indice] = auxTrabajos;
			lista[indice].isEmpty = 0;
			todoOk = 1;
		}
		else
		{
			printf("No hay espacio disponible en la lista\n");
		}
	}

	return todoOk;
}

int mostrarTrabajo(eTrabajo *lista, eMascota *listaM, int tamM, eColor *listaC, int tamC, eTipo *listaT, int tamTIPO, eServicio *listaS, int tamS)
{
	int todoOk = 0;
	char nombre[20];
	char servicio[20];
	if (lista != NULL && listaC != NULL && listaM != NULL && tamM > 0 && tamC > 0)
	{
		cargarDescripcionServicio(listaS, tamS, lista->idServicio, servicio);
		cargarNombreMascota(listaM, tamM, lista->idMascota, nombre);

		printf(" %-4d %-15s %-15s %02d/%02d/%-4d\n", lista->id, nombre, servicio, lista->fecha.dia, lista->fecha.mes, lista->fecha.anio);
		todoOk = 1;
	}
	return todoOk;
}

int listarTrabajo(eTrabajo *lista, int tamTra, eMascota *listaM, int tamM, eColor *listaC, int tamC, eTipo *listaT, int tamTIPO, eServicio *listaS, int tamS)
{
	int todoOk = 0;
	int flag = 0;
	if (lista != NULL && tamM > 0 && listaM != NULL && tamM > 0 && listaC != NULL && tamC > 0 && listaT != NULL && tamTIPO > 0 && listaS != NULL && tamS > 0)
	{
		system("cls");
		printf(" \n\n ***   Listado de Trabajos  ***\n\n");
		printf("%-4s %-15s %-15s %-9s \n", "ID", "Nombre", "Servicio", "Fecha");
		printf("-------------------------------------------------------------\n");
		for (int i = 0; i < tamTra; i++)
		{
			if (!lista[i].isEmpty)
			{
				mostrarTrabajo(lista + i, listaM, tamM, listaC, tamC, listaT, tamTIPO, listaS, tamS);
				flag = 1;
			}
		}
		if (!flag)
		{
			printf("\n** No hay Trabajos en el sistema.** ");
		}
		todoOk = 1;
	}
	return todoOk;
}

void hardCodearTrabajos(eTrabajo *lista)
{
	eTrabajo workss[35] = {
		{1, 1, 20000, {12, 3, 2019}, 0},
		{2, 2, 20000, {2, 4, 2019}, 0},
		{3, 3, 20001, {7, 1, 2019}, 0},
		{4, 4, 20002, {9, 11, 2019}, 0},
		{5, 5, 20002, {12, 12, 2019}, 0},
		{6, 6, 20001, {21, 7, 2019}, 0},
		{7, 7, 20001, {22, 8, 2019}, 0},
		{8, 8, 20002, {31, 5, 2019}, 0},
		{9, 9, 20000, {2, 2, 2019}, 0},
		{10, 10, 20000, {18, 2, 2019}, 0},
		{11, 12, 20001, {17, 3, 2019}, 0},
		{12, 11, 20000, {17, 4, 2019}, 0},
		{13, 15, 20000, {2, 6, 2019}, 0},
		{14, 14, 20001, {7, 3, 2019}, 0},
		{15, 13, 20002, {21, 7, 2019}, 0},
		{16, 16, 20002, {11, 9, 2019}, 0},
		{17, 19, 20001, {3, 7, 2019}, 0},
		{18, 18, 20001, {21, 8, 2019}, 0},
		{19, 17, 20002, {28, 5, 2019}, 0},
		{20, 21, 20001, {2, 8, 2019}, 0},
		{21, 20, 20000, {8, 2, 2019}, 0},
		{22, 22, 20001, {17, 3, 2019}, 0},
		{23, 18, 20000, {17, 4, 2019}, 0},
		{24, 17, 20000, {21, 3, 2019}, 0},
		{25, 14, 20002, {16, 4, 2019}, 0},
		{26, 21, 20000, {17, 4, 2019}, 0},
		{27, 5, 20001, {23, 3, 2019}, 0},
		{28, 4, 20000, {12, 2, 2019}, 0},
		{29, 1, 20000, {2, 3, 2019}, 0},
		{30, 8, 20001, {7, 2, 2019}, 0},
		{31, 9, 20002, {9, 12, 2019}, 0},
		{32, 10, 20001, {12, 9, 2019}, 0},
		{33, 3, 20001, {21, 5, 2019}, 0},
		{34, 9, 20002, {12, 2, 2019}, 0},
		{35, 8, 20000, {21, 1, 2019}, 0}};
	for (int i = 0; i < 35; i++)
	{
		lista[i] = workss[i];
	}
}
