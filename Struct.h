#ifndef STRUCTS_H
#define STRUCTS_H



struct Persona{
    char *nombre;//fgets y luego calcular con malloc
    int edad;//malloc
    char genero;//[1]Masculino,[2]Femenino
    char fn[9];//dd/mm/aa
    struct Persona *ptrSig;
    struct Alumno *ptrAlum;
};
struct Alumno{
    char matricula[10];
    char carrera[6];//IDDSI,LCA,LAT,LB,LF.
    int semestre;//1,2,3,4,5,6,7,8,9,10
    char correo[23];//
    float calificacion[5][5];//3 parciales y 1 ordinario,5 promedios, 5 materias
};
#endif