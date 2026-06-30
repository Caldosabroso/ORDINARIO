#ifndef BAJAS_H
#define BAJAS_H
#include <stdio.h>
#include "menu.h"
#include "Struct.h"
#include <stdlib.h>
void bajas(struct Persona **ptr);
void eliminarPrimeraPersona(struct Persona **ptr);
void eliminarVariasPersonas(struct Persona **ptr);
void eliminarTodasLasPersonas(struct Persona **ptr);

//Funcion para interactuar con Bajas
void bajas(struct Persona **ptr)
{
    int opcion;

    do
    {
        opcion = MenuBajas();

        switch(opcion)
        {
            case 1:
                eliminarPrimeraPersona(ptr);
                break;

            case 2:
                eliminarVariasPersonas(ptr);
                break;

            case 3:
                eliminarTodasLasPersonas(ptr);
                break;
        }

    }while(opcion != 4);
}
//Funcion para eliminar la primera persona de la lista
void eliminarPrimeraPersona(struct Persona **ptr)
{
    if(*ptr == NULL)
    {
        printf("La lista esta vacia. No hay personas para eliminar.\n");
        return;
    }

    struct Persona *temp = *ptr;
    *ptr = (*ptr)->ptrSig;
    printf("Se elimino a %s\n", temp->nombre);
    // Liberar memoria de la persona eliminada
    free(temp->nombre);
    free(temp->ptrAlum);
    free(temp);

    printf("Se ha eliminado la primera persona de la lista\n");
}
//Funcion para eliminar varias personas de la lista
void eliminarVariasPersonas(struct Persona **ptr){
    if(*ptr == NULL)
    {
        printf("La lista está vacía\n");
        return;
    }

    int opcion;
    do
    {
        eliminarPrimeraPersona(ptr);

        if(*ptr == NULL)
        {
            printf("No hay más personas para eliminar.\n");
            break;
        }

        printf("Desea eliminar a otra persona? [1]: Sí, [0]: No: ");
        scanf("%d", &opcion);
    } while(opcion == 1);
}

//Funcion para eliminar todas las personas de la lista
void eliminarTodasLasPersonas(struct Persona **ptr)
{
    if(*ptr == NULL)
    {
        printf("La lista esta vacia. No hay personas para eliminar.\n");
        return;
    }

    while(*ptr != NULL)
    {
        eliminarPrimeraPersona(ptr);
    }

    printf("Se han eliminado todas las personas de la lista.\n");
}
#endif
