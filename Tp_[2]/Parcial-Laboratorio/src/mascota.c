/*
 * estructura1.c
 *
 *  Created on: 10 may. 2022
 *      Author: Matias
 */
#include "mascota.h"

int menu()
{
	int opcion;
	printf(" \n  *** MENU DE OPCIONES ***  \n");
	printf("1)Alta mascota \n");
	printf("2)Modificar mascota  \n");
	printf("3)Baja mascota  \n");
	printf("4)Listar mascota  \n");
	printf("5)Listar tipos  \n");
	printf("6)Listar colores  \n");
	printf("7)Listar servicios  \n");
	printf("8)Alta trabajo  \n");
	printf("9)Listar trabajos  \n");
	printf("10)Salir \n");
	printf("11)Cargar mascotas y trabajos de prueba\n");
	validarInt("\n*Ingrese una opcion* :   \n", "\n**  Error. Ingrese una opcion valida: **   \n", &opcion, 1, 11);
	return opcion;
}

int isEmpty(eMascota *lista, int tam, int *pIndice)
{
	int todoOk = 0;
	if (lista != NULL && tam > 0 && pIndice != NULL)
	{

		*pIndice = -1;
		for (int i = 0; i < tam; i++)
		{
			if (lista[i].isEmpty)
			{
				*pIndice = i;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int buscarId(eMascota *lista, int tam, int id, int *pIndice)
{
	int todoOk = 0;
	if (lista != NULL && tam > 0 && pIndice != NULL)
	{
		*pIndice = -1;
		for (int i = 0; i < tam; i++)
		{

			if (lista[i].id == id && !lista[i].isEmpty)
			{
				*pIndice = i;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int initStruct(eMascota *lista, int tam)
{
	int todoOk = 0;

	if (lista != NULL && tam > 0)
	{
		for (int i = 0; i < tam; i++)
		{
			lista[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int mostrarMascota(eMascota *lista, eColor *listaC, int tamC, eTipo *listaT, int tamT)
{
	int todoOk = 0;
	char Color[20];
	char Tipo[20];
	if (lista != NULL && listaC != NULL && listaT != NULL && tamT > 0 && tamC > 0)
	{
		cargarDescripcionColor(listaC, tamC, lista->idColor, Color);
		cargarDescripcionTipo(listaT, tamT, lista->idTipo, Tipo);

		printf(" %-4d %-20s %-8s %-8s %-3d    %-1c\n", lista->id, lista->nombre, Tipo, Color, lista->edad, lista->vacunado);
		todoOk = 1;
	}
	return todoOk;
}

int listarMascota(eMascota *lista, int tamM, eColor *listaC, int tamC, eTipo *listaT, int tamT)
{
	int todoOk = 0;
	int flag = 0;
	if (lista != NULL && tamM > 0 && listaC != NULL && tamC > 0 && listaT != NULL && tamT > 0)
	{
		system("cls");
		printf(" \n\n       ***   Listado de Mascotas  ***\n\n");
		printf("%-4s  %-20s %-8s %-8s %-3s  %-1s\n", "ID", "NOMBRE", "TIPO", "COLOR", "EDAD", "VACUNACION");
		printf("---------------------------------------------------------\n");
		for (int i = 0; i < tamM; i++)
		{
			if (!lista[i].isEmpty)
			{
				mostrarMascota(lista + i, listaC, tamC, listaT, tamT);
				flag = 1;
			}
		}
		if (!flag)
		{
			printf("\n** No hay Mascotas en el sistema.** ");
		}
		todoOk = 1;
	}
	return todoOk;
}

int addMascota(eMascota *lista, int tamM, eColor *listaC, int tamC,
			   eTipo *listaT, int tamT, int *idMascota)
{
	int todoOk = 0;

	eMascota auxMascotas;
	int indice;
	if (lista != NULL && tamM > 0 && listaC != NULL && tamC > 0 && listaT != NULL && tamT > 0)
	{

		if (isEmpty(lista, tamM, &indice))
		{
			validarTexto("\nIngrese el nombre de su mascota: \n",
						 "\nError. Reingrese el nombre de su mascota: \n",
						 auxMascotas.nombre, 20);
			listarTipo(listaT, tamT);
			validarInt("\nIngrese el id del tipo: \n",
					   "\nError. Reingrese el tipo de mascota: \n",
					   &auxMascotas.idTipo, 1000, 1004);
			listarColor(listaC, tamC);
			validarInt("\nIngrese el id del Color: \n",
					   "\nError. reingrese el id del color", &auxMascotas.idColor,
					   5000, 5004);
			validarInt("\nIngrese la edad de su mascota\n",
					   "\nError. Reingrese la edad de su mascota\n",
					   &auxMascotas.edad, 0, 80);
			printf("\nSu mascota se encuentra vacunado? (si/no): \n");
			fflush(stdin);
			scanf("%c", &auxMascotas.vacunado);
			while (auxMascotas.vacunado != 'n' && auxMascotas.vacunado != 's')
			{
				printf(
					"\nError. Reingrese una respuesta valida.Su mascota se encuentra vacunado? (si/no): \n");
				fflush(stdin);
				scanf("%c", &auxMascotas.vacunado);
			}
			auxMascotas.id = *idMascota;
			lista[indice] = auxMascotas;
			lista[indice].isEmpty = 0;
			todoOk = 1;
		}
		else
		{
			printf("\nNo hay espacio en la lista\n");
		}
	}
	return todoOk;
}

int removeMascota(eMascota *lista, int tamM, eColor *listaC, int tamC,
				  eTipo *listaT, int tamT, int *flagAdd)
{
	int todoOk = 0;
	int id;
	int indice;
	char confirmacion;
	if (lista != NULL && tamM > 0 && listaC != NULL && tamC > 0 && listaT != NULL && tamT > 0)
	{

		listarMascota(lista, tamM, listaC, tamC, listaT, tamT);
		validarInt("Ingrese el id de la mascota que desea remover: \n",
				   "Error. Reingrese un id valido", &id, 1, 2000);
		buscarId(lista, tamM, id, &indice);
		while (indice == -1)
		{
			validarInt(
				"Error. no se encontro una mascota con ese ID. Reingrese un id valido: ",
				"Error. Reingrese un id valido", &id, 1, 2000);
			buscarId(lista, tamM, id, &indice);
		}
		printf(" \n\n         ***   Mascota seleccionada  ***\n\n");
		printf(
			" ID     NOMBRE       TIPO     COLOR      EDAD      VACUNACION     \n");
		printf(
			"-----------------------------------------------------------------------\n");
		mostrarMascota(lista + indice, listaC, tamC, listaT, tamT);
		printf("\n\nEsta seguro que desea remover esta mascota? (si/no): \n ");
		fflush(stdin);
		scanf("%c", &confirmacion);
		while (confirmacion != 's' && confirmacion != 'n')
		{
			printf(
				"\n\nERROR. Reingrese respuesta valida. Esta seguro que desea remover esta mascota? (si/no): \n ");
			fflush(stdin);
			scanf("%c", &confirmacion);
		}

		if (confirmacion == 's')
		{
			lista[indice].isEmpty = 1;
			todoOk = 1;
			*flagAdd = *flagAdd - 1;
			printf("** Mascota removida con exito");
		}
		else
		{
			printf(" ** Baja cancelada **");
			todoOk = 1;
		}
	}

	return todoOk;
}

int modificarMascota(eMascota *lista, int tamM, eColor *listaC, int tamC,
					 eTipo *listaT, int tamT)
{
	int todoOk = 0;
	int id;
	int indice;
	int salida = 'n';
	int opcion;
	if (lista != NULL && tamM > 0 && listaC != NULL && tamC > 0 && listaT != NULL && tamT > 0)
	{
		listarMascota(lista, tamM, listaC, tamC, listaT, tamT);
		validarInt("\n\nIngrese el id de la mascota que desea modificar;  \n",
				   "\nError. Reingrese un id valido \n", &id, 1, 2000);
		buscarId(lista, tamM, id, &indice);
		while (indice == -1)
		{
			validarInt(
				"\n Error. no se encontro una mascota con ese ID. Reingrese un id valido: \n ",
				"\n Error. Reingrese un id valido\n ", &id, 1, 2000);
			buscarId(lista, tamM, id, &indice);
		}

		do
		{
			printf(" \n\n         ***   Listado de Mascotas  ***\n\n");
			printf(
				" ID     NOMBRE       TIPO     COLOR      EDAD      VACUNACION     \n");
			printf(
				"-----------------------------------------------------------------------\n");
			mostrarMascota(lista + indice, listaC, tamC, listaT, tamT);
			printf(
				"\n  *** MENU MODIFICAR ***\n\n \n1)Modificar tipo\n2)Modificar Vacunado\n3)Salir\n");
			validarInt("\n Ingrese una opcion: \n",
					   "\n Error. ingrese una opcion valida: \n", &opcion, 1, 3);
			if (opcion == 1)
			{
				listarTipo(listaT, tamT);
				validarInt("\n Ingrese el id del tipo: \n",
						   "\n Error. Reingrese el tipo de mascota: \n",
						   &lista->idTipo, 1000, 1004);
			}
			else if (opcion == 2)
			{
				printf("\n Su mascota se encuentra vacunado? (si/no): \n");
				fflush(stdin);
				scanf("%c", &lista->vacunado);
				while (lista->vacunado != 'n' && lista->vacunado != 's')
				{
					printf(
						"\n Error. Reingrese una respuesta valida.Su mascota se encuentra vacunado? (si/no): \n");
					fflush(stdin);
					scanf("%c", &lista->vacunado);
				}
			}
			else
			{
				salida = 's';
			}

		} while (salida == 'n');
	}

	return todoOk;
}

int cargarNombreMascota(eMascota *lista, int tam, int id, char *descripcion)
{
	int todoOk = 0;
	int indice;

	buscarId(lista, tam, id, &indice);

	if (descripcion != NULL && indice != -1 && lista != NULL)
	{
		strcpy(descripcion, lista[indice].nombre);
		todoOk = 1;
	}
	return todoOk;
}

int hardCodearMascotas(eMascota *lista)
{
	int todoOk = 0;
	if (lista != NULL)
	{
		eMascota mascotass[22] = {
			{1, "Pichicho1", 1000, 5001, 12, 'n', 0},
			{2, "DFR234", 1003, 5000, 10, 's', 0},
			{3, "GFT564", 1002, 5003, 2, 'n', 0},
			{4, "ACD321", 1002, 5003, 3, 's', 0},
			{5, "HTD656", 1004, 5002, 4, 's', 0},
			{6, "QSZ435", 1003, 5001, 9, 's', 0},
			{7, "LGX201", 1001, 5000, 1, 'n', 0},
			{8, "SUZ324", 1001, 5002, 11, 's', 0},
			{9, "HCU762", 1000, 5003, 6, 's', 0},
			{10, "DYC735", 1003, 5001, 8, 'n', 0},
			{11, "JJK879", 1003, 5001, 1, 's', 0},
			{12, "FED322", 1004, 5002, 3, 'n', 0},
			{13, "GHV332", 1001, 5003, 2, 's', 0},
			{14, "BDE221", 1000, 5004, 1, 'n', 0},
			{15, "OPD332", 1000, 5001, 8, 's', 0},
			{16, "PPD121", 1002, 5001, 1, 'n', 0},
			{17, "IIT230", 1001, 5000, 9, 'n', 0},
			{18, "KOD220", 1004, 5002, 15, 's', 0},
			{19, "QSZ305", 1004, 5002, 1, 'n', 0},
			{20, "SSD128", 1002, 5003, 14, 'n', 0},
			{21, "SSD240", 1003, 5004, 13, 'n', 0},
			{22, "EDF213", 1001, 5000, 12, 'n', 0}};

		for (int i = 0; i < 22; i++)
		{
			lista[i] = mascotass[i];
		}
		todoOk = 1;
	}
	return todoOk;
}
