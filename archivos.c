#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _alumno{
    double promedio;
    long long int matricula;
    char nombre[100];
}alumno;


/*
*/
int main(int argc, char **argv){
    FILE *arch_alumnos, *arch_salida;
    alumno al[10];
    int valor, i, n = 0;
    for(i = 0; i < argc; i++)
        printf("%d) %s\n", i, argv[i]);
    if(argc < 3){
       /*Ejecutable = argv[0]
       <nombre_entrada> = argv[1]
       <nombre_salida> = argv[2]*/
        printf("Uso:Ejecutable <nombre_entrada> <nombre_salida>\n");
        printf("<nombre_entrada>: Es el archivo que contiene nombres y matriculas\n");
        printf("<nombre_salida>: Es el archivo donde se almacenaran los resultados\n");
        exit(0);
    }
    valor = atoi(argv[3]);
    printf("%d %s\n", valor, argv[3]);
    if((arch_alumnos = fopen(argv[1], "r"))== NULL){
        printf("Error el archivo \"%s\" no se pudo abrir", argv[1]);
        exit(0);
    }
    /*entrada con formato, se define mediante []*/
    /*entre corchetes digo todo lo que quiero leer
    o hasta donde no quiero leer con ^*/
    while(fscanf(arch_alumnos, "%[^|]|%lld|%lf",
        al[n].nombre, &al[n].matricula, &al[n].promedio)==3){
        n++;
        while(fgetc(arch_alumnos) != '\n');
    }
    if((arch_salida = fopen(argv[2], "w")) == NULL){
        printf("El archivo de salida no se pudo crear\n");
        exit(0);
    }
    for(i = 0; i < n; i++){
        fprintf(arch_salida, "%-15lld %30s %5.2f\n", al[i].matricula, al[i].nombre, al[i].promedio);
    }
    fclose(arch_alumnos);
    fclose(arch_salida);
    return 0;
}
