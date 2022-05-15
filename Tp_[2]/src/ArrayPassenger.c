/*
 * ArrayPassenger.c
 *
 *  Created on: 27 abr. 2022
 *      Author: Matias
 * 2.26
 */
#include "ArrayPassenger.h"

int menu()
{
	int opcion;
	EclipseCls();
	printf(" \n\n *** Menu de Opciones ***\n");
	printf("1)Alta pasajero\n");
	printf("2)Modificar pasajero\n");
	printf("3)Baja pasajero\n");
	printf("4)Informar lista de pasajeros\n");
	printf("5)Cargar pasajeros de prueba\n");
	printf("6)Salir\n");

	validarInt("\n*Ingrese una opcion* : ", "\n**  Error. Ingrese una opcion valida: ** ",
			   &opcion, 1, 6);

	return opcion;
}

int initPassengers(Passenger *list, int len)
{
	int todoOk = 0;

	if (list != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			list[i].isEmpty = 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int listarPasajeros(Passenger *list, int len)
{
	int todoOk = 0;
	int flag = 0;
	if (list != NULL && len > 0)
	{
		EclipseCls();
		printf(" \n\n         ***   Listado de Pasajeros   ***\n\n");
		printf(" ID      Nombre     Apellido    Precio       Codigo      Tipo         Estado  \n");
		printf("--------------------------------------------------------------------------------\n");
		for (int i = 0; i < len; i++)
		{
			if (!list[i].isEmpty)
			{
				mostrarPasajero(list + i);
				flag = 1;
			}
		}
		if (!flag)
		{
			printf("\n** No hay empleados en el sistema.** ");
		}


		todoOk = 1;
	}
	return todoOk;
}

int mostrarPasajero(Passenger *list)
{
	int todoOk = 0;
	if (list != NULL)
	{
		char tipo[20];
		char estado[20];
		// 1 = First Class    2 = Business  3 = Turista
		if (list->typePassenger == 1)
		{
			strcpy(tipo, "First Class");
		}
		else if (list->typePassenger == 2)
		{
			strcpy(tipo, "Business");
		}
		else
		{
			strcpy(tipo, "Turista");
		}
		// 1 = Activo   2 = Demorado   3 = Cancelado
		if (list->statusFly == 1)
		{
			strcpy(estado, "Activo");
		}
		else if (list->statusFly == 2)
		{
			strcpy(estado, "Demorado");
		}
		else
		{
			strcpy(estado, "Cancelado");
		}
		printf(" %04d %10s  %10s    %6.2f  %10s  %11s   %10s\n", list->id, list->name, list->lastName, list->price, list->flycode, tipo,
			   estado);
		todoOk = 1;
	}
	return todoOk;
}

int isEmpty(Passenger list[], int len, int *pIndex)
{
	int todoOk = 0;
	if (list != NULL && len > 0 && pIndex != NULL)
	{

		*pIndex = -1;
		for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty)
			{
				*pIndex = i;
				break;
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int addPassengers(Passenger *list, int len, int id, char name[], char lastName[], float price, int typePassenger, int statusFly, char flycode[], int *pId, int indice)
{
	int todoOk = 0;
	if (list != NULL && len >= 0 && pId != NULL && name != NULL && lastName != NULL && flycode != NULL && pId != NULL)
	{
		// NOMBRE
		validarTexto("\n** Ingrese nombre: **\n",
					 "\n** Nombre invalido. Reingrese nombre:  ** \n",
					 name, 200);
		ordenarStrings(name);
		// APELLIDO
		validarTexto("\n** Ingrese su apellido: **\n",
					 "\n** Apellido invalido. Reingrese apellido:  ** \n",
					 lastName, 200);
		ordenarStrings(lastName);
		// PRECIO
		validarFloat("\n** Ingrese el precio del vuelo: ** \n",
					 "\n** El precio no es valido. Reingrese el precio del vuelo: ** \n",
					 &price, 0, 99999999);
		// CODIGO
		printf("\n** Ingrese el codigo de vuelo: ** \n");
		fflush(stdin);
		fgets(flycode, 10, stdin);
		limpiarBarraN(flycode, 10);
		// TIPO
		validarInt(
			"\n** Ingrese el tipo de pasajero: 1 = First Class  2 = Business  3 = Turista **  \n",
			"\n** Error al ingresar el tipo. Reingrese el tipo de pasajero: 1 = First Class  2 = Business  3 = Turista  ** \n",
			&typePassenger, 1, 3);
		// ESTADO
		validarInt(
			"\n** Ingrese el estado del vuelo: 1 = Activo   2 = Demorado   3 = Cancelado ** \n",
			"\n** Error. Reingrese el estado del vuelo: 1 = Activo   2 = Demorado   3 = Cancelado ** \n",
			&statusFly, 1, 3);

		id = *pId;
		strcpy((list + indice)->name, name);
		strcpy((list + indice)->lastName, lastName);
		(list + indice)->price = price;
		(list + indice)->typePassenger = typePassenger;
		(list + indice)->statusFly = statusFly;
		strcpy((list + indice)->flycode, flycode);
		(list + indice)->id = id;
		list[indice].isEmpty = 0;
		*pId = *pId + 1;
		todoOk = 1;
	}

	return todoOk;
}

int removePassenger(Passenger *list, int len, int *flagAdd)
{
	int todoOk = 0;
	int id;
	int indice;
	char confirmacion;
	if (list != NULL && len >= 0)
	{
		listarPasajeros(list, len);
		validarInt("\n** Ingrese el ID: ** \n", "\n** Error, reingrese ID: ** \n", &id, 1, 2000);

		while (!findPassengerById(list, len, id, &indice))
		{
			validarInt("\n** Error. No se encontro un pasajero con ese ID, reingrese el ID: ** ", "** Error, Reingrese ID:** ", &id, 1, 2000);
		}
		printf("          ***   Pasajero seleccionado  ***\n\n");
		printf(" ID      Nombre     Apellido    Precio       Codigo      Tipo         Estado  \n");
		printf("--------------------------------------------------------------------------------\n");
		mostrarPasajero(list + indice);
		printf("\n\nEsta seguro que desea remover este pasajero? (si/no): ");
		scanf("%c", &confirmacion);
		if (confirmacion == 's')
		{
			list[indice].isEmpty = 1;
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

int findPassengerById(Passenger *list, int len, int id, int *indice)
{
	int todoOk = 0;

	if (list != NULL && len >= 0)
	{
		*indice = -1;
		for (int i = 0; i < len; i++)
		{
			if (!list[i].isEmpty && list[i].id == id)
			{
				*indice = i;
				todoOk = 1;
				break;
			}
		}
	}
	return todoOk;
}

int menuModificar(Passenger* list)
{
	int opcion;
	EclipseCls();
	printf("          ***   Pasajero seleccionado  ***\n\n");
	printf(" ID      Nombre     Apellido    Precio       Codigo      Tipo         Estado  \n");
	printf("--------------------------------------------------------------------------------\n");
	mostrarPasajero(list);
	printf(" \n\n *** MODIFICACION DE PASAJERO ***\n");
	printf(" \n    *** Menu de Opciones ***\n");
	printf("1) Modificar nombre\n");
	printf("2) Modificar apellido\n");
	printf("3) Modificar precio\n");
	printf("4) Modificar codigo de vuelo\n");
	printf("5) Modificar tipo de pasajero\n");
	printf("6) Modificar estado del vuelo\n");
	printf("7) Volver al menu principal\n");
	validarInt("Ingrese una opcion: ","Error. Opcion invalida. reingrese opcion: ", &opcion, 1, 7);
	return opcion;
}

int modificarPasajero(Passenger *list, int len)
{
	int todoOk = 0;
	int id;
	int indice = -1;
	int confirmacion = 1;

	if(list != NULL && len > 0){

	listarPasajeros(list, len);
	validarInt("\nIngrese el id del usuario que desea modificar: \n",
	"\nError. ID invalido, reingrese ID: \n", &id, 1, 2000);
	findPassengerById(list, len, id, &indice);
	while(indice == -1){
		validarInt("\nError. ID invalido, reingrese ID: \n",
				"\nError. ID invalido, reingrese ID: \n", &id, 1, 2000);
				findPassengerById(list, len, id, &indice);
	}
		do
		{
			switch (menuModificar(list+indice))
			{

			case 1:
				validarTexto("\n **Ingrese el nuevo nombre: ** \n ",
							 "\n ** Error al ingresar el nombre, Reingrese: **\n",
							 list[indice].name, 200);
				ordenarStrings(list[indice].name);
				break;
			case 2:
				validarTexto("\n ** Ingrese su apellido: **",
							 "\n ** Apellido invalido. Reingrese apellido: ** \n",
							 list[indice].lastName, 200);
				ordenarStrings(list[indice].lastName);
				break;
			case 3:
				validarFloat("\n** Ingrese el precio del vuelo: ** \n",
							 "\n** El precio no es valido. Reingrese el precio del vuelo: ** \n",
							 &(list + indice)->price, 0, 99999999);
				break;
			case 4:
				printf("\n** Ingrese el codigo de vuelo: ** \n");
				fflush(stdin);
				fgets(list[indice].flycode, 10, stdin);
				limpiarBarraN(list[indice].flycode, 10);
				break;
			case 5:
				validarInt(
					"\n** Ingrese el tipo de pasajero: 1 = First Class    2 = Business  3 = Turista ** \n",
					"\n** Error al ingresar el tipo. Reingrese el tipo de pasajero: 1 = First Class    2 = Business  3 = Turista ** \n",
					&(list + indice)->typePassenger, 1, 3);
				break;
			case 6:
				validarInt(
					"\n** Ingrese el estado del vuelo:  1 = Activo   2 = Demorado   3 = Cancelado ** \n",
					"\n** Error. Reingrese el estado del vuelo** \n",
					&(list + indice)->statusFly, 1, 3);
				break;
			case 7:
				confirmacion = 0;
				break;
			}

		} while (confirmacion);

		todoOk = 1;
	}
		return todoOk;
	}




int sortPassengers(Passenger *list, int len, int criterio)
{
	int todoOk = 0;
	Passenger listAux;

	if (list != NULL && len > 0 && (criterio == 1 || criterio == 0))
	{

		for (int i = 0; i < len - 1; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (list[i].isEmpty == 0 && list[j].isEmpty == 0)
				{
					if (((list[i].typePassenger == list[j].typePassenger) && strcmp(list[i].lastName, list[j].lastName) > 0 && criterio == UP) 
					|| (list[i].typePassenger != list[j].typePassenger && list[i].typePassenger > list[j].typePassenger && criterio == UP) 
					|| ((list[i].typePassenger == list[j].typePassenger) && strcmp(list[i].lastName, list[j].lastName) < 0 && criterio == DOWN) 
					|| (list[i].typePassenger != list[j].typePassenger && list[i].typePassenger < list[j].typePassenger && criterio == DOWN))
					{
						listAux = list[i];
						list[i] = list[j];
						list[j] = listAux;
					}
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int sortPassengersByCode(Passenger *list, int len, int criterio)
{
	int todoOk = 0;
	Passenger listAux;

	if (list != NULL && len > 0 && (criterio == 1 || criterio == 0))
	{

		for (int i = 0; i < len - 1; i++)
		{
			for (int j = i + 1; j < len; j++)
			{
				if (list[i].isEmpty == 0 && list[j].isEmpty == 0 && list[i].statusFly == 1 && list[j].statusFly == 1)
				{
					if (((list[i].statusFly == list[j].statusFly) && strcmp(list[i].flycode, list[j].flycode) > 0 && criterio == UP) //UP ASCENDENTE
					|| (list[i].statusFly > list[j].statusFly && criterio == UP) 
					|| ((list[i].statusFly == list[j].statusFly) && strcmp(list[i].flycode, list[j].flycode) < 0 && criterio == DOWN) //DOWN DESCENDENTE 
					|| (list[i].statusFly < list[j].statusFly && criterio == DOWN))
					{
						listAux = list[i];
						list[i] = list[j];
						list[j] = listAux;
					}
				}
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int informarPasajeros(Passenger *list, int len)
{
	int todoOk = 0;
	int criterio;
	char salida = 'n';

	if (list != NULL && len > 0)
	{
		do
		{
			switch (menuInformar())
			{
			case 1:
				validarInt("\n** Ingrese el criterio con el que desea ordenar:** 1=Ascendente 0= Descendiente  \n",
						   "\n** Error al ingresar criterio, ingrese nuevamente: ** 1=Ascendente 0= Descendiente  \n",
						   &criterio, 0, 1);
				if (sortPassengers(list, len, criterio))
				{
					printf("\n** Pasajeros ordenados con exito ** \n\n");
					if (listarPasajeros(list, len))
					{
						printf("--------------------------------------------------------------------------------\n\n\n");
					}
					else
					{
						printf("\nError al cargar lista de pasajeros\n");
					}
				}
				else
				{
					printf("\n** Ocurrio un error al ordenar ** ");
				}
				todoOk = 1;
				break;
			case 2:
				if (!calculosPrecios(list, len))
				{
					printf("** Error al calcular los datos de los precios **");
				}
				todoOk = 1;
				break;
			case 3:
				validarInt("\n** Ingrese el criterio con el que desea ordenar: 1=Ascendente 0 = Descendiente ** \n",
						   "\n** Error al ingresar criterio, ingrese nuevamente 1=Ascendente 0 = Descendiente ** \n", &criterio, 0, 1);
				if (sortPassengersByCode(list, len, criterio))
				{
					printf("\n** Pasajeros ordenados con exito ** \n\n ");
					printf(" ID      Nombre     Apellido    Precio       Codigo      Tipo         Estado  \n");
					printf("--------------------------------------------------------------------------------\n");
					for (int i = 0; i < len; i++)
					{
						if (list[i].statusFly == 1 && list[i].isEmpty == 0)
						{
							mostrarPasajero(list + i);
						}
					}
				}
				todoOk = 1;
				break;
			case 4:
				salida = 's';
				todoOk = 1;
				break;
			}
		} while (salida == 'n');
	}
	return todoOk;
}

int menuInformar()
{
	int ordenamiento;
	validarInt("\n** Indique como desea ordenar los pasajeros ** "
			   "\n1) Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero"
			   "\n2) Total y promedio de los precios de los pasajes y cuantos pasajeros superan el precio promedio"
			   "\n3) Listado de los pasajeros por Codigo de vuelo y estados de vuelos Activo"
			   "\n4) Salir\n",
			   "\n** Error, Indique como desea ordenar los pasajeros ** "
			   "\n1) Listado de los pasajeros ordenados alfabeticamente por Apellido y Tipo de pasajero"
			   "\n2) Total y promedio de los precios de los pasajes y cuantos pasajeros superan el precio promedio"
			   "\n3) Listado de los pasajeros por Codigo de vuelo y estados de vuelos Activo"
			   "\n4) Salir\n",
			   &ordenamiento, 1, 4);

	return ordenamiento;
}

int hardcodearPasajeros(Passenger *list, int len, int cantidad, int *pId)
{
	int todoOk = 0;

	Passenger hardcodeo[] = {
		{0000, "Maria", "Gimenez", 15000, "asd123", 2, 3, 0},
		{0000, "Graciela", "Puertas", 11000, "asd124", 2, 3, 0},
		{0000, "Yolanda", "Yoyo", 19000, "asd126", 3, 2, 0},
		{0000, "Alberto", "Abeja", 14000, "asd121", 2, 1, 0},
		{0000, "Zaul", "Zapato", 17000, "asd128", 1, 3, 0},
		{0000, "Oscar", "Oscuro", 13000, "asd122", 3, 1, 0},
		{0000, "Beto", "Bacing", 16000.111, "asd125", 2, 3, 0},
		{0000, "Florencia", "Flag", 18000.56, "asd129", 2, 2, 0},
		{0000, "Matias", "Corta", 12000.333, "asd127", 1, 1, 0},
		{0000, "Sandra", "Fernandez", 20000.250, "asd119", 3, 3, 0}};

	if (list != NULL && len > 0 && cantidad >= 0 && cantidad <= len && pId != NULL)
	{

		for (int i = 0; i < cantidad; i++)
		{
			list[i] = hardcodeo[i];
			list[i].id = *pId;
			*pId = *pId + 1;
		}
		todoOk = 1;
	}
	return todoOk;
}

int calculosPrecios(Passenger *list, int len)
{
	int todoOk = 0;
	float totalPrecio = 0;
	float promedio;
	int contadorPasajeros = 0;
	int contadorEncimaPromedio = 0;

	if (list != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			if (list[i].isEmpty == 0)
			{
				totalPrecio += (list[i].price);
				contadorPasajeros++;
			}
		}
		promedio = (totalPrecio / contadorPasajeros);
		for (int j = 0; j < len; j++)
		{
			if (list[j].isEmpty == 0)
			{
				if (list[j].price > promedio)
				{
					contadorEncimaPromedio++;
				}
			}
		}
		EclipseCls();
		printf("Total        Promedio         N° Pasajeros > promedio  \n");
		printf("--------------------------------------------------------\n");
		printf("%8.2f    %8.2f      %4d\n", totalPrecio, promedio, contadorEncimaPromedio);
		todoOk = 1;
	}
	return todoOk;
}
