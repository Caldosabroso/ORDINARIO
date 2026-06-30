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
        printf("-----------OPCIONES-----------\n¿Cuantas persona desea dar de ALTA?\n");
        printf("[1] Una persona\n");
        printf("[2] Varias personas\n");
        printf("[3] Regresar al menu anterior\n");
        scanf("%d",&opcion);
    return opcion;
}
//Submenu para eliminar una, varias o todas las personas
int MenuBajas(void){
    int opcion;
        printf("-----------OPCIONES-----------\n¿Qué desea hacer?\n");
        printf("[1] Eliminar la primera persona\n");
        printf("[2] Eliminar varias personas\n");
        printf("[3] Eliminar todas las personas\n");
        printf("[4] Regresar al menu anterior\n");
        scanf("%d",&opcion);
    return opcion;
}

#endif
