#ifndef COMIDA_H_INCLUDED
#define COMIDA_H_INCLUDED

typedef struct{

    int id;
    char descripcion[20];
    float precio;

}eComida;



#endif // COMIDA_H_INCLUDED

int listarComidas(eComida comidas[], int tam);
int buscarComida(eComida comidas[], int tam, int id, int* pIndice);
int validarComida(eComida comidas[], int tam, int id);
int cargarDescripcionComida(eComida comidas[], int tam, int id, char descripcion[]);
