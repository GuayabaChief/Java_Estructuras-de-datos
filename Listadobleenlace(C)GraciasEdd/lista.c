#include "lista.h"

/* ---------- function.h ----------- */
void inicializar (Lista * lista) { 
lista ->inicio = NULL; 
lista ->fin = NULL; 
lista ->tamano = 0;
}

/* insercion en una lista vacia */
/* inserción en una lista vacía */
int ins_en_lista_vacia (Lista * lista, char *dato){

  Elemento *nuevo_elemento=(Elemento*)malloc(sizeof (Elemento));
  if(nuevo_elemento==NULL){
    puts("\nNo se pudo reservar memoria dinamica");
  }
  
  nuevo_elemento->dato = (char *) malloc (50 * sizeof (char));
  if(nuevo_elemento->dato==NULL){
    puts("\nNo se pudo reservar memoria dinamica");
  } 
  
  strcpy (nuevo_elemento->dato, dato);
  nuevo_elemento->siguiente = NULL;
  lista->inicio = nuevo_elemento;
  lista->fin = nuevo_elemento;
  lista->tamano++;

  return 0;
}

/* inserción al inicio de la lista */
int ins_inicio_lista (Lista * lista, char *dato) { 

  Elemento *nuevo_elemento=(Elemento*)malloc(sizeof (Elemento));
  if(nuevo_elemento==NULL){
    puts("\nNo se pudo reservar memoria dinamica");
  }
  
  nuevo_elemento->dato = (char *) malloc (50 * sizeof (char));
  if(nuevo_elemento->dato==NULL){
    puts("\nNo se pudo reservar memoria dinamica");
  } 

  strcpy(nuevo_elemento->dato, dato); 
  nuevo_elemento->siguiente = lista->inicio; 
  lista ->inicio = nuevo_elemento; 
  lista ->tamano++; 
return 0;
}

/*insercion al final de la lista */
int ins_fin_lista (Lista * lista, Elemento * actual, char *dato) { 

  Elemento *nuevo_elemento=(Elemento*)malloc(sizeof (Elemento));
  if(nuevo_elemento==NULL){
    puts("\nNo se pudo reservar memoria dinamica");
  }
  
  nuevo_elemento->dato = (char *) malloc (50 * sizeof (char));
  if(nuevo_elemento->dato==NULL){
    puts("\nNo se pudo reservar memoria dinamica");
  }  


  strcpy (nuevo_elemento->dato, dato); 
  actual->siguiente = nuevo_elemento; 
  nuevo_elemento->siguiente = NULL; 
  lista ->fin = nuevo_elemento; 
  lista ->tamano++; 
return 0;
}

/* insercion en la posicion solicitada */
int ins_lista (Lista * lista, char *dato, int pos) { 

    if (lista ->tamano < 2){
    return -1; 
    }

    if (pos < 1 || pos >= lista ->tamano){
    return -1; 
    } 

    Elemento *actual; 
    Elemento *nuevo_elemento; 
    int i; 

    nuevo_elemento=(Elemento*)malloc(sizeof (Elemento));
    if(nuevo_elemento==NULL){
    puts("\nNo se pudo reservar memoria dinamica");
    return 1;
    }
  
    nuevo_elemento->dato = (char *) malloc (50 * sizeof (char));
    if(nuevo_elemento->dato==NULL){
        puts("\nNo se pudo reservar memoria dinamica");
        return 1;
    }

    actual=lista ->inicio; 

    for (i = 1; i < pos; ++i){
        actual = actual->siguiente; 
        if (actual->siguiente == NULL){
            return -1; 
        } 
    
    strcpy (nuevo_elemento->dato, dato); 
    nuevo_elemento->siguiente = actual->siguiente; 
    actual->siguiente = nuevo_elemento; 
    lista ->tamano++; 

    return 0;
    } 

    
}

/* supresión al inicio de la lista */
int sup_inicio (Lista * lista) {

  if (lista ->tamano == 0){
  return -1; 
  } 

  Elemento *sup_elemento=(Elemento*)malloc(sizeof(Elemento));

  sup_elemento = lista ->inicio; 
  lista ->inicio = lista ->inicio->siguiente; 
  if (lista ->tamano == 1){
    lista ->fin = NULL;
  } 
  free (sup_elemento->dato); 
  free (sup_elemento); 
  lista ->tamano--; 
  return 0;
}

/* supresión al final de la lista */
int sup_final (Lista * lista){

  /*if (lista ->tamano == 0){
  return -1; 
  } 

  
  Elemento *actual=(Elemento*)malloc(sizeof(Elemento));

  actual = lista ->inicio; 

  for (int i = 1; i < lista->tamano; ++i){
    
    actual = actual->siguiente;
  }
 
 
  
  actual->siguiente=NULL;
  lista->fin=actual;

  free(actual->dato);
  free(actual);
  lista ->tamano--;
  
  return 0; */
  int pos=(lista->tamano)-1;
  sup_en_lista (lista, pos);
  return 0;
}


/* suprimir un elemento después de la posición solicitada */
int sup_en_lista (Lista * lista, int pos) { 
if (lista ->tamano <= 1 || pos < 1 || pos >= lista ->tamano) 
return -1; 
int i; 
Elemento *actual; 
Elemento *sup_elemento; 
actual = lista ->inicio; 
for (i = 1; i < pos; ++i)
actual = actual->siguiente; 
sup_elemento = actual->siguiente; 
actual->siguiente = actual->siguiente->siguiente; 
if(actual->siguiente == NULL) lista ->fin = actual; 
free (sup_elemento->dato);
free (sup_elemento);
lista ->tamano--;
return 0;
}

/* visualización de la Lista */
void muestra (Lista * lista){ 

Elemento *actual=(Elemento*)malloc(sizeof(Elemento)); 
if(actual==NULL){
  puts("\nNo se pudo crear el nodo Elemento");
}
actual = lista ->inicio; 
while (actual != NULL){ 
printf ("%p - %s\n", actual, actual->dato); 
actual = actual->siguiente; 
    }
}

/* destruir la Lista */
void destruir (Lista *lista){
  while (lista->tamano > 0)
    sup_inicio (lista);
}

int menu (Lista *lista,int *k){ 
int eleccion; 
printf("********** MENU **********\n"); 
if (lista ->tamano == 0){ 
printf ("1. Adición del1er elemento\n"); 
printf ("2. Quitar\n");
} else if (lista ->tamano == 1 || *k == 1) { 
printf ("1. Adición al inicio de la lista\n"); 
printf ("2. Adición al final de la lista\n"); 
printf ("4. Supresión al inicio de la lista\n"); 
printf ("6. Destruir la lista\n"); 
printf ("7. Quitar\n"); 
printf ("8. Supresión al final de la lista\n");
}
else { 
printf ("1. Adición al inicio de la lista\n"); 
printf ("2. Adición al final de la lista\n");
printf ("3. Adición después de la posición indicada\n"); 
printf ("4. Supresión al inicio de la lista\n"); 
printf ("5. Supresión después de la posición indicada\n"); 
printf ("6. Destruir la lista\n"); 
printf ("7. Quitar\n"); 
printf ("8. Supresión al final de la lista\n");
} 
printf ("\n\nElegir: "); 
scanf ("%d", &eleccion); 
getchar(); 
if(lista->tamano == 0 && eleccion == 2) eleccion = 7; 
return eleccion;
}