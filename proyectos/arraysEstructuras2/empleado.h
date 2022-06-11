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


// abm empleado
int altaEmpleado(eEmpleado vec[], int tam, eSector sectores[], int tamSec, int* pLegajo);
int bajaEmpleado(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int modificarEmpleado(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int cargarEmpleados(eEmpleado vec[], int tam);
int inicializarEmpleados(eEmpleado vec[], int tam);
int buscarEmpleadoLibre(eEmpleado vec[], int tam, int* pIndex);
int buscarEmpleado(eEmpleado vec[], int tam,int legajo, int* pIndex);
int hardcodearEmpleados(eEmpleado vec[], int tam, int cant, int* pLegajo);
int menuModificarEmpleado();
int menu();

// Mostrar Empleados
int mostrarEmpleado(eEmpleado e, eSector sectores[], int tam);
int listarEmpleados(eEmpleado vec[], int tam, eSector sectores[], int tamSec);


//Informes
int listarVarones(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int listarMujeres(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int listarEmpleadosMayoresA(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int informarPromedioSueldos(eEmpleado vec[], int tam);
int informarEmpleadoMayorEdad(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int informarEmpleadosSector(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int cantidadEmpleadosSector(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int promedioSueldosSector(eEmpleado vec[], int tam,eSector sectores[], int tamSec, int idSector, float* pPromedio);
int promedioSueldosSectorElegido(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int promedioSueldosXSector(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int informarEmpleadosXSector(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int mayorSueldoSector(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
int sectorQueMasGana(eEmpleado vec[], int tam,eSector sectores[], int tamSec);
// Ordenamiento
int ordenarEmpleadosLegajoAsc(eEmpleado vec[], int tam);
int ordenarEmpleadosNombreAsc(eEmpleado vec[], int tam);
int ordenarEmpleadosSexoAsc(eEmpleado vec[], int tam);
int ordenarEmpleados(eEmpleado vec[], int tam, int campo, int criterio);
int ordenarEmpleadosPorSexoYLegajo(eEmpleado vec[], int tam);


// sector que mas gana




