#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"
#include "fecha.h"
#include "sector.h"

#define TAM 10
#define TAMS 5

int menu();

int main()
{
    eEmpleado lista[TAM];
    eSector sectores[TAMS] =
    {
        {5000, "Sistemas"},
        {5001, "RRHH"},
        {5002, "Contable"},
        {5003, "Legales"},
        {5004, "Ventas"}
    };

    char salir = 'n';
    int proximoLegajo = 10000;

    inicializarEmpleados(lista, TAM);
    hardcodearEmpleados(lista, TAM, 10, &proximoLegajo);

    do
    {
        switch(menu())
        {
        case 1:
            system("cls");
            if(altaEmpleado(lista, TAM, &proximoLegajo))
            {
                printf("\nEmpleado agregado con exito!!\n\n");
            }
            else
            {
                printf("\nError al realizar el alta del empleado!!\n\n");
            }
            break;
        case 2:
            bajaEmpleado(lista, TAM, sectores, TAMS);
            break;
        case 3:
            modificarEmpleado(lista, TAM, sectores, TAMS);
            break;
        case 4:
            printf("Ordenar empleado\n");
            break;
        case 5:
            listarEmpleados(lista, TAM, sectores, TAMS);
            break;
        case 6:
            listarVarones(lista,TAM,sectores, TAMS);
            break;
        case 7:
            listarMujeres(lista,TAM, sectores, TAMS);
            break;
        case 8:
            listarEmpleadosMayoresA(lista, TAM, sectores, TAMS);
            break;
        case 9:
            informarPromedioSueldos(lista, TAM);
            break;
        case 10:
            informarEmpleadoDeMayorEdad(lista, TAM, sectores, TAMS);
            break;
        case 11:
            listarSectores(sectores, TAMS);
            break;
        case 14:
            salir = 's';
            break;
        default:
            printf("Opcion Incorrecta!!\n");
            break;
        }
        system("pause");
    }while(salir != 's');

    return 0;
}

int menu()
{
    int opcion;
    system("cls");
    printf("      ******ABM Empleados******      \n");
    printf("-------------------------------------\n\n");
    printf("1- Alta Empleado\n");
    printf("2- Baja Empleado\n");
    printf("3- Modificar Empleado\n");
    printf("4- Ordenar Empleados\n");
    printf("5- Listar Empleados\n");
    printf("6- Listar Varones\n");
    printf("7- Listar Mujeres\n");
    printf("8- Listar Empleados mayores a una edad determinada\n");
    printf("9- Informar promedio de Sueldos\n");
    printf("10- Informar empleado de mayor edad\n");
    printf("11- Listar Sectores\n");
    printf("14- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

