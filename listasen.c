#include <stdio.h>
#include <stdlib.h>
typedef struct _nodo{
    int info;
    struct _nodo *next;//apuntador a estructura
}nodo;
void inicializa();
int main(){
    int i;
    nodo *inicio,*nuevo;
    inicio = (nodo *)malloc(sizeof(nodo));
    nuevo=(nodo*)malloc(sizeof(nodo));
    inicio->next = nuevo;
    inicio->info = 1;
//inserta
    for(i = 0;i < 100;i++){
        nuevo=(nodo*)malloc(sizeof(nodo));
        inicio->next = nuevo;
        nuevo->info = i*2;
        nuevo->next = NULL;
            printf("Elemento: %d \n", nuevo->info);

    }
//agrega
   /* for(i = 0;i < 100;i++){
        nuevo=(nodo*)malloc(sizeof(nodo));
        nuevo->next = inicio->next;
        inicio->next = nuevo;
        nuevo->info = i;
    }*/
   /* nuevo=inicio;
    while(nuevo != NULL){
        printf("%d", nuevo->info);
        nuevo=nuevo->next;
    }*/
    //libera
    while(inicio != NULL){
        nuevo = inicio;
        inicio = inicio->next;
        free(nuevo);
    }
    return 0;
}
