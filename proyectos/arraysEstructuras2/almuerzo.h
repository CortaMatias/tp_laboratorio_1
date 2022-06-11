#include "fecha.h"
#include "empleado.h"
#include "comida.h"

#ifndef ALMUERZO_H_INCLUDED
#define ALMUERZO_H_INCLUDED

typedef struct{
    int id;
    int idEmpleado;
    int idComida;
    eFecha fecha;
    int isEmpty;
}eAlmuerzo;

#endif // ALMUERZO_H_INCLUDED

int inicializarAlmuerzos(eAlmuerzo vec[], int tam);
int buscarAlmuerzoLibre(eAlmuerzo vec[], int tam, int* pIndex);
int altaAlmuerzo(eAlmuerzo almuerzos[], int tamA, eEmpleado empleados[], int tamE, eSector sectores[], int tamS, eComida comidas[], int tamC, int* pIdAlmuerzo);
int listarAlmuerzos(eAlmuerzo almuerzos[], int tamA, eEmpleado empleados[], int tamE, eSector sectores[], int tamS, eComida comidas[], int tamC);
