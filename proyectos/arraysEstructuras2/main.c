#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "empleado.h"
#include "sector.h"
#include "comida.h"
#include "almuerzo.h"



#define TAM 10
#define TAMS 5
#define TAMC 5
#define TAMA 50



int main()
{
    //int indice;
    char salir = 'n';
    int proximoLegajo = 10000;
    int proximoIdAlmuerzo = 20000;
    eEmpleado lista[TAM];
    eAlmuerzo almuerzos[TAMA];
    eSector sectores[TAMS] =
    {
        {5000, "Sistemas"},
        {5001, "RRHH"},
        {5002, "Contable"},
        {5003, "Legales"},
        {5004, "Ventas"}
    };

    eComida comidas[TAMC] =
    {
        {7000, "Milanesa", 500},
        {7001, "Ensalada", 600},
        {7002, "Pizza", 450},
        {7003, "Lasagna", 650},
        {7004, "Sopa",  550}
    };

    inicializarEmpleados(lista, TAM);
    inicializarAlmuerzos(almuerzos, TAMA);

    hardcodearEmpleados(lista, TAM, 5, &proximoLegajo);

    do
    {
        switch(menu())
        {

        case 1:
            if( altaEmpleado(lista, TAM, sectores, TAMS, &proximoLegajo))
            {
                printf("Empleado agregado con exito!!!\n");
            }
            else
            {
                printf("Problema al hacer el alta de empleado\n");
            }

            break;
        case 2:
            if( bajaEmpleado(lista, TAM, sectores, TAMS) == 0)
            {
                printf("Problema al hacer la baja de empleado\n");
            }
            break;
        case 3:
            if( modificarEmpleado(lista, TAM, sectores, TAMS) == 0)
            {
                printf("Problema al hacer la modificacion de empleado\n");
            }
            break;

            break;
        case 4:
            printf("Ordenar Empleados\n");
            break;
        case 5:
            listarEmpleados(lista, TAM, sectores, TAMS);
            break;

        case 6:
            listarVarones(lista, TAM, sectores, TAMS);
            break;
        case 7:
            listarMujeres(lista, TAM, sectores, TAMS);
            break;
        case 8:
            listarEmpleadosMayoresA(lista, TAM, sectores, TAMS);
            break;
        case 9:
            informarPromedioSueldos(lista, TAM);
            break;
        case 10:
            informarEmpleadoMayorEdad(lista, TAM, sectores, TAMS);
            break;
        case 11:
            listarSectores(sectores, TAMS);
            break;
        case 12:
            informarEmpleadosSector(lista, TAM, sectores, TAMS);
            break;
        case 13:
            informarEmpleadosXSector(lista, TAM, sectores, TAMS);
            break;
        case 14:
            cantidadEmpleadosSector(lista, TAM, sectores, TAMS);
            break;
        case 15:
            promedioSueldosSectorElegido(lista, TAM, sectores, TAMS);
            break;
        case 16:
            promedioSueldosXSector(lista, TAM, sectores, TAMS);
            break;
        case 17:
            mayorSueldoSector(lista, TAM, sectores, TAMS);
            break;
        case 18:
            sectorQueMasGana(lista, TAM, sectores, TAMS);
            break;
        case 19:
            system("cls");
            listarComidas(comidas, TAMC);
            break;
        case 20:
            if( altaAlmuerzo(almuerzos, TAMA, lista, TAM, sectores, TAMS, comidas, TAMC, &proximoIdAlmuerzo))
            {
                printf("Almuerzo agregado con exito!!!\n");
            }
            else
            {
                printf("Problema al hacer el alta de almuerzo\n");
            }

            break;
        case 21:
            listarAlmuerzos(almuerzos, TAMA, lista, TAM, sectores, TAMS, comidas, TAMC);
            break;
        case 30:
            salir = 's';
            break;
        }
        system("pause");

    }
    while(salir != 's');

    return 0;
}


