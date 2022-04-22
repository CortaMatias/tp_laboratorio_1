/*
 ============================================================================
 Name        : TpNew.c
 Author      : Matias Corta
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "library.h"

int main(void) {
	setbuf(stdout, NULL);
	char salir = 'n';
	float kilometros;
	float precioAerolineas;
	float precioLatam;
	int flagDiferencia = 0;
	int flagPrecios = 0;
	int flagCostos = 0;
	int flagKilometros = 0;
	int flagInformar = 0;
	int flagNombre = 1;
	float creditoLatam;
	float debitoLatam;
	float bitcoinLatam;
	float unitarioLatam;
	float creditoAerolineas;
	float debitoAerolineas;
	float bitcoinAerolineas;
	float unitarioAerolineas;
	float diferencia;

	do {
		switch (menu(kilometros, &flagKilometros, &flagPrecios, &flagCostos,
				&flagInformar, precioAerolineas, precioLatam, debitoLatam,
				creditoLatam, bitcoinLatam, unitarioLatam, debitoAerolineas,
				creditoAerolineas, bitcoinAerolineas, unitarioAerolineas,
				diferencia)) {
		case 1:
			//si el usuario ya ingreso a la opcion 4 y reingresa la opcion 1 se restablecen las banderas
			if (flagInformar) {
				flagKilometros = 0;
				flagPrecios = 0;
				flagCostos = 0;
				flagInformar = 0;
				// si el usuario ya realizo los calculos pero desea reingresar los datos se restablecen las banderas
			} else if (flagCostos) {
				flagCostos = 0;
			}
			if (pedirKilometros(&kilometros, &flagKilometros) == 0) {
				printf("**Error al cargar los kilometros **");
			} else {
				flagKilometros = 1;
			}
			pausarConsola();
			break;

		case 2:
			if (flagInformar) {
				flagKilometros = 0;
				flagPrecios = 0;
				flagCostos = 0;
				flagInformar = 0;
			} else if (flagCostos) {
				flagCostos = 0;
			}
			if (flagKilometros) {
				if (pedirPrecio(&flagPrecios, &precioAerolineas, &precioLatam)
						== 0) {
					printf(" ** Error al cargar los precios ** ");
				} else {
					flagPrecios = 1;
					flagDiferencia = 1;
				}
			} else {
				printf(
						"\n ** No puede ingresar a esta opcion sin antes ingresar los kilometros a viajar **");
			}
			pausarConsola();
			break;

		case 3:
			if (flagPrecios) {
				if (calcularCostos(kilometros, precioLatam, &creditoLatam,
						&debitoLatam, &bitcoinLatam, &unitarioLatam,
						&flagDiferencia, &diferencia, &precioLatam,
						&precioAerolineas) == 0) {
					printf("Error al calcular los costos de Latam");
				} else if (calcularCostos(kilometros, precioAerolineas,
						&creditoAerolineas, &debitoAerolineas,
						&bitcoinAerolineas, &unitarioAerolineas,
						&flagDiferencia, &diferencia, &precioLatam,
						&precioAerolineas) == 0) {
					printf(
							"Error al calcular los costos de Aerolineas Argentinas");
				} else {
					printf(
							" ** Los costos fueron calculados continue en la siguiente opcion **");
					flagCostos = 1;
				}
			} else {
				printf(
						"\n ** No puede calcular los costos si todavia no ingreso los precios ** ");
			}
			pausarConsola();
			break;

		case 4:
			if (flagCostos) {
				if (informarDatos(debitoLatam, creditoLatam, bitcoinLatam,
						unitarioLatam, diferencia, &flagNombre) == 0) {
					printf("Error al informar los datos de Latam");
				} else if (informarDatos(debitoAerolineas, creditoAerolineas,
						bitcoinAerolineas, unitarioAerolineas, diferencia,
						&flagNombre) == 0) {
					printf(
							"Error al informar los datos de Aerolineas Argentinas ");
				} else {
					flagInformar = 1;
				}

			} else {
				printf(
						"\n ** No puede informar los resultados sino realizo los pasos previos ** \n");
			}
			pausarConsola();
			break;

		case 5:
			flagDiferencia = 1;
			if (calcularCostos(kilometros = 7090, precioLatam = 159339,
					&creditoLatam, &debitoLatam, &bitcoinLatam, &unitarioLatam,
					&flagDiferencia, &diferencia, &precioLatam,
					&precioAerolineas) == 0) {
				printf("Error al calcular los costos de Latam");
			} else if (calcularCostos(kilometros = 7090, precioAerolineas =
					162965, &creditoAerolineas, &debitoAerolineas,
					&bitcoinAerolineas, &unitarioAerolineas, &flagDiferencia,
					&diferencia, &precioLatam, &precioAerolineas) == 0) {
				printf("Error al calcular los costos de Aerolineas Argentinas");
			} else {
				printf(" ** Los costos fueron calculados **");
			}
			pausarConsola();
			if (informarDatos(debitoLatam, creditoLatam, bitcoinLatam,
					unitarioLatam, diferencia, &flagNombre) == 0) {
				printf("Error al informar los datos de Latam");
			} else if (informarDatos(debitoAerolineas, creditoAerolineas,
					bitcoinAerolineas, unitarioAerolineas, diferencia,
					&flagNombre) == 0) {
				printf("Error al informar los datos de Aerolineas Argentinas ");
			}
			pausarConsola();
			break;

		case 6:
			printf(
					" ** Esta seguro que desea salir del programa? (si / no) ** ");
			fflush(stdin);
			scanf("%c", &salir);
			break;

		default:
			printf(" ** Opcion invalida!, ingrese un numero del menu. **\n");
			break;

		}
	} while (salir == 'n');
	printf("Salida con exito, hasta luego!");

	return EXIT_SUCCESS;
}
