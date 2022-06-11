/*
 * informes.c
 *
 *  Created on: 20 may. 2022
 *      Author: Matias
 */
#include "informes.h"

int informes(eTrabajo *lista, int tamTra, eMascota *listaM, int tamM, eServicio *listaS, int tamS, int *idTrabajo, eColor *listaC, int tamC,
		   eTipo *listaT, int tamT){
int todoOk;
char salir = 'n';

if (lista != NULL && tamTra > 0 && listaS != NULL && tamS > 0 && listaM != NULL && tamM > 0 && idTrabajo != NULL && listaC != NULL && tamC > 0 && listaT != NULL && tamT > 0)
	{
		do{switch(menuInformes()){

		case 1:

			break;
		case 2:

					break;
		case 3:

					break;
		case 4:

					break;
		case 5:

					break;
		case 6:

					break;
		case 7:

					break;
		case 8:

					break;
		case 9:

					break;
		case 10:
			salir = 's';
					break;
		}


		}while(salir == 'n');
		todoOk = 1;
	}

return todoOk;
}

int menuInformes(){
int opcion;

printf("1)");
printf("2)");
printf("3)");
printf("4)");
printf("5)");
printf("6)");
printf("7)");
printf("8)");
printf("9)");

validarInt("Ingrese la opcion que desea elegir", "Error ingrese una opcion valida", &opcion, 1, 15);

return opcion;
}

int mostrarMascotaColorSeleccionado(eMascota *lista, int tamM, eColor *listaC,
		int tamC, eTipo *listaT, int tamT) {
	int todoOk = 0;
	int idColor;
	int contador = 0;

	if (lista != NULL && tamM > 0 && listaC != NULL && tamC > 0
			&& listaT != NULL && tamT > 0) {

		listarColor(listaC, tamC);
		validarInt("\nIngrese el id del color que desea buscar: \n",
				"\nError. ingrese un id valido. \n", &idColor, 5000, 5004);

		system("cls");
		printf(" \n\n       ***   Listado de Mascotas  ***\n\n");
		printf("%-4s  %-15s %-8s %-8s %-3s  %-7s  %-15s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNAS", "DUEÑO");
		printf("-------------------------------------------------------------------------------------\n");
		for (int i = 0; i < tamM; i++) {

			if (lista[i].idColor == idColor && !lista[i].isEmpty) {
				mostrarMascota(lista + i, listaC, tamC, listaT, tamT);
				contador++;
			}
		}
		printf("\nLa cantidad total de mascotas de este color es:  %d\n", contador);
		todoOk = 1;
	}
	return todoOk;
}

int mostrarMascotaTipoSeleccionado(eMascota *lista, int tamM, eTipo *listaT,
		int tamT, eColor *listaC, int tamC) {
	int todoOk = 0;
	int idTipo;
	int contador = 0;

	if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
			&& listaC != NULL && tamC > 0) {
		listarTipo(listaT, tamT);
		validarInt("\nIngrese el id del tipo de mascota que desea buscar: \n",
				"Error. Ingrese un id valido", &idTipo, 1000, 1004);

		system("cls");
			printf(" \n\n       ***   Listado de Mascotas  ***\n\n");
			printf("%-4s  %-15s %-8s %-8s %-3s  %-7s  %-15s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNAS", "DUEÑO");
			printf("-------------------------------------------------------------------------------------\n");
		for (int i = 0; i < tamM; i++) {

			if (lista[i].idTipo == idTipo && !lista[i].isEmpty) {
				mostrarMascota(lista + i, listaC, tamC, listaT, tamT);
				contador++;
			}
		}
		printf("\nLa cantidad total de mascotas de este tipo es: %d\n", contador);
		todoOk = 1;
	}

	return todoOk;
}

int mostrarMascotaVieja(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC) {
	int todoOk = 0;
	int edadMinimo;
	int flagMaximo = 0;

	if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
			&& listaC != NULL && tamC > 0) {

		for (int i = 0; i < tamM - 1; i++) {
			if ((edadMinimo >= lista[i].edad || !flagMaximo)
					&& !lista[i].isEmpty) {
				edadMinimo = lista[i].edad;
				flagMaximo = 1;
			}
		}
		if (!flagMaximo) {
			printf("\nNo hay mascotas en el sistema.\n");
		} else {
			system("cls");
				printf(" \n\n       ***   Listado de Mascotas  ***\n\n");
				printf("%-4s  %-20s %-8s %-8s %-3s  %-1s\n", "ID", "NOMBRE", "TIPO",
						"COLOR", "EDAD", "VACUNACION");
				printf("---------------------------------------------------------\n");

			for (int j = 0; j < tamM; j++) {
				if (!lista[j].isEmpty && edadMinimo == lista[j].edad) {
					mostrarMascota(lista + j, listaC, tamC, listaT, tamT);

				}
			}

		}

		printf("\n\n");
		todoOk = 1;
	}
	return todoOk;
}


int mostrarMascotaPorTipo(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC) {
	int todoOk = 0;

	if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
			&& listaC != NULL && tamC > 0) {

		system("cls");
			printf(" \n\n       ***   Listado de Aves  ***\n\n");
			printf("%-4s  %-15s %-8s %-8s %-3s  %-7s  %-15s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNAS", "DUEÑO");
			printf("-------------------------------------------------------------------------------------\n");
		printf("---------------------------------------------------------\n");
		for (int i = 0; i < tamM - 1; i++) {

			if (lista[i].idTipo == 1000) {
				mostrarMascota(lista + i, listaC, tamC, listaT, tamT);
			}
		}

		system("cls");
			printf(" \n\n       ***   Listado de Perros  ***\n\n");
			printf("%-4s  %-15s %-8s %-8s %-3s  %-7s  %-15s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNAS", "DUEÑO");
			printf("-------------------------------------------------------------------------------------\n");
		printf("---------------------------------------------------------\n");
		for (int i = 0; i < tamM - 1; i++) {
			if (lista[i].idTipo == 1001) {
				mostrarMascota(lista + i, listaC, tamC, listaT, tamT);
			}
		}

		system("cls");
			printf(" \n\n       ***   Listado de Roedores ***\n\n");
			printf("%-4s  %-15s %-8s %-8s %-3s  %-7s  %-15s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNAS", "DUEÑO");
			printf("-------------------------------------------------------------------------------------\n");
		printf("---------------------------------------------------------\n");
		for (int i = 0; i < tamM - 1; i++) {

			if (lista[i].idTipo == 1002) {
				mostrarMascota(lista + i, listaC, tamC, listaT, tamT);
			}
		}

		system("cls");
			printf(" \n\n       ***   Listado de Gatos ***\n\n");
			printf("%-4s  %-15s %-8s %-8s %-3s  %-7s  %-15s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNAS", "DUEÑO");
			printf("-------------------------------------------------------------------------------------\n");
		printf("---------------------------------------------------------\n");
		for (int i = 0; i < tamM - 1; i++) {

			if (lista[i].idTipo == 1003) {
				mostrarMascota(lista + i, listaC, tamC, listaT, tamT);
			}
		}

		system("cls");
			printf(" \n\n       ***   Listado de Peces  ***\n\n");
			printf("%-4s  %-15s %-8s %-8s %-3s  %-7s  %-15s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNAS", "DUEÑO");
			printf("-------------------------------------------------------------------------------------\n");
		printf("---------------------------------------------------------\n");
		for (int i = 0; i < tamM - 1; i++) {

			if (lista[i].idTipo == 1004) {
				mostrarMascota(lista + i, listaC, tamC, listaT, tamT);
			}

		}
		printf("\n\n");
		todoOk = 1;
	}

	return todoOk;
}


int ordenarPorColor(eMascota *lista, int tam, int criterio) {
	int todoOk = 0;
	eMascota auxMascota;

	if (lista != NULL && tam > 0) {

		for (int i = 0; i < tam - 1; i++) {
			for (int j = i + 1; j < tam; j++) {
				if ((lista[i].idColor > lista[j].idColor && !lista[i].isEmpty
						&& !lista[j].isEmpty && criterio == 0) //ASCENDENTE
						|| (lista[i].idColor < lista[j].idColor
								&& !lista[i].isEmpty && !lista[j].isEmpty
								&& criterio == 1)) { //Descendente

					auxMascota = lista[i];
					lista[i] = lista[j];
					lista[j] = auxMascota;
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}


int ordenarPorNombreMascota(eMascota *lista, int tam, int criterio) {
	int todoOk = 0;
	eMascota auxMascota;

	if (lista != NULL && tam > 0) {

		for (int i = 0; i < tam - 1; i++) {
			for (int j = i + 1; j < tam; j++) {
				if ((strcmp(lista[i].nombre, lista[j].nombre) > 0
						&& !lista[i].isEmpty && !lista[j].isEmpty
						&& criterio == 0) //ASCENDENTE
						|| (strcmp(lista[i].nombre, lista[j].nombre) < 0
								&& !lista[i].isEmpty && !lista[j].isEmpty
								&& criterio == 1)) //Descendente
						{
					auxMascota = lista[i];
					lista[i] = lista[j];
					lista[j] = auxMascota;
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}


// muestra las mascotas que coinciden con le tipo
int cantidadPorTipo(eMascota *lista, int tam, eTipo *listaT, int tamT) {
	int todoOk = 0;
	int contadorAve = 0;
	int contadorPerro = 0;
	int contadorRoedor = 0;
	int contadorGato = 0;
	int contadorPez = 0;
	int tipoU = 0;

	if (lista != NULL && tam > 0 && listaT != NULL && tamT > 0) {

		listarTipo(listaT, tamT);
		validarInt(
				"\nIngrese el id del tipo de mascota que desea conocer la cantidad.\n",
				"\nError. Re ingrese un id valido\n", &tipoU, 1000, 1004);

		for (int i = 0; i < tam; i++) {

			switch (lista[i].idTipo) {
			case 1000:
				contadorAve++;
				break;
			case 1001:
				contadorPerro++;
				break;
			case 1002:
				contadorRoedor++;
				break;
			case 1003:
				contadorGato++;
				break;
			case 1004:
				contadorPez++;
				break;
			}

		}

		switch (tipoU) {
		case 1000:
			printf("\n La cantidad de Aves es: %d\n\n", contadorAve);
			break;
		case 1001:
			printf("\n La cantidad de Perros es: %d\n\n", contadorPerro);
			break;
		case 1002:
			printf("\n La cantidad de Roedores es: %d\n\n", contadorRoedor);
			break;
		case 1003:
			printf("\n La cantidad de Gatos es: %d\n\n", contadorGato);
			break;
		case 1004:
			printf("\n La cantidad de Peces es: %d\n\n", contadorPez);
			break;
		}

		todoOk = 1;
	}

	return todoOk;
}

//muestra las mascotas que coinciden con el color
int cantidadPorColor(eMascota *lista, int tamM, eColor *listaC, int tamC) {
	int todoOk = 0;
	int contadorNegro = 0;
	int contadorBlanco = 0;
	int contadorRojo = 0;
	int contadorGris = 0;
	int contadorAzul = 0;
	int colorU = 0;

	if (lista != NULL && tamM > 0 && listaC != NULL && tamC > 0) {

		listarColor(listaC, tamC);
		validarInt(
				"\nIngrese el id del color de mascota que desea conocer la cantidad\n",
				"\nError. Reingrese un id valido\n", &colorU, 5000, 5004);
		for (int i = 0; i < tamM; i++) {

			switch (lista[i].idColor) {
			case 5000:
				contadorNegro++;
				break;
			case 5001:
				contadorBlanco++;
				break;
			case 5002:
				contadorRojo++;
				break;
			case 5003:
				contadorGris++;
				break;
			case 5004:
				contadorAzul++;
				break;
			}
		}

		switch (colorU) {
		case 5000:
			printf("\n La cantidad de mascotas Negras es:%d\n\n",
					contadorNegro);
			break;
		case 5001:
			printf("\n La cantidad de mascotas Blancas es:%d\n\n",
					contadorBlanco);
			break;
		case 5002:
			printf("\n La cantidad de mascotas Rojas es: %d\n\n",
					contadorRojo);
			break;
		case 5003:
			printf("\n La cantidad de mascotas Grises es: %d\n\n",
					contadorGris);
			break;
		case 5004:
			printf("\n La cantidad de mascotas Azules es: %d\n\n",
					contadorAzul);
			break;
		}
		todoOk = 1;
	}
	return todoOk;
}

//Muetra las mascotas que coinciden en tipo y color
int cantidadPorColorYTipo(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC) {
	int todoOk = 0;
	int tipoU;
	int colorU;
	int contador = 0;
	char color[10];
	char tipo[10];
	if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
			&& listaC != NULL && tamC > 0) {

		listarColor(listaC, tamC);
		validarInt(
				"\nIngrese el id del color de mascota que desea conocer la cantidad\n",
				"\nError. Reingrese un id valido\n", &colorU, 5000, 5004);

		listarTipo(listaT, tamT);
		validarInt(
				"\nIngrese el id del tipo de mascota que desea conocer la cantidad.\n",
				"\nError. Re ingrese un id valido\n", &tipoU, 1000, 1004);

		for (int i = 0; i < tamM ; i++) {
			if (lista[i].idColor == colorU && lista[i].idTipo == tipoU) {
				contador++;
			}
		}
	}
	cargarDescripcionColor(listaC, tamC, colorU, color);
	cargarDescripcionTipo(listaT, tamT, tipoU, tipo);
	printf(
			"\nLa cantidad de mascotas del color: %-10s y tipo: %-10s es: %d\n\n\n",
			color, tipo, contador);

	return todoOk;
}

int colorDeMascotaTop(eMascota *lista, int tamM, eColor *listaC, int tamC) {

	int todoOk = 0;
	char color[15];
	int contadorMaximo = 0;
	int flagColor = 0;
	int contador[5] = {0}; // 0 = NEGRO -- 1 = Blanco -- 2 = Rojo -- 3 = Gris  -- 4 =AZUL


	if (lista != NULL && tamM > 0 && listaC != NULL && tamC > 0) {

		for (int i = 0; i < tamM; i++) {

			switch (lista[i].idColor) {
			case 5000:
				contador[0] = contador[0]+1;
				break;
			case 5001:
				contador[1] = contador[1]+1;
				break;
			case 5002:
				contador[2] = contador[2]+1;
				break;
			case 5003:
				contador[3] = contador[3]+1;
				break;
			case 5004:
				contador[4] = contador[4]+ 1;
				break;
			}
		}

		for (int i = 0; i < 5; i++){

			for (int j =  i+1; j < 5; j++){

				if( !flagColor || contador[i]>contador[j]){
					contadorMaximo = contador[i];
					flagColor = 1;
				}
			}
		}


		printf("\nEl o los colores elegidos %d veces son:  ", contadorMaximo);
		for (int i = 0; i < 5; i++){
		if(contadorMaximo == contador[i]){
			cargarDescripcionColor(listaC, tamC, i+5000, color );
			printf("%s \n", color);
			}
		}
		todoOk = 1;
	}


	return todoOk;
	}

int tipoMascotaTop(eMascota *lista, int tamM, eTipo *listaT, int tamT){
	int todoOk = 0;
		char tipo[15];
		int contadorMaximo = 0;
		int flagTipo = 0;
		int contador[5] = {0};


		if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0) {

			for (int i = 0; i < tamM; i++) {

				switch (lista[i].idTipo) {
				case 1000:
					contador[0] = contador[0]+1;
					break;
				case 1001:
					contador[1] = contador[1]+1;
					break;
				case 1002:
					contador[2] = contador[2]+1;
					break;
				case 1003:
					contador[3] = contador[3]+1;
					break;
				case 1004:
					contador[4] = contador[4]+ 1;
					break;
				}
			}

			for (int i = 0; i < 5; i++){

				for (int j =  i+1; j < 5; j++){

					if( !flagTipo || contador[i]>contador[j]){
						contadorMaximo = contador[i];
						flagTipo = 1;
					}
				}
			}


			printf("\nEl o los tipos elegidos %d veces son:  ", contadorMaximo);
			for (int i = 0; i < 5; i++){
			if(contadorMaximo == contador[i]){
				cargarDescripcionTipo(listaT, tamT, i+1000, tipo );
				printf("%s \n", tipo);
				}
			}
			todoOk = 1;
		}


		return todoOk;
		}

int servicioMascotaTop(eTrabajo *lista, int tam, eServicio *listaS, int tamS){
	int todoOk = 0;
		char servicio[20];
		int contadorMaximo = 0;
		int flagServicio = 0;
		int contador[5] = {0};



		if (lista != NULL && tam > 0 && listaS != NULL && tamS > 0) {

			for (int i = 0; i < tam; i++) {

				switch (lista[i].idServicio) {
				case 20000:
					contador[0] = contador[0]+1;
					break;
				case 20001:
					contador[1] = contador[1]+1;
					break;
				case 20002:
					contador[2] = contador[2]+1;
					break;
				}
			}

			for (int i = 0; i < tamS; i++){

				for (int j =  i+1; j < tamS; j++){

					if( !flagServicio || contador[i]>contador[j]){
						contadorMaximo = contador[i];
						flagServicio = 1;
					}
				}
			}

			printf("\nEl o los servicios elegidos %d veces son:  ", contadorMaximo);
			for (int i = 0; i < tamS; i++){
			if(contadorMaximo == contador[i]){
				cargarDescripcionServicio(listaS, tamS, i+20000, servicio );
				printf("%s \n", servicio);
				}
			}
			todoOk = 1;
		}
		return todoOk;
		}


int mostrarServiciosMascota(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS){
int todoOk = 0;
int indice;
int idMascota;
int flagTrabajo = 0;
int contador = 0;

	if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
			&& listaC != NULL && tamC > 0){

	listarMascota(lista, tamM, listaC, tamC, listaT, tamT);
	validarInt("\nIngrese el id de la mascota que desea saber sus servicios: \n", "\nError. Reingrese un id valido\n", &idMascota, 1, 2000);
	while(!buscarId(lista, tamM, idMascota, &indice)){
		validarInt("\nERROR. Ingrese el id de la mascota que desea saber sus servicios: \n", "Error. Reingrese un id valido\n", &idMascota, 1, 2000);
	}

	system("cls");
	printf(" \n\n ***   Listado de Trabajos  ***\n\n");
	printf("%-4s %-15s %-15s %-9s \n", "ID", "Nombre", "Servicio", "Fecha");
	printf("-------------------------------------------------------------\n");
	for (int i = 0; i < tamTra; i++){
		if(!listaTra[i].isEmpty && listaTra[i].idMascota == idMascota){
			mostrarTrabajo(listaTra + i, lista, tamM, listaC, tamC, listaT, tamT, listaS, tamS);
			contador++;
			flagTrabajo = 1;
		}
	}
	printf("\nLa cantidad total de servicios realizados a esta mascota es: %d\n", contador);
	if(!flagTrabajo){
	printf("\nNo hay trabajos asignados a esta mascota\n");
	}

	todoOk = 1;
	}

return todoOk;
}

int mostrarPrecioPorMascota(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS){

	int todoOk = 0;
	int indice;
	int idMascota;
	int flagTrabajo = 0;
	float acumuladorPrecios = 0;
	char nombre[20];
	int idServicio = 0;

		if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
				&& listaC != NULL && tamC > 0){

		listarMascota(lista, tamM, listaC, tamC, listaT, tamT);
		validarInt("\nIngrese el id de la mascota que desea saber sus servicios: \n", "\nError. Reingrese un id valido\n", &idMascota, 1, 2000);
		while(!buscarId(lista, tamM, idMascota, &indice)){
			validarInt("\nERROR. Ingrese el id de la mascota que desea saber sus servicios: \n", "Error. Reingrese un id valido\n", &idMascota, 1, 2000);
		}

		for (int i = 0; i < tamTra; i++){
			if(!listaTra[i].isEmpty && listaTra[i].idMascota == idMascota){
				idServicio = listaTra[i].idServicio;
				acumuladorPrecios = (acumuladorPrecios + listaS[idServicio -20000].precio);
				flagTrabajo = 1;
			}
		}


		if(!flagTrabajo){
		printf("\nNo hay trabajos asignados a esta mascota\n");
		}else{
			cargarNombreMascota(lista, tamM, idMascota, nombre);
			printf("\nEl precio total de los servicios de la mascota %-10s es de  %f\n", nombre,acumuladorPrecios);
		}

		todoOk = 1;
		}

		return todoOk;
}

int mostrarPrecioPorServicio(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS){

	int todoOk = 0;
	int flagTrabajo = 0;
	float acumuladorPrecios = 0;
	char descripcion[20];
	int idServicio = 0;

		if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
				&& listaC != NULL && tamC > 0){

		listarServicios(listaS, tamS);
		validarInt("\nIngrese el id del servicio que desea saber su importe total: \n", "\nError. Reingrese un id valido\n", &idServicio, 20000, 20002);

		for (int i = 0; i < tamTra; i++){
			if(!listaTra[i].isEmpty && listaTra[i].idServicio == idServicio){
				idServicio = listaTra[i].idServicio;
				acumuladorPrecios = (acumuladorPrecios + listaS[idServicio -20000].precio);
				flagTrabajo = 1;
			}
		}

		if(!flagTrabajo){
		printf("\nNo hay trabajos asignados a esta mascota\n");
		}else{
			cargarDescripcionServicio(listaS, tamS, idServicio, descripcion);
			printf("\nEl precio total del servicio %-8s es de  %f\n", descripcion,acumuladorPrecios);
		}

		todoOk = 1;
		}

		return todoOk;
}



int mostrarMascotasPorServicio(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS){

		int todoOk = 0;
		int flagTrabajo = 0;
		char nombre[20];
		int idServicio = 0;
		char servicio[20];

			if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
					&& listaC != NULL && tamC > 0){

			listarServicios(listaS, tamS);
			validarInt("\nIngrese el id del servicio que desea analizar\n", "\nError. Reingrese id del servicio\n", &idServicio,20000,20002);

			cargarDescripcionServicio(listaS, tamS, idServicio, servicio);
			printf("\nLos nombres de las mascotas que recibieron el servicio %s \n", servicio);
			for (int i = 0; i < tamTra; i++){
				if(!listaTra[i].isEmpty && listaTra[i].idServicio == idServicio){
					cargarNombreMascota(lista, tamM, listaTra[i].idMascota, nombre);
					printf("\n%-10s  %d/%d/%d \n", nombre, listaTra[i].fecha.dia, listaTra[i].fecha.mes, listaTra[i].fecha.anio);
					flagTrabajo = 1;
				}
			}
			if(!flagTrabajo){
			printf("\nNo hay mascotas asignadas para ese servicio\n");
			}

			todoOk = 1;
			}

	return todoOk;
}


int servicioPorFecha(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS){

			int todoOk = 0;
			int flagTrabajo = 0;
			char servicio[20];
			int dia;
			int mes;
			int anio;
			int contadorServicios= 0;
				if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
						&& listaC != NULL && tamC > 0){


				validarFecha(&dia, &mes, &anio);


				printf("\nLos servicios realizados en esta fecha %d/%d/%d son: \n", dia,mes,anio);
				for (int i = 0; i < tamTra; i++){
					if(!listaTra[i].isEmpty && listaTra[i].fecha.dia == dia && listaTra[i].fecha.mes == mes && listaTra[i].fecha.anio == anio){
						cargarDescripcionServicio(listaS, tamS, listaTra[i].idServicio, servicio);
						contadorServicios++;
						printf("\n %-10s \n", servicio);
						flagTrabajo = 1;
					}
				}
				printf("\n\nCantidad total de servicios: %d\n", contadorServicios);
				if(!flagTrabajo){
				printf("\nNo hay servicios en esa fecha\n");
				}

				todoOk = 1;
				}
		return todoOk;
}

int promedioServicio(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS){

	int todoOk = 0;
	int flag = 0;
	char descripcion[20];
	int id;
	float promedio;
	int contador = 0;
	int total = 0;

		if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
				&& listaC != NULL && tamC > 0){
		listarServicios(listaS, tamS);
		validarInt("\nIngrese el id del servicio que desea conocer el promedio\n", "\nError. Ingrese un id valido\n", &id,20000,20002);

		for (int i = 0; i < tamTra; i++){

			if(!listaTra[i].isEmpty){
				total++;
			}

			if(!listaTra[i].isEmpty && listaTra[i].idServicio == id){
				contador++;
				flag = 1;
			}
		}
		promedio = (float) contador / total;

		if(!flag){
		printf("\nNo se han realizado trabajos con ese servicio \n");
		}else{
			cargarDescripcionServicio(listaS, tamS, id, descripcion);
			printf("\nEL promedio de %-10s es: %f\n\n", descripcion, promedio);
		}

		todoOk = 1;
		}
return todoOk;
}


int promedioTipoMascotas(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS){

	int todoOk = 0;
	int flag = 0;
	char descripcion[20];
	int id;
	float promedio;
	int contador = 0;
	int total = 0;

		if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
				&& listaC != NULL && tamC > 0){
		listarTipo(listaT, tamT);
		validarInt("\nIngrese el id del tipo que desea conocer el promedio\n", "\nError. Ingrese un id valido\n", &id,1000,1004);

		for (int i = 0; i < tamTra; i++){

			if(!lista[i].isEmpty){
				total++;
			}

			if(!lista[i].isEmpty && lista[i].idTipo == id){
				contador++;
				flag = 1;
			}
		}
		promedio = (float) contador / total;

		if(!flag){
		printf("\nNo se han encontrado mascotas de este tipo\n");
		}else{
			cargarDescripcionTipo(listaT, tamT, id, descripcion);
			printf("\nEL promedio de %-10s es: %f\n\n", descripcion, promedio);
		}

		todoOk = 1;
		}
return todoOk;
}


int promedioColorMascotas(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS){

	int todoOk = 0;
	int flag = 0;
	char descripcion[20];
	int id;
	float promedio;
	int contador = 0;
	int total = 0;

		if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
				&& listaC != NULL && tamC > 0){
		listarColor(listaC, tamC);
		validarInt("\nIngrese el id del color que desea conocer el promedio\n", "\nError. Ingrese un id valido\n", &id,5000,5004);

		for (int i = 0; i < tamTra; i++){

			if(!lista[i].isEmpty){
				total++;
			}

			if(!lista[i].isEmpty && lista[i].idColor == id){
				contador++;
				flag = 1;
			}
		}
		promedio = (float) contador / total;

		if(!flag){
		printf("\nNo se han encontrado mascotas de este color\n");
		}else{
			cargarDescripcionColor(listaC, tamC, id, descripcion);
			printf("\nEL promedio de %-10s es: %f\n\n", descripcion, promedio);
		}

		todoOk = 1;
		}
return todoOk;
}

int ordenarMascotaPorEdad(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, int criterio) {
	int todoOk = 0;
	eMascota auxMascota;

	if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
			&& listaC != NULL && tamC > 0) {

		for (int i = 0; i < tamM - 1; i++) {
			for (int j = i + 1; j < tamM - 1; j++){
			if((lista[i].edad > lista[j].edad && !criterio)//ASCENDETE
			|| (lista[i].edad < lista[j].edad && criterio))//DESCENDENTE
			{
				auxMascota = lista[i];
				lista[i]=lista[j];
				lista[j]=auxMascota;
				todoOk = 1;
				}
			}
		}
		if (!todoOk) {
			printf("\nError al ordenar las mascotas.\n");
		} else {
			printf("Ordenado con Exito");
		}
	}
	return todoOk;
}

int ordenarTrabajosPorServicio(eTrabajo *lista, int tamTra, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, int criterio) {
	int todoOk = 0;
	eTrabajo auxTrabajo;

	if (lista != NULL && tamTra > 0 && listaT != NULL && tamT > 0
			&& listaC != NULL && tamC > 0) {

		for (int i = 0; i < tamTra - 1; i++) {
			for (int j = i + 1; j < tamTra - 1; j++){
			if((lista[i].idServicio > lista[j].idServicio && !criterio)//ASCENDETE
			|| (lista[i].idServicio < lista[j].idServicio && criterio))//DESCENDENTE
			{
				auxTrabajo = lista[i];
				lista[i]=lista[j];
				lista[j]=auxTrabajo;
				todoOk = 1;
				}
			}
		}
		if (!todoOk) {
			printf("\nError al ordenar los trabajos.\n");
		} else {
			printf("Ordenado con Exito");
		}
	}
	return todoOk;
}


int cantidadMascotasPorServicio(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS){

	int todoOk = 0;
	int id;
	int contador[3] = {0};

	if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
				&& listaC != NULL && tamC > 0){
		listarServicios(listaS, tamS);
		validarInt("\nIngrese el id del servicio que desea conocer el promedio\n", "\nError. Ingrese un id valido\n", &id,20000,20002);

		for (int i = 0; i < tamTra; i++) {

						switch (listaTra[i].idServicio) {
						case 20000:
							contador[0] = contador[0]+1;
							break;
						case 20001:
							contador[1] = contador[1]+1;
							break;
						case 20002:
							contador[2] = contador[2]+1;
							break;
						}
					}
		switch (id) {
			case 20000:
				printf("\n La cantidad de Aves es: %d\n\n", contador[0]);
				break;
			case 20001:
				printf("\n La cantidad de Perros es: %d\n\n", contador[1]);
				break;
			case 20002:
				printf("\n La cantidad de Roedores es: %d\n\n", contador[2]);
				break;
			}


	todoOk = 1;
	}

return todoOk;
}


int totalPrecioServicios(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS){
int todoOk = 1;
int acumulador[3] = {0};
int total;
if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
				&& listaC != NULL && tamC > 0){


		for (int i = 0; i < tamTra; i++) {

						switch (listaTra[i].idServicio) {
						case 20000:
							acumulador[0] =	acumulador[0]+ listaS[0].precio;
							break;
						case 20001:
							acumulador[1] =	acumulador[1]+ listaS[1].precio;
							break;
						case 20002:
							acumulador[2] =	acumulador[2]+listaS[2].precio;
							break;
						}
					}
				printf("\n El total recaudado por el servicio corte es:%d\n\n", acumulador[0]);
				printf("\n El total recaudado por el servicio Desparacitado es: %d\n\n", acumulador[1]);
				printf("\n El total reacaudado por el servicio Castrado es: %d\n\n", acumulador[2]);

				total= acumulador[0] + acumulador[1] + acumulador[2];
				printf("El total de todos los servicios es %d", total);
				todoOk = 1;
	}
return todoOk;
}

int mostrarVacunados(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS){
int todoOk = 0;
int contador = 0;

if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
					&& listaC != NULL && tamC > 0){

		system("cls");
		printf(" \n\n       ***   Listado de Mascotas  ***\n\n");
		printf("%-4s  %-15s %-8s %-8s %-3s  %-7s  %-15s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNAS", "DUEÑO");
		printf("-------------------------------------------------------------------------------------\n");
			for (int i = 0; i < tamM; i++) {

				if (lista[i].vacunado == 's' && !lista[i].isEmpty) {
					mostrarMascota(lista + i, listaC, tamC, listaT, tamT);
					contador++;
				}
			}
			printf("\nLa cantidad total de mascotas vacunadas es: %d\n", contador);

todoOk = 1;
}
return todoOk;
}

int mostrarNoVacunados(eMascota *lista, int tamM, eTipo *listaT, int tamT,
		eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS){
int todoOk = 0;
int contador = 0;

if (lista != NULL && tamM > 0 && listaT != NULL && tamT > 0
					&& listaC != NULL && tamC > 0){

	system("cls");
		printf(" \n\n       ***   Listado de Mascotas  ***\n\n");
		printf("%-4s  %-15s %-8s %-8s %-3s  %-7s  %-15s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNAS", "DUEÑO");
		printf("-------------------------------------------------------------------------------------\n");
			for (int i = 0; i < tamM; i++) {

				if (lista[i].vacunado == 'n' && !lista[i].isEmpty) {
					mostrarMascota(lista + i, listaC, tamC, listaT, tamT);
					contador++;
				}
			}
			printf("\nLa cantidad total de mascotas NO vacunadas es: %d\n", contador);

todoOk = 1;
}
return todoOk;
}




