#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

void mostrarEmpleado(eEmpleado e)
{

    printf("  %4d       %10s       %c      %2d    %9.2f\n", e.legajo, e.nombre, e.sexo, e.edad, e.sueldo);

}


int listarEmpleados(eEmpleado vec[], int tam)
{
    int todoOk = 0;
    if(vec != NULL && tam > 0)
    {
        //system("cls");
        printf("          *** Listado de Empleados ***\n\n");
        printf(" Legajo       Nombre        Sexo    Edad    Sueldo\n");
        printf("-----------------------------------------------------\n");
        for(int i=0; i < tam; i++)
        {
            mostrarEmpleado(vec[i]);
        }
        printf("\n\n");

        todoOk = 1;
    }
    return todoOk;
}



int cargarEmpleados(eEmpleado vec[], int tam)
{
    int todoOk = 0;
    char auxCad[100];
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam; i++)
        {
            printf("Ingrese legajo: ");
            scanf("%d", &vec[i].legajo);

            printf("Ingrese el nombre del alumno: ");
            fflush(stdin);
            gets(auxCad);

            while(strlen(auxCad) >= 20)
            {
                printf("Nombre demasiado largo. Reingrese nombre: ");
                fflush(stdin);
                gets(auxCad);
            }
            strcpy(vec[i].nombre, auxCad);


            printf("Ingrese sexo('m' o 'f'): ");
            fflush(stdin);
            scanf("%c", &vec[i].sexo);

            printf("Ingrese edad: ");
            scanf("%d", &vec[i].edad);

            printf("Ingrese sueldo: ");
            scanf("%f", &vec[i].sueldo);
        }

        todoOk = 1;
    }
    return todoOk;
}

int ordenarEmpleadosLegajoAsc(eEmpleado vec[], int tam){
 int todoOk = 0;
 eEmpleado auxEmpleado;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++){
            for(int j= i + 1; j < tam; j++){
                if(vec[i].legajo > vec[j].legajo){
                        auxEmpleado = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxEmpleado;
                }
            }
        }
      todoOk = 1;
    }
    return todoOk;
}

int ordenarEmpleadosNombreAsc(eEmpleado vec[], int tam){
 int todoOk = 0;
 eEmpleado auxEmpleado;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++){
            for(int j= i + 1; j < tam; j++){
                if(strcmp(vec[i].nombre, vec[j].nombre) > 0){
                        auxEmpleado = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxEmpleado;
                }
            }
        }
      todoOk = 1;
    }
    return todoOk;
}

int ordenarEmpleadosSexoAsc(eEmpleado vec[], int tam){
 int todoOk = 0;
 eEmpleado auxEmpleado;
    if(vec != NULL && tam > 0)
    {
        for(int i=0; i < tam -1; i++){
            for(int j= i + 1; j < tam; j++){
                if(vec[i].sexo > vec[j].sexo){
                        auxEmpleado = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxEmpleado;
                }
            }
        }
      todoOk = 1;
    }
    return todoOk;
}




int ordenarEmpleados(eEmpleado vec[], int tam, int campo, criterio){
int todoOk = 0;
 eEmpleado auxEmpleado;
    if(vec != NULL && tam > 0 && campo >= 0 && campo <= 4 && criterio >= 0 && criterio <=1)
    {
    for(int i=0; i < tam -1; i++){
            for(int j= i + 1; j < tam; j++){
                if(strcmp(vec[i].nombre, vec[j].nombre) > 0 && campo == 0 && criterio == 1 )
                    || (strcmp(vec[i].nombre, vec[j].nombre) < 0 && campo == 0 && criterio == 0)
                    || (strcmp(vec[i].edad > vec[j].edad) > 0 && campo == 1 && criterio == 1)
                    || (strcmp(vec[i].edad < vec[j].edad) > 0 && campo == 1 && criterio == 0){
                    || (strcmp(vec[i].edad > vec[j].edad) > 0 && campo == 1 && criterio == 1)
                    || (strcmp(vec[i].edad < vec[j].edad) > 0 && campo == 1 && criterio == 0)
                        auxEmpleado = vec[i];
                        vec[i] = vec[j];
                        vec[j] = auxEmpleado;
                }
            }
    }
todoOk = 1;
    }
    return todoOk;
}

