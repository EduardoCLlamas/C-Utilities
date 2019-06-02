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

typedef struct _pila{
    struct _nodo *member;
    struct _pila *next;
}pila;

///////////////PROTOTIPOS//////////////
void plantar(nodo **,char *,int);
void imprime(nodo *,int);
void agregar(nodo *,char *,int);
void busca(nodo *,char *);
void elimina(nodo **,char *);
int nivel(nodo *,int);
nodo *recorre(nodo *raiz);
void ini_pila(pila *, nodo *);
void push_pila(pila *, nodo *);
void pop(pila *);
void iterativo(nodo *);

int main(){
    char a[MAX],b[MAX];
    int i,n,j;
    nodo *arbol;
    arbol = NULL;
    printf("Cuantos datos desea ingresar?\n");
    scanf("%d",&n);
    printf("ingrese el primer departamento y su telefono\n");
    scanf("%s%d",&a,&j);
    plantar(&arbol,a,j);
    for(i = 0;i<n-1;i++){
        printf("ingrese el siguiente departamento y su telefono\n");
        scanf("%s%d",&b,&j);
        agregar(arbol,b,j);
    }

    printf("muestra el arbol:\n");
    imprime(arbol, 0);
//    printf("busque el telefono del departamento deseado\n");
//    scanf("%s",&b);
//    busca(arbol,b);
//    printf("la altura es: %d \n",nivel(arbol,0));
//    //printf("%d\n",recorre(arbol));
//    printf("elimina el departamento deseado\n");
//    scanf("%s",&b);
//    elimina(&arbol,b);
//    printf("muestra el arbol:\n");
//    imprime(arbol,0);
//    printf("la altura es: %d \n",nivel(arbol,0));
    iterativo(arbol);


return 0;
}

void plantar(nodo **raiz,char *a,int t){
    (*raiz) = (nodo *)malloc(sizeof(nodo));
    (*raiz)->izq = NULL;
    (*raiz)->der = NULL;
    (*raiz)->tele = t;
    strcpy((*raiz)->info,a);
}


void agregar(nodo *raiz,char *a,int t){
    if(strcmp(raiz->info,a) > 0){
        if(raiz->izq == NULL)
            plantar(&raiz->izq,a,t);
        else
            agregar(raiz->izq,a,t);
    }
    else{
        if(raiz->der == NULL)
            plantar(&raiz->der,a,t);

        else
          agregar(raiz->der,a,t);
    }

}




void busca(nodo *raiz,char *a){
    if(strcmp(raiz->info,a) == 0){
        printf("Se encontro el dato: %s\n Su numero es: %d\n",raiz->info,raiz->tele);
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


nodo *recorre(nodo *raiz){
    nodo *aux;
    aux = raiz;
    while((aux->der)->der != NULL){
        aux = aux ->der;
    }
        return aux;
}

/*nodo *recorre(nodo *raiz){
    if(raiz->der->der == NULL)
        printf("%d\n",raiz);
        //return raiz;
    else
        recorre(raiz->der);
}*/

void elimina(nodo **raiz,char *a){
    nodo *padremov,*aux, *auxi, *auxd, *otro;
    if(strcmp((*raiz)-> info,a) == 0){
        //si es hoja, si es raíz o si es rama. SON DATOS LOS QUE SE COPIAN NO DIRECCIONES
        if((*raiz)-> izq == NULL && (*raiz)-> der == NULL){
            aux = (*raiz);
            (*raiz) = NULL;
            free(aux);
        }
        //rama con solo un hijo
        else if((*raiz)->izq == NULL){
            aux = (*raiz);
            (*raiz) = (*raiz)->der;
            free(aux);
        }
        else if((*raiz)->der == NULL){
            aux = (*raiz);
            (*raiz) = (*raiz)->izq;
            free(aux);
        }
        else{
            aux = (*raiz);
            auxd = (*raiz)->der;
            auxi = (*raiz)->izq;
            if((*raiz)->izq->der == NULL){
                (*raiz) = (*raiz)->izq;
                (*raiz)->der = auxd;
                free(aux);
            }
            else{
                otro = (*raiz)->izq;
                padremov = recorre(otro);
                (*raiz) = padremov->der;
                padremov->der = (*raiz)->izq;
                (*raiz)->der = auxd;
                (*raiz)->izq = auxi;
                free(aux);

            }
        }
    }
    else{
        if(strcmp((*raiz)->info,a) > 0){
            elimina(&(*raiz)->izq,a);
        }
        else{
            elimina(&(*raiz)->der,a);
        }
    }
}


int nivel(nodo *raiz,int niv){
    int a = 0;
    int b = 0;

    if(raiz == NULL){
        return 0;
     }

    else{
        a = nivel(raiz->izq,niv+1);
        b = nivel(raiz->der,niv+1);
        if(b >= a && b >= niv){
            return b;
        }

        else{
            if(a >= b && a >= niv){
                return a;
            }
            else{
                return niv;
            }
        }
    }


    }


void imprime(nodo *raiz, int niv){
    if(raiz != NULL){
        printf("%s---nivel:%d\n",raiz->info,niv);
        printf("%d\n",raiz);
        niv++;
        imprime(raiz->izq,niv);
        imprime(raiz->der,niv);
    }
}

void iterativo(nodo *raiz){
    nodo *auxi, *auxd;
    pila *nuevo;
    int i=1;
    ini_pila(nuevo,raiz);
    auxi = raiz->izq;
    auxd = raiz->der;
    while(auxi->izq != NULL){
        printf("%s %d\n",auxi->info,auxi->tele);
        push_pila(nuevo,auxi->der);
        auxi = auxi->izq;
        i++;
    }
    while(i != 0){
        auxi = nuevo->member;
        printf("%s %d\n",auxi->info,auxi->tele);
        pop(nuevo);
        i--;
    }

//
//    if(auxi->der != NULL){
//        while(auxi->der != NULL){
//        printf("%s %s\n",auxi->info,auxi->tele);
//        push_pila(nuevo,auxi);
//        auxi = auxi->der;
//        }
//        if(auxi->der == NULL && auxi->izq){
//            auxi = nuevo->member;
//            pop(nuevo);
//        }
//    }

}

void ini_pila(pila *mypila, nodo *guard){
    pila *first;
	first = (pila *)malloc(sizeof(pila));
	first ->member = guard;
    first ->next = NULL;
}

void push_pila(pila *mypila, nodo *guard){
    pila *nuevo;
    nuevo = (pila *)malloc(sizeof(pila));
    nuevo ->next = mypila;
    nuevo -> member = guard;
    mypila = nuevo;

}
void pop(pila *mypila){
    pila *aux;
        aux = mypila;
        mypila = mypila ->next;
        free(aux);
}




