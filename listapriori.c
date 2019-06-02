#include <stdio.h>
#include <stdlib.h>

/////////////////// ESTRUCTURAS ///////////////////////

typedef struct _nododl{
    int info;
    int priori;
    struct _nododl *next;
    struct _nododl *prev;
}nododl;

typedef struct _lista{
    struct _nododl *inicio;
    struct _nododl *fin;
}lista;

////////////////// PROTOTIPOS //////////////////////////

void inicializa(lista *, int, int);
void push(lista *, int, int);
void push_pri(lista *, int, int);
void push_pos(lista *, int, int, int);
void inserta(lista *, int, int);
void agrega(lista *, int, int);
void pop(lista *);
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
    inicializa(&inicio,1,2);
    show(&inicio);
    push_pri(&inicio,5,4);
    show(&inicio);
    push_pri(&inicio,4,1);
    show(&inicio);
    push_pri(&inicio,3,9);
    show(&inicio);
    push_pri(&inicio,6,2);
    show(&inicio);
    push_pri(&inicio,7,0);
    show(&inicio);
    push_pri(&inicio,2,0);
    show(&inicio);
    push_pri(&inicio,9,4);
    show(&inicio);
    push_pri(&inicio,10,7);
    show(&inicio);
    push_pri(&inicio,20,5);
    show(&inicio);
    push_pri(&inicio,40,1);
    show(&inicio);
    push_pri(&inicio,5,2);
    show(&inicio);
    push_pri(&inicio,7,50);
    show(&inicio);
    push_pri(&inicio,9,10);
    show(&inicio);
    push_pri(&inicio,3,20);
    show(&inicio);
    show(&inicio);
    pop(&inicio);
    show(&inicio);
    pop(&inicio);
    show(&inicio);
    pop(&inicio);
    show(&inicio);
    pop(&inicio);
    show(&inicio);
    pop(&inicio);
    show(&inicio);
    pop(&inicio);
    show(&inicio);
    pop(&inicio);
    show(&inicio);
    pop(&inicio);
    show(&inicio);
    pop(&inicio);
    show(&inicio);
    pop(&inicio);
    show(&inicio);
    pop(&inicio);
    show(&inicio);
    pop(&inicio);
    show(&inicio);
    libera(&inicio);
	return 0;
}

/////////////////// FUNCIONES /////////////////////////

void inicializa(lista *mylist, int n, int p){
    nododl *first;

	first = (nododl *)malloc(sizeof(nododl));
	first ->info = n;
	first ->priori = p;
    first ->next = NULL;
    first ->prev =NULL;
    mylist ->inicio = first;
    mylist ->fin = first;
}

//////////////////PUSH COLA ////////////////////
void push(lista *mylist, int n, int p){
    nododl *nuevo;
    nuevo = (nododl *)malloc(sizeof(nododl));
    nuevo ->next = mylist->fin;
    mylist->fin->prev = nuevo;
    nuevo ->prev = NULL;
    nuevo ->info = n;
    mylist ->fin = nuevo;

}
void push_pri(lista *mylist, int n, int p){
    nododl *nuevo, *aux;
    int cont = 1,id = 0;
    aux = mylist ->inicio;

   while((p > (aux->priori) || p == (aux->priori)) && aux->prev != NULL){
            aux = aux->prev;
            cont++;
            id = 1;
    }

    if(id == 0 && cont == 1 && p >(aux->priori)){
        agrega(mylist,n,p);
    }

    else if(id == 0 && cont == 1 && p <(aux->priori)){
        inserta(mylist,n,p);
    }

    else if(id == 0 && p == aux->priori){
        agrega(mylist,n,p);
    }

    else if(id == 1 && p > aux->priori){
        agrega(mylist,n,p);
    }

    else{
        push_pos(mylist,cont,n,p);
    }
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
        printf("la lista esta vacia no se puede mostrar ningun valor\n\n");
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
        printf("la lista esta vacia no se puede mostar ningun valor\n\n");
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

void push_pos(lista *mylist, int n, int v, int p){
    nododl *nuevo, *aux;
    aux = mylist ->inicio;
    int cont = 1;
    if(n == 1){
        push(mylist,v,p);
    }
    else if(n > tamanio(mylist)){
        printf("la posicion sobrepasa el tamanio de la lista\n");
    }
    else{
        while( cont < n){
            mylist ->inicio = mylist ->inicio ->prev;
            cont++;
        }
        nuevo = (nododl *)malloc(sizeof(nododl));
        nuevo ->prev = mylist ->inicio;
        nuevo ->next = mylist ->inicio ->next;
        mylist ->inicio ->next ->prev = nuevo;
        mylist ->inicio ->next = nuevo;
        nuevo ->info = v;
        nuevo ->priori = p;
        mylist ->inicio = aux;
    }


}

void inserta(lista *mylist, int n, int p){
    nododl *nuevo;
    nuevo = (nododl *)malloc(sizeof(nododl));
    nuevo ->prev = mylist ->inicio;
    mylist ->inicio ->next = nuevo;
    nuevo ->next = NULL;
    nuevo ->info = n;
    nuevo ->priori =p;
    mylist ->inicio = nuevo;

}

void agrega(lista *mylist,int n, int p){
    nododl *nuevo;
    nuevo = (nododl *)malloc(sizeof(nododl));
    nuevo ->next = mylist ->fin;
    mylist ->fin ->prev = nuevo;
    nuevo ->prev = NULL;
    nuevo ->info = n;
    nuevo ->priori =p;
    mylist ->fin = nuevo;


}

void pop(lista *mylist){
    nododl *aux;
    if(tamanio(mylist)>1){
        aux = mylist ->inicio;
        mylist ->inicio = mylist ->inicio ->prev;
        mylist ->inicio ->next = NULL;
        printf("el valor eliminado es: %d\n\n",aux->info);
        free(aux);

    }
    else if(tamanio(mylist) == 1){
        printf("el valor eliminado es: %d\n\n",mylist ->inicio ->info);
        free(mylist->inicio);
    }
    else if(esvacia(mylist)==0){
        printf("No se pueden eliminar mas valores \n\n");
    }
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
            printf("Se elimino la posicion: %d\n\n", n);
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
            printf("Se elimino la posicion: %d\n\n", n);
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
        aux = actual = mylist ->inicio;

        while(aux ->info != n && aux != NULL){
            actual = aux;
            aux= aux ->prev;
            cont++;
        }

        if(aux != NULL){

            if(cont == 0){
                mylist ->inicio = mylist ->inicio ->prev;
                mylist ->inicio ->next = NULL;
                printf("Se elimino el valor: %d\n\n", aux ->info);
                free(aux);
            }
            else if(aux == mylist->fin){
                mylist ->fin = mylist ->fin ->next;
                mylist ->fin ->prev = NULL;
                free(aux);

            }
            else if(cont != 0 && aux != NULL){
                printf("Se elimino el valor: %d\n\n", aux ->info);
                actual ->prev = aux ->prev;
                aux ->prev ->next = actual;
                free(aux);
            }
        }
        else{
            printf("El valor %d no se encuentra en la lista\n\n", n);
        }

}


