#include <stdio.h>
#include <stdlib.h>
int tam;

typedef struct pila{
	int elementos;
	int *a;
}pila;

void crear_pila(pila *pilaX,int n){
    pilaX->a = (int*)malloc(sizeof(int)*n);
	pilaX-> elementos = 0;
}

void incrementa(pila *pilaX,int n){
    pilaX->a = (int*)realloc(pilaX->a,sizeof(int)*n);//se coloca lo que se va a redimencionar antes del sizeof
}

int push_pila(pila *pilaX,int n){
    int a,b;
	if (pilaX->elementos >= tam){
		printf("Pila llena, no se pueden colocar mas elementos desea agregar mas memoria?\n");
		printf("1:SI, 2:NO\n");
		scanf("%d",&a);
		if(a == 1){
            printf("cuantos elementos quiere tener?\n");
            scanf("%d",&b);
            tam = b;
            incrementa(pilaX,b);
            pilaX->a[pilaX->elementos] = n;
            pilaX->elementos++;
		}
		else if(a >= 2 || a < 1){
            return 0;
		}
	}
	else {
		pilaX->a[pilaX->elementos]=n;
		pilaX->elementos++;
	}


}

void show_pila(pila *pilaX){
	int i;
	for(i = 0; i<pilaX->elementos; i++){
		printf("%d\n",pilaX->a[i]);

	}
}

int pop_pila(pila *pilaX){
	if (pilaX->elementos == 0){
		printf("Pila vacia, no se pueden eliminar mas elementos");

	}
	else{
        printf("El elemento eliminado es:%d\n",pilaX->a[pilaX->elementos - 1]);
		pilaX->elementos--;
		return pilaX->a[pilaX->elementos];
	}

}

void libera(pila *pilaX){
    free(pilaX->a);
}

int main() {
    int n;
    printf("Cuantos elementos desea?\n");//es el tamaño de la pila
    scanf("%d",&n);
    tam = n;
	pila pilaA;
	crear_pila(&pilaA,n);// se crea la pila
	push_pila(&pilaA,1);//se agregan solo 7 elementos
	push_pila(&pilaA,2);
	push_pila(&pilaA,3);
	push_pila(&pilaA,4);
    push_pila(&pilaA,5);
	push_pila(&pilaA,6);
	push_pila(&pilaA,7);
	show_pila(&pilaA);//se muestra la pila
	pop_pila(&pilaA);//se quitan los últimos tres elementos
	pop_pila(&pilaA);
	pop_pila(&pilaA);
    show_pila(&pilaA);//se muestra de nuevo la pila
	libera(&pilaA);//para redimencionar la pila, se debe hacer más push que el tamaño de la pila
	return 0;
}

