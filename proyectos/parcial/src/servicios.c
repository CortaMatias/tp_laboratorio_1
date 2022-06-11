/*
 * servicios.c
 *
 *  Created on: 8 may. 2022
 *      Author: Matias
 */

#include "servicios.h"

int mostrarServicio(eServicio* listaS){
int todoOk = 0;

printf("%04d   %10s   %f\n", listaS->id, listaS->descripcion, listaS->precio);
return todoOk;
}




int listarServicios(eServicio* listaS, int tamS){
	int todoOk = 0;
		if (listaS != NULL && tamS > 0)
		{

			printf(" \n\n         ***   Listado de servicios   ***\n\n");
			printf(" ID      Servicio    Precio  \n");
			printf("--------------------------------\n");
			for (int i = 0; i < tamS; i++)
			{
				mostrarServicio(listaS + i);
			}
			todoOk = 1;
		}
	return todoOk;
	}

int cargarDescripcionServicio(eServicio* listaS, int tamS, int id, char* descripcion){
int todoOk = 0;
int indice;

    buscarServicio(listaS,tamS, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, listaS[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


int buscarServicio(eServicio* listaS, int tamS, int id, int* pIndice){
    int todoOk = 0;
    if(listaS != NULL && tamS > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tamS; i++){
                if(listaS[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
