#include <stdio.h>
#include <stdlib.h>

/////////////////// ESTRUCTURAS ///////////////////////

typedef struct _nododl{
    int info;
    struct _nododl *next;
    struct _nododl *prev;
}nododl;

typedef struct _lista{
    struct _nododl *inicio;
    struct _nododl *fin;
}lista;

////////////////// PROTOTIPOS //////////////////////////

void inicializa(lista *,int);
void push(lista *, int);
void push_pos(lista *, int, int);
void inserta(lista *, int);
void agrega(lista *, int);
void pop_val(lista *, int);
void pop_pos(lista *, int);
int tamanio(lista *);
int esvacia(lista *);
void show(lista *);
void showrev(lista *);
void libera(lista *);

///////////////////////////// MAIN //////////////////////

int main(int argc, char **argv)
{
    lista inicio;
    inicializa(&inicio,1);
    push(&inicio,2);
    push(&inicio,3);
    push(&inicio,4);
    push(&inicio,5);
    agrega(&inicio,0);
    inserta(&inicio,99);
    show(&inicio);
    //printf("%d\n",esvacia(&inicio));
    //push_pos(&inicio,1,8);
    //show(&inicio);
    //pop_pos(&inicio,1);
    //show(&inicio);
    pop_val(&inicio,5);
    show(&inicio);
    showrev(&inicio);
    libera(&inicio);
	return 0;
}

/////////////////// FUNCIONES /////////////////////////

void inicializa(lista *mylist, int n){
    nododl *first;

	first = (nododl *)malloc(sizeof(nododl));
	first ->info = n;
    first ->next = NULL;
    first ->prev =NULL;
    mylist ->inicio = first;
    mylist ->fin = first;
}
void push(lista *mylist, int n){
    nododl *nuevo;
    nuevo = (nododl *)malloc(sizeof(nododl));
    nuevo ->next = mylist->fin;
    mylist->fin->prev = nuevo;
    nuevo ->prev = NULL;
    nuevo ->info = n;
    mylist ->fin = nuevo;

}

int tamanio(lista *mylist){
    nododl *aux;
    aux = mylist ->fin;
    int cont = 0;
    while(mylist->fin != NULL){
        mylist ->fin = mylist ->fin ->next;
        cont++;
    }
    mylist ->fin = aux;
    return(cont);
}

int esvacia(lista *mylist){
    if(mylist ->fin != NULL){
        return 1;
    }
    return 0;
}

void show(lista *mylist){
    nododl *aux;
    if(esvacia(mylist) != 0){
        aux = mylist ->fin;
        while(mylist ->fin != NULL)
            {
                printf("-|%d|-", mylist ->fin ->info);
                mylist ->fin = mylist ->fin->next;
            }
            mylist ->fin = aux;
            printf("\n\n");
    }
    else{
        printf("la lista esta vacia no se puede eliminar ningun valor\n\n");
    }
}
void showrev(lista *mylist){
    nododl *aux;
    if(esvacia(mylist) != 0){
    aux = mylist ->inicio;
    while(mylist ->inicio != NULL)
        {
            printf("-|%d|-", mylist ->inicio ->info);
            mylist ->inicio = mylist ->inicio->prev;
        }
        mylist ->inicio = aux;
        printf("\n\n");
    }
    else{
        printf("la lista esta vacia no se puede eliminar ningun valor\n\n");
    }
}

void libera(lista *mylist){
    nododl *tmp;
    while(mylist ->inicio != NULL){
        tmp = mylist ->inicio;
        mylist ->inicio = mylist ->inicio ->prev;
        free(tmp);
    }
}

void push_pos(lista *mylist, int n, int v){
    nododl *nuevo, *aux;
    aux = mylist ->fin;
    int cont = 1;
    if(n == 1){
        push(mylist,v);
    }
    else if(n > tamanio(mylist)){
        printf("la posicion sobrepasa el tamanio de la lista\n");
    }
    else{
        while( cont < n){
            mylist ->fin = mylist ->fin ->next;
            cont++;
        }
        nuevo = (nododl *)malloc(sizeof(nododl));
        nuevo ->next = mylist ->fin;
        nuevo ->prev = mylist ->fin ->prev;
        mylist ->fin ->prev ->next = nuevo;
        mylist ->fin ->prev = nuevo;
        nuevo ->info = v;
        mylist ->fin = aux;
    }


}

void inserta(lista *mylist, int n){
    nododl *nuevo;
    nuevo = (nododl *)malloc(sizeof(nododl));
    nuevo ->prev = mylist ->inicio;
    mylist ->inicio ->next = nuevo;
    nuevo ->next = NULL;
    nuevo ->info = n;
    mylist ->inicio = nuevo;

}

void agrega(lista *mylist,int n){
    nododl *nuevo;
    nuevo = (nododl *)malloc(sizeof(nododl));
    nuevo ->next = mylist ->fin;
    mylist ->fin ->prev = nuevo;
    nuevo ->prev = NULL;
    nuevo ->info = n;
    mylist ->fin = nuevo;


}

void pop_pos(lista *mylist, int n){
    nododl *aux, *elim;
    int cont = 1;
    if(esvacia(mylist) != 0){
        aux = mylist ->inicio;
        if(n == 1 && tamanio(mylist) == 1){
            libera(mylist);
            printf("La lista ya no contiene elementos");
        }
        else if(n == 1){
            mylist ->inicio = mylist ->inicio ->prev;
            mylist ->inicio ->next = NULL;
            printf("Se elimino la posicion: %d\n", n);
            free(aux);
        }
        else if(n > tamanio(mylist)){
            printf("la posicion esta fuera de rango\n\n");
        }
        else if(n == tamanio(mylist)){
            elim = aux = mylist ->fin;
            aux = aux ->next;
            aux ->prev = NULL;
            mylist ->fin = aux;
            printf("Se elimino la posicion: %d\n", n);
            free(elim);
        }

        else{
            while( cont < n){
                aux = aux ->prev;
                cont++;
            }
            elim = aux;
            aux ->prev ->next = aux ->next;
            aux ->next ->prev = aux ->prev;
            printf("Se elimino la posicion: %d\n", n);
            free(elim);
        }
    }
    else{
        printf("la lista esta vacia no se puede eliminar ningun valor\n\n");
    }
}

void pop_val(lista *mylist, int n){
    int cont = 0;
    nododl *aux, *actual, *datelim;
        aux = actual = mylist ->fin;

        while(aux ->info != n && aux != NULL){
            actual = aux;
            aux= aux ->next;
            cont++;
        }

        if(aux != NULL){

            if(cont == 0){
                mylist ->fin = mylist ->fin ->next;
                mylist ->fin ->prev = NULL;
                printf("Se elimino el valor: %d\n", aux ->info);
                free(aux);
            }
            else if(aux == mylist->inicio){
                mylist ->inicio = mylist ->inicio ->prev;
                mylist ->inicio ->next = NULL;
                free(aux);

            }
            else if(cont != 0 && aux != NULL){
                printf("Se elimino el valor: %d\n", aux ->info);
                actual ->next = aux ->next;
                aux ->next ->prev = actual;
                free(aux);
            }
        }
        else{
            printf("El valor %d no se encuentra en la lista\n\n", n);
        }

}

