#include <stdio.h>
#include <stdlib.h>
#define COLS 24
#define FILA 5
int main(int argc, char **argv){
    FILE *arch_text, *arch_salida;

    char text[COLS][FILA];
    int i,j;

    arch_text=fopen(argv[1],"r");

    for(i=0;i<COLS;i++){
        for(j=i;j<FILA;j++){
            fscanf(arch_text,"%c",&text[i][j]);
        }
    }
    arch_salida=fopen(argv[2],"w");
    for(i=0;i<COLS;i++){
        for(j=i;j<FILA;j++){
            printf("%d ", text[i][j]);
            fprintf(arch_salida,"%d ", text[i][j]);
        }
        printf("\n");
    }
    fclose(arch_text);
    fclose(arch_salida);
    return 0;
}

