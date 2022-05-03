#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "stdbool.h"

/*
    |Variable   | Estado    | Significado
        error       0           Sin errores (todo resultado es exitoso)
        error      -1           Error, Lista llena
        error      -2           LIsta vacia
        error      -3           Inexistencia de dato en la estructura
        error      -4           Nodo inicial nulo
        error      -5           Ruta del archivo no encontrada
*/

typedef struct{

int valor;

}Dato;

struct Nodo{
Dato info;
struct Nodo*sig;
int pos;
};

typedef struct{
struct Nodo*cab;
int cursor;
}Elemento_Lista;

typedef Elemento_Lista*Lista;


Lista crearLista(int* e){
Lista l=(Lista)malloc(sizeof(Elemento_Lista));
if(l==NULL){
perror("No hay memoria para la lista");
        *e=-1;
}
else{
l->cab=NULL;
*e=0;
}
return l;
}

bool isEmpty(Lista lista,int *e){
    if(lista->cab==NULL && lista->cab->sig==NULL){
        *e=-2;
        return true;
    } else{
        *e=0;
        return false;
    }
}

void agregarDer(Lista*lista, int *e, Dato datoInfo){
    struct Nodo* temp=(struct Nodo*)malloc(sizeof(struct Nodo));
    struct Nodo* aux;
    if(temp==NULL){
        puts("La estructura no se creo correctamente");
        *e=-3;
    }
    else if((*lista)->cab==NULL){
        temp->info=datoInfo;
        temp->sig=NULL;
        temp->pos=0;
        (*lista)->cab=temp;
        *e=0;
    }
    else{
        temp->info=datoInfo;
        temp->sig=NULL;
        temp=(*lista)->cab;
        if(aux->sig==NULL){
            temp->pos=1;
        }
        else{
            while(aux->sig!=NULL){
                aux=aux->sig;
            }
            temp->pos=aux->pos+1;
        }
        aux->sig=temp;
        *e=0;
    }

    struct Nodo* nodoaux=(*lista)->cab;
    while(nodoaux->sig!=NULL){
        nodoaux=nodoaux->sig;
        nodoaux->pos++;
    }
}

void agregarIzq(Lista*lista, int *e, Dato datoInfo){
    struct Nodo* aux=(struct Nodo*)malloc(sizeof(struct Nodo));
    if(aux==NULL){
        puts("La estructura no se creo correctamente");
        *e=-3;
    }
    else if((*lista)->cab==NULL){
        aux->info=datoInfo;
        aux->sig=(*lista)->cab;
        (*lista)->cab=aux;
    }
    else{
        aux->info=datoInfo;
        aux->sig=(*lista)->cab;
        (*lista)->cab=aux;
    }
    struct Nodo* nodoaux=(*lista)->cab;
    while(nodoaux->sig!=NULL){
        nodoaux=nodoaux->sig;
        nodoaux->pos++;
    }
}

void agregarPosN(Lista*lista, int *e, Dato datoInfo, int pos){
    struct Nodo* aux=(struct Nodo*)malloc(sizeof(struct Nodo));
    struct Nodo *anterior,*nuevo;
    anterior=NULL;
    nuevo=(*lista)->cab;
    aux->info=datoInfo;
    if(aux==NULL){
        puts("La lista esta vacia");
        *e=-1;
    }
    else if(!isEmpty(*lista,e)){
        while(nuevo->pos!=pos){
            anterior=nuevo;
            nuevo=nuevo->sig;

        }
        aux->sig=nuevo;
        anterior->sig=aux;
        struct Nodo*cursor=nuevo;
        while(cursor!=NULL){
            cursor->pos++;
            cursor=cursor->sig;

        }
        *e=0;
    }
    else if(isEmpty(*lista,e)){
        aux->info=datoInfo;
        aux->sig=NULL;
        aux->pos=0;
        (*lista)->cab=aux;
        *e=0;
    }
}

void extraerIzq(Lista*lista,int* e,Dato* datoE){
    struct Nodo*aux=NULL;
    if(isEmpty(*lista,e)){
        puts("La lista esta vacia\nNada que extraer");
    }
    else if((*lista)->cursor==1){
        *datoE=(*lista)->cab->info;
        free((*lista)->cab);
        (*lista)->cursor=0;
    }
    else if((*lista)->cursor>1){
        aux=(*lista)->cab;
        *datoE=(*lista)->cab->info;
        (*lista)->cab=aux->sig;
        (*lista)->cursor--;
        while(aux->sig!=NULL){
            aux=aux->sig;
            aux->pos--;
        }
        free(aux);
        *e=0;
    }
}

void recorrerLista(Lista lista, int *e){
    struct Nodo* aux=lista->cab;
    while(aux!=NULL){
        printf("\nElemento actual es %d en la posicion %d",aux->info.valor,aux->pos);
        aux=aux->sig;
    }
    *e=0;
}

void borrarLista(Lista* lista, int *e){
    if((*lista)->cab==NULL){
        puts("Lista vacia");
    }
    else{
        struct Nodo* aux=(*lista)->cab->sig;
        struct Nodo* aux2=(*lista)->cab;
        while(aux!=NULL){
            free(aux2);
            aux2=aux;
            aux=aux->sig;

        }
        free(aux2);

    }
    free(lista);
}

int entrada();
int entrada1();

void main(int argc,char** argv){
    int e,r,op,pos;
    Lista lista=crearLista(&e);
    Dato nodo;
    do{
        puts("Elija la opción deseada: ");
        puts("1.- Ingresar dato por la izquierda");
        puts("2.- Ingresar dato por la derecha");
        puts("3.- Ingresar dato por la posicion");
        puts("4.- Mostrar datos");
        puts("5.- Eliminar Lista");
        op=entrada();
        if(op>=1&&op<=3){
            puts("Ingrese un numero");
            scanf("%d",&nodo.valor);
            if(op==1){
                agregarIzq(&lista,&e,nodo);
            }
            else if(op==2){
                agregarDer(&lista,&e,nodo);
            }
            else if(op==3){
                puts("Digite la posicion donde se insertara la informacion");
                scanf("%d",&pos);
                agregarPosN(&lista,&e,nodo,pos);
            }
           
        }
        else if(op==4){
            recorrerLista(lista,&e);
        }
         else if(op==5){
            borrarLista(&lista,&e);    
        }
        puts("Desea volver al menu? \n1- Si\n2- No");
        r=entrada1();
    }while(r==1);
    system("pause");
}

int entrada(){
    int r;
    do{
        scanf("%d",&r);
        if(r<1||r>5)
            puts("\aOpción no valida");
            puts("Ingrese una opcion valida");
    }while(r<1||r>5);
    return r;
}

int entrada1(){
    int r;
    do{
        scanf("%d",&r);
        if(r<1||r>2)
            puts("\aOpción no valida");
            puts("Ingrese una opcion valida");
    }while(r<1||r>2);
    return r;
}