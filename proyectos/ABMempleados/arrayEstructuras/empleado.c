#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "empleado.h"

void mostrarEmpleado(eEmpleado empleado, eSector sectores[], int tams)
{
    char descSector[20];

    cargarDescripcionSector(sectores, tams, empleado.idSector, descSector);

    printf(" %4d   %-16s  %c     %2d   %9.2f    %02d/%02d/%d   %-10s\n", empleado.legajo, empleado.nombre, empleado.sexo, empleado.edad, empleado.sueldo,
           empleado.fIngreso.dia, empleado.fIngreso.mes, empleado.fIngreso.anio, descSector);
}

int listarEmpleados(eEmpleado empleados[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int flag = 0;
    if(empleados != NULL && tam>0)
    {
        printf("      ******Listado de Empleados******      \n\n");
        printf("Legajo  Nombre            Sexo  Edad   Sueldo      F.Ingreso    Sector\n");
        for(int i=0; i<tam; i++)
        {
            if(empleados[i].isEmpty == 0)
            {
                mostrarEmpleado(empleados[i], sectores, tams);
                flag++;
            }
        }
        if(flag == 0)
        {
            printf("No hay empleados en el sistema!!\n");
        }
    }

    return todoOk;
}

int cargarEmpleados(eEmpleado empleados[], int tam)
{
    int todoOk = 0;
    if(empleados != NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            system("cls");
            printf("Ingrese legajo: ");
            scanf("%d", &empleados[i].legajo );

            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(empleados[i].nombre);

            printf("Ingrese sexo: ");
            fflush(stdin);
            scanf("%c", &empleados[i].sexo);

            printf("Ingrese Edad: ");
            scanf("%d", &empleados[i].edad);

            printf("Ingrese Sueldo: ");
            scanf("%f", &empleados[i].sueldo);
        }

        todoOk = 1;
    }
    return todoOk;
}

int ordenarEmpleadosLegajosAsc(eEmpleado empleados[], int tam)
{
    int todoOk = 0;
    eEmpleado auxEmpleado;

    if(empleados!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(empleados[i].legajo>empleados[j].legajo)
                {
                    auxEmpleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxEmpleado;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarEmpleadosNombreAsc(eEmpleado empleados[], int tam)
{
    int todoOk = 0;
    eEmpleado auxEmpleado;

    if(empleados!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(strcmp(empleados[i].nombre, empleados[j].nombre)>0)
                {
                    auxEmpleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxEmpleado;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarEmpleadosSexo(eEmpleado empleados[], int tam)
{
    int todoOk = 0;
    eEmpleado auxEmpleado;

    if(empleados!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(empleados[i].sexo > empleados[j].sexo)
                {
                    auxEmpleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxEmpleado;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int ordenarEmpleados(eEmpleado empleados[], int tam, int campo, int criterio)
{
    int todoOk = 0;
    eEmpleado auxEmpleado;

    if(empleados!=NULL && tam>0 && campo>=0 && campo<=4 && criterio>=0 && criterio<=1)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if((strcmp(empleados[i].nombre, empleados[j].nombre)>0 && campo == 0 && criterio == 1)
                        || (strcmp(empleados[i].nombre, empleados[j].nombre)<0 && campo == 0 && criterio == 0)
                        || (empleados[i].sexo<empleados[j].sexo && campo == 3 && criterio == 0)
                        || (empleados[i].sexo>empleados[j].sexo && campo == 3 && criterio == 1)
                        || (empleados[i].edad>empleados[j].edad && campo == 1 && criterio == 1)
                        || (empleados[i].edad<empleados[j].edad && campo == 1 && criterio == 0)
                        || (empleados[i].legajo>empleados[j].legajo && campo == 2 && criterio == 1)
                        || (empleados[i].legajo<empleados[j].legajo && campo == 2 && criterio == 0)
                        || (empleados[i].sueldo>empleados[j].sueldo && campo == 4 && criterio == 1)
                        || (empleados[i].sueldo<empleados[j].sueldo && campo == 4 && criterio == 0))
                {
                    auxEmpleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxEmpleado;
                }
            }
        }

        todoOk = 1;
    }
    return todoOk;
}

int ordenarEmpleadosPorSexoYLegajo(eEmpleado empleados[], int tam)
{
    int todoOk = 0;
    eEmpleado auxEmpleado;

    if(empleados!=NULL && tam>0)
    {
        for(int i=0; i<tam-1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(((empleados[i].sexo == empleados[j].sexo)&&(empleados[i].legajo>empleados[j].legajo))
                        ||((empleados[i].sexo != empleados[j].sexo)&& (empleados[i].sexo > empleados[j].sexo)))
                {
                    auxEmpleado = empleados[i];
                    empleados[i] = empleados[j];
                    empleados[j] = auxEmpleado;
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int inicializarEmpleados(eEmpleado empleados[], int tam)
{
    int todoOk = 0;

    if(empleados!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            empleados[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarLibre(eEmpleado empleados[], int tam, int* pIndex)
{
    int todoOk = 0;

    if(empleados!=NULL && tam>0 && pIndex!=NULL)
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(empleados[i].isEmpty == 1)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int altaEmpleado(eEmpleado empleados[], int tam, int* pProximoLegajo)
{
    int todoOk = 0;
    int indice;
    eEmpleado auxEmpleado;
    eFecha auxFecha;

    if(empleados!=NULL && tam>0 && pProximoLegajo!=NULL)
    {
        if(buscarLibre(empleados, tam, &indice))
        {
            if(indice == -1)
            {
                printf("No hay lugar en el sistema!!\n\n");
            }
            else
            {
                printf("Ingrese nombre: ");
                fflush(stdin);
                gets(auxEmpleado.nombre);

                printf("Ingrese sexo: ");
                fflush(stdin);
                scanf("%c", &auxEmpleado.sexo);

                printf("Ingrese Edad: ");
                scanf("%d", &auxEmpleado.edad);

                printf("Ingrese Sueldo: ");
                scanf("%f", &auxEmpleado.sueldo);

                printf("Ingrese fecha de ingreso (dd/mm/aaaa): ");
                scanf("%d/%d/%d", &auxFecha.dia, &auxFecha.mes, &auxFecha.anio);

                auxEmpleado.isEmpty = 0;

                auxEmpleado.legajo = *pProximoLegajo;
                (*pProximoLegajo)++;

                auxEmpleado.fIngreso = auxFecha;
                empleados[indice] = auxEmpleado;

                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema con los parametros!!\n\n");
        }
    }
    return todoOk;
}

int buscarEmpleado(eEmpleado empleados[], int tam, int legajo, int* pIndex)
{
    int todoOk = 0;

    if(empleados!=NULL && tam>0 && pIndex!=NULL && legajo > 0)
    {
        *pIndex = -1;
        for(int i=0; i<tam; i++)
        {
            if(empleados[i].isEmpty == 0 && empleados[i].legajo == legajo)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int bajaEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char confirma;

    if(empleados!=NULL && tam>0)
    {
        listarEmpleados(empleados, tam, sectores, tams);
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        if(buscarEmpleado(empleados, tam, legajo, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un empleado con legajo %d\n", legajo);
            }
            else
            {
                mostrarEmpleado(empleados[indice], sectores, tams);
                printf("Confirma baja?: ");
                fflush(stdin);
                scanf("%c", &confirma);
                if(confirma != 'S' && confirma != 's')
                {
                    printf("Baja cancelada por el usuario!!\n");
                }
                else
                {
                    empleados[indice].isEmpty = 1;
                    printf("Baja realizada con exito!!\n\n");
                    todoOk = 1;
                }
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar empleado!!\n\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int modificarEmpleado(eEmpleado empleados[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int indice;
    int legajo;
    char salir = 'n';
    char auxCad[100];
    char auxChar;
    int auxInt;
    float auxFloat;
    eFecha fecha;


    if(empleados!=NULL && tam>0)
    {
        listarEmpleados(empleados, tam, sectores, tams);
        printf("Ingrese legajo: ");
        scanf("%d", &legajo);
        if(buscarEmpleado(empleados, tam, legajo, &indice))
        {
            if(indice == -1)
            {
                printf("No hay un empleado con legajo %d\n", legajo);
            }
            else
            {
                mostrarEmpleado(empleados[indice], sectores, tams);
                do
                {
                    switch(menuModificarEmpleado())
                    {
                    case 1:
                        printf("Ingrese nuevo nombre: ");
                        fflush(stdin);
                        gets(auxCad);

                        strcpy(empleados[indice].nombre, auxCad);
                        printf("Nombre modificado con exito!!\n\n");
                        break;
                    case 2:
                        printf("Ingrese nuevo sexo: ");
                        fflush(stdin);
                        scanf("%c", &auxChar);

                        empleados[indice].sexo = auxChar;
                        printf("Sexo modificado con exito!!\n\n");
                        break;
                    case 3:
                        printf("Ingrese nueva edad: ");
                        scanf("%d", &auxInt);

                        empleados[indice].edad = auxInt;
                        printf("Edad modificada con exito!!\n\n");
                        break;
                    case 4:
                        printf("Ingrese nuevo sueldo: ");
                        scanf("%f", &auxFloat);

                        empleados[indice].sueldo = auxFloat;
                        printf("Sueldo modificado con exito!!\n\n");
                        break;
                    case 5:
                        printf("Ingrese nueva fecha de Ingreso (dd/mm/aaaa): ");
                        scanf("%d/%d/%d", &fecha.dia, &fecha.mes, &fecha.anio);

                        empleados[indice].fIngreso = fecha;
                        printf("Fecha modificada con exito!!\n\n");
                        break;
                    case 6:
                        salir = 's';
                        break;
                    default:
                        printf("Opcion Incorrecta!!\n");
                        break;
                    }
                    system("pause");
                }
                while(salir != 's');

                todoOk = 1;
            }
        }
        else
        {
            printf("Ocurrio un problema al buscar empleado!!\n\n");
        }

        todoOk = 1;
    }
    return todoOk;
}

int hardcodearEmpleados(eEmpleado empleados[], int tam, int cant, int* pLegajo)
{
    int todoOk = 0;

    eEmpleado impostores[10] =
    {
        {0000, "Yanzon", 'm', 30, 100000,{2,5,2022},5000,0},
        {0000, "Baus", 'f', 23, 120000,{4,12,2020},5000,0},
        {0000, "Vitochi", 'f', 20, 140000,{23,10,2019},5004,0},
        {0000, "Rambo", 'm', 27, 120000,{1,2,2021},5001,0},
        {0000, "Pela", 'm', 27, 110000,{26,8,2018},5000,0},
        {0000, "Felipe", 'm', 21, 100500,{5,6,2019},5003,0},
        {0000, "Leandro", 'm', 80, 190000,{7,3,2021},5002,0},
        {0000, "Sebastian", 'm', 20, 160000,{6,11,2018},5004,0},
        {0000, "Telma", 'f', 44, 130000,{29,1,2020},5001,0},
        {0000, "El negro", 'm', 80, 115500,{2,9,2021},5002,0}
    };

    if(empleados!=NULL && tam>0 && pLegajo!=NULL && cant>0 && cant<=tam)
    {
        for(int i=0; i<cant; i++)
        {
            empleados[i] = impostores[i];
            empleados[i].legajo = *pLegajo;
            *pLegajo = *pLegajo + 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int menuModificarEmpleado()
{
    int opcion;

    printf("      ******Campos a Modificar******      \n");
    printf("-------------------------------------\n\n");
    printf("1- Nombre\n");
    printf("2- Sexo\n");
    printf("3- Edad\n");
    printf("4- Sueldo\n");
    printf("5- Fecha de Ingreso\n");
    printf("6- Salir\n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int listarVarones(eEmpleado empleados[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;

    if(empleados!=NULL && tam>0)
    {
        system("cls");
        printf("      ******Informe de Varones******      \n\n");
        printf("Legajo  Nombre           Sexo   Edad    Sueldo      F.Ingreso\n");
        for(int i=0; i<tam; i++)
        {
            if(empleados[i].isEmpty == 0 && empleados[i].sexo == 'm')
            {
                mostrarEmpleado(empleados[i], sectores, tams);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarMujeres(eEmpleado empleados[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;

    if(empleados!=NULL && tam>0)
    {
        system("cls");
        printf("      ******Informe de Mujeres******      \n\n");
        printf("Legajo  Nombre           Sexo   Edad    Sueldo      F.Ingreso\n");
        for(int i=0; i<tam; i++)
        {
            if(empleados[i].isEmpty == 0 && empleados[i].sexo == 'f')
            {
                mostrarEmpleado(empleados[i], sectores, tams);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int listarEmpleadosMayoresA(eEmpleado empleados[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int edad;

    if(empleados!=NULL && tam>0)
    {
        printf("Ingrese edad: ");
        scanf("%d", &edad);

        system("cls");
        printf("      ******Informe Empleados mayores a %d anios******      \n\n", edad);
        printf("Legajo  Nombre           Sexo   Edad    Sueldo      F.Ingreso\n");
        for(int i=0; i<tam; i++)
        {
            if(empleados[i].isEmpty == 0 && empleados[i].edad>edad)
            {
                mostrarEmpleado(empleados[i], sectores, tams);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int informarPromedioSueldos(eEmpleado empleados[], int tam)
{
    int todoOk = 0;
    int contEmpleados = 0;
    float acumSueldos = 0;
    float promedio = 0;

    if(empleados!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(empleados[i].isEmpty == 0)
            {
                contEmpleados++;
                acumSueldos = acumSueldos + empleados[i].sueldo;
            }
        }
        if(contEmpleados>0)
        {
            promedio = (float) acumSueldos / contEmpleados;
        }

        system("cls");
        printf("      ******Informe Promedio Sueldos******      \n\n");
        printf("El promedio de sueldos es: %.2f$\n\n", promedio);
        //system("pause");
        todoOk = 1;
    }
    return todoOk;
}

int informarEmpleadoDeMayorEdad(eEmpleado empleados[], int tam, eSector sectores[], int tams)
{
    int todoOk = 0;
    int maxEdad;
    int contEmpleados = 0;

    if(empleados!=NULL && tam>0)
    {
        for(int i=0; i<tam; i++)
        {
            if(empleados[i].isEmpty == 0)
            {
                contEmpleados++;
                if(contEmpleados == 0)
                {
                    maxEdad = empleados[i].edad;
                }
                else
                {
                    if(empleados[i].edad>maxEdad)
                    {
                        maxEdad = empleados[i].edad;
                    }
                }
            }
        }

        system("cls");
        printf("      ******Informe Empleado de Mayor Edad******      \n\n");
        printf("Legajo  Nombre           Sexo   Edad    Sueldo      F.Ingreso\n");
        if(contEmpleados == 0)
        {
            printf("\nNo hay empleados cargados en el sistema!!\n\n");
        }
        else
        {
            for(int i=0; i<tam; i++)
            {
                if(empleados[i].isEmpty == 0 && empleados[i].edad == maxEdad)
                {
                    mostrarEmpleado(empleados[i], sectores, tams);
                }
            }
        }
        todoOk = 1;
    }
    return todoOk;
}
