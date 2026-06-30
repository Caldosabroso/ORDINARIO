#ifndef ALTAS_H
#define ALTAS_H
#include <stdio.h>
#include <stdlib.h>
#include "Struct.h"
#include "menu.h"
#include <string.h>
void agregarUnaPersona(struct Persona **ptr);
void agregarVariasPersonas(struct Persona **ptr);

void capturarPersona(struct Persona *persona);
void capturarAlumno(struct Alumno *alumno);

void insertarLista(struct Persona **ptr,struct Persona *nuevo);

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
                agregarUnaPersona(ptr);//dentro se llama a la funcion capturar datos de persona
                break;

            case 2:
                agregarVariasPersonas(ptr);//dentro se llama a la funcion capturar datos de alumno
                break;
        }

    }while(opcion!=3);
}
//Funcion para agregar una persona/////////////////////////////////////////
void agregarUnaPersona(struct Persona **ptr)
{
    struct Persona *nuevaPersona = NuevoNodoPerso();
    if(nuevaPersona == NULL){
        return;
    }

    nuevaPersona->ptrAlum = NuevoNodoAlum();
     if(nuevaPersona->ptrAlum == NULL){   
        printf("No se pudo crear el registro del alumno\n");
        free(nuevaPersona);
        return;
    }

    capturarPersona(nuevaPersona);
    capturarAlumno(nuevaPersona->ptrAlum);

    insertarLista(ptr, nuevaPersona);
    printf("Persona agregada exitosamente.\n");
}

//Funcion para capturar datos de la persona
void capturarPersona(struct Persona *persona)
{
    char aux[100];

    printf("Nombre: ");
    getchar();                 // Limpia el '\n' que pudo quedar del scanf anterior
    fgets(aux, 100, stdin);

    aux[strcspn(aux, "\n")] = '\0'; // Elimina el salto de línea

    persona->nombre = (char *)malloc(strlen(aux) + 1);
    char genero;
    if(persona->nombre == NULL)
    {
        printf("No se pudo reservar memoria para el nombre.\n");
        return;
    }

    strcpy(persona->nombre, aux);

    printf("Edad: ");
    scanf("%d", &persona->edad);

    printf("Genero [M] Masculino\n[F] Femenino\n Indique la letra: ");
    scanf(" %c", &genero);
    if(genero == 'M' || genero == 'm'){
    persona->genero = 'M';
    }
    else if(genero == 'F' || genero == 'f'){
    persona->genero = 'F';}

    printf("Fecha de nacimiento (dd/mm/aa): ");
    scanf("%8s", persona->fn);
}

//Funcion para capturar datos del alumno
void capturarAlumno(struct Alumno *alumno)
{
    printf("Matricula: ");
    scanf("%9s", alumno->matricula);

    printf("Carrera: ");
    scanf("%5s", alumno->carrera);

    printf("Semestre: ");
    scanf("%d", &alumno->semestre);

    printf("Correo: ");
    scanf("%22s", alumno->correo);
    for(int i = 0; i < 5; i++)
    {
        printf("Calificaciones de la materia %d (3 parciales y 1 ordinario):\n", i + 1);
        for(int j = 0; j < 4; j++)
        {
            printf("Calificacion %d: ", j + 1);
            scanf("%f", &alumno->calificacion[i][j]);
        }
    }
}
//Funcion insertar en la lista
void insertarLista(struct Persona **ptr, struct Persona *nuevo)
{
    struct Persona *aux;

    //Caso 1: La lista está vacía
    if(*ptr == NULL)
    {
        *ptr = nuevo;
    }
    else
    {
        //Caso 2: Ya existen uno o más nodos
        aux = *ptr;

        while(aux->ptrSig != NULL)
        {
            aux = aux->ptrSig;
        }

        aux->ptrSig = nuevo;
    }
}
//Funcion para agregar varias personas
void agregarVariasPersonas(struct Persona **ptr)
{
    int respuesta;
    do{
        agregarUnaPersona(ptr);
        printf("Desea agregar otra persona? [1]: Si, [0]: No: ");
        scanf("%d", &respuesta);
        if(respuesta == 0)
        {
            break;
        }
    }while(respuesta ==1);

}
#endif
