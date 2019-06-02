#include <stdio.h>
#include <string.h>
int intercambia_cadenas(char s[], char t[]){
    char aux[1001];
    strcpy(aux, s);
    strcpy(s, t);
    strcpy(t, aux);
    return;
}

int main(int argc, char **argv){
    FILE *arch_nombres, *arch_salida;
    char nombre[1001][11];
    int n,i,j;
    arch_nombres=fopen(argv[1], "r");
    fscanf(arch_nombres,"%d",&n);
    for(i=0;i<n;i++){
        fscanf(arch_nombres,"%s",nombre[i]);
    }

    for(i = 0; i < n; i++){
        for(j = i; j < n; j++){
            if((strcmp(nombre[i], nombre[j])) > 0){
                intercambia_cadenas(nombre[i],nombre[j]);
            }
        }
    }

    arch_salida=fopen(argv[2], "w");
    for(i = 0; i < n; i++){
        fprintf(arch_salida,"%s\n", nombre[i]);
    }

    fclose(arch_nombres);
    fclose(arch_salida);
    return 0;
}

