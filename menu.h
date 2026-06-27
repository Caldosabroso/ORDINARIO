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
    do{
        printf("-----------OPCIONES-----------\n¿Cuantas persona desea dar de ALTA?\n");
        printf("[1] Una persona\n");
        printf("[2] Varias personas\n");
        printf("[3] Regresar al menu anterior\n");
        scanf("%d",&opcion);
    }while(opcion==3);
    return opcion;
}
#endif
