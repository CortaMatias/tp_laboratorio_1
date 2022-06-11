/*
 * informes.h
 *
 *  Created on: 20 may. 2022
 *      Author: Matias
 */

#include "trabajo.h"

#ifndef INFORMES_H_
#define INFORMES_H_



#endif /* INFORMES_H_ */

int informes(eTrabajo *lista, int tamTra, eMascota *listaM, int tamM, eServicio *listaS, int tamS, int *idTrabajo, eColor *listaC, int tamC,
		   eTipo *listaT, int tamT);

int menuInformes();

int mostrarMascotaColorSeleccionado(eMascota *lista, int tamM, eColor *listaC,
		int tamC, eTipo *listaT, int tamT);

int promedioVacunados(eMascota *lista, int tamM);


int mostrarMascotaJoven(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC);

int mostrarMascotaPorTipo(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC);

int cantidadPorColorYTipo(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC);

int colorDeMascotaTop(eMascota *lista, int tamM, eColor *listaC, int tamC);

int mostrarServiciosMascota(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);

int mostrarPrecioPorMascota(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);

int mostrarMascotasPorServicio(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);

int servicioPorFecha(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);


