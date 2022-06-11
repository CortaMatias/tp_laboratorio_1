/*
 * autos.c
 *
 *  Created on: 8 may. 2022
 *      Author: Matias
 */
#include "autos.h"



int menu(){
int opcion;

printf(" \n\n *** Menu de Opciones ***\n");
	printf("1)Alta auto\n");
	printf("2)Modificar auto\n");
	printf("3)Baja auto\n");
	printf("4)Listar autos\n");
	printf("5)Listar marcas\n");
	printf("6)Listar colores\n");
	printf("7)Listar servicios\n");
	printf("8)Alta trabajo\n");
	printf("9)Listar trabajos\n");
	printf("10)Salir\n");

	validarInt("\n*Ingrese una opcion* : ", "\n**  Error. Ingrese una opcion valida: ** ", &opcion, 1, 10);
return opcion;
}

int addAuto(eAutos* lista, int tamA, int* idAuto, eMarca* listaM, int tamM, eColor* listaC, int tamC){
int todoOk = 0;
int indice;

if(isEmpty(lista, tamA, &indice)){

eAutos auxLista;
	validarAlfaNumerico("\nIngrese la patente: \n", "\nError. Reingrese la patente: ", auxLista.patente, 7);
	listarMarcas(listaM,tamM);
	validarInt("\nIngrese el id de la marca: ", "\nError reingrese el id de la marca: ", &auxLista.idMarca, 1000, 1004);
	listarColores(listaC, tamC);
	validarInt("\nIngrese el id del color: ", "\nError. Reingrese el id del color: ", &auxLista.idColor, 5000,5004);
	validarInt("\nIngrese el modelo del auto: ", "\nError. Reingrese el modelo del auto: ", &auxLista.modelo, 1910, 2022);

	auxLista.id = *idAuto;
	lista[indice]=auxLista;
	lista[indice].isEmpty = 0;
	*idAuto = *idAuto + 1;
	todoOk = 1;
}
else{
	printf("\nNo hay espacio en la lista \n");
}
return todoOk;
}

int removeAuto(eAutos* lista, int tamA, int *flagAdd, eColor* listaC, int tamC, eMarca* listaM, int tamM)
{
	int todoOk = 0;
	char patente[7];
	int indice;
	char confirmacion;
	if (lista != NULL && tamA >= 0)
	{
		listarAutos(lista, tamA, listaC, tamC, listaM, tamM);
		validarAlfaNumerico("\n** Ingrese la patente: ** \n", "\n** Error, reingrese patente: ** \n", patente,7);

		while (!findAutoByPatente(lista, tamA, patente, &indice))
		{
			validarAlfaNumerico("\n** Error. No se encontro un auto con esa patente, reingrese patente: ** ", "** Error, Reingrese patente:** ", patente, 7);
		}
		printf(" \n\n         ***   Auto seleccionado   ***\n\n");
		printf(" ID      Patente     Marca    Color      Modelo      \n");
		printf("-------------------------------------------------------\n");
		mostrarAuto(lista + indice, listaC, tamC, listaM, tamM);
		printf("\n\nEsta seguro que desea remover este auto? (si/no): ");
		scanf("%c", &confirmacion);
		if (confirmacion == 's')
		{
			lista[indice].isEmpty = 1;
			todoOk = 1;
			*flagAdd = *flagAdd - 1;
		}
		else
		{
			todoOk = 0;
		}
	}
	return todoOk;
}

int findAutoByPatente(eAutos *lista, int tamA, char* patente, int *indice)
{
	int todoOk = 0;

	if (lista != NULL && tamA >= 0)
	{
		*indice = -1;
		for (int i = 0; i < tamA; i++)
		{
			if (!lista[i].isEmpty && strcmp(lista[i].patente , patente) == 0)
			{
				*indice = i;
				todoOk = 1;
				break;
			}
		}
	}
	return todoOk;
}


int menuModificar(eAutos* lista, eColor* listaC, int tamC,eMarca* listaM, int tamM){
int opcion;

printf(" \n\n         ***   Auto seleccionado   ***\n\n");
printf(" ID      Patente     Marca    Color      Modelo      \n");
printf("-------------------------------------------------------\n");
mostrarAuto(lista, listaC, tamC, listaM, tamM);
printf("\n1)Modificar Color\n2)Modificar modelo\n3)Salir\n");
validarInt("Ingrese la opcion: ", "Error al ingresar opcion, reingrese: ", &opcion, 1, 3);

return opcion;
}

int modificarAuto(eAutos* lista, int tamA, eColor* listaC, int tamC, eMarca* listaM, int tamM){
int todoOk = 0;
char salida = 'n';
char patente[7];
int indice;
int idColor;
int modelo;
int opcion;
	listarAutos(lista, tamA, listaC, tamC, listaM, tamM);
	validarAlfaNumerico("\nIngrese la pantete del vehiculo que desea eliminar: \n", "\nError. Reingrese la patente: \n", patente, 7);
	while (!findAutoByPatente(lista, tamA, patente, &indice))
			{
			validarAlfaNumerico("\n** Error. No se encontro un auto con esa patente, reingrese patente: ** \n", "** Error, Reingrese patente: ** \n", patente, 7);
			}
	do{
		opcion = menuModificar(lista + indice, listaC, tamC, listaM, tamM);
	if (opcion == 1){
			listarColores(listaC, tamC);
			validarInt("\nIngrese el id del color: ", "\nError. Reingrese el id del color: \n", &idColor, 5000,5004);
			lista[indice].idColor = idColor;
	}else if (opcion ==2){
		validarInt("\nIngrese el modelo del auto: ", "\nError. Reingrese el modelo del auto: \n", &modelo, 1910, 2022);
		lista[indice].modelo = modelo;
	}else{
		salida = 's';
	}

	}while(salida == 'n');


return todoOk;
}

int initAutos(eAutos *lista, int tamA)
{
	int todoOk = 0;

	if (lista != NULL && tamA > 0)
	{
		for (int i = 0; i < tamA; i++)
		{
			lista[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}


int isEmpty(eAutos* lista, int tamA, int *pIndice)
{
	int todoOk = 0;
	if (lista != NULL && tamA > 0 && pIndice != NULL)
	{

		*pIndice = -1;
		for (int i = 0; i < tamA; i++)
		{
			if (lista[i].isEmpty)
			{
				*pIndice= i;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int mostrarAuto(eAutos* lista, eColor* listaC, int tamC, eMarca* listaM, int tamM){
int todoOk = 0;
char marca[20];
char color[20];
	if(lista != NULL && listaC != NULL && listaM != NULL && tamM >0 && tamC>0){
	cargarDescripcionColor(listaC, tamC, lista->idColor, color);
	cargarDescripcionMarca(listaM,tamM, lista->idMarca, marca);

printf(" %04d    %6s   %7s     %5s   %4d\n", lista->id, lista->patente, marca, color, lista->modelo);
		todoOk = 1;
	}
return todoOk;
}

int listarAutos(eAutos* lista, int tamA, eColor* listaC, int tamC, eMarca* listaM, int tamM){
	int todoOk = 0;
		int flag = 0;
		if (lista != NULL && tamA > 0)
		{
			system("cls");
			printf(" \n\n         ***   Listado de Autos   ***\n\n");
			printf(" ID      Patente     Marca    Color      Modelo      \n");
			printf("-------------------------------------------------------\n");
			for (int i = 0; i < tamA; i++)
			{
				if (!lista[i].isEmpty)
				{
					mostrarAuto(lista + i, listaC, tamC, listaM, tamM);
					flag = 1;
				}
			}
			if (!flag)
			{
				printf("\n** No hay autos en el sistema.** ");
			}
			todoOk = 1;
		}
		return todoOk;
}


int validarPatente(eAutos* listaA, int tamA, char* patente){
    int esValido = 0;
    int indice;

    buscarPatente(listaA, tamA, patente, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}

int buscarPatente(eAutos* listaA, int tamA, char* patente, int* pIndice){
    int todoOk = 0;
    if(listaA != NULL && tamA > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tamA; i++){
                if(!listaA[i].isEmpty && strcmp(listaA[i].patente , patente)== 0){
                    *pIndice = i;
                    todoOk = 1;
                    break;
                }
            }

    }
    return todoOk;
}

void hardCodearAutos(eAutos* lista, int tamA)
{
    eAutos autoss [23]= {
    {1, "AAA201", 1000, 5001, 1995, 1},
    {2, "DFR234", 1003, 5000, 2002, 1},
    {3, "GFT564", 1002, 5003, 2007, 1},
    {4, "ACD321", 1002, 5003, 1995, 1},
    {5, "HTD656", 1004, 5002, 2008, 1},
    {6, "QSZ435", 1003, 5001, 1994, 1},
    {7, "LGX201", 1001, 5000, 2012, 1},
    {8, "SUZ324", 1001, 5002, 1991, 1},
    {9, "HCU762", 1000, 5003, 2008, 1},
    {10, "DYC735", 1003, 5001, 2002, 1},
    {11, "JJK879", 1003, 5001, 2010, 1},
    {12, "FED322", 1004, 5002, 2006, 1},
    {13, "GHV332", 1001, 5003, 2007, 1},
    {14, "BDE221", 1000, 5004, 1996, 1},
    {15, "OPD332", 1000, 5001, 2014, 1},
    {16, "PPD121", 1002, 5001, 2015, 1},
    {17, "IIT230", 1001, 5000, 2009, 1},
    {18, "KOD220", 1004, 5002, 2011, 1},
    {19, "QSZ305", 1004, 5002, 1993, 1},
    {20, "SSD128", 1002, 5003, 1992, 1},
    {21, "SSD240", 1003, 5004, 1992,0},
    {22, "EDF213", 1001, 5000, 2001,0}};
    for(int i=0;i<tamA;i++)
    {
        lista[i]= autoss[i];
    }

}
