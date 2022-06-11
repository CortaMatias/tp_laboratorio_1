
#include "Passenger.h"
#include "LinkedList.h"
#include "parser.h"

int controller_gestionId(LinkedList *pArrayListPassenger, int id);
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger);
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger);
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_removePassenger(LinkedList* pArrayListPassenger);
int controller_ListPassenger(LinkedList* pArrayListPassenger);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger);
int controller_showPassenger(Passenger* pasajero);
int menu();
int menuEdit();
int menuSort();
int controller_SortId(void* pasajero1, void* pasajero2);
int controller_SortNombre(void* nombre1, void* nombre2);
int controller_SortApellido(void* pasajero1, void* pasajero2);
int controller_SortPrecio(void* pasajero1, void* pasajero2);
int controller_SortTipo(void* pasajero1, void* pasajero2);
int controller_SortCodigo(void* pasajero1, void* pasajero2);
int controller_SortEstado(void* pasajero1, void* pasajero2);
