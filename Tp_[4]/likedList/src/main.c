/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/Controller.h"
#include "../inc/Passenger.h"
#include "../testing/inc/main_test.h"
#include "../inc/LinkedList.h"


int main(void)
{
	setbuf(stdout,NULL);
	/*startTesting(1);  // ll_newLinkedList
	startTesting(2);  // ll_len
	startTesting(3);  // getNode - test_getNode
	startTesting(4);  // addNode - test_addNode
	startTesting(5);  // ll_add
	startTesting(6);  // ll_get
	startTesting(7);  // ll_set
	startTesting(8);  // ll_remove
	startTesting(9);  // ll_clear
	startTesting(10); // ll_deleteLinkedList
	startTesting(11); // ll_indexOf
	startTesting(12); // ll_isEmpty
	startTesting(13); // ll_push
	startTesting(14); // ll_pop
	startTesting(15); // ll_contains
	startTesting(16); // ll_containsAll
	startTesting(17); // ll_subList
	startTesting(18); // ll_clone
	startTesting(19); // ll_sort*/

	int flagAdd = 0;

		int option = 0;
	    LinkedList* listaPasajeros = ll_newLinkedList();
	    LinkedList* listaPasajerosAux;
	    do{
	    	switch(menu())
	        {
	        		case 1:
	                    if(controller_loadFromText("data.csv", listaPasajeros)){
	                    	printf("Pasajeros cargados con exito");
	                    	flagAdd = ll_len(listaPasajeros);
	                    }

	                    break;
	                case 2:
	                    if(controller_loadFromBinary("data.bin", listaPasajeros)){
	                    printf("Pasajeros cargados con exito");
	                    flagAdd = ll_len(listaPasajeros);
	                    }

	                    break;
	                case 3:
	                	if(controller_addPassenger(listaPasajeros)){
	                	printf("Pasajero cargados con exito");
	                	flagAdd++;
	                	}
	                    break;
	                case 4:
	                    if(!ll_isEmpty(listaPasajeros)){
	                    	if(controller_editPassenger(listaPasajeros)){
	                    		printf("Los datos fueron modificados con exito");
	                    	}
	                    }else{
	                    	printf("No hay pasajeros en la lista para modificar.");
	                    }
	                    break;
	                case 5:
	                    if(!ll_isEmpty(listaPasajeros)){
	                    	controller_removePassenger(listaPasajeros);
	                    }else{
	                    	printf("No hay pasajeros en la lista para modificar.");
	                    }

	                    break;
	                case 6:
	                	controller_ListPassenger(listaPasajeros);
	                    break;
	                case 7:
	                	if(!ll_isEmpty(listaPasajeros)){
	                		controller_sortPassenger(listaPasajeros);
	                	}else{
	                		printf("No hay pasajeros en la lista para ordenar");
	                	}

	                    break;
	                case 8:
	                	if(!ll_isEmpty(listaPasajeros)){
	                		controller_saveAsText("data.csv", listaPasajeros);
	                		printf("Los datos fueron guardados con exito en el archivo data.csv");
	                	}else{
	                		printf("No hay pasajeros en la lista para guardar");
	                	}

	                    break;
	                case 9:
	                	if(!ll_isEmpty(listaPasajeros)){
	                		controller_saveAsBinary("data.bin", listaPasajeros);
	                		printf("Los datos fueron guardados con exito en el archivo data.bin");
	                	}else{
	                		printf("No hay pasajeros en la lista para guardar");
	                	}
	                    break;
	                case 10:
	                	listaPasajerosAux = controller_ll_containsAll(listaPasajeros, 0);
	                	controller_ListPassenger(listaPasajerosAux);
	                	break;
	                case 11:
	                	//PUSH
	                	controller_varios(listaPasajeros, 1);
	                	                	break;
	                case 12:
	                	//SET
	                	controller_varios(listaPasajeros, 0);
	                	                	break;
	                case 13:
	                	controller_ll_contains(listaPasajeros);
	                	break;

	                case 14:
	                	ll_clear(listaPasajeros);
	                	ll_clear(listaPasajerosAux);
	                	                	break;
	                case 15:
	                	controller_ll_pop(listaPasajeros);
	                	break;
	                case 16:
	                	listaPasajerosAux = controller_ll_containsAll(listaPasajeros, 1);
	                	controller_ListPassenger(listaPasajerosAux);
	                	                	break;
	      	        case 17:
	                	ll_deleteLinkedList(listaPasajeros);
	                	ll_deleteLinkedList(listaPasajerosAux);
	                    option = 10;
	                    break;

	        }
	    }while( option != 10);



    return 0;
}

































