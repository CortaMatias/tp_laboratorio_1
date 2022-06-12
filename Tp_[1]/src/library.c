/*
 * library.c
 *
 *  Created on: 11 abr. 2022
 *      Author: Matias
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int menu(float kilometros, int *pFlagKilometros, int *pFlagPrecios,
		int *pFlagCostos, int *pFlagInformar, float aerolineas, float latam,
		float debitoLatam, float creditoLatam, float bitcoinLatam,
		float unitarioLatam, float debitoAerolineas, float creditoAerolineas,
		float bitcoinAerolineas, float unitarioAerolineas, float diferencia) {
	int opcion;
	printf(" \n\n *** Menu de Opciones ***\n");

	//1
	if (*pFlagKilometros == 0) {
		printf(" 1) Ingresar la cantidad de kilometros: Sin datos \n");

	} else {
		printf(" 1) Ingresar la cantidad de kilometros: %.2f", kilometros);
	}

	//2
	if (*pFlagPrecios == 0) {
		printf(" 2)Ingresar el precio de los vuelos: Sin datos \n");

	} else {
		printf(
				"\n 2) Ingresar el precio de los vuelos: (Aerolineas = %.2f, Latam = %.2f) \n",
				aerolineas, latam);
	}

	//3
	if (*pFlagCostos == 0) {
		printf(
				" 3) Calcular todos los costos:\n   a) Tarjeta de débito (descuento 10%%)\n   "
						"b) Tarjeta de crédito (interés 25%%)\n   c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos) \n  "
						" d) Mostrar precio por km (precio unitario)\n "
						"  e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas) \n");
	} else {
		printf(
				" 3) Calcular todos los costos\n a) Tarjeta de débito (descuento 10%%): CALCULADO\n b) Tarjeta de crédito (interés 25%%): CALCULADO \n"
						" c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos): CALCULADO \n"
						" d) Mostrar precio por km (precio unitario): CALCULADO \n e) Mostrar diferencia de precio ingresada (Latam - Aerolíneas): CALCULADO \n");
	}

//4
	if (*pFlagInformar == 0) {
		printf(
				"\n 4) Informar Resultados:\n\nLatam:\n  a) Precio con tarjeta de débito: Sin datos.\n "
						" b) Precio con tarjeta de crédito: Sin datos.\n "
						" c) Precio pagando con bitcoin : Sin datos.\n"
						"  d) Precio unitario: Sin datos.\n\nAerolíneas:\n "
						" a) Preciocon tarjeta de débito: Sin datos.\n  b)"
						" Precio con tarjeta de crédito: Sin datos.\n"
						"  c) Precio pagando con bitcoin : Sin datos.\n "
						" d) Precio unitario: Sin datos."
						"\n  La diferencia de precio es : Sin datos. \n");
	} else {
		printf(
				"\n4. Informar Resultados\nLatam:\na) Precio con tarjeta de débito: %.2f \nb) Precio con tarjeta de crédito: %.2f \nc) Precio pagando con bitcoin : %.2f \nd) Precio unitario: %.2f \n"
						"\nAerolíneas:\na) Precio con tarjeta de débito: %.2f \nb) Precio con tarjeta de crédito: %.2f \nc) Precio pagando con bitcoin : %.2f \nd) Precio unitario: %.2f \n"
						"La diferencia de precio es : %.2f", debitoLatam,
				creditoLatam, bitcoinLatam, unitarioLatam, debitoAerolineas,
				creditoAerolineas, bitcoinAerolineas, unitarioAerolineas,
				diferencia);
	}
//5
	printf("\n5. Carga forzada de datos");
//6
	printf("\n6. Salir del menu \n");
	scanf("%d", &opcion);
	return opcion;
}

//OPCION 1  PEDIR KILOMETROS;
int pedirKilometros(float *kilometros, int *pFlagKilometros) {
	int todoOk = 0;
	if (kilometros != NULL && pFlagKilometros != NULL) {
		printf(" ** Ingrese la cantidad de kilometros a viajar ** : \n");
		scanf("%f", kilometros);

		while (*kilometros <= 0) {
			printf(
					"\n ** Error. Ingrese una cantidad valida de kilometros(mayor a cero) ** : ");
			scanf("%f", kilometros);
		}
		*pFlagKilometros = 1;
		printf("** La cantidad de kilometros a viajar es: %.2f **\n",
				*kilometros);
		todoOk = 1;
	} else {
		return todoOk;
	}
	return todoOk;
}

//OPCION 2  PEDIR PRECIO 
int pedirPrecio(int *pFlagPrecio, float *aerolineas, float *latam) {
	int todoOk = 0;

	if (pFlagPrecio != NULL && aerolineas != NULL && latam != NULL) {
		printf(" **Ingrese el precio del vuelo de Aerolineas**: ");
		scanf("%f", aerolineas);
		printf("**Ingrese el precio del vuelo de Latam**: ");
		scanf("%f", latam);

		while (*aerolineas <= 0 || *latam <= 0) {
			printf("\nError. Ingrese un precio valido (mayor a cero)");
			printf("\nIngrese el precio del vuelo de Aerolineas: ");
			scanf("%f", aerolineas);
			printf("\nIngrese el precio del vuelo de Latam: ");
			scanf("%f", latam);
		}
		*pFlagPrecio = 1;
		todoOk = 1;
		printf("\n** El precio del vuelo de aerolineas es: %.2f **",
				*aerolineas);
		printf("\n** El precio del vuelo de Latam es: %.2f **", *latam);
	} else {
		return todoOk;
	}
	return todoOk;
}

//OPCION 3 calcular costos;

int calcularCostos(float kilometros, float precio, float *credito,
		float *debito, float *bitcoin, float *unitario, int *pFlagDiferencia,
		float *diferencia, float *latam, float *aerolineas) {

	int todoOk = 0;
	if (credito != NULL && debito != NULL && bitcoin != NULL && unitario != NULL
			&& pFlagDiferencia != NULL && diferencia != NULL && latam != NULL
			&& aerolineas != NULL) {

		todoOk = 1;
		*credito = (float) precio * 1.25;
		*debito = (float) precio * 0.9;
		*bitcoin = (float) precio / 4606954.55;
		*unitario = (float) precio / kilometros;
		if (*pFlagDiferencia) {
			*diferencia = *latam - *aerolineas;
		} else {
			return todoOk;
		}
	}
	return todoOk;
}

//OPCION 4 informar datos;
int informarDatos(float debito, float credito, float bitcoin, float unitario,
		float diferencia, int *pFlagNombre) {
	int todoOk = 0;
	if (pFlagNombre != NULL) {
		if (*pFlagNombre) {
			printf("\nAerolinea LATAM\n");
			printf("\na) Precio con tarjeta de débito: %.2f", debito);
			printf("\nb) Precio con tarjeta de crédito: %.2f", credito);
			printf("\nc) Precio pagando con bitcoin: %.10f", bitcoin);
			printf("\nd) Precio unitario: %.2f", unitario);
			*pFlagNombre = 0;
			todoOk = 1;
		} else {
			printf("\n\nAerolineas Argentinas\n");
			printf("\na) Precio con tarjeta de débito: %.2f", debito);
			printf("\nb) Precio con tarjeta de crédito: %.2f", credito);
			printf("\nc) Precio pagando con bitcoin: %.10f", bitcoin);
			printf("\nd) Precio unitario: %.2f", unitario);
			printf("\n\nLa diferencia de precio es: %.2f", diferencia);
			*pFlagNombre = 1;
			todoOk = 1;
		}
	} else {
		return todoOk;
	}
	return todoOk;
}

//Pausar consola
void pausarConsola() {
	printf("\n\n** Pulse Enter para continuar **\n");
	fflush(stdin);
	getchar();
}
