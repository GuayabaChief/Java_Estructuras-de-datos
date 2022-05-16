#include "exa.h"

Cola crearCola(int* e){
    Cola cola=(Cola) malloc(sizeof(Elemento_de_Cola));
    if(cola==NULL){
        *e=-4;
        puts("No se logro obtener memoria para una estructura COLA");
    }
    cola->cabecera=NULL;
    cola->final=NULL;
    cola->cursor=0;
    return cola;
}

// Inserta cola por el final
void encolar(Cola* cola, int* e, Dato datoIngreso){
    struct Nodo* nodoUsuario=(struct Nodo*) malloc(sizeof(struct Nodo));
    if(nodoUsuario==NULL){
        *e=-6;
        puts("La estructura del nuevo nodo no se creo correctamente, favor de liberar datos de la cola");
    }
    else if(estaVacia(*cola, e)){
        (*nodoUsuario).dato=datoIngreso;
        (*nodoUsuario).siguiente=NULL;
        (*cola)->cabecera=nodoUsuario;
        (*cola)->final=nodoUsuario;
    } else{
        (*nodoUsuario).dato=datoIngreso;
        (*nodoUsuario).siguiente=NULL;
        (*cola)->final->siguiente=nodoUsuario;
        (*cola)->final=nodoUsuario;
    }
    (*cola)->cursor++;
    *e=0;
}

//Eliminar dato por la cabecera
void desencolar(Cola* cola, int* e, Dato *datoExtraido){
    struct Nodo* aux=NULL;
    if(estaVacia(*cola,e)){
        puts("Cola vacia, no hay elementos que extraer");
        *e=-3;
    } else if((*cola)->cursor==1){
        *datoExtraido=(*cola)->cabecera->dato;
        (*cola)->cabecera=NULL;
        (*cola)->final=NULL;
        *e=-3;
        (*cola)->cursor=0;
    } else if((*cola)->cursor>1){
        aux=(*cola)->cabecera;
        *datoExtraido=(*cola)->cabecera->dato;
        (*cola)->cabecera=(*cola)->cabecera->siguiente; //(*cola)->cabecera=aux->siguiente; 
        (*cola)->cursor--;
        aux->siguiente=NULL;
        free(aux);
        *e=0;
    }
}

// Devuelve un true o un false si la cola contiene o no Nodos:
bool estaVacia(Cola cola,int *e){
    if(cola->cabecera==NULL && cola->final==NULL && cola->cursor==0){
        *e=-3;
        return true;
    } else{
        *e=0;
        return false;
    }
}

// Libera la memoria RAM usada por la cola:
void borraCola(Cola* cola, int *e,Lista* robot1,Lista* robot2,Lista* robot3,Lista* robot4, Lista* robot5){
    Dato aux;
    while(!estaVacia(*cola,e)){

        printf("\nEdad: %d",(*cola)->cabecera->dato.edad);

        if((*cola)->cabecera->dato.edad>18 && (*cola)->cabecera->dato.edad<22){
            if (robot1->tamano == 0){
                    ins_en_lista_vacia (robot1, (*cola)->cabecera->dato);
                }
                else{
                    ins_fin_lista(robot1,robot1->fin, (*cola)->cabecera->dato);
                } 
            puts("\n: : Persona en fila de robot 1 : : ");
        }

        if((*cola)->cabecera->dato.edad==18){
             if (robot2->tamano == 0){
                    ins_en_lista_vacia (robot2, (*cola)->cabecera->dato);
                }
                else{
                    ins_fin_lista(robot2,robot2->fin, (*cola)->cabecera->dato);
                } 
            puts("\n: : Persona en fila de robot 2 : : ");
        }

        if((*cola)->cabecera->dato.edad>22 && (*cola)->cabecera->dato.edad<44){
                 if (robot3->tamano == 0){
                    ins_en_lista_vacia (robot3, (*cola)->cabecera->dato);
                }
                else{
                    ins_fin_lista(robot3,robot3->fin, (*cola)->cabecera->dato);
                } 
            puts("\n: : Persona en fila de robot 3 : : ");
        }

        if((*cola)->cabecera->dato.edad==22 || (*cola)->cabecera->dato.edad==44){
                 if (robot4->tamano == 0){
                    ins_en_lista_vacia (robot4, (*cola)->cabecera->dato);
                }
                else{
                    ins_fin_lista(robot4,robot4->fin, (*cola)->cabecera->dato);
                }
            puts("\n: : Persona en fila de robot 4 : : ");
        }

        if((*cola)->cabecera->dato.edad>44 && (*cola)->cabecera->dato.edad<=60){
                 if (robot5->tamano == 0){
                    ins_en_lista_vacia (robot5, (*cola)->cabecera->dato);
                }
                else{
                    ins_fin_lista(robot5,robot5->fin, (*cola)->cabecera->dato);
                } 
            puts("\n: : Persona en fila de robot 5 : : ");
        }

        desencolar(cola,e,&aux);
    }
    puts("\n: : Se termino de vaciar la cola : : ");
    *e=0;
   //*cola=crearCola();
   //cola

   /*Borrar cola 2da forma*/
   /* struct Nodo* aux1, *auxResp;
    aux1=(*cola)->cabecera;
    while(aux1!=NULL){
        auxResp=aux1->siguiente;
        aux1->siguiente=NULL;
        free(aux1);
        aux1=auxResp;
    }
    */
}

void imprimeCola(Cola cola , int* e){
    if(cola==NULL){
        puts("Inexistencia de la cola");
    } else if(estaVacia(cola,e)){
        puts("Cola esta vacia");
        *e=-3;
    } else{
        puts("Imprimiendo contenido:");
       /* struct Nodo datoExt;
        for(int iterador=0; iterador<cola->cursor;iterador++){
            desencolar(&cola,e,&datoExt);
            printf("Valor en el nodo extraido: %d\n",datoExt.dato.valor);
        }*/
        struct Nodo* nodoAux=cola->cabecera;
        while(nodoAux!=NULL){
            printf("Los datos en el nodo extraido: edad: %d nombre: %s altura %.2f\n",nodoAux->dato.edad,nodoAux->dato.nombre,nodoAux->dato.altura);
            nodoAux=nodoAux->siguiente;
        }
    }
}

int numAle(){
    int numgen;
    
    srand(time(NULL));
    
    numgen=18+rand()%(60+1-18);
        /*Para generar un número pseudoaleatorio se requiere la función rand
        la fórmula sería la siguiente:
        limite Inferior + rand() % (limite superior + 1 - limite inferior) */

    return numgen;

}

/* ---------- function.h ----------- */
void inicializar (Lista * lista) { 
lista ->inicio = NULL; 
lista ->fin = NULL; 
lista ->tamano = 0;
}

/* insercion en una lista vacia */
/* inserción en una lista vacía */
int ins_en_lista_vacia (Lista * lista, Dato datoUsuario){

  Elemento *nuevo_elemento=(Elemento*)malloc(sizeof (Elemento));
  if(nuevo_elemento==NULL){
    puts("\nNo se pudo reservar memoria dinamica");
  }
  
 
  nuevo_elemento->datoUsuario=datoUsuario;
  nuevo_elemento->siguiente = NULL;
  lista->inicio = nuevo_elemento;
  lista->fin = nuevo_elemento;
  lista->tamano++;

  return 0;
}

/* inserción al inicio de la lista */
int ins_inicio_lista (Lista * lista, Dato datoUsuario) { 

  Elemento *nuevo_elemento=(Elemento*)malloc(sizeof (Elemento));
  if(nuevo_elemento==NULL){
    puts("\nNo se pudo reservar memoria dinamica");
  }
  
 

  nuevo_elemento->datoUsuario=datoUsuario; 
  nuevo_elemento->siguiente = lista->inicio; 
  lista ->inicio = nuevo_elemento; 
  lista ->tamano++; 
return 0;
}

/*insercion al final de la lista */
int ins_fin_lista (Lista * lista, Elemento * actual, Dato datoUsuario) { 

  Elemento *nuevo_elemento=(Elemento*)malloc(sizeof (Elemento));
  if(nuevo_elemento==NULL){
    puts("\nNo se pudo reservar memoria dinamica");
  }
  
 

  nuevo_elemento->datoUsuario=datoUsuario;
  actual->siguiente = nuevo_elemento; 
  nuevo_elemento->siguiente = NULL; 
  lista ->fin = nuevo_elemento; 
  lista ->tamano++; 
return 0;
}

/* insercion en la posicion solicitada */
int ins_lista (Lista * lista, Dato datoUsuario, int pos) { 

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
  

    actual=lista ->inicio; 

    for (i = 1; i < pos; ++i){
        actual = actual->siguiente; 
        if (actual->siguiente == NULL){
            return -1; 
        } 
    
    nuevo_elemento->datoUsuario=datoUsuario; 
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

  free (sup_elemento); 
  lista ->tamano--; 
  return 0;
}

/* supresión al final de la lista */
int sup_final (Lista * lista){

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
    printf ("\n%s | %d", actual->datoUsuario.nombre, actual->datoUsuario.edad); 
    actual = actual->siguiente; 
        }
}

/* destruir la Lista */
void Atender(Lista* robot1,Lista* robot2,Lista* robot3,Lista* robot4, Lista* robot5){
    int turno=0, robot=0;
    printf("\nAtendiendo");
    
    printf("\nRobot 1: %d",robot1->tamano);
    printf("\nRobot 2: %d",robot2->tamano);
    printf("\nRobot 3: %d",robot3->tamano);
    printf("\nRobot 4: %d",robot4->tamano);
    printf("\nRobot 5: %d",robot5->tamano);



 while((robot1->tamano>=0) && (robot2->tamano>=0) && (robot3->tamano>=0) && (robot4->tamano>=0) && (robot5->tamano>=0)){
      turno++;
      robot++;
      printf("\nTurno no. %d - Robot %d",turno,robot);

      switch(robot){
          case 1:
                if(robot1->tamano==0){
                    printf("\nNo hay nadie en la ventanilla 1");
                }
                else if(robot1->tamano==1){
                    printf("\nAtendiendo a:\n%s | %d",robot1->inicio->datoUsuario.nombre, robot1->inicio->datoUsuario.edad);
                    sup_inicio (robot1);
                }
                else if(robot1->tamano>1){
                    printf("\nAtendiendo a:\n%s | %d",robot1->inicio->datoUsuario.nombre, robot1->inicio->datoUsuario.edad);
                    sup_inicio (robot1);
                    printf(" y a %s | %d",robot1->inicio->datoUsuario.nombre, robot1->inicio->datoUsuario.edad);
                    sup_inicio (robot1);
                }
          break;

          case 2:

           if(robot2->tamano==0){
                    printf("\nNo hay nadie en la ventanilla 2");
                }
            else if(robot2->tamano==1){
                    printf("\nAtendiendo a:\n%s | %d",robot2->inicio->datoUsuario.nombre, robot2->inicio->datoUsuario.edad);
                    sup_inicio (robot2);
            }
            else if(robot2->tamano>1){
                    printf("\nAtendiendo a:\n%s | %d",robot2->inicio->datoUsuario.nombre, robot2->inicio->datoUsuario.edad);
                    sup_inicio (robot2);
                    printf(" y a %s | %d",robot1->inicio->datoUsuario.nombre, robot1->inicio->datoUsuario.edad);
                    sup_inicio (robot2);  
                }
          break;

          case 3:
          if(robot3->tamano==0){
                    printf("\nNo hay nadie en la ventanilla 3");
                   
                }
            else if(robot3->tamano==1){
                    printf("\nAtendiendo a:\n%s | %d",robot3->inicio->datoUsuario.nombre, robot3->inicio->datoUsuario.edad);
                    sup_inicio (robot3);
                  
                }
                else if(robot3->tamano>1){
                    printf("\nAtendiendo a:\n%s | %d",robot3->inicio->datoUsuario.nombre, robot3->inicio->datoUsuario.edad);
                    sup_inicio (robot3);
                    printf(" y a %s | %d",robot3->inicio->datoUsuario.nombre, robot3->inicio->datoUsuario.edad);
                    sup_inicio (robot3);
                }
          break;

          case 4:
          if(robot4->tamano==0){
                    printf("\nNo hay nadie en la ventanilla 4");
                    
                }
            else if(robot4->tamano==1){
                    printf("\nAtendiendo a:\n%s | %d",robot4->inicio->datoUsuario.nombre, robot4->inicio->datoUsuario.edad);
                    sup_inicio (robot4);
                   
                }
               else if(robot4->tamano>1){
                    printf("\nAtendiendo a:\n%s | %d",robot4->inicio->datoUsuario.nombre, robot4->inicio->datoUsuario.edad);
                    sup_inicio (robot4);
                    printf(" y a %s | %d",robot4->inicio->datoUsuario.nombre, robot4->inicio->datoUsuario.edad);
                    sup_inicio (robot4);
                }
          break;

          case 5:
            if(robot5->tamano==0){
                    printf("\nNo hay nadie en la ventanilla 5");
                }
                else if(robot5->tamano==1){
                    printf("\nAtendiendo a:\n%s | %d",robot5->inicio->datoUsuario.nombre, robot5->inicio->datoUsuario.edad);
                    sup_inicio (robot5);
                
                }
                else if(robot5->tamano>1){
                    printf("\nAtendiendo a:\n%s | %d",robot5->inicio->datoUsuario.nombre, robot5->inicio->datoUsuario.edad);
                    sup_inicio (robot5);
                    printf(" y a %s | %d",robot5->inicio->datoUsuario.nombre, robot5->inicio->datoUsuario.edad);
                    sup_inicio (robot5);
                
                    
                }
          break;
    }

      printf("\nPersonas esperando en este turno: ");
                    printf("\nVentanilla 1:");
                    muestra(robot1);
                    printf("\nVentanilla 2:");
                    muestra(robot2);
                    printf("\nVentanilla 3:");
                    muestra(robot3);
                    printf("\nVentanilla 4:");
                    muestra(robot4);
                    printf("\nVentanilla 5:");
                    muestra(robot5);
                    
      if(robot==5){
          robot=0;
    
      }

    if((robot1->tamano==0) && (robot2->tamano==0) && (robot3->tamano==0) && (robot4->tamano==0) && (robot5->tamano==0)){
       printf("\n\t: : YA NO HAY MÁS CLIENTES EN LAS FILAS NI EN LA COLA");
        break;
    
    }
      
  }
    
}