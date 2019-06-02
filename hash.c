#include <stdio.h>
#include <stdlib.h>

/////////////////// ESTRUCTURAS ///////////////////////

typedef struct _nododl{
    int info;
    int priori;
    struct _nododl *next;
    struct _nododl *prev;
}nododl;



////////////////// PROTOTIPOS //////////////////////////

void inicia_hash(nododl ***, int);
void inicializa(nododl **, int, int);
void push_hash(nododl ***, int, int, int);
void push_pri(nododl ***, int, int, int);


///////////////////////////// MAIN //////////////////////

int main(int argc, char **argv)
{

    nododl **inicio;
    inicia_hash(&inicio,9);

	return 0;
}

/////////////////// FUNCIONES /////////////////////////

void inicia_hash(nododl ***tbhash,int n){
    int i;
    *tbhash = (nododl **)malloc(sizeof(nododl*)*n);
    for(i = 0; i < n; i++){
        (*tbhash)[i] = NULL;
    }
}

void inicializa(nododl **inicio, int n,int p){
	*inicio = (nododl *)malloc(sizeof(nododl));
	(*inicio) ->info = n;
	(*inicio) ->priori = p;
    (*inicio) ->next = NULL;
    (*inicio) ->prev =NULL;
}
//convertir la primer letra siempre a minuscula, comparar su ascii con el de z y regresar el numero

void push_hash(nododl ***tbhash, char indice, char *pal,char *desc){
    nododl *nuevo;

    if((*tbhash)[pos-1] == NULL){
        inicialista(&nuevo,pal,desc);
        (*tbhash)[pos-1] = nuevo;
    }
    else{

    }

}

void push_pri(nododl ***tbhash ,int pos, int n, int p){
    nododl *nuevo, *aux;
    int cont = 1,id = 0;
    aux = (*tbhash)[pos-1];

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
