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

//Ingresas un tipo de mascota y te muestra las mascotas de ese tipo y cantidad!!
int mostrarMascotaTipoSeleccionado(eMascota *lista, int tamM, eTipo *listaT,
		int tamT, eColor *listaC, int tamC);
//Ingresas un color y te muestra las mascotas de ese color y cantidad!!!
int mostrarMascotaColorSeleccionado(eMascota *lista, int tamM, eColor *listaC,
		int tamC, eTipo *listaT, int tamT);
//Muestra la mascota mas vieja o las
int mostrarMascotaVieja(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC);

int mostrarMascotaPorTipo(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC);
//Ingresas el id de una mascota y te muestra los servicios que se le hicieron a esa mascota
int mostrarServiciosMascota(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);
//Ingresas el id de una mascota y te muestra el importe gastado en servicios
int mostrarPrecioPorMascota(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);
//Ingreas el id de un servicio y muestra el importe total recaudado por ese servicio
int mostrarPrecioPorServicio(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);
//Te muestra lo recaudado por cada servicio y el total de todo lo recaudado
//totalPrecioServicios(listaM, TAMM, listaT, TAMTIPO, listaC,TAMC, listaTra, TAMTRABAJO, listaS, TAMS);
int totalPrecioServicios(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);
//Ingresas el id de un servicio y te muestra el nombre de las mascotas que se realizaron ese servicio
int mostrarMascotasPorServicio(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);
int mostrarNoVacunados(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);
int mostrarVacunados(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);



//Ordena las mascotas por nombres 0=ascendeten 1 = descendiente
int ordenarPorNombreMascota(eMascota *lista, int tam, int criterio);
//Ordena las mascotas por color 0=ascendeten 1 = descendiente
int ordenarPorColor(eMascota *lista, int tam, int criterio);
//Ordena las mascotas por edad 0=ascendeten 1 = descendiente
int ordenarMascotaPorEdad(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, int criterio);
//Ordena los trabajos por servicio 0=ascendeten 1 = descendiente
int ordenarTrabajosPorServicio(eTrabajo *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, int criterio);


//Ingresas un tipo de mascota y te muestra la cantidad de mascotas de ese tipo que hay
int  cantidadPorTipo(eMascota *lista, int tam, eTipo* listaT, int tamT);
// ingresas un color y te muestra todas las mascotas de ese color
int cantidadPorColor(eMascota* lista, int tamM, eColor* listaC, int tamC);
//Ingresas un tipo y un color y temuestra todas las mascotas de ese tipo y color
int cantidadPorColorYTipo(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC);
//Ingresas el id de un servicio y te muestra la cantidad de mascotas que se realizaron ese servicio
int cantidadMascotasPorServicio(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);



//Muestra cual es el color mas frecuente en las mascotas
int colorDeMascotaTop(eMascota *lista, int tamM, eColor *listaC, int tamC);
// muestra cual es el tipo de mascota mas frecuente
int tipoMascotaTop(eMascota *lista, int tamM, eTipo *listaT, int tamT);
//muestra cual es el servicio mas elegido
int servicioMascotaTop(eTrabajo *lista, int tam, eServicio *listaS, int tamS);



//Ingresas una fecha y te muestra la cantidad de servicios que se realizaron y su descripcion
int servicioPorFecha(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);
//ingresa un servicio y le mostramos el promedio de eleccion de ese servicio
int promedioServicio(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);
//Ingresas un tipo de mascota y te dice el promedio
int promedioTipoMascotas(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);
//Ingresas un color y te dice el promedio
int promedioColorMascotas(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS);




