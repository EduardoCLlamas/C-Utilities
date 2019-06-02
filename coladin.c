#include <stdio.h>
#include <stdlib.h>
int tam;

typedef struct _cola{
    int final;
    int *arreglo;
}cola;

void gen(cola *colaN,int n){
    colaN->arreglo = (int*)malloc(sizeof(int)*n);
	colaN-> final = 0;
}

void incrementa(cola *colaN,int n){
    colaN->arreglo = (int*)realloc(colaN->arreglo,sizeof(int)*n);
}
int push(cola *colaN,int n){
    int a,b;
	if (colaN->final >= tam){
		printf("Cola llena, no se pueden colocar mas elementos desea agregar mas memoria?\n");
		printf("1:SI, 2:NO\n");
		scanf("%d",&a);
		if(a == 1){
            printf("cuantos elementos quiere tener?\n");
            scanf("%d",&b);
            tam = b;
            incrementa(colaN,b);
            colaN->arreglo[colaN->final] = n;
            colaN->final++;
		}
		else if(a >= 2 || a < 1){
            return 0;
		}
	}
	else {
		colaN->arreglo[colaN->final]=n;
		colaN->final++;
	}


}
void pop_cola(cola *colaN){
    int aux,i;
	if ((*colaN).final == 0){
		printf("Cola vacia, no se pueden eliminar mas elementos");

	}
	else{
        printf("El elemento eliminado es:%d\n",colaN->arreglo[0]);
		for(i = 0;i < colaN->final;i++){
            aux = colaN->arreglo[i];
            colaN->arreglo[i] = colaN->arreglo[i + 1];
            colaN->arreglo[i + 1] = aux;
		}
		(*colaN).final--;
	}

}

void show_cola(cola *colaN){
    int i;
    for(i = 0;i < colaN->final;i++){
        printf("%d\n",colaN->arreglo[i]);
    }
}
void libera(cola *colaN){
    free(colaN->arreglo);
}
int main(){
    int n;
    printf("Cuantos elementos desea?\n");
    scanf("%d",&n);
    tam = n;
    cola colota;
    gen(&colota,n);
    push(&colota,1);
    /*push(&colota,10);
    push(&colota,100);
    push(&colota,1000);*/
    show_cola(&colota);
    pop_cola(&colota);
    pop_cola(&colota);
    show_cola(&colota);
    libera(&colota);
return 0;
}
