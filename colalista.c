#include <stdio.h>
#include <stdlib.h>

typedef struct _nodo{
    int info;
    struct _nodo *next;//apuntador a estructura
}nodo;

void inicializa(nodo **inicio, int n){
	*inicio = (nodo *)malloc(sizeof(nodo));
	(*inicio) ->info = n;
    (*inicio) ->next = NULL;
}

int tam(nodo *inicio){
    int cont = 0;
    while(inicio != NULL){
        cont++;
        inicio=inicio->next;
    }
    return(cont);
}

void pushcola(nodo **inicio, int n){
	nodo *nuevo;
	nuevo = (nodo *)malloc(sizeof(nodo));
	nuevo->next = *inicio;
	*inicio = nuevo;
    nuevo->info = n;
}

void pop(nodo **inicio){
    int i;
    nodo *act,*ant;
    if(tam(*inicio)>1){
        ant = *inicio;
        for(i=0;i<tam(*inicio)-2;i++){
             ant = ant->next;
        }
        act = ant->next;
        ant->next = NULL;
        printf("el valor eliminado es: %d\n",act->info);
        free(act);
    }
    else if(tam(*inicio) == 1){
        printf("el valor eliminado es: %d\n",(*inicio)->info);
        (*inicio) = NULL;
    }
    else if(esvacia(*inicio)==0){
        printf("No se pueden eliminar mas valores \n");
    }
}


void showcola(nodo *inicio){
    if(esvacia(inicio) == 0){
        printf("No hay valores que mostrar\n");
    }
    else{
        printf("La cola contiene:\n\n");
        while(inicio!=NULL)
        {
            printf("-|%d|-",inicio->info);
            inicio=inicio->next;
        }
    }
    printf("\n\n");
}

int esvacia(nodo *inicio){
    if(inicio != NULL){
        return 1;
    }
    return 0;
}

void libera(nodo *inicio){
    nodo *tmp;
    while(inicio != NULL){
        tmp=inicio;
        inicio = inicio->next;
        free(tmp);
    }
}
void invierte(nodo **inicio){
    if(esvacia(*inicio)== 0){
        printf("La lista esta vacia, no se puede invertir\n");
    }
    int info,i,j;
    int t=tam(*inicio);
    nodo *fin, *tmp;
    tmp = fin = *inicio;
    for(i = 0;i < (tam(*inicio)/2); i++, t--){
        j = 0;
        while(j < t -1){
            fin = fin->next;
            j++;
        }
        info = tmp ->info;
        tmp ->info = fin ->info;
        fin ->info = info;
        tmp = tmp ->next;
        fin = *inicio;
    }
}

nodo *copy(nodo *inicio){
    if(esvacia(inicio)== 0){
        return 0;
    }
    nodo *copia, *aux;
    aux = inicio;
    inicializa(&copia,inicio->info);
    aux = aux->next;
    while(aux != NULL){
        pushcola(&copia,aux->info);
        aux=aux->next;
    }
    invierte(&copia);
    return(copia);
}

void elimina(nodo **inicio, int n){
    int cont = 0;
        if(esvacia(*inicio)== 0){
            printf("La lista esta vacia, no se puede eliminar\n");
    }
    if(tam(*inicio)>1){
        nodo *aux, *actual, *datelim;
        aux = actual = *inicio;
        while(aux ->info != n){
            actual = aux;
            aux= aux ->next;
            cont++;
        }
        if(cont != 0){
            printf("Se elimino el valor: %d\n", aux ->info);
            actual ->next = aux ->next;
            free(aux);
        }
        else{
            (*inicio) = (*inicio) ->next;
            free(aux);
        }
    }
    else{
        free(*inicio);
    }
}

int main(int argc, char **argv)
{
    nodo *inicio;
    inicializa(&inicio,1);
    pushcola(&inicio,2);
    pushcola(&inicio,3);
    pushcola(&inicio,4);
    pushcola(&inicio,5);
    pushcola(&inicio,6);
    pushcola(&inicio,7);
    showcola(inicio);
    printf("Invierto cola\n");
    invierte(&inicio);
    showcola(inicio);
    printf("elimino el valor deseado \n");
    elimina(&inicio,3);
    showcola(inicio);
    printf("Elimino elementos los 3 primeros\n");
    pop(&inicio);
    pop(&inicio);
    pop(&inicio);
    //pop(&inicio);
    //pop(&inicio);
    //pop(&inicio);
    //pop(&inicio);
    printf("Hago una copia de la cola\n");
    printf("Original:\n");
    showcola(inicio);
    printf("Copia:\n");
    showcola(copy(inicio));
    printf("Invierto la copia\n");
    invierte(&inicio);
    showcola(inicio);
    printf("Libero la copia y la original\n");
    libera(copy(inicio));
    libera(inicio);

	return 0;
}
