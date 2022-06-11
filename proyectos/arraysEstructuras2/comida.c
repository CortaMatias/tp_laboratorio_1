#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "comida.h"



int listarComidas(eComida comidas[], int tam){
int todoOk = 0;

    if(comidas != NULL && tam > 0){
     // system("cls");
        printf("   *** Lista de Comidas  ***\n");
        printf("  Id    Descripcion    Precio\n");
        printf("--------------------------------\n");
        for(int i=0; i < tam; i++){
            printf("   %4d    %10s  %5.2f\n", comidas[i].id, comidas[i].descripcion, comidas[i].precio);
        }
        printf("\n\n");
        todoOk = 1;
    }
 return todoOk;
}


int buscarComida(eComida comidas[], int tam, int id, int* pIndice){
    int todoOk = 0;
    if(comidas != NULL && tam > 0 && pIndice != NULL){
            *pIndice = -1;
            for(int i=0; i < tam; i++){
                if(comidas[i].id == id){
                    *pIndice = i;
                    break;
                }
            }
        todoOk = 1;
    }
    return todoOk;
}

int validarComida(eComida comidas[], int tam, int id){
    int esValido = 0;
    int indice;

    buscarComida(comidas, tam, id, &indice);

    if(indice != -1){
        esValido = 1;
    }
    return esValido;
}


int cargarDescripcionComida(eComida comidas[], int tam, int id, char descripcion[]){
int todoOk = 0;
int indice;

    buscarComida(comidas,tam, id,&indice);

    if(descripcion != NULL && indice != -1 ){
       strcpy(descripcion, comidas[indice].descripcion);
       todoOk = 1;
    }
  return todoOk;
}


