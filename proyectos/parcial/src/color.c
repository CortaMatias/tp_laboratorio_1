/*
 * color.c
 *
 *  Created on: 8 may. 2022
 *      Author: Matias
 */

#include "color.h"


int mostrarColor(eColor* lista){
int todoOk = 0;
printf("%04d  %s \n", lista->id, lista->descripcion);
return todoOk;
}


int listarColores(eColor* lista, int tamC){
int todoOk = 0;
	if (lista != NULL && tamC > 0)
	{

		printf(" \n\n         ***   Listado de colores   ***\n\n");
		printf(" ID      Marca  \n");
		printf("------------------\n");
		for (int i = 0; i < tamC; i++)
		{
			mostrarColor(lista + i);
		}
		todoOk = 1;
	}
return todoOk;
}

int cargarDescripcionColor(eColor* listaC, int tamC, int id, char* descripcion){
int todoOk = 0;
int indice;

    buscarColor(listaC,tamC, id,&indice);

    if(descripcion != NULL && indice != -1 )
    {
       strcpy(descripcion, listaC[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


int buscarColor(eColor* listaC, int tamC, int id, int* pIndice){
    int todoOk = 0;
    if(listaC != NULL && tamC > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tamC; i++){
                if(listaC[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}
