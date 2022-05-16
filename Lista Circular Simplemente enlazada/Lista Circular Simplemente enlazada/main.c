#include "LCSE.h"

int main(){
    int e=0;
    Lista lista = crearLista(&e);
    Dato nodoUsuario;

    nodoUsuario.valor=5;
    agregarDer(&lista,&e,nodoUsuario);

    nodoUsuario.valor=8;
    agregarDer(&lista,&e,nodoUsuario);

    nodoUsuario.valor=7;
    agregarIzq(&lista,&e,nodoUsuario);

    nodoUsuario.valor=33;
    agregarPosN(&lista, &e, nodoUsuario,1);

    nodoUsuario.valor=12;
    agregarIzq(&lista,&e,nodoUsuario);

    nodoUsuario.valor=52;
    agregarDer(&lista,&e,nodoUsuario);

    recorrerLista(&lista,&e);
    vaciarLista(&lista,&e);
    recorrerLista(&lista,&e);
    borrarLista(&lista,&e);
    recorrerLista(&lista,&e);

    puts("Programa finalizado");
    return e;
}