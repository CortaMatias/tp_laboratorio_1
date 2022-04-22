/*
 ============================================================================
 Name        : Tp1.c
 Author      : Matias Corta 1A
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "library.h"
#include <conio.h>

int main(void) {
	setbuf(stdout, NULL);

	char salir = 'n';
	float kilometros;
	int flagKilometros = 0;
	float precioAerolineas;
	float precioLatam;
	int flagPrecios = 0;
	int flagCostos = 0;
	float tarjetaCreditoLatam;
	float tarjetaDebitoLatam;
	float bitcoinLatam;
	float precioUnitarioKmLatam;
	float tarjetaCreditoAerolineas;
	float tarjetaDebitoAerolineas;
	float bitcoinAerolineas;
	float precioUnitarioKmAerolineas;
	float diferenciaPrecio;

	do {
		switch (menu()) {
		case 1:
			pedirKilometros(&kilometros, &flagKilometros);
			pausarConsola();

			break;

		case 2:
			if (flagKilometros) {
				pedirPrecio(&flagPrecios, &precioLatam, &precioAerolineas);
			} else {
				printf(
						"\nNo puede ingresar a esta opcion sin antes ingresar los kilometros a viajar");
			}
			pausarConsola();
			break;

		case 3:
			if (flagPrecios) {
				//LATAM
				calcularCostos(kilometros, precioAerolineas,&tarjetaCreditoLatam, &tarjetaDebitoLatam,
						&bitcoinLatam, &precioUnitarioKmLatam, &flagCostos);


				calcularCostos (kilometros, precioAerolineas,
						&flagCostos, &tarjetaCreditoAerolineas,
						&tarjetaDebitoAerolineas, &bitcoinAerolineas,
						&precioUnitarioKmAerolineas);
			/*	calcularCostosLatam(kilometros, precioAerolineas, precioLatam,
						&tarjetaCreditoLatam, &tarjetaDebitoLatam,
						&bitcoinLatam, &precioUnitarioKmLatam,
						&diferenciaPrecio);


				calcularCostosAerolineas(kilometros, precioAerolineas,
						&flagCostos, &tarjetaCreditoAerolineas,
						&tarjetaDebitoAerolineas, &bitcoinAerolineas,
						&precioUnitarioKmAerolineas);*/
				printf(
						"Los costos fueron calculados continue en la siguiente opcion");
			} else {
				printf(
						"\nNo puede calcular los costos si todavia no ingreso los precios. ");
			}
			pausarConsola();
			break;

		case 4:
			if (flagCostos) {
				informarDatosLatam(tarjetaCreditoLatam, tarjetaDebitoLatam,
						bitcoinLatam, precioUnitarioKmLatam);

				pausarConsola();

				informarDatosAerolineas(tarjetaCreditoAerolineas,
						tarjetaDebitoAerolineas, bitcoinAerolineas,
						precioUnitarioKmAerolineas, diferenciaPrecio);
				pausarConsola();
			} else {
				printf(
						"No puede informar los resultados sino realizo los pasos previos.");
			}

			break;

		case 5:
			calcularCostosLatam(kilometros = 7090, precioAerolineas = 162965,
					precioLatam = 159339, &tarjetaCreditoLatam,
					&tarjetaDebitoLatam, &bitcoinLatam, &precioUnitarioKmLatam,
					&diferenciaPrecio);

			calcularCostosAerolineas(kilometros = 7090, precioAerolineas =
					162965, &flagCostos, &tarjetaCreditoAerolineas,
					&tarjetaDebitoAerolineas, &bitcoinAerolineas,
					&precioUnitarioKmAerolineas);
			printf("Los costos fueron calculados, presione enter para verlos.");
			pausarConsola();

			informarDatosLatam(tarjetaCreditoLatam, tarjetaDebitoLatam,
					bitcoinLatam, precioUnitarioKmLatam);

			pausarConsola();
			informarDatosAerolineas(tarjetaCreditoAerolineas,
					tarjetaDebitoAerolineas, bitcoinAerolineas,
					precioUnitarioKmAerolineas, diferenciaPrecio);
			pausarConsola();
			break;

		case 6:
			printf("Esta seguro que desea salir del programa? ('s' =  SI / 'n' = NO)");
			fflush(stdin);
			scanf ("%c", &salir);
			break;

		default:
			printf("Opcion invalida!, ingrese un numero del menu.\n");
			break;
		}

		system("cls");
	} while (salir != 's');

	return EXIT_SUCCESS;
}
