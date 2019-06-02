#include <stdio.h>
#include <stdlib.h>

typedef struct _nododl{
    int info;
    struct _nododl *next;
    struct _nododl *prev;
    struct _nododl *fin;
}nododl;


void inicializa(nododl **,int);
void pushcola(nododl **, int);
int tam(nododl *);
void showcola(nododl *);
void showcolarevez(nododl **);
int esvacia(nododl *);
void libera(nododl *);
void pop_val(nododl **, int);
void pop_pos(nododl **, int);
void push_pos(nododl **, int, int);
void invierte(nododl **);


int main(int argc, char **argv)
{
    nododl *inicio;
    inicializa(&inicio,1);
    pushcola(&inicio,2);
    pushcola(&inicio,3);
    pushcola(&inicio,4);
    pushcola(&inicio,5);
    pushcola(&inicio,6);
    pushcola(&inicio,7);
    //printf("%d\n",ultimo(&inicio));
    showcola(inicio);
    push_pos(&inicio,9,3);
    printf("coloco en posicion 9 el valor 3\n");
    showcola(inicio);
    push_pos(&inicio,3,3);
    printf("coloco en posicion 3 el valor 3\n");
    showcola(inicio);
    push_pos(&inicio,6,99);
    printf("coloco en posicion 6 el valor 99\n");
    showcola(inicio);
    showcolarevez(&inicio);
    printf("Invierto cola\n");
    invierte(&inicio);
    showcola(inicio);
    printf("elimino el valor deseado \n");
    pop_val(&inicio,3);
    showcola(inicio);
    printf("elimino la posicion deseada 9 \n");
    pop_pos(&inicio,9);
    showcola(inicio);
    showcolarevez(&inicio);
    /*printf("Elimino elementos los 3 primeros\n");
    pop(&inicio);
    pop(&inicio);
    pop(&inicio);*/
    //pop(&inicio);
    //pop(&inicio);
    //pop(&inicio);
    //pop(&inicio);
    //printf("Hago una copia de la cola\n");
    //printf("Original:\n");
    //showcola(inicio);
    //printf("Copia:\n");
    //showcola(copy(inicio)); //tengo que ver cómo liverarlo
    //printf("Invierto la copia\n");
    //invierte(&inicio);
    //showcola(inicio);
    //printf("Libero la copia y la original\n");
    //libera(copy(inicio)); //estoy liberando una tercer copia
    libera(inicio);

	return 0;
}

void inicializa(nododl **inicio, int n){
	*inicio = (nododl *)malloc(sizeof(nododl));
	(*inicio) ->info = n;
    (*inicio) ->next = NULL;
    (*inicio) ->prev =NULL;
    (*inicio) ->fin = (*inicio);
}

int tam(nododl *inicio){
    int cont = 0;
    while(inicio != NULL){
        cont++;
        inicio=inicio->next;
    }
    return(cont);
}


void pushcola(nododl **inicio, int n){
	nododl *nuevo;
	nuevo = (nododl *)malloc(sizeof(nododl));
	nuevo ->next = *inicio;
	(*inicio) ->prev = nuevo;
	nuevo ->prev = NULL;
    nuevo->info = n;
    *inicio = nuevo;
}


void showcola(nododl *inicio){
    if(esvacia(inicio) == 0){
        printf("No hay valores que mostrar\n");
    }
    else{
        printf("contenido de la lista\n\n");
        while(inicio!=NULL)
        {
            printf("-|%d|-",inicio->info);
            inicio=inicio->next;
        }
    }
    printf("\n\n");
}
void showcolarevez(nododl **inicio){
    nododl *aux;
    if(esvacia(*inicio) == 0){
        printf("No hay valores que mostrar\n");
    }
    else{
        aux = (*inicio) ->fin;
        printf("lista al revez:\n\n");
        while(aux->next != NULL)
        {
            printf("-|%d|-",aux->info);
            aux = aux ->prev;
        }
    }
    printf("\n\n");
}

int esvacia(nododl *inicio){
    if(inicio != NULL){
        return 1;
    }
    return 0;
}

void libera(nododl *inicio){
    nododl *tmp;
    while(inicio != NULL){
        tmp=inicio;
        inicio = inicio->next;
        free(tmp);
    }
}

void invierte(nododl **inicio){
    if(esvacia(*inicio)== 0){
        printf("La lista esta vacia, no se puede invertir\n");
    }
    int info,i,j;
    int t=tam(*inicio);
    nododl *fin, *tmp;
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
/*
nododl *copy(nododl *inicio){
    if(esvacia(inicio)== 0){
        return 0;
    }
    nododl *copia, *aux;
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
*/

void push_pos(nododl **inicio, int n, int v){
    nododl *nuevo, *aux;
    int cont = 1;
    if(n == 1){
        pushcola(&*inicio,v);
    }
    else if(n > tam(*inicio)){
        printf("la posicion sobrepasa el tamanio de la lista\n");
    }
    else{

        aux = *inicio;
        while( cont < n){
            aux = aux ->next;
            cont++;
        }
        nuevo = (nododl *)malloc(sizeof(nododl));
        nuevo ->next = aux;
        nuevo ->prev = aux ->prev;
        aux ->prev ->next = nuevo;
        aux ->prev = nuevo;
        nuevo ->info = v;
    }
}
void pop_pos(nododl **inicio, int n){
    nododl *aux, *elim;
    int cont = 1;
    aux = *inicio;
    if(n == 1){
        (*inicio) = (*inicio) ->next;
        (*inicio) ->prev = NULL;
        free(aux);
    }
    else if(n > tam(*inicio)){
        printf("la posicion esta fuera de rango\n");
    }
    else if(n == tam(*inicio)){
        while( cont < n){
            aux = aux ->next;
            cont++;
        }
        elim = aux;
        aux = aux ->prev;
        aux ->next = NULL;
        free(elim);
    }
    else{
        while( cont < n){
            aux = aux ->next;
            cont++;
        }
        elim = aux;
        aux ->prev ->next = aux ->next;
        aux ->next ->prev = aux ->prev;
        free(elim);
    }
}

void pop_val(nododl **inicio, int n){
    int cont = 0;
        if(esvacia(*inicio)== 0){
            printf("La lista esta vacia, no se puede eliminar\n");
    }
    if(tam(*inicio)>1){
        nododl *aux, *actual, *datelim;
        aux = actual = *inicio;
        while(aux ->info != n){
            actual = aux;
            aux= aux ->next;
            cont++;
        }
        if(cont != 0){
            printf("Se elimino el valor: %d\n", aux ->info);
            actual ->next = aux ->next;
            aux ->next ->prev =actual;
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

