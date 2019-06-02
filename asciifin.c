#include <stdio.h>
int longitud(char *s){
	int cont = 0;
	while(*s != '\0'){
		cont++;
		s++;
	}
	return cont;
}
int main(int argc, char **argv){
    FILE *entrada,*salida;
    char hola[100];
    int i,c;
        for(i=0;i<100;i++){
        hola[i]='\0';
    }
    entrada=fopen(argv[1],"r");
    for(i=0;i<100;i++){
    fscanf(entrada,"%c", &hola[i]);
    }
    c=longitud(hola);
    printf("%d\n", c);
    for(i=0;i<c;i++){
        printf("%c ", hola[i]);
    }


    salida=fopen(argv[2],"w");
    for(i=0;i<c;i++){
        printf("%d ", hola[i]);
        fprintf(salida,"%d ", hola[i]);
    }
    fclose(entrada);
    fclose(salida);
    return 0;
}
