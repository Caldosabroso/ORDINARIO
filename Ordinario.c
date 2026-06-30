#include "Struct.h"
#include <stdio.h>
#include "menu.h"
#include "Altas.h"
#include "Bajas.h"
#include "Especiales.h"
#include "Mostrar.h"
int main(){
    int opcion;
    struct Persona *ptr=NULL;
    do{
        opcion=menuPrincipal();
    
        switch(opcion){
            case 1: altas(&ptr);
        
            break;
            case 2: bajas(&ptr);

            break;
            case 3: mostrarPersonas(ptr);
            break;
            case 4:
            break;
            case 5: eliminarTodasLasPersonas(&ptr);
            printf("PROGRAMA FINALIZADO\n");
            break;

            default:
            printf("Opción no válida.\n");
    }
    }while(opcion!=5);



return 0;
}
