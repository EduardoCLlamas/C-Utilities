#include <stdio.h>
#include <stdlib.h>
#define MAX 5
typedef struct pila{
	int elementos;
	int a[MAX];
}pila;

void crear_pila(pila *pilaX){
	pilaX-> elementos = 0;
}
void push_pila(pila *pilaX,int n){
	if (pilaX->elementos >= MAX){
		printf("Pila llena, no se pueden colocar mas elementos");

	}
	else {
		pilaX->a[pilaX->elementos] = n;
		pilaX->elementos++;
	}


}
void show_pila(pila *pilaX){
	int i;
	for(i = 0; i < pilaX->elementos; i++){
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
int main() {
	pila pilaA;
	crear_pila(&pilaA);
	push_pila(&pilaA,1);
	push_pila(&pilaA,10);
	push_pila(&pilaA,100);
	push_pila(&pilaA,1000);
	show_pila(&pilaA);
	pop_pila(&pilaA);
	pop_pila(&pilaA);
	pop_pila(&pilaA);
	pop_pila(&pilaA);
	pop_pila(&pilaA);
	show_pila(&pilaA);
	return 0;
}

