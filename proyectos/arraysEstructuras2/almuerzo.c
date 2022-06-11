#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "almuerzo.h"

int inicializarAlmuerzos(eAlmuerzo vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarAlmuerzoLibre(eAlmuerzo vec[], int tam, int* pIndex)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0 && pIndex != NULL)
    {
        *pIndex = -1;
        for(int i=0; i < tam; i++)
        {
            if( vec[i].isEmpty )
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}




int altaAlmuerzo(eAlmuerzo almuerzos[], int tamA, eEmpleado empleados[], int tamE, eSector sectores[], int tamS, eComida comidas[], int tamC, int* pIdAlmuerzo){
    int todoOk = 0;
    int indice;
    eAlmuerzo nuevoAlmuerzo;
    eFecha fecha;

    if(almuerzos != NULL && sectores != NULL && comidas != NULL && empleados != NULL && pIdAlmuerzo != NULL && tamA > 0 && tamE > 0 && tamC > 0 && tamS > 0)
    {

        system("cls");
        printf("       *** Alta Almuerzo *** \n");
        printf("-------------------------------------------\n\n");


        if( buscarAlmuerzoLibre(almuerzos, tamA, &indice) )
        {
            if(indice == - 1)
            {
                printf("No hay lugar en el sistema\n");
            }
            else
            {
                // aca caigo cuando haya lugar
                listarEmpleados(empleados, tamE, sectores, tamS);
                printf("Ingrese id empleado\n");
                scanf("%d", &nuevoAlmuerzo.idEmpleado);
                buscarEmpleado(empleados, tamE, nuevoAlmuerzo.idEmpleado, &indice);

                while( indice == -1){
                printf("Empleado invalido. Ingrese id empleado\n");
                scanf("%d", &nuevoAlmuerzo.idEmpleado);
                buscarEmpleado(empleados, tamE, nuevoAlmuerzo.idEmpleado, &indice);
                }

                listarComidas(comidas, tamC);
                printf("Ingrese id comida\n");
                scanf("%d", &nuevoAlmuerzo.idComida);

                while( !validarComida(comidas, tamC, nuevoAlmuerzo.idComida )){
                printf("Comida invalido. Ingrese id comida\n");
                scanf("%d", &nuevoAlmuerzo.idComida);
                }

                printf("Ingrese Fecha  dd/mm/aaaa: ");
                scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);
                nuevoAlmuerzo.fecha = fecha;

                nuevoAlmuerzo.isEmpty = 0;
                nuevoAlmuerzo.id = *pIdAlmuerzo;
                *pIdAlmuerzo = *pIdAlmuerzo + 1;
                almuerzos[indice] = nuevoAlmuerzo;
                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros\n");
        }
    }
    return todoOk;
}

int listarAlmuerzos(eAlmuerzo almuerzos[], int tamA, eEmpleado empleados[], int tamE, eSector sectores[], int tamS, eComida comidas[], int tamC)
{
    int todoOk = 0;
    int flag = 0;
    char descripcion[20];

     if(almuerzos != NULL && sectores != NULL && comidas != NULL && empleados != NULL  && tamA > 0 && tamE > 0 && tamC > 0 && tamS > 0)
    {
        system("cls");
        printf("          *** Listado de Almuerzos ***\n\n");
        printf("  Id          IdEmpleado        Comida    Fecha\n");
        printf("--------------------------------------------------------------------------------\n");
        for(int i=0; i < tamA; i++)
        {
            if( !almuerzos[i].isEmpty )
            {
                cargarDescripcionComida(comidas, tamC, almuerzos[i].idComida, descripcion);
                printf("   %d     %d      %10s          %02d/%02d/%02d\n", almuerzos[i].id, almuerzos[i].idEmpleado, descripcion, almuerzos[i].fecha.dia, almuerzos[i].fecha.mes, almuerzos[i].fecha.anio);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("       No hay almuerzos en el sistema");
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}







