#include "Struct.h"
#include <stdio.h>
#include "menu.h"
#include "Altas.h"
int main(){
    int opcion;
    struct Persona *ptr=NULL;
    do{
        opcion=menuPrincipal();
    
        switch(opcion){
            case 1: altas(&ptr);
        
            break;
            case 2:

            break;
            case 3:
            break;
            case 4:
            break;

        }
    }while(opcion!=5);



return 0;
}
