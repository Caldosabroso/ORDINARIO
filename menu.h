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
#endif
