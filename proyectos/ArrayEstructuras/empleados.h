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
} eEmpleado;


#endif // EMPLEADO_H_INCLUDED

void mostrarEmpleado(eEmpleado empleado);
int listarEmpleados(eEmpleado vec[], int tam);
int cargarEmpleados(eEmpleado vec[], int tam);
int ordenarEmpleadosLegajoAsc(eEmpleado vec[], int tam);
int ordenarEmpleadosNombreAsc(eEmpleado vec[], int tam);
int ordenarEmpleadosSexoAsc(eEmpleado vec[], int tam);

int ordenarEmpleadosSexoAsc(eEmpleado vec[], int tam, int campo, criterio);


