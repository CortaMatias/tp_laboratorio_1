/*
 ============================================================================
 Name        : Parcial.c
 Author      : Matias Corta
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

typedef struct {
	int id;
	char nombre[20];
	char tipo[20];
	float efectividad;
}eVacuna;

int aplicarAumento(float* precio);
int cambiarCaracteres(char* texto, char parametro1, char parametro2);
int sortVacunas (eVacuna* vacunas, int len);

int main(void) {
	float precio = 20;
	eVacuna vacunas[5] = {
			{1, "Astrazeneca", "Fuerte" , 90},
			{2, "Pfizer", "Intermedio", 85},
			{3, "Shinoparm", "Debil", 75},
			{4, "Jhonson", "Intermedio", 80},
			{5, "Sputnik", "Fuerte", 95}
	};
	char nombre [20]= "Juana De Arco";
	if(aplicarAumento(&precio)){
	printf("El valor final del producto es %f", precio);
	}

	if(cambiarCaracteres(nombre,' ', '*')){
	printf("\n\nResultado del cambio de caracteres %s", nombre);
	}

	if(sortVacunas(vacunas, 5)){
	printf(" \n\n         ***   Listado de Vacunas   ***\n\n");
	printf(" ID      Nombre      Tipo    Efectividad        \n");
	printf("-------------------------------------------------\n");
	//printf(" %04d %15s  %15s    %6.2f "), vacunas->id, vacunas->nombre, vacunas->tipo, vacunas->efectividad ;


	printf("-------------------------------------------------\n");
	}


	return EXIT_SUCCESS;
}

int aplicarAumento(float* precio){
int todoOk = 0;

if(precio > 0){

	*precio = *precio * 1.05;
	todoOk = 1;
}

return todoOk;
}

int cambiarCaracteres(char* texto, char parametro1, char parametro2){
int todoOk = 0;
int len;
int contador = 0;
len = strlen(texto);
if(texto != NULL){

	for(int i= 0; i < len -1; i++){

	if(texto[i] == parametro1){
		texto[i]= parametro2;
		contador++;
		todoOk = 1;
	}
	}
}
return todoOk;
}


int sortVacunas (eVacuna* list, int len){
int todoOk = 0;
eVacuna auxVacunas;
for (int i = 0; i < len - 1; i++)
		{
			for (int j = i + 1; j < len; j++)
			{

					if ((strcmp((list+i)->tipo , (list + j)->tipo)== 0 &&  list[i].efectividad > list[j].efectividad))
						||
					{
						auxVacunas = list[i];
						list[i] = list[j];
						list[j] = auxVacunas;
					}
			}
		}
		todoOk = 1;
return todoOk;
}


