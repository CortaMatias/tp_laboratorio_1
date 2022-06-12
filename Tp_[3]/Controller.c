#include "Controller.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int menu()
{
	int opcion;

	printf("\n\n\n1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n");
	printf("2. Cargar los datos de los pasajeros desde el archivo data.bin (modo binario).\n");
	printf("3. Alta de pasajero\n");
	printf("4. Modificar datos de pasajero\n");
	printf("5. Baja de pasajero\n");
	printf("6. Listar pasajeros\n");
	printf("7. Ordenar pasajeros\n");
	printf("8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).\n");
	printf("9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).\n");
	printf("10. Salir\n");

	validarInt("\n\nIngrese una opcion: ",
			   "\n\nError. Ingrese una opcion valida: ", &opcion, 1, 10);

	return opcion;
}

int controller_loadFromText(char *path, LinkedList *pArrayListPassenger)
{
	int todoOk = 0;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		FILE *data = fopen(path, "r");

		if (data == NULL)
		{
			todoOk = 0;
			printf("error al abrir el archivo\n");
		}
		else
		{
			// Si esta vacio copia lo del archivo a la lista
			if (ll_len(pArrayListPassenger) == 0)
			{
				todoOk = parser_PassengerFromText(data, pArrayListPassenger);
				// si tiene datos, hacemos el backUp
			}
			else
			{
				if (!controller_saveAsText("backUp.csv", pArrayListPassenger))
				{
					printf("Los datos fueron cargados, pero no se pudo hacer el backUp");
					ll_clear(pArrayListPassenger);
					todoOk = parser_PassengerFromText(data, pArrayListPassenger);
				}
				else
				{
					printf("Se han sobre-escrito los datos, se hizo un backUp en \"backUp.csv\"");
					ll_clear(pArrayListPassenger);
					todoOk = parser_PassengerFromText(data, pArrayListPassenger);
				}
			}
		}
		fclose(data);
	}

	return todoOk;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char *path, LinkedList *pArrayListPassenger)
{
	int todoOk = 0;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		FILE *data = fopen(path, "rb");

		if (data == NULL)
		{
			todoOk = 0;
			printf("error al abrir el archivo\n");
		}
		else
		{
			// Si esta vacio copia lo del archivo a la lista
			if (ll_len(pArrayListPassenger) == 0)
			{
				todoOk = parser_PassengerFromBinary(data, pArrayListPassenger);
				// si tiene datos, hacemos el backUp
			}
			else
			{
				if (!controller_saveAsBinary("backUp.bin", pArrayListPassenger))
				{
					printf("Los datos fueron cargados, pero no se pudo hacer el backUp");
					ll_clear(pArrayListPassenger);
					todoOk = parser_PassengerFromBinary(data, pArrayListPassenger);
				}
				else
				{
					printf("Se han sobre-escrito los datos, se hizo un backUp en \"backUp.bin\"");
					ll_clear(pArrayListPassenger);
					todoOk = parser_PassengerFromBinary(data, pArrayListPassenger);
				}
			}
		}
		fclose(data);
	}
	return todoOk;
}

int controller_gestionId(LinkedList *pArrayListPassenger, int id)
{
	Passenger *new;
	int flag = 0;
	int mayorId = 0;
	int tam = ll_len(pArrayListPassenger);

	if (pArrayListPassenger != NULL)
	{
		if (tam == 0 && id <= 0)
		{
			id = 1;
		}
		else
		{
			for (int i = 0; i < tam; i++)
			{
				new = (Passenger *)ll_get(pArrayListPassenger, i);
				if (!flag || new->id > mayorId)
				{
					flag = 1;
					mayorId = new->id;
					id = mayorId + 1;
				}
			}
		}
	}

	return id;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;

	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[7];
	char tipoPasajero[50];
	char estadoDeVuelo[50];
	char precioChar[50];
	int id = 1;

	Passenger *new;

	if (pArrayListPassenger != NULL)
	{

		validarTexto("** Ingrese nombre del pasajero:  **\n",
					 "Error. Reingrese el nombre del pasajero: \n", nombre, 50);
		ordenarStrings(nombre);
		validarTexto("\n** Ingrese su apellido: **\n",
					 "\n** Apellido invalido. Reingrese apellido:  ** \n", apellido,
					 50);
		ordenarStrings(apellido);
		validarFloat("\n** Ingrese el precio del vuelo: ** \n",
					 "\n** El precio no es valido. Reingrese el precio del vuelo: ** \n",
					 &precio, 1, 100000000);

		validarTexto(
			"\n** Ingrese el tipo de pasajero:  FirstClass o ExecutiveClass o EconomicClass **  \n",
			"\n** Error. ReIngrese el tipo de pasajero:  FirstClass o ExecutiveClass o EconomicClass ** \n",
			tipoPasajero, 50);
		ordenarStrings(tipoPasajero);

		while (strcmp(tipoPasajero, "Firstclass") != 0 && strcmp(tipoPasajero, "Executiveclass") != 0 && strcmp(tipoPasajero, "Economicclass") != 0)
		{
			validarTexto(
				"\n** Error. ReIngrese el tipo de pasajero:  FirstClass o ExecutiveClass o EconomicClass **  \n",
				"\n** Error. ReIngrese el tipo de pasajero:  FirstClass o ExecutiveClass o EconomicClass ** \n",
				tipoPasajero, 50);
			ordenarStrings(tipoPasajero);
		}
		validarTexto(
			"\n** Ingrese el estado del vuelo:  En horario o Demorado o Aterrizado o En Vuelo ** \n",
			"\n** Error. ReIngrese el estado del vuelo:  En horario o Demorado o Aterrizado o En Vuelo ** \n",
			estadoDeVuelo, 50);
		ordenarStrings(estadoDeVuelo);

		while (strcmp(estadoDeVuelo, "En horario") != 0 && strcmp(estadoDeVuelo, "Demorado") != 0 && strcmp(estadoDeVuelo, "Aterrizado") != 0 && strcmp(estadoDeVuelo, "En vuelo"))
		{
			validarTexto("\n** Error. ReIngrese el estado del vuelo:  En horario o Demorado o Aterrizado  o En Vuelo**  \n",
						 "\n** Error. ReIngrese el estado del vuelo:  En horario o Demorado o Aterrizado o En Vuelo** \n",
						 estadoDeVuelo, 50);
			ordenarStrings(estadoDeVuelo);
		}

		validarAlfaNumerico("Ingrese el codigo de vuelo: \n",
							"Error. Reingrese codigo de vuelo: \n", codigoDeVuelo, 8);

		sprintf(precioChar, "%f", precio);

		id = controller_gestionId(pArrayListPassenger, id);
		ordenarStringsTp3(tipoPasajero);
		ordenarStringsTp3(estadoDeVuelo);
		new = Passenger_newParametros(id, nombre, apellido, precioChar,
									  codigoDeVuelo, tipoPasajero, estadoDeVuelo);

		if (new != NULL)
		{

			ll_add(pArrayListPassenger, new);
			todoOk = 1;
		}
	}
	return todoOk;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	int opcion;
	int id;
	Passenger *new;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[7];
	char tipoPasajero[50];
	char estadoDeVuelo[50];

	if (pArrayListPassenger != NULL)
	{
		if (controller_ListPassenger(pArrayListPassenger))
		{

			validarInt("\n\nIngrese el id del pasajero que desea modificar: \n\n",
					   "\n\nError. ReIngrese un id valido del pasajero que desea modificar: \n\n",
					   &id, 1, 5000);

			if (ll_len(pArrayListPassenger) > 0)
			{
				for (int i = 0; i < ll_len(pArrayListPassenger); i++)
				{
					new = (Passenger *)ll_get(pArrayListPassenger, i);

					if (new->id == id)
					{
						do
						{
							controller_showPassenger(new);
							switch (menuEdit())
							{
							case 1:
								validarTexto("** Ingrese nombre del pasajero:  **\n",
											 "Error. Reingrese el nombre del pasajero: \n", nombre, 50);
								ordenarStrings(nombre);
								Passenger_setNombre(new, nombre);
								break;
							case 2:
								validarTexto("\n** Ingrese su apellido: **\n",
											 "\n** Apellido invalido. Reingrese apellido:  ** \n",
											 apellido, 50);
								ordenarStrings(apellido);
								Passenger_setApellido(new, apellido);
								break;
							case 3:
								validarFloat(
									"\n** Ingrese el precio del vuelo: ** \n",
									"\n** El precio no es valido. Reingrese el precio del vuelo: ** \n",
									&precio, 1, 100000000);
								Passenger_setPrecio(new, precio);
								break;
							case 5:
								validarTexto(
									"\n** Ingrese el tipo de pasajero:  FirstClass o ExecutiveClass o EconomyClass **  \n",
									"\n** Error. ReIngrese el tipo de pasajero:  FirstClass o ExecutiveClass o EconomyClass ** \n",
									tipoPasajero, 50);
								ordenarStrings(tipoPasajero);
								while (strcmp(tipoPasajero, "Firstclass") != 0 && strcmp(tipoPasajero, "Executiveclass") != 0 && strcmp(tipoPasajero, "Economyclass") != 0)
								{
									validarTexto(
										"\n** Error. ReIngrese el tipo de pasajero:  FirstClass o ExecutiveClass o EconomyClass **  \n",
										"\n** Error. ReIngrese el tipo de pasajero:  FirstClass o ExecutiveClass o EconomyClass ** \n",
										tipoPasajero, 50);
									ordenarStrings(tipoPasajero);
								}
								ordenarStringsTp3(tipoPasajero);
								Passenger_setTipoPasajero(new, tipoPasajero);
								break;
							case 6:
								validarTexto(
									"\n** Ingrese el estado del vuelo:  En horario o Demorado o Aterrizado o En Vuelo ** \n",
									"\n** Error. ReIngrese el estado del vuelo:  En horario o Demorado o Aterrizado o En Vuelo ** \n",
									estadoDeVuelo, 50);
								ordenarStrings(estadoDeVuelo);

								while (strcmp(estadoDeVuelo, "En horario") != 0 && strcmp(estadoDeVuelo, "Demorado") != 0 && strcmp(estadoDeVuelo, "Aterrizado") != 0 && strcmp(estadoDeVuelo, "En vuelo"))
								{
									validarTexto("\n** Error. ReIngrese el estado del vuelo:  En horario o Demorado o Aterrizado  o En Vuelo**  \n",
												 "\n** Error. ReIngrese el estado del vuelo:  En horario o Demorado o Aterrizado o En Vuelo** \n",
												 estadoDeVuelo, 50);
									ordenarStrings(estadoDeVuelo);
								}
								ordenarStringsTp3(estadoDeVuelo);
								Passenger_setEstadoDeVuelo(new, estadoDeVuelo);
								break;
							case 4:
								validarAlfaNumerico(
									"Ingrese el codigo de vuelo: \n",
									"Error. Reingrese codigo de vuelo: \n",
									codigoDeVuelo, 8);
								Passenger_setCodigoVuelo(new, codigoDeVuelo);
								break;
							case 7:
								opcion = 7;
								todoOk = 1;
								break;
							}

						} while (opcion != 7);
					}
				}
			}
		}
	}

	return todoOk;
}

int menuEdit()
{
	int opcion;

	printf("\n\n\n1. Modificar nombre\n");
	printf("2. Modificar apellido\n");
	printf("3. Modificar precio\n");
	printf("4. Modificar codigo de vuelo\n");
	printf("5. Modificar tipo de pasajero\n");
	printf("6. Modificar estado de vuelo\n");
	printf("7. Salir\n");

	validarInt("\n\nIngrese una opcion: ",
			   "\n\nError. Ingrese una opcion valida: ", &opcion, 1, 7);
	return opcion;
}
/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	int id;
	Passenger *new;
	char confirma;

	if (pArrayListPassenger != NULL)
	{

		if (controller_ListPassenger(pArrayListPassenger))
		{

			validarInt("\n\nIngrese el id del pasajero que desea borrar: \n",
					   "\n\nError ReIngrese un id valido del pasajero que desea borrar: \n",
					   &id, 1, 5000);

			if (ll_len(pArrayListPassenger) > 0)
			{
				for (int i = 0; i < ll_len(pArrayListPassenger); i++)
				{
					new = (Passenger *)ll_get(pArrayListPassenger, i);

					if (new->id == id)
					{
						controller_showPassenger(new);
						printf(
							"\n\nDesea eliminar este pasajero? (si o no)\n\n");
						fflush(stdin);
						fgets(&confirma, 2, stdin);
						if (confirma == 's')
						{
							ll_remove(pArrayListPassenger, i);
							printf("\n\nPasajero removido con exito\n");
						}
						else
						{
							printf("\n\nBaja cancelada\n");
						}
					}
				}
			}
		}
	}
	return todoOk;
}

/** \brief Listar pasajeros
 *
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	Passenger *pasajero;

	if (pArrayListPassenger != NULL)
	{
		if (ll_len(pArrayListPassenger) > 0)
		{
			printf("%-4s %-20s %-20s %-9s %-8s %-15s %-10s\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO", "TIPO", "ESTADO");
			printf("--------------------------------------------------------------------------------------------\n");
			for (int i = 0; i < ll_len(pArrayListPassenger); i++)
			{
				pasajero = (Passenger *)ll_get(pArrayListPassenger, i);
				printf("%-4d %-20s %-20s %7.2f %-8s %-15s %-10s\n", pasajero->id,
					   pasajero->nombre, pasajero->apellido, pasajero->precio,
					   pasajero->codigoDeVuelo, pasajero->tipoPasajero,
					   pasajero->estadoDeVuelo);
			}
			todoOk = 1;
		}
		else
		{
			printf("agrege pasajeros a antes de listarlos o cargue un archivo correctamente\n");
		}
	}

	return todoOk;
}

int controller_showPassenger(Passenger *pasajero)
{
	int todoOk = 0;

	if (pasajero != NULL)
	{
		printf("%-4s %-20s %-20s %-9s %-8s %-15s %-10s\n", "ID", "NOMBRE", "APELLIDO", "PRECIO", "CODIGO", "TIPO", "ESTADO");
		printf("---------------------------------------------------------------------------------------\n\n");
		printf("%-4d %-20s %-20s %.4f %-8s %-15s %-10s\n", pasajero->id,
			   pasajero->nombre, pasajero->apellido, pasajero->precio,
			   pasajero->codigoDeVuelo, pasajero->tipoPasajero,
			   pasajero->estadoDeVuelo);
		todoOk = 1;
	}
	return todoOk;
}



































































































































































































































































































































/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	int r;
	int criterio;
	if (pArrayListPassenger != NULL)
	{
		validarInt(
			"\n\nIngrese el criterio con el que desea ordenar la lista:  1 = Ascendente   0 = Descendente\n",
			"\nError. Ingrese el criterio con el que desea ordenar la lista:  1 = Ascendente   0 = Descendente\n",
			&criterio, 0, 1);

		switch (menuSort())
		{
		case 1:
			r = ll_sort(pArrayListPassenger, controller_SortId, criterio);
			break;
		case 2:
			r = ll_sort(pArrayListPassenger, controller_SortNombre, criterio);
			break;
		case 3:
			r = ll_sort(pArrayListPassenger, controller_SortApellido, criterio);
			break;
		case 4:
			r = ll_sort(pArrayListPassenger, controller_SortPrecio, criterio);
			break;
		case 5:
			r = ll_sort(pArrayListPassenger, controller_SortCodigo, criterio);
			break;
		case 6:
			r = ll_sort(pArrayListPassenger, controller_SortTipo, criterio);
			break;
		case 7:
			r = ll_sort(pArrayListPassenger, controller_SortEstado, criterio);
			break;
		}
		if (!r)
		{
			printf("\nLos datos fueron ordenados con exito\n");
			todoOk = 1;
		}
		else if (r == -1)
		{
			printf("\nError al ordenar los datos\n");
		}
	}
	return todoOk;
}

int menuSort()
{
	int opcion;

	printf("\n\n\n1.Ordenar lista por ID\n");
	printf("2.Ordenar lista por nombre \n");
	printf("3.Ordenar lista por apellido \n");
	printf("4.Ordenar lista por precio \n");
	printf("5.Ordenar lista por codigo de vuelo \n");
	printf("6.Ordenar lista por tipo de pasajero \n");
	printf("7.Ordenar lista por estado del vuelo \n");

	validarInt("\n\nIngrese una opcion: ",
			   "\n\nError. Ingrese una opcion valida: ", &opcion, 1, 7);

	return opcion;
}

int controller_SortNombre(void *nombre1, void *nombre2)
{

	if (nombre1 != NULL && nombre2 != NULL)
	{

		if (strcmp(((Passenger *)nombre1)->nombre,
				   ((Passenger *)nombre2)->nombre) > 0)
		{
			return 1;
		}
		if (strcmp(((Passenger *)nombre1)->nombre,
				   ((Passenger *)nombre2)->nombre) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int controller_SortApellido(void *pasajero1, void *pasajero2)
{

	if (pasajero1 != NULL && pasajero2 != NULL)
	{

		if (strcmp(((Passenger *)pasajero1)->apellido,
				   ((Passenger *)pasajero2)->apellido) > 0)
		{
			return 1;
		}
		if (strcmp(((Passenger *)pasajero1)->apellido,
				   ((Passenger *)pasajero2)->apellido) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int controller_SortTipo(void *pasajero1, void *pasajero2)
{

	if (pasajero1 != NULL && pasajero2 != NULL)
	{

		if (strcmp(((Passenger *)pasajero1)->tipoPasajero,
				   ((Passenger *)pasajero2)->tipoPasajero) > 0)
		{
			return 1;
		}
		if (strcmp(((Passenger *)pasajero1)->tipoPasajero,
				   ((Passenger *)pasajero2)->tipoPasajero) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int controller_SortEstado(void *pasajero1, void *pasajero2)
{

	if (pasajero1 != NULL && pasajero2 != NULL)
	{

		if (strcmp(((Passenger *)pasajero1)->estadoDeVuelo,
				   ((Passenger *)pasajero2)->estadoDeVuelo) > 0)
		{
			return 1;
		}
		if (strcmp(((Passenger *)pasajero1)->estadoDeVuelo,
				   ((Passenger *)pasajero2)->estadoDeVuelo) < 0)
		{
			return -1;
		}
	}
	return 0;
}



int controller_SortCodigo(void *pasajero1, void *pasajero2)
{

	if (pasajero1 != NULL && pasajero2 != NULL)
	{

		if (strcmp(((Passenger *)pasajero1)->codigoDeVuelo,
				   ((Passenger *)pasajero2)->codigoDeVuelo) > 0)
		{
			return 1;
		}
		if (strcmp(((Passenger *)pasajero1)->codigoDeVuelo,
				   ((Passenger *)pasajero2)->codigoDeVuelo) < 0)
		{
			return -1;
		}
	}
	return 0;
}

int controller_SortId(void *pasajero1, void *pasajero2)
{

	if (pasajero1 != NULL && pasajero2 != NULL)
	{

		if (((Passenger *)pasajero1)->id > ((Passenger *)pasajero2)->id)
		{
			return 1;
		}
		if (((Passenger *)pasajero1)->id < ((Passenger *)pasajero2)->id)
		{
			return -1;
		}
	}
	return 0;
}

int controller_SortPrecio(void *pasajero1, void *pasajero2)
{

	if (pasajero1 != NULL && pasajero2 != NULL)
	{

		if (((Passenger *)pasajero1)->precio > ((Passenger *)pasajero2)->precio)
		{
			return 1;
		}
		if (((Passenger *)pasajero1)->precio < ((Passenger *)pasajero2)->precio)
		{
			return -1;
		}
	}
	return 0;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char *path, LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	Passenger *pasajero;
	if (path != NULL && pArrayListPassenger != NULL)
	{
		FILE *data = fopen(path, "a");
		if (data == NULL)
		{
			todoOk = 0;
			printf("error al abrir el archivo\n");
		}
		else if (ll_len(pArrayListPassenger) > 0)
		{
			for (int i = 0; i < ll_len(pArrayListPassenger); i++)
			{
				pasajero = (Passenger *)ll_get(pArrayListPassenger, i);
				fprintf(data, "%d,%s,%s,%f,%s,%s,%s\n", pasajero->id,
						pasajero->nombre, pasajero->apellido, pasajero->precio,
						pasajero->codigoDeVuelo, pasajero->tipoPasajero,
						pasajero->estadoDeVuelo);
			}
			todoOk = 1;
			fclose(data);
		}
	}
	return todoOk;
}
/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char *path, LinkedList *pArrayListPassenger)
{
	int todoOk = 0;
	Passenger *pasajero;

	if (path != NULL && pArrayListPassenger != NULL)
	{
		FILE *data = fopen(path, "ab");
		int cant;
		if (data == NULL)
		{
			todoOk = 0;
			printf("error al abrir el archivo\n");
		}

		if (ll_len(pArrayListPassenger) > 0)
		{
			for (int i = 0; i < ll_len(pArrayListPassenger); i++)
			{
				pasajero = (Passenger *)ll_get(pArrayListPassenger, i);
				cant = fwrite(pasajero, sizeof(Passenger), 1, data);
				if (cant != 1)
				{
					break;
				}
			}
			todoOk = 1;
			fclose(data);
		}
	}
	return todoOk;
}
