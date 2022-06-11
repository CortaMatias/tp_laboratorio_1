#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "empleado.h"

#define TAM 5

int main()
{
    eEmpleado lista[TAM] ={
        {4356, "Juan", 'm', 30, 100000},
        {5478, "Daniela", 'f', 23, 120000},
        {1123, "Lucia", 'f', 20, 140000},
        {2309, "Mauro", 'm', 27, 120000},
        {8769, "Diego", 'm', 27, 110000}
    };

    //cargarEmpleados(lista, TAM);
    listarEmpleados(lista, TAM);

    //ordenarEmpleadosLegajoAsc(lista, TAM);
    //ordenarEmpleadosNombreAsc(lista, TAM);
    ordenarEmpleadosSexoAsc(lista, TAM);

    listarEmpleados(lista, TAM);


    return 0;
}





