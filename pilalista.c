#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    int info;
    struct _nodo *next;//apuntador a estructura
}nodo;

void inicializa(nodo **inicio, int n)
{
	*inicio = (nodo *)malloc(sizeof(nodo));
	(*inicio) ->info = n;
    (*inicio) ->next = NULL;

}

void pushpila(nodo **inicio, int n)
{
	nodo *nuevo;
	nuevo = (nodo *)malloc(sizeof(nodo));
    nuevo->info = n;
    nuevo ->next = *inicio;
	*inicio=nuevo;
}

void showpila(nodo *inicio)
{
    while(inicio!=NULL)
    {
		printf("%d, ",inicio->info);
       	inicio=inicio->next;
    }
    printf("\n");
}

nodo *poppila(nodo *inicio, int *n){

	if(esvacia(inicio) != 0){
    nodo *tmp;
    *n = inicio->info;
    printf("Sale %d\n",inicio->info);
    tmp=inicio;
    inicio=inicio->next;
    free(tmp);
    return(inicio);
	}
	else{
        printf("la pila esta vacia no se puede eliminar mas nodos\n");
        return 0;
	}
}
void libera(nodo *inicio){
    nodo *tmp;
    while(inicio != NULL){
        tmp=inicio;
        inicio = inicio->next;
        free(tmp);
    }
}
int esvacia(nodo *inicio){
    if(inicio != NULL){
        return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    nodo *inicio;
    int elemento;

    inicializa(&inicio,100);
    pushpila(&inicio,2);
    pushpila(&inicio,3);
    pushpila(&inicio,4);
    pushpila(&inicio,5);

    showpila(inicio);

    inicio=poppila(inicio,&elemento);

    inicio=poppila(inicio,&elemento);

    showpila(inicio);

    libera(inicio);

	return 0;
}

