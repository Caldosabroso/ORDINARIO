#ifndef ALTAS_H
#define ALTAS_H
#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#include "menu.h"
//Funcion para reservar memoria de struct Persona
struct Persona *NuevoNodoPerso(void){
    struct Persona *ptrTemp;
    ptrTemp = (struct Persona*) malloc(sizeof(struct Persona));

    if(ptrTemp == NULL){
        printf("No se reservó memoria\n");
        return NULL;
    }
    ptrTemp->nombre = NULL;
    ptrTemp->ptrSig = NULL;
    ptrTemp->ptrAlum = NULL;

    return ptrTemp;
}

//Funcion para reservar memoria de struct Alumno
struct Alumno *NuevoNodoAlum(void){
    struct Alumno *ptrTemp;
    ptrTemp = (struct Alumno*) malloc(sizeof(struct Alumno));

    if(ptrTemp == NULL){
        printf("No se reservó memoria\n");
        return NULL;
    }

    return ptrTemp;
}
//Funcion para interactuar con Altas
void altas(struct Persona **ptr)
{
    int opcion;

    do{
        opcion = MenuAltas();

        switch(opcion)
        {
            case 1:
                agregarUnaPersona(ptr);//Falta hacer esta funcion, dentro se llama a la funcion capturar datos de persona
                break;

            case 2:
                agregarVariasPersonas(ptr);//Falta hacer esta funcion, dentro se llama a la funcion capturar datos de alumno
                break;
        }

    }while(opcion!=3);
}


#endif
