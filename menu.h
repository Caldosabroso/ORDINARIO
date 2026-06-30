#ifndef MENU_H
#define MENU_H
#include <stdio.h>

int menuPrincipal(void);//definicion o prototipo de la funcion
int menuPrincipal(void){
    int opcion;
    printf("--------MENU--------\n[1] ALTAS\n[2] BAJAS\n[3] MOSTRAR\n[4] ESPECIALES\n[5] Terminar programa\n ");
        scanf("%d",&opcion);
        return opcion;
}

//Submenu para varias o solo una persona
int MenuAltas(void){
    int opcion;
        printf("-----------OPCIONES-----------\nCuantas persona desea dar de ALTA?\n");
        printf("[1] Una persona\n");
        printf("[2] Varias personas\n");
        printf("[3] Regresar al menu anterior\n");
        scanf("%d",&opcion);
    return opcion;
}
//Submenu para eliminar una, varias o todas las personas
int MenuBajas(void){
    int opcion;
        printf("-----------OPCIONES-----------\nQué desea hacer?\n");
        printf("[1] Eliminar la primera persona\n");
        printf("[2] Eliminar varias personas\n");
        printf("[3] Eliminar todas las personas\n");
        printf("[4] Regresar al menu anterior\n");
        scanf("%d",&opcion);
    return opcion;
}
int MenuMostrar(void){
    int opcion;
        printf("-----------OPCIONES-----------\nQue desea hacer?\n");
        printf("[1] Mostrar a todas las personas\n");
        printf("[2] Mostrar a las personas de la carrera seleccionada\n");
        printf("[3] Mostrar todas las personas del semestre seleccionado\n");
        printf("[4] Mostrar a todas las personas del semestre y carrera\n");
        printf("[5] Buscar a una persona por nombre\n");
        printf("[6] Buscar a un alumno por matricula\n");
        printf("[7] Regresar al menu anterior\n");
        scanf("%d",&opcion);
    return opcion;
}
int Menucarreras(void){
    int opcion;
        printf("-----------OPCIONES-----------\nSeleccione la carrera:\n");
        printf("[1] IDDSI\n");
        printf("[2] LCA\n");
        printf("[3] LAT\n");
        printf("[4] LB\n");
        printf("[5] LF\n");
        scanf("%d",&opcion);
    return opcion;
}
int Menusemestre(void){
    int opcion;
        printf("-----------OPCIONES-----------\nSeleccione el semestre:\n");
        printf("[1] 1er semestre\n");
        printf("[2] 2do semestre\n");
        printf("[3] 3er semestre\n");
        printf("[4] 4to semestre\n");
        printf("[5] 5to semestre\n");
        printf("[6] 6to semestre\n");
        printf("[7] 7mo semestre\n");
        printf("[8] 8vo semestre\n");
        printf("[9] 9no semestre\n");
        printf("[10] 10mo semestre\n");
        scanf("%d",&opcion);
    return opcion;
}

#endif
