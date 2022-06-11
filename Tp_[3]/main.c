#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"


/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main(){

	setbuf(stdout,NULL);
	int flagAdd = 0;

	int option = 0;
    LinkedList* listaPasajeros = ll_newLinkedList();
    do{
    	switch(menu())
        {
        		case 1:
                    controller_loadFromText("data.csv", listaPasajeros);
                    flagAdd = ll_len(listaPasajeros);
                    break;
                case 2:
                    controller_loadFromBinary("data.bin", listaPasajeros);
                    flagAdd = ll_len(listaPasajeros);
                    break;
                case 3:
                    controller_addPassenger(listaPasajeros);
                    flagAdd++;
                    break;
                case 4:
                    if(flagAdd){
                    	if(controller_editPassenger(listaPasajeros)){
                    		printf("Los datos fueron modificados con exito");
                    	}
                    }else{
                    	printf("No hay pasajeros en la lista para modificar.");
                    }
                    break;
                case 5:
                    if(flagAdd){
                    	controller_removePassenger(listaPasajeros);
                    	flagAdd --;
                    }else{
                    	printf("No hay pasajeros en la lista para modificar.");
                    }

                    break;
                case 6:
                    controller_ListPassenger(listaPasajeros);
                    break;
                case 7:
                	if(flagAdd){
                		controller_sortPassenger(listaPasajeros);
                	}else{
                		printf("No hay pasajeros en la lista para ordenar");
                	}

                    break;
                case 8:
                	if(flagAdd){
                		controller_saveAsText("data.csv", listaPasajeros);
                	}else{
                		printf("No hay pasajeros en la lista para guardar");
                	}

                    break;
                case 9:
                	if(flagAdd){
                		controller_saveAsBinary("data.bin", listaPasajeros);
                	}else{
                		printf("No hay pasajeros en la lista para guardar");
                	}
                    break;
                    case 10:
                    option = 10;
                    break;

        }
    }while( option != 10);
    return 0;
}

