#include <stdio.h>
#include <stdlib.h>

typedef struct _bucket{
    int dato;
    struct _bucket *siguiente;
    struct _bucket *anterior;
}bucket;

void creaTabla(bucket **,int);
void hashing(bucket **,int,int);
void liberar(bucket**,int);
void mostrar(bucket *,int);
void buscar(bucket *,int,int);

int main(){
    bucket *tablaHash;
    int n,i;
    int elementos,valor,vBuscar;
    printf("De que tamanio quiere su tabla hash\n");
    scanf("%d",&n);
    creaTabla(&tablaHash,n);
    printf("cuantos elementos desea ingresar?\n");
    scanf("%d",&elementos);
    for(i = 0;i < elementos;i++){
        printf("ingrese un elemento:\n");
        scanf("%d",&valor);
        hashing(&tablaHash,valor,n);
    }
    printf("termino el hashing\n");
    mostrar(tablaHash,n);
    printf("ingrese el elemento a buscar:\n");
    scanf("%d",&vBuscar);
    buscar(tablaHash,vBuscar,n);
    liberar(&tablaHash,n);
    return 0;
}

void creaTabla(bucket **tabla,int n){
    int i;
    (*tabla) = (bucket *)malloc(sizeof(bucket)*(n*2));
    for(i = 0;i < (n*2);i++){
        (*tabla)[i].anterior = NULL;
        (*tabla)[i].siguiente = NULL;
        (*tabla)[i].dato = 0;
    }
}


void hashing(bucket **tablaHash,int valor,int n){
    int index;
    bucket *nuevo,*aux;
    index = valor%(n*2);
    printf("%d index\n",index);
    aux = &(*tablaHash)[index];
    if(((*tablaHash)[index].dato) == 0){
        (*tablaHash)[index].dato = valor;
        printf("%d metio\n",(*tablaHash)[index].dato);
    }
    else{
        while(aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        nuevo = (bucket *)malloc(sizeof(bucket));
        aux->siguiente = nuevo;
        nuevo->anterior = aux;
        nuevo->dato = valor;
        nuevo->siguiente = NULL;
        printf("%d dado in\n",nuevo->dato);
    }
}

void liberar(bucket **tabla,int n){
    int i;
    bucket *tmp,*aux;
    for(i = 0;i < (n*2);i++){
        tmp = (*tabla)[i].siguiente;
        while(tmp != NULL){
            aux = tmp;
            tmp = tmp->siguiente;
            free(aux);
    }
    }
    free(*tabla);
}

void mostrar(bucket *tabla,int n){
    bucket *aux;
    int i;
    for(i = 0; i < (n*2);i++){
        aux = &tabla[i];
        while(aux != NULL){
            if(aux != NULL){
              printf("%d --->",aux->dato);
            }
            aux = aux->siguiente;
        }
        printf("---->NULL\n");
    }
}

void buscar(bucket *tabla,int valor,int n){
    int index = valor%(n*2);
    int cont = 0;
    bucket *aux = &tabla[index];
    while(aux != NULL){
        if(aux->dato == valor ){
        printf("Se encontro: %d\n",aux->dato);
        cont++;
        }
        aux = aux->siguiente;
    }
    printf("Se encontraron %d coincidencias\n",cont);
    if(!cont){
        printf("No se encontraron coincidencias\n");
    }

}

