#include <stdio.h>
#include <stdlib.h>
typedef struct _nodo{
    int info;
    struct _nodo *next;//apuntador a estructura
}nodo;
nodo* fondo = NULL;
nodo* cima = NULL;

void inicializa(nodo nodoX){
    fondo = (nodo *)malloc(sizeof(nodo));
    fondo ->next = NULL;
}

void push_pila(nodo nodoX, int n){
    cima = (nodo*)malloc(sizeof(nodo));
    fondo ->next = cima;
    cima ->next = NULL;
    cima ->info = n;
    printf("%d %d\n",cima ->info,&cima ->info);


}
void libera(nodo nodoX){
    while(fondo != NULL){
    cima = fondo;
    fondo = fondo ->next;
    free(cima);
    }
}
void show_pila(nodo nodoX){
    cima = fondo;
    while(cima != NULL){
        printf("%d", cima->info);
        cima = cima->next;
    }
}
int main(){
    int n,i,e;
    nodo nodoX;
    printf("cuantos elementos desea?\n");
    scanf("%d", &e);
    inicializa(nodoX);
    for(i = 0;i < e;i++){
        printf("Ingrese el valor %d\n",i+1);
        scanf("%d", &n);
        push_pila(nodoX,n);
    }
    //show_pila(nodoX);

    libera(nodoX);

return 0;
}
