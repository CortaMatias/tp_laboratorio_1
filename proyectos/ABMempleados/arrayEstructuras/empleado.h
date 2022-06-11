#include "fecha.h"
#include "sector.h"

#define NOMBRE 0
#define EDAD 1
#define LEGAJO 2
#define SEXO 3
#define SUELDO 4

#define ASC 1
#define DESC 0

#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    int edad;
    float sueldo;
    eFecha fIngreso;
    int idSector;
    int isEmpty;
} eEmpleado;

#endif // EMPLEADO_H_INCLUDED

void mostrarEmpleado(eEmpleado empleado, eSector sectores[], int tams);
int listarEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tams);
int cargarEmpleados(eEmpleado empleados[], int tam);
int ordenarEmpleadosLegajosAsc(eEmpleado empleados[], int tam);
int ordenarEmpleadosNombreAsc(eEmpleado empleados[], int tam);
int ordenarEmpleadosSexo(eEmpleado empleados[], int tam);
int ordenarEmpleados(eEmpleado empleados[], int tam, int campo, int criterio);
int ordenarEmpleadosPorSexoYLegajo(eEmpleado empleados[], int tam);
int inicializarEmpleados(eEmpleado empleados[], int tam);
int buscarLibre(eEmpleado empleados[], int tam, int* pIndex);
int altaEmpleado(eEmpleado empleados[], int tam, int* pProximoLegajo);
int buscarEmpleado(eEmpleado empleados[], int tam, int legajo, int* pIndex);
int bajaEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tams);
int modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tams);
int hardcodearEmpleados(eEmpleado empleados[], int tam, int cant, int* pLegajo);
int menuModificarEmpleado();

//informes

int listarVarones(eEmpleado empleados[], int tam, eSector sectores[], int tams);
int listarMujeres(eEmpleado empleados[], int tam, eSector sectores[], int tams);
int listarEmpleadosMayoresA(eEmpleado empleados[], int tam, eSector sectores[], int tams);
int informarPromedioSueldos(eEmpleado empleados[], int tam);
int informarEmpleadoDeMayorEdad(eEmpleado empleados[], int tam, eSector sectores[], int tams);
