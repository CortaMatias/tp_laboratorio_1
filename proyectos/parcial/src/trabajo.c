/*
 * trabajo.c
 *
 *  Created on: 8 may. 2022
 *      Author: Matias
 */
#include "trabajo.h"
#include "servicios.h"

int altaTrabajo(eAutos* listaA, int tamA, eServicio* listaS, int tamS, eTrabajo* listaT, int tamT, int* idTrabajo, eColor* listaC, int tamC, eMarca* listaM, int tamM){
int todoOk = 0;
int indice;

if(listaA != NULL && tamA > 0 && listaS != NULL && tamS > 0){

eTrabajo auxLista;
	if(isEmptyTrabajo(listaT, tamT, &indice)){
			listarAutos(listaA, tamA,listaC, tamC, listaM, tamM);
			validarAlfaNumerico("\nIngrese la patente del vehiculo\n", "\nError. Reingrese la patente del vehiculo.\n",auxLista.patente, 7);
			while((!validarPatente(listaA,tamA, auxLista.patente))){
			validarAlfaNumerico("\nError. Reingrese la patente del vehiculo.\n", "\nError. Reingrese la patente del vehiculo.\n",auxLista.patente, 7);
			}

			listarServicios(listaS, tamS);
			validarInt("\nIngrese el id del servicio\n", "\nError. Reingrese el id del servicio.\n", &auxLista.idServicio, 20000,20004);


			validarFecha(&auxLista.fecha.dia, &auxLista.fecha.mes, &auxLista.fecha.anio);

			auxLista.id = *idTrabajo;
			listaT[indice]=auxLista;
			listaT[indice].isEmpty = 0;
			todoOk = 1;
	}else{
		printf("\nNo hay espacio en la lista \n");
	}
}
return todoOk;
}

int initTrabajo(eTrabajo* listaT, int tamT){
		int todoOk = 0;

		if (listaT != NULL && tamT > 0)
		{
			for (int i = 0; i < tamT; i++)
			{
				listaT[i].isEmpty = 1;
			}
			todoOk = 1;
		}
		return todoOk;
	}

int isEmptyTrabajo(eTrabajo* listaT, int tamT, int *pIndice)
{
	int todoOk = 0;
	if (listaT != NULL && tamT > 0 && pIndice != NULL)
	{

		*pIndice = -1;
		for (int i = 0; i < tamT; i++)
		{
			if (listaT[i].isEmpty)
			{
				*pIndice= i;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}


int mostrarTrabajo(eTrabajo* listaT, eServicio* listaS, int tamS){
int todoOk = 0;
char servicio[20];
if(listaT != NULL){

	cargarDescripcionServicio(listaS, tamS, listaT->idServicio, servicio);
printf("%04d   %6s     %9s   %02d/%02d/%04d\n", listaT->id, listaT->patente, servicio, listaT->fecha.dia, listaT->fecha.mes, listaT->fecha.anio);
}
return todoOk;

}




int listarTrabajos(eTrabajo* listaT, int tamT, eServicio* listaS, int tamS){
	int todoOk = 0;
	int flag = 0;
		if (listaT != NULL && tamT > 0)
		{
			printf(" \n\n         ***   Listado de Trabajos   ***\n\n");
			printf(" ID    Patente      Servicio      Fecha  \n");
			printf("-----------------------------------------\n");
			for (int i = 0; i < tamT; i++)
			{
				if(!listaT[i].isEmpty)
				{
					mostrarTrabajo(listaT + i, listaS, tamS);
					flag = 1;
					todoOk = 1;
				}
			}

			if (!flag)
			{
			printf("\n** No hay trabajos en el sistema.** ");
			}
		}
	return todoOk;
	}

