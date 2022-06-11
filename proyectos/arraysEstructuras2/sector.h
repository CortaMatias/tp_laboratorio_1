#ifndef SECTOR_H_INCLUDED
#define SECTOR_H_INCLUDED

typedef struct{

int id;
char descripcion[20];

}eSector;



#endif // SECTOR_H_INCLUDED

int listarSectores(eSector sectores[], int tam);
int cargarDescripcionSector(eSector sectores[], int tam, int id, char descripcion[]);
int buscarSector(eSector sectores[], int tam, int id, int* pIndice);
int validarSector(eSector sectores[], int tam, int id);
