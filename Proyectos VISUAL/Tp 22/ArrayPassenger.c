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
    printf(" \n\n *** Menu de Opciones ***\n");

    printf("1) Ingresar pasajero\n");

    printf("2) Modificar datos de un pasajero\n");

    printf("3) Dar de baja un pasajero\n");

    printf("4) Informar lista de pasajeros\n  ");

    validarInt("Ingrese una opcion: ", "Error. Ingrese una opcion valida: ", &opcion, 1, 100);

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

int listarPasajeros(Passenger *list[], int len)
{
    int todoOk = 0;
    int flag = 0;
    if (list != NULL && len > 0)
    {
        // system("cls");
        printf("          *** Listado de Pasajeros ***\n\n");
        printf(" ID    Nombre    Apellido    Precio    Codigo     Tipo     Estado  \n\n");
        printf("-----------------------------------------------------------------\n");
        for (int i = 0; i < len; i++)
        {
            if (!list[i]->isEmpty)
            {
                mostrarPasajero(list[i]);
            }
        }
        if (!flag)
        {
            printf("No hay empleados en el sistema.");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}


int mostrarPasajero(Passenger *list)
{
    int todoOk = 0;
    if (list != NULL)
    {
        printf("  %d       %10s       %s      %f    %s %d %d", list->id, list->name, list->lastName, list->price, list->flycode, list->typePassenger, list->statusFly);
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


int addPassengers(Passenger *list, int len, int *id)
{
    int todoOk = 0;
    int indice;
    if (list != NULL && len >= 0 && id != NULL)
    {
        if (isEmpty(list, len, &indice))
        {
            if (indice == -1)
            {
                printf("No hay espacio disponible");
            }
            else
            {   // NOMBRE
                validarTexto("Ingrese nombre: ", "Nombre demasiado largo. Reingrese nombre: ", list[indice].name, len);
                // APELLIDO
                validarTexto("Ingrese su apellido: ", "Apellido demasiado largo. Reingrese apellido: ",list[indice].lastName, len);
                //PRECIO
                validarFloat("Ingrese el precio del vuelo: ", "El precio no es valido. Reingrese el precio del vuelo: ", &(list+indice)->price, 0, 99999999);
                //CODIGO
                printf("Ingrese el codigo de vuelo: ");
                fflush(stdin);
                fgets(list[indice].flycode, 10, stdin);
                // TIPO
                validarInt("Ingrese el tipo de pasajero: 1 = Turista    2 = Business  3 = First Class ","Error al ingresar el tipo. Reingrese el tipo de pasajero: 1 = Turista    2 = Business  3 = First Class ", (list+indice)->typePassenger, 1,3);
                // ESTADO
                validarInt("Ingrese el estado del vuelo: 1 = Activo   2 = Demorado   3 = Cancelado ","Error. Reingrese el estado del vuelo",(list+indice)->statusFly, 1,3);
                todoOk = 1;
                list[indice].isEmpty = 0;
                list[indice].id = *id;
                *id = *id + 1;
            }
        }
    }else {
        printf("Ocurrio un problema.");
    }
    return todoOk;
}



