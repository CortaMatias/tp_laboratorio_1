/*
 * Passenger.c
 *
 *  Created on: 19 may. 2022
 *      Author: Maru
 */

#include "../inc/Passenger.h"

Passenger *Passenger_new()
{
	Passenger *pasajero = (Passenger *)malloc(sizeof(Passenger));
	return pasajero;
}

Passenger *Passenger_newParametros(int id, char *nombre, char *apellido, char *precio, char *codigoDeVuelo, char *tipoPasajero, char *estadoDeVuelo)
{

	Passenger *new;
	new = Passenger_new();

	if (new != NULL && nombre != NULL &&apellido != NULL &&precio != NULL &&codigoDeVuelo != NULL &&tipoPasajero != NULL &&estadoDeVuelo != NULL)
	{
		if (!Passenger_setId(new, id)
			|| !Passenger_setNombre(new, nombre)
			|| !Passenger_setApellido(new, apellido)
			|| !Passenger_setPrecio(new, atof(precio))
			|| !Passenger_setCodigoVuelo(new, codigoDeVuelo)
			|| !Passenger_setTipoPasajero(new, tipoPasajero)
			|| !Passenger_setEstadoDeVuelo(new, estadoDeVuelo))
		{
			Passenger_delete(new);
		}
	}
	return new;
}

void Passenger_delete(Passenger *this)
{
	if (this != NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger *this, int id)
{
	int todoOk = 0;
	if (this != NULL && id > 0)
	{
		this->id = id;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getId(Passenger *this, int *id)
{
	int todoOk = 0;
	if (this != NULL && id != NULL)
	{
		*id = this->id;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setNombre(Passenger *this, char *nombre)
{
	int todoOk = 0;
	if (this != NULL && nombre != NULL && strlen(nombre) > 1)
	{
		strcpy(this->nombre, nombre);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getNombre(Passenger *this, char *nombre)
{
	int todoOk = 0;
	if (this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setApellido(Passenger *this, char *apellido)
{
	int todoOk = 0;
	if (this != NULL && apellido != NULL && strlen(apellido) > 1)
	{
		strcpy(this->apellido, apellido);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getApellido(Passenger *this, char *apellido)
{
	int todoOk = 0;
	if (this != NULL && apellido != NULL)
	{
		strcpy(apellido, this->apellido);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setPrecio(Passenger *this, float precio)
{
	int todoOk = 0;
	if (this != NULL && precio > 0)
	{
		this->precio = precio;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getPrecio(Passenger *this, float *precio)
{
	int todoOk = 0;
	if (this != NULL && precio != NULL)
	{
		*precio = this->precio;
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setCodigoVuelo(Passenger *this, char *codigoDeVuelo)
{
	int todoOk = 0;
	if (this != NULL && codigoDeVuelo != NULL && strlen(codigoDeVuelo) > 1)
	{
		strcpy(this->codigoDeVuelo, codigoDeVuelo);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getCodigoVuelo(Passenger *this, char *codigoDeVuelo)
{
	int todoOk = 0;
	if (this != NULL && codigoDeVuelo != NULL)
	{
		strcpy(codigoDeVuelo, this->codigoDeVuelo);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setTipoPasajero(Passenger *this, char *tipoPasajero)
{
	int todoOk = 0;
	if (this != NULL && tipoPasajero != NULL && strlen(tipoPasajero) > 1)
	{
		strcpy(this->tipoPasajero, tipoPasajero);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_getTipoPasajero(Passenger *this, char *tipoPasajero)
{
	int todoOk = 0;
	if (this != NULL && tipoPasajero != NULL)
	{
		strcpy(tipoPasajero, this->tipoPasajero);
		todoOk = 1;
	}
	return todoOk;
}

int Passenger_setEstadoDeVuelo(Passenger *this, char *estadoDeVuelo)
{
	int todoOk = 0;
	if (this != NULL && estadoDeVuelo != NULL && strlen(estadoDeVuelo) > 1)
	{
		strcpy(this->estadoDeVuelo, estadoDeVuelo);
		todoOk = 1;
	}
	return todoOk;
}
int Passenger_getEstadoDeVuelo(Passenger *this, char *estadoDeVuelo)
{
	int todoOk = 0;
	if (this != NULL && estadoDeVuelo != NULL)
	{
		strcpy(estadoDeVuelo, this->estadoDeVuelo);
		todoOk = 1;
	}
	return todoOk;
}

int cargarDescripcionTipo(int tipo, char *descripcion)
{

	int todoOk = 0;

	if (descripcion != NULL)
	{
		if (tipo == 1)
		{
			strcpy(descripcion, "First Class");
		}
		else if (tipo == 2)
		{
			strcpy(descripcion, "Executive Class");
		}
		else
		{
			strcpy(descripcion, "Economic Class");
		}
		todoOk = 1;
	}
	return todoOk;
}

int cargarDescripcionEstado(int estado, char *descripcion)
{

	int todoOk = 0;

	if (descripcion != NULL)
	{
		if (estado == 1)
		{
			strcpy(descripcion, "En horario");
		}
		else if (estado == 2)
		{
			strcpy(descripcion, "Demorado");
		}
		else
		{
			strcpy(descripcion, "Aterrizado");
		}
		todoOk = 1;
	}
	return todoOk;
}
