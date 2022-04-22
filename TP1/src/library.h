/*
 * library.h
 *
 *  Created on: 11 abr. 2022
 *      Author: Matias
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_
/**
 * @brief muestra el menu de opciones y se actualiza cuando el usuario ingresa los datos dentro de cada opcion
 * 
 * @param kilometros flotante que ingresa el usuario en referencia a los kilometros que va a viajar
 * @param pFlagKilometros bandera que indica si el usuario ya ingreso los kilometros o no 1=si 0=no
 * @param pFlagPrecios bandera que indica si el usuario ya ingreso el valor de los precios de los vuelos 1=si 0=no
 * @param pFlagCostos bandera que indica si el usuario ya ingreso a la opcion de calcular los costos 1=si 0=no
 * @param pFlagInformar bandera que indica si el usuario ya ingreso a la opcion de informarDatos
 * @param aerolineas flotante que indica el precio de Aerolineas Argentinas
 * @param latam flotante que determina el precio de Aerolinea Latam
 * @param debitoLatam flotante donde se guarda el calculo de las tarjetas de debito de Latam
 * @param creditoLatam flotante donde se guarda el calculo de las tarjetas de credito Latam
 * @param bitcoinLatam flotante donde se guarda el calculo en bitcoins de Latam 
 * @param unitarioLatam flotante donde se guarda el calculo del precio unitario de Latam
 * @param debitoAerolineas flotante donde se guarda el calculo del precio final de las tarjetas de debito de Aerolineas Argentinas
 * @param creditoAerolineas flotante donde se guarda el calculo del precio final de las tarjetas credito de Aerolineas Argentinas
 * @param bitcoinAerolienas flotante donde se guarda el calculo en bitcoins de Aerolineas Argentinas
 * @param unitarioAerolineas flotante donde se guarda el calculo del precio unitario de Aerolineas Argentinas
 * @param diferencia flotante donde se guarda la diferencia entre los precios de una Aerolinea y la otra
 * @return int entero que retorna la opcion ingresada por el usuario
 */
int menu(float kilometros, int *pFlagKilometros, int *pFlagPrecios,
		int *pFlagCostos, int *pFlagInformar, float aerolineas, float latam,
		float debitoLatam, float creditoLatam, float bitcoinLatam,
		float unitarioLatam, float debitoAerolineas, float creditoAerolineas,
		float bitcoinAerolienas, float unitarioAerolineas, float diferencia);

/**
 * @brief pide al usuario que ingrese los kilometros que va a viajar con todas las respectivas validaciones. 
 * 
 * @param kilometros flotante que guarda el dato ingresado por el usuario en referencia a los kilometros a viajar
 * @param pFlagKilometros bandera que determina si el usuario ingreso o no el dato de los kilometros
 * @return int entero que retorna si hubo algun error o no 0=Error 1=todoOk
 */
int pedirKilometros(float *kilometros, int *pFlagKilometros);

/**
 * @brief pide al usuario que ingrese los precios de los vuelos con sus respectivas validaciones
 * 
 * @param pFlagPrecio bandera que determina si se ingreso el precio de los vuelos o no 1=si 0=no
 * @param aerolineas flotante que guarda el valor ingresado del vuelo en referencia a Latam
 * @param latam flotante que guar el valor ingresado del vuelo en referencia a Aerolineas Argentinas
 * @return int entero que retorna si hubo algun error o no 0=Error 1=todoOk
 */
int pedirPrecio(int *pFlagPrecio, float *aerolineas, float *latam);

/**
 * @brief calcula los datos ingresados por el usuario y avisa si esto ocurrio a traves de sus respectivas validaciones
 * 
 * @param kilometros flotante que guarda el dato ingresado por el usuario en referencia a los kilometros a viajar
 * @param precio flotante que guarda el valor del precio del vuelo de la aerolinea correspondiente
 * @param credito flotante que guarda el valor final de la tarjeta de credito correspondiente
 * @param debito  flotante que guarda el valor final de la tarjeta de debito correspondiente 
 * @param bitcoin  flotante que guarda el valor final del vuelo expresado en bitcoin de la aerolinea correspondiente
 * @param unitario  flotante que guarda el valor unitario de la aerolinea correspondiente
 * @param pFlagDiferencia bandera que determina si ya calculamos la diferencia o no 0=no 1=si
 * @param diferencia flotante que guarda el valor final de la diferencia entre los precios de las aerolineas
 * @param latam flotante que guarda el valor del precio de los vuelos de Latam 
 * @param aerolineas flotante que guarda el valor del precio de los vuelos de Aerolineas Argentinas
 * @return int entero que retorna si hubo algun error o no 0=Error 1=todoOk
 */
int calcularCostos(float kilometros, float precio, float *credito,
		float *debito, float *bitcoin, float *unitario, int *pFlagDiferencia,
		float *diferencia, float *latam, float *aerolineas);

/**
 * @brief informa al usuario los precios calculados sobre los datos ingresados 
 * 
 * @param debito flotante que guarda el valor final del vuelo financiado por tarjeta de debito de la aerolinea correspondiente 
 * @param credito flotante que guarda el valor final del vuelo financiado por tarjeta de credito de la aerolinea correspondiente 
 * @param bitcoin flotante que guarda el valor final del vuelo expresado en bitcoin de la aerolinea correspondiente 
 * @param unitario flotante que guarda el valor unitario final de la aerolinea correspondiente 
 * @param diferencia flotante que guarda el valor de la diferencia entre una aerolinea y la otra 
 * @param pFlagNombre bandera que determina si ya se informo los datos de Latam 1=no 0=si
 * @return int 
 */
int informarDatos(float debito, float credito, float bitcoin, float unitario,
		float diferencia, int *pFlagNombre);
/**
 * @brief pausa la consola
 * 
 */
void pausarConsola();
#endif /* LIBRARY_H_ */
