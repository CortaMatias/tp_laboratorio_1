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
			mostrarMascotaColorSeleccionado(listaM,tamM, listaC,tamC, listaT,tamT);
			break;
		case 2:
			promedioVacunados(listaM, tamM);
					break;
		case 3:
			mostrarMascotaJoven(listaM,tamM, listaT,tamT,listaC,tamC);

					break;
		case 4:
			mostrarMascotaPorTipo(listaM, tamM, listaT, tamT, listaC, tamC);
			//int mostrarMascotaPorTipo(eMascota *lista, int tamM, eTipo *listaT, int tamT,			eColor *listaC, int tamC)
					break;
		case 5:
			cantidadPorColorYTipo(listaM,tamM, listaT, tamT, listaC, tamC);
			//int cantidadPorColorYTipo(eMascota *lista, int tamM, eTipo *listaT, int tamT,				eColor *listaC, int tamC)
					break;
		case 6:
			colorDeMascotaTop(listaM, tamM, listaC, tamC);
		//int colorDeMascotaTop(eMascota *lista, int tamM, eColor *listaC, int tamC)
					break;
		case 7:
			mostrarServiciosMascota(listaM,tamM, listaT, tamT, listaC, tamC, lista, tamTra, listaS, tamS);
			//int mostrarServiciosMascota(eMascota *lista, int tamM, eTipo *listaT, int tamT,eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS)
					break;
		case 8:
			mostrarPrecioPorMascota(listaM, tamM, listaT, tamT, listaC, tamC, lista, tamTra, listaS, tamS);
			//int mostrarPrecioPorMascota(eMascota *lista, int tamM, eTipo *listaT, int tamT,eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS)
					break;
		case 9:
			mostrarMascotasPorServicio(listaM, tamM, listaT, tamT, listaC, tamC, lista, tamTra, listaS, tamS);
			//int mostrarMascotasPorServicio(eMascota *lista, int tamM, eTipo *listaT, int tamT,eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS)
					break;
		case 10:
			servicioPorFecha(listaM, tamM, listaT, tamT, listaC, tamC, lista, tamTra, listaS, tamS);
			//int servicioPorFecha(eMascota *lista, int tamM, eTipo *listaT, int tamT,	eColor *listaC, int tamC, eTrabajo* listaTra, int tamTra, eServicio* listaS, int tamS)
					break;
		case 11:
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
printf(" \n\n**** Menu de informes **** \n\n");
printf("1)Mostrar las mascotas del color seleccionado por el usuario\n");
printf("2)Mostrar promedio de mascotas vacunadas\n");
printf("3)Informar la o las mascotas de menor edad\n");
printf("4)Lista de las mascotas separadas por tipo\n");
printf("5)Elegir un color y un tipo y contar cuantas mascotas hay de ese color y ese tipo\n");
printf("6)Mostrar el o los colores con mas cantidad de mascotas\n");
printf("7)Ingresar una mascota y ver los trabajos realizados\n");
printf("8)Ingresar una mascota y ver la suma de los importes de los servicios realizados\n");
printf("9)Ingresar un servicio y mostrar las mascotas a las que se le realizo ese servicio y la fecha\n");
printf("10)Elegir una fecha y mostrar todos los servicios realizados en la misma\n");
printf("11)Salir del menu de informes\n");



validarInt("\nIngrese la opcion que desea elegir\n", "\nError ingrese una opcion valida\n", &opcion, 1, 15);

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
				printf("---------------------------------------------------------------\n");
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


int promedioVacunados(eMascota *lista, int tamM){
int todoOk = 0;
int contador = 0;
float promedio = 0;
int total = 0;

if (lista != NULL && tamM > 0){

			for (int i = 0; i < tamM; i++) {

				if(!lista[i].isEmpty){
					total++;
				}

				if (lista[i].vacunado == 's' && !lista[i].isEmpty) {
					contador++;
				}
			}
			promedio = (float) contador / total;
			printf("\nEl promedio de mascotas vacunadas es: %f %%\n", promedio*100);

todoOk = 1;
}
return todoOk;
}

int mostrarMascotaJoven(eMascota *lista, int tamM, eTipo *listaT, int tamT,
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
				printf("%-4s  %-15s %-8s %-8s %-3s  %-7s  %-15s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNAS", "DUEÑO");
				printf("---------------------------------------------------------------------------\n");

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

		for (int i = 0; i < tamM - 1; i++) {

			if (lista[i].idTipo == 1000) {
				mostrarMascota(lista + i, listaC, tamC, listaT, tamT);
			}
		}

		system("cls");
			printf(" \n\n       ***   Listado de Perros  ***\n\n");
			printf("%-4s  %-15s %-8s %-8s %-3s  %-7s  %-15s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNAS", "DUEÑO");
			printf("-------------------------------------------------------------------------------------\n");

		for (int i = 0; i < tamM - 1; i++) {
			if (lista[i].idTipo == 1001) {
				mostrarMascota(lista + i, listaC, tamC, listaT, tamT);
			}
		}

		system("cls");
			printf(" \n\n       ***   Listado de Roedores ***\n\n");
			printf("%-4s  %-15s %-8s %-8s %-3s  %-7s  %-15s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNAS", "DUEÑO");
			printf("-------------------------------------------------------------------------------------\n");

		for (int i = 0; i < tamM - 1; i++) {

			if (lista[i].idTipo == 1002) {
				mostrarMascota(lista + i, listaC, tamC, listaT, tamT);
			}
		}

		system("cls");
			printf(" \n\n       ***   Listado de Gatos ***\n\n");
			printf("%-4s  %-15s %-8s %-8s %-3s  %-7s  %-15s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNAS", "DUEÑO");
			printf("-------------------------------------------------------------------------------------\n");

		for (int i = 0; i < tamM - 1; i++) {

			if (lista[i].idTipo == 1003) {
				mostrarMascota(lista + i, listaC, tamC, listaT, tamT);
			}
		}

		system("cls");
			printf(" \n\n       ***   Listado de Peces  ***\n\n");
			printf("%-4s  %-15s %-8s %-8s %-3s  %-7s  %-15s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNAS", "DUEÑO");
			printf("-------------------------------------------------------------------------------------\n");

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


		printf("\nEl o los colores mas elegidos se eligieron %d veces y fueron:  \n", contadorMaximo);
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
			printf("\nEl precio total de los servicios de la mascota %-10s es de  %.2f\n", nombre,acumuladorPrecios);
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

