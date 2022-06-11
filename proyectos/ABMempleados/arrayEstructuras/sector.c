#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sector.h"

int listarSectores(eSector sectores[], int tams)
{
    int todoOk = 0;
    if(sectores!=NULL && tams>0)
    {
        system("cls");
        printf("      ******Sectores******\n");
        printf("Id      Descripcion\n");
        printf("--------------------------\n");
        for(int i=0; i<tams; i++)
        {
            printf("%d      %-16s\n", sectores[i].id, sectores[i].descripcion);
        }
        todoOk = 1;
    }
    return todoOk;
}

int cargarDescripcionSector(eSector sectores[], int tams, int id, char descripcion[])
{
    int todoOk = 0;
    if(sectores!=NULL && tams>0 && id>=5000 && id<=5004 && descripcion!=NULL)
    {
        for(int i=0; i<tams; i++)
        {
            if(id == sectores[i].id)
            {
                strcpy(descripcion, sectores[i].descripcion);
                break;
            }
        }
        todoOk = 1;
    }

    return todoOk;
}
