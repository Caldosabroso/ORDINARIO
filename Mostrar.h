#ifndef MOSTRAR_H
#define MOSTRAR_H
#include <stdio.h>
#include "menu.h"
#include <string.h>
#include "Struct.h"
void mostrarTodasLasPersonas(struct Persona *ptr);
void mostrarPersonasPorCarrera(struct Persona *ptr, const char *carrera);
void mostrarPersonasPorSemestre(struct Persona *ptr, int semestre);
void buscarPersonaPorNombre(struct Persona *ptr, const char *nombre);
void buscarAlumnoPorMatricula(struct Persona *ptr, const char *matricula);
void imprimirPersona(struct Persona *persona);
void imprimirAlumno(struct Alumno *alumno);
void mostrarPersonas(struct Persona *ptr);
//Funcion general de mostrar a las personas de la lista
void mostrarPersonas(struct Persona *ptr)
{
    int opcion;
    do
    {
        opcion = MenuMostrar();

        switch(opcion)
        {
            case 1:
                mostrarTodasLasPersonas(ptr);
                break;

            case 2:{
            
                int carreraSeleccionada = Menucarreras();
                char carrera[6];
                switch (carreraSeleccionada)
                {
                case 1:
                    strcpy(carrera, "IDDSI");
                    break;
                case 2:
                    strcpy(carrera, "LCA");
                    break;
                case 3:
                    strcpy(carrera, "LAT");
                    break;
                case 4:
                    strcpy(carrera, "LB");
                    break;
                case 5:
                    strcpy(carrera, "LF");
                    break;
                default:
                    printf("Carrera no valida.\n");
                    continue; // Salir del switch y volver al menú
                }
                
                mostrarPersonasPorCarrera(ptr, carrera);
                break;
            }
            
            case 3:{
                int semestreSeleccionado = Menusemestre();
                mostrarPersonasPorSemestre(ptr, semestreSeleccionado);
                break;
            }
            case 4:
               
                break;
            case 5:
                {
                    char nombre[100];
                    printf("Ingrese el nombre de la persona a buscar: ");
                    scanf(" %[^\n]", nombre);
                    buscarPersonaPorNombre(ptr, nombre);
                }
                break;
            case 6:
                {
                    char matricula[10];
                    printf("Ingrese la matrícula del alumno a buscar: ");
                    scanf(" %9s", matricula);
                    buscarAlumnoPorMatricula(ptr, matricula);
                break;
                }
                
                default:
                    printf("Opcion no valida.\n");
                    break;
                
                
        }
        

    } while(opcion != 7);
}
//Funcion para mostrar a todas las personas de la lista
void mostrarTodasLasPersonas(struct Persona *ptr)
{
    if(ptr == NULL)
    {
        printf("La lista esta vacia. No hay personas para mostrar.\n");
        return;
    }

    struct Persona *aux = ptr;

    while(aux != NULL)
    {
        // Imprimir información de la persona
        imprimirPersona(aux);
        if(aux->ptrAlum != NULL)
        {
            // Imprimir información del alumno
            imprimirAlumno(aux->ptrAlum);
        }

        printf("-------------------------\n");
        aux = aux->ptrSig;
    }
}
//Funcion para mostrar a las personas de una carrera seleccionada
void mostrarPersonasPorCarrera(struct Persona *ptr, const char *carrera)
{
    if(ptr == NULL)
    {
        printf("La lista esta vacia. No hay personas para mostrar.\n");
        return;
    }

    struct Persona *aux = ptr;
    int encontrado = 0;

    while(aux != NULL)
    {
        if(aux->ptrAlum != NULL && strcmp(aux->ptrAlum->carrera, carrera) == 0)
        {
            // Imprimir información de la persona encontrada
            imprimirPersona(aux);
            if(aux->ptrAlum != NULL)
            {
                // Imprimir información del alumno
                imprimirAlumno(aux->ptrAlum);
            }
            printf("-------------------------\n");
            encontrado = 1;
        }
        aux = aux->ptrSig;
    }

    if(!encontrado)
    {
        printf("No se encontraron personas en la carrera seleccionada.\n");
    }
}
//funcion para mostrar a las personas de un semestre seleccionado
void mostrarPersonasPorSemestre(struct Persona *ptr, int semestre)
{
    if(ptr == NULL)
    {
        printf("La lista esta vacia. No hay personas para mostrar.\n");
        return;
    }

    struct Persona *aux = ptr;
    int encontrado = 0;

    while(aux != NULL)
    {
        if(aux->ptrAlum != NULL && aux->ptrAlum->semestre == semestre)
        {
            // Imprimir información de la persona encontrada
            imprimirPersona(aux);
            if(aux->ptrAlum != NULL)
            {
                // Imprimir información del alumno
                imprimirAlumno(aux->ptrAlum);
            }
            printf("-------------------------\n");
            encontrado = 1;
        }
        aux = aux->ptrSig;
    }

    if(!encontrado)
    {
        printf("No se encontraron personas en el semestre seleccionado.\n");
    }
}
//funcion para buscar a un alumno por matricula
void buscarAlumnoPorMatricula(struct Persona *ptr, const char *matricula)
{
    if(ptr == NULL)
    {
        printf("La lista esta vacia. No hay alumnos para buscar.\n");
        return;
    }

    struct Persona *aux = ptr;
    int encontrado = 0;

    while(aux != NULL)
    {
        if(aux->ptrAlum != NULL && strcmp(aux->ptrAlum->matricula, matricula) == 0)
        {
            // Imprimir información del alumno encontrado
            imprimirPersona(aux);
            imprimirAlumno(aux->ptrAlum);
            printf("-------------------------\n");
            encontrado = 1;
        }
        aux = aux->ptrSig;
    }

    if(!encontrado)
    {
        printf("No se encontro al alumno con la matricula especificada.\n");
    }
}
//Funcion para buscar a una persona por nombre
void buscarPersonaPorNombre(struct Persona *ptr, const char *nombre)
{
    if(ptr == NULL)
    {
        printf("La lista esta vacia. No hay personas para buscar.\n");
        return;
    }

    struct Persona *aux = ptr;
    int encontrado = 0;

    while(aux != NULL)
    {
        if(strcmp(aux->nombre, nombre) == 0)
        {
            // Imprimir información de la persona encontrada
            imprimirPersona(aux);
            if(aux->ptrAlum != NULL)
            {
                // Imprimir información del alumno
                imprimirAlumno(aux->ptrAlum);
            }
            printf("-------------------------\n");
            encontrado = 1;
        }
        aux = aux->ptrSig;
    }

    if(!encontrado)
    {
        printf("No se encontro a la persona con el nombre especificado.\n");
    }
}
//Funcion imprimir persona
void imprimirPersona(struct Persona *persona){
    
     printf("Nombre: %s\n", persona->nombre);
        printf("Edad: %d\n", persona->edad);
        printf("Genero: %c\n", persona->genero);
        printf("Fecha de nacimiento: %s\n", persona->fn);
}
//Funcion imprimir alumno
void imprimirAlumno(struct Alumno *alumno){
    
    printf("Matricula: %s\n", alumno->matricula);
    printf("Carrera: %s\n", alumno->carrera);
    printf("Semestre: %d\n", alumno->semestre);
    printf("Correo: %s\n", alumno->correo);
}
#endif
