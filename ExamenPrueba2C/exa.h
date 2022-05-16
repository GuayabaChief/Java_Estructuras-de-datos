#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
/*
    |Variable   | Estado    | Significado
        error       0           Sin errores (todo resultado es exitoso)
        error      -3           Error, COLA vacía
        error      -4           Inexistencia de la COLA, o esta apunta a NULL
        error      -5           Inexistencia de dato en la estructura 
        error      -6           Nodo inicial nulo
*/

///--------------------------------------------->
typedef struct{
    int edad;
    char nombre[20];
    float altura;
} Dato;

struct Nodo{
    Dato dato;
    struct Nodo* siguiente;
};

//TDA Cola dinámica
typedef struct{
    int cursor;//iterador  -> cantidad de nodos existentes
    struct Nodo* cabecera;
    struct Nodo* final;
}Elemento_de_Cola;

typedef Elemento_de_Cola* Cola;

///----------------------------------------------->

typedef struct ElementoLista
{
  Dato datoUsuario;
  struct ElementoLista *siguiente;
} Elemento;

typedef struct ListaIdentificar
{
  Elemento *inicio;
  Elemento *fin;
  int tamano;
} Lista;

///----------------------------------------------->
Cola crearCola(int*);

// Inserta cola por el final
void encolar(Cola*, int*, Dato );

//Eliminar dato por la cabecera
void desencolar(Cola*, int*, Dato *);

// Devuelve un true o un false si la cola contiene o no Nodos:
bool estaVacia(Cola,int *);

// Libera la memoria RAM usada por la cola:
void borraCola(Cola* cola, int *e,Lista* robot1,Lista* robot2,Lista* robot3,Lista* robot4, Lista* robot5);

void imprimeCola(Cola , int*);

// GENERAR NUMERO ALEATORIOS

int numAle();

///----------------------------------------------->

/* inicialización de la lista */
void inicializar(Lista * lista);


/* INSERCION */

/* inserción en una lista vacía */
int ins_en_lista_vacia (Lista * lista, Dato datoUsuario);

/* inserción al inicio de la lista */
int ins_inicio_lista (Lista * lista, Dato datoUsuario);

/* inserción al final de la lista */
int ins_fin_lista (Lista * lista, Elemento * actual, Dato datoUsuario);

/* inserción en otra parte */
int ins_lista (Lista * lista, Dato datoUsuario, int pos);

/* SUPRESION */

int sup_inicio (Lista * lista);
int sup_final (Lista * lista);
int sup_en_lista (Lista * lista, int pos);


void muestra (Lista * lista);
void Atender(Lista* robot1,Lista* robot2,Lista* robot3,Lista* robot4, Lista* robot5);