#include "LCDE.h"

Lista crearLista(int *e){
    Lista l = (Elemento_Lista*)malloc(sizeof(Lista));
    if(l==NULL){
        puts("No hay memoria para la lista");
        *e=-1;
    }else{
        l->cab=NULL;
        l->cursor=0;
        *e=0;
    }
    return l;
}

void agregarDer(Lista *lista, int *e, Dato ingresar){
    struct Nodo* aux;
    struct Nodo* nodoUsuario = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(nodoUsuario==NULL){
        puts("No se pudo asignar memoria");
        *e=-3;
    }else{
        nodoUsuario->info=ingresar;
        if((*lista)->cab==NULL){
            nodoUsuario->pos=0;
            (*lista)->cab=nodoUsuario;
            nodoUsuario->sig=nodoUsuario;
            nodoUsuario->ant=nodoUsuario;
            (*lista)->cursor=(*lista)->cursor+1;
            *e=0;
            puts("nodo agregado");
        }else{
            aux = (*lista)->cab;
            if(aux->sig==(*lista)->cab){
                nodoUsuario->pos=1;
            }else{
                while(aux->sig!=(*lista)->cab){
                    aux=aux->sig;
                }
                nodoUsuario->pos=aux->pos+1;
            }
            aux->sig=nodoUsuario;
            (*lista)->cab->ant=nodoUsuario;
            nodoUsuario->sig=(*lista)->cab;
            nodoUsuario->ant=aux;
            (*lista)->cursor=(*lista)->cursor+1;
            *e=0;
            puts("nodo agregado");
        }
    }
}

void agregarIzq(Lista *lista, int *e, Dato ingresar){
    struct Nodo* aux;
    struct Nodo* nodoUsuario = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(nodoUsuario==NULL){
        puts("No se pudo asignar memoria");
        *e=-3;
    }else{
        nodoUsuario->info=ingresar;
        if((*lista)->cab==NULL){
            nodoUsuario->pos=0;
            (*lista)->cab=nodoUsuario;
            nodoUsuario->sig=nodoUsuario;
            nodoUsuario->ant=nodoUsuario;
            (*lista)->cursor=(*lista)->cursor+1;
            *e=0;
            puts("nodo agregado");
        }else{
            nodoUsuario->sig=(*lista)->cab;
            nodoUsuario->pos=0;
            aux = (*lista)->cab;
            (*lista)->cab->ant=nodoUsuario;
            while(aux->sig!=(*lista)->cab){
                aux->pos=aux->pos+1;
                aux=aux->sig;
            }
            aux->sig=nodoUsuario;
            nodoUsuario->ant=aux;
            aux->pos=aux->pos+1;
            (*lista)->cab=nodoUsuario;
            (*lista)->cursor=(*lista)->cursor+1;
            puts("nodo agregado");
        }
    }
}

void agregarPosN(Lista *lista, int *e, Dato ingresar, int n){
    struct Nodo* aux;
    struct Nodo* nodoUsuario = (struct Nodo*)malloc(sizeof(struct Nodo));
    if(nodoUsuario==NULL){
        puts("No se pudo reservar memoria");
        *e=-3;
    }else{
        if(n>(*lista)->cursor){
            puts("No hay suficientes elementos en la lista");
        }else{
            if(n==0){
                agregarIzq(lista, e, ingresar);
                puts("nodo agregado");
            }else{
                nodoUsuario->info=ingresar;
                if((*lista)->cab==NULL){
                    nodoUsuario->pos=0;
                    (*lista)->cab=nodoUsuario;
                    nodoUsuario->sig=nodoUsuario;
                    nodoUsuario->ant=nodoUsuario;
                    (*lista)->cursor=(*lista)->cursor+1;
                    *e=0;
                    puts("nodo agregado");
                }else{
                    aux=(*lista)->cab;
                    while(aux->sig->pos!=n){
                        aux=aux->sig;
                    }
                    nodoUsuario->sig=aux->sig;
                    aux->sig->ant=nodoUsuario;
                    aux->sig=nodoUsuario;
                    nodoUsuario->ant=aux;
                    nodoUsuario->pos=aux->pos+1;
                    aux=nodoUsuario->sig;
                    while(aux!=(*lista)->cab){
                        aux->pos=aux->pos+1;
                        aux=aux->sig;
                    }
                    (*lista)->cursor=(*lista)->cursor+1;
                    puts("nodo agregado");
                }
            }
        }
    }
}

void recorrerLista(Lista *lista, int *e){
    if((*lista)->cab==NULL){
        puts("La lista se encuentra vacia");
    }else{
        struct Nodo* aux = (*lista)->cab;
        printf("Se tienen %d datos\n", (*lista)->cursor);
        while(aux->sig!=(*lista)->cab){
            printf("Dato en la posicion %d\n", aux->pos);
            printf("    Informacion: %d\n\n", aux->info.valor);
            aux=aux->sig;
        }
        printf("Dato en la posicion %d\n", aux->pos);
        printf("    Informacion: %d\n\n", aux->info.valor);
    }
}

void borrarLista(Lista *lista, int *e){
    if((*lista)->cursor!=0){
        puts("La lista aun contiene elementos");
    }else{
        free(lista);
        puts("Lista borrada");
    }
}

void extraerIzq(Lista *lista, int *e, Dato *extraido){
    struct Nodo* aux;
    if((*lista)->cab==NULL){
        puts("La lista no contiene elementos");
        *e=-2;
    }else{
        if((*lista)->cursor==1){
            aux = (*lista)->cab;
            (*lista)->cab=NULL;
            aux->sig=NULL;
            aux->ant=NULL;
            *extraido=aux->info;
            free(aux);
            *e=0;
            printf("Dato extraido: %d\n", extraido->valor);
            (*lista)->cursor=(*lista)->cursor-1;
        }else{
            aux = (*lista)->cab;
            struct Nodo* aux2 = aux->sig;
            while(aux2->sig!=(*lista)->cab){
                aux2=aux2->sig;
            }
            aux2->sig=aux->sig;
            aux->sig->ant=aux2;
            (*lista)->cab=aux->sig;
            aux->sig=NULL;
            aux->ant=NULL;
            *extraido = aux->info;
            free(aux);
            aux=(*lista)->cab;
            while(aux2!=aux){
                aux->pos=aux->pos-1;
                aux=aux->sig;
            }
            aux2->pos=aux2->pos-1;
            *e=0;
            printf("Dato extraido: %d\n", extraido->valor);
            (*lista)->cursor=(*lista)->cursor-1;
        }
    }
}

void extraerDer(Lista *lista, int *e, Dato *extraido){
    struct Nodo* aux;
    if((*lista)->cab==NULL){
        puts("La lista no contiene elementos");
        *e=-2;
    }else{
        if((*lista)->cursor==1){
            aux = (*lista)->cab;
            (*lista)->cab=NULL;
            aux->sig=NULL;
            aux->ant=NULL;
            *extraido=aux->info;
            free(aux);
            *e=0;
            printf("Dato extraido: %d\n", extraido->valor);
            (*lista)->cursor=(*lista)->cursor-1;
        }else{
            aux = (*lista)->cab;
            struct Nodo* aux2 = aux->sig;
            while(aux2->sig!=(*lista)->cab){
                aux2=aux2->sig;
            }
            while(aux->sig!=aux2){
                aux=aux->sig;
            }
            aux2->sig=NULL;
            aux->sig=(*lista)->cab;
            (*lista)->cab->ant=aux;
            aux2->ant=NULL;
            *extraido=aux->info;
            free(aux2);
            printf("Dato extraido: %d\n", extraido->valor);
            (*lista)->cursor=(*lista)->cursor-1;
        }
    }
}

void extraerN(Lista *lista, int *e, Dato *extraido, int n){
    if((*lista)->cab==NULL){
        puts("La lista no contiene elementos");
        *e=-2;
    }else{
        if(n>(*lista)->cursor){
            puts("La lista no contiene suficientes elementos");
        }else{
            if(n==0){
                extraerIzq(lista,e,extraido);
            }else{
                struct Nodo* aux = (*lista)->cab;
                struct Nodo* aux2 = (*lista)->cab;
                while(aux->pos!=n){
                    aux=aux->sig;
                }
                while(aux2->sig!=aux){
                    aux2=aux2->sig;
                }
                *extraido = aux->info;
                aux2->sig=aux->sig;
                aux->sig->ant=aux2;
                aux->sig=NULL;
                aux->ant=NULL;
                free(aux);
                aux2=aux2->sig;
                while(aux2!=(*lista)->cab){
                    aux2->pos=aux2->pos-1;
                    aux2=aux2->sig;
                }
                printf("Dato extraido: %d\n", extraido->valor);
                (*lista)->cursor=(*lista)->cursor-1;
            }   
        }  
    }
}

void vaciarLista(Lista *lista, int *e){
    struct Nodo* aux = (*lista)->cab;
    struct Nodo* aux2 = (*lista)->cab->sig;
    if((*lista)->cab==NULL){
        puts("Lista vacia");
        *e=-2;
    }else{
        if((*lista)->cursor==1){
            Dato dato;
            extraerIzq(lista,e,&dato);
            puts("Lista vaciada con exito");
        }else{
            printf("Inicia vaciado de %d elementos\n", (*lista)->cursor);
            aux->sig=NULL;
            aux2->ant=NULL;
            (*lista)->cab=NULL;
            while(aux2->sig!=NULL){
                aux=aux2->sig;
                aux2->sig=NULL;
                aux->ant=NULL;
                free(aux2);
                aux2=aux;
                (*lista)->cursor=(*lista)->cursor-1;
            }
            free(aux2);
            (*lista)->cursor=(*lista)->cursor-1;
            puts("Lista vaciada con exito");
        }
    }
}

void update(Lista *lista,int *e, Dato ingresar, int n){
    struct Nodo* aux=(*lista)->cab;
    if(n>=(*lista)->cursor||n<0){
        puts("No se encuentra la posicion");
    }else{
        while(aux->pos!=n){
            aux=aux->sig;
        }
        aux->info=ingresar;
        printf("Dato actualizado: %d\n", aux->info);
    }
}
