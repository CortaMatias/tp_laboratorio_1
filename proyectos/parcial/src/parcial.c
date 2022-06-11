/*
 ============================================================================
 Name        : parcial.c
 Author      : Matias Corta
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "autos.h"
#include "servicios.h"
#include "trabajo.h"
#define TAMA 2000
#define TAMM 5
#define TAMC 5
#define TAMS 5
#define TAMT 2000

int main(void) {
	setbuf(stdout, NULL);
	int salida = 'n';
	eAutos listaA[TAMA];
	eMarca listaM[TAMM]= {{1000,"Renault"},{1001,"Fiat"},{1002,"Ford"},{1003,"Chevrolet"},{1004,"Peugeot"}};
	eColor listaC[TAMC]= {{5000,"Negro"},{5001,"Blanco"},{5002,"Gris"},{5003,"Rojo"},{5004,"Azul"}};
	eServicio listaS[TAMS] ={
	       {20000, "Lavado", 250},
	       {20001, "Pulido", 300},  
	       {20002, "Encerado", 400},
	       {20003, "Completo", 600},
	       {20004, "Teflonado", 800}
	       };
	eTrabajo listaT[TAMT];
	int idAuto = 1;
	int flagAdd= 0;
	int idTrabajo = 9000;
	int flagAddTrabajo = 0;


	if(initAutos(listaA,TAMA)&& initTrabajo(listaT,TAMT)){

		do{ switch(menu(listaA, TAMA)){

	case 1:
		if(addAuto(listaA, TAMA, &idAuto, listaM, TAMM, listaC, TAMC)){
			flagAdd++;
		}
	break;

	case 2:
		if(flagAdd){
		modificarAuto(listaA, TAMA, listaC, TAMC, listaM, TAMM);
		}
	break;

	case 3:
		if(flagAdd){
		removeAuto(listaA, TAMA, &flagAdd, listaC, TAMC, listaM, TAMM);
		}
	break;

	case 4:
		if(flagAdd){
			listarAutos(listaA, TAMA, listaC, TAMC, listaM, TAMM);
		}

	break;

	case 5:
		listarMarcas(listaM, TAMM);
	break;

	case 6:
		listarColores(listaC, TAMC);
	break;

	case 7:
		listarServicios(listaS, TAMS);
		break;

	case 8:
		if((flagAdd) && altaTrabajo(listaA, TAMA, listaS, TAMS, listaT, TAMT, &idTrabajo, listaC, TAMC, listaM, TAMM) ){
			printf("\nCarga realizada con exito\n");
			idTrabajo++;
			flagAddTrabajo++;
		}else{
			printf("\nError. No hay vehiculos ingresados.\n");
		}
	break;
	case 9:
		if(flagAddTrabajo)
			{
			listarTrabajos(listaT,TAMT, listaS, TAMS);
			}
		break;
	}


	}while(salida == 'n');

	}
	return EXIT_SUCCESS;
}
