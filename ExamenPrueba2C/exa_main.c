#include "exa.h"

int main(int argc, char** argv){
    int error, numgen;
    Dato persona;
    Cola cola=crearCola(&error);
    
    

    /// SE LLENA LA COLA
    for(int i=0;i<atoi(argv[1]);i++){
        printf("\n\n\t: : PERSONA %d : :",i);

        fflush(stdin);

        printf("\nIngresa el nombre de la persona: ");
        scanf("%s",persona.nombre);

        persona.edad=numAle();
        printf("\nEdad de la persona: %d",persona.edad);

        printf("\n\nIngresa la altura de la persona: ");
        scanf("%f",&persona.altura);

        printf("\n: : : : : : : : : : : : : : : : : : : :");

        encolar(&cola,&error,persona);
    }

    ///DECLARACION DE ROBOTS Y LLENADO DE LAS LISTAS DE LOS ROBOTS
    Lista *robot1, *robot2, *robot3, *robot4, *robot5;

    if ((robot1 = (Lista *) malloc (sizeof (Lista))) == NULL){
        puts("\nNo se pudo crear robot 1");
    }

    if ((robot2 = (Lista *) malloc (sizeof (Lista))) == NULL){
        puts("\nNo se pudo crear robot 2");
    }

    if ((robot3 = (Lista *) malloc (sizeof (Lista))) == NULL){
        puts("\nNo se pudo crear robot 3");
    }

    if ((robot4 = (Lista *) malloc (sizeof (Lista))) == NULL){
        puts("\nNo se pudo crear robot 4");
    }

    if ((robot5 = (Lista *) malloc (sizeof (Lista))) == NULL){
        puts("\nNo se pudo crear robot 5");
    }

    inicializar(robot1);
    inicializar(robot2);
    inicializar(robot3);
    inicializar(robot4);
    inicializar(robot5);

    //Aqui se distribuyen en las listas
    borraCola(&cola,&error,robot1,robot2,robot3,robot4,robot5);
    Atender(robot1,robot2,robot3,robot4,robot5);
    return 0;
}