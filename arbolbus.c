#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 30

typedef struct _nodo{
    char info[MAX];
    int tele;
    struct _nodo *izq;
    struct _nodo *der;
}nodo;

///////////////PROTOTIPOS//////////////
void plantar(nodo **,char *);
void imprime(nodo *);
void agregar(nodo *,char *);
void busca(nodo *,char *);

int main(){
    char a[MAX],b[MAX],c[MAX],d[MAX],e[MAX],f[MAX],g[MAX],h[MAX];
    nodo *arbol;
    arbol = NULL;
    gets(a);
    gets(b);
    gets(c);
    gets(d);
    gets(e);
    gets(f);
    gets(g);
    gets(h);
    plantar(&arbol,a);
    agregar(arbol,b);
    agregar(arbol,c);
    agregar(arbol,d);
    agregar(arbol,e);
    agregar(arbol,f);
    agregar(arbol,g);
    busca(arbol,h);
    //imprime(arbol);


return 0;
}

void plantar(nodo **raiz,char *a){
    (*raiz) = (nodo *)malloc(sizeof(nodo));
    (*raiz)->izq = NULL;
    (*raiz)->der = NULL;
    strcpy((*raiz)->info,a);
}


void agregar(nodo *raiz,char *a){
    if(strcmp(raiz->info,a) > 0){
        if(raiz->izq == NULL)
            plantar(&raiz->izq,a);
        else
            agregar(raiz->izq,a);
    }
    else{
        if(raiz->der == NULL)
            plantar(&raiz->der,a);

        else
          agregar(raiz->der,a);
    }

}

void busca(nodo *raiz,char *a){
    if(strcmp(raiz->info,a) == 0){
        printf("se encontro el dato: %s\n",raiz->info);
    }
    else{
        if(strcmp(raiz->info,a) > 0){
            busca(raiz->izq,a);
        }
        else{
            busca(raiz->der,a);
        }
    }
}


void imprime(nodo *raiz){
    if(raiz == NULL){
    }
    if(raiz != NULL){
        printf("%s\n",raiz->info);
        imprime(raiz->izq);
        imprime(raiz->der);
    }
}




