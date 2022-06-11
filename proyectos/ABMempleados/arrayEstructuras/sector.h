#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eSector;

#endif // SECTOR_H_INCLUDED

int listarSectores(eSector sectores[], int tams);
int cargarDescripcionSector(eSector sectores[], int tams, int id, char descripcion[]);
