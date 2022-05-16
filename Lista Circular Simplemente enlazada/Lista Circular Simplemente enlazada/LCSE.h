#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>

typedef struct{
    int valor;
}Dato;

struct Nodo{
    Dato info;
    struct Nodo* sig;
    int pos;
};

typedef struct{
    struct Nodo* cab;
    int cursor;
}Elemento_Lista;

typedef Elemento_Lista* Lista;

Lista crearLista(int* e);
void agregarDer(Lista *lista, int *e, Dato ingresar);
void agregarIzq(Lista *lista, int *e, Dato ingresar);
void agregarPosN(Lista *lista, int *e, Dato ingresar, int n);
void recorrerLista(Lista *lista, int *e);
void vaciarLista(Lista *lista, int *e);
void borrarLista(Lista *lista, int *e);
void extraerIzq(Lista *lista, int *e, Dato *extraido);
void extraerDer(Lista *lista, int *e, Dato *extraido);
void extraerN(Lista *lista, int *e, Dato *extraido, int n);