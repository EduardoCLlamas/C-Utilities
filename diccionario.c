#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 1000

//////////////////////////////////////////ESTRUCTURA///////////////////////////////////////

typedef struct _nododl{ //creo una estructura con dos campos del tipo caracter y dos apuntadores a estructura nodo para lista DL
    char palabra[MAX];
    char descrip[MAX];
    struct _nododl *next;
    struct _nododl *prev;
}nodo;

//////////////////////////PROTOTIPOS////////////////////////////////
int verifica(FILE *);
void menu(nodo **);
void inicializa(nodo ***);
void inicia_lista(nodo **, char *, char *);
void push_hash(nodo ***, char *,char *);
void agrega(nodo **,char *, char *);
void carga();
int indice(char *);
nodo *busca(nodo **,char *);
void muestra(nodo **, char *);
void imprime(nodo **,FILE **);
void conv_min(char *);
void libera(nodo ***);

////////////////////////////////MAIN///////////////////////////////////////

int main(int argc, char **argv){
    int termino = 0;
    int i;
    nodo *aux;
    char word[20];
    char sear[20];
    char conten[1000];
    nodo **dicc;
    FILE *arch_dic,*arch_sal;
    arch_dic = fopen(argv[1],"r");
//    arch_sal = fopen(argv[2],"w");
    if(verifica(arch_dic)){
        fclose(arch_dic);
        arch_dic = fopen(argv[1],"r+");
        inicializa(&dicc);
        termino = fscanf(arch_dic,"%[^:]%[^\n]\n", &word,&conten);
        while(termino != EOF){
            conv_min(word);
            push_hash(&dicc,word,conten);
            termino = fscanf(arch_dic,"%[^:]%[^\n]\n", &word, &conten);
        }
        menu(dicc);

        imprime(dicc,&arch_dic);
        libera(&dicc);
        fclose(arch_dic);
//        fclose(arch_sal);
    }
    else{
        printf("el formato del archivo de entrada es incorrecto\n Debe respetar el siguente formato:\n Palabra: Descripcion");
    }
return 0;
}

///////////////////////////////////FUNCIONES///////////////////////////////////////////

int verifica(FILE *archivo){//si regresa 1 quiere decir que está correcto el formato del archivo
    int llego = 0;
    char desc[MAX];
    char *cont;
    int res = 0;
    llego = fscanf(archivo,"%[^\n]\n",&desc);
    while(llego != EOF){
            cont = strchr(desc,':');
        if(cont == NULL){
            res++;
        }
        llego = fscanf(archivo,"%[^\n]\n",&desc);
    }
    if(res != 0)
        return 0;
    else
        return 1;
}

void menu(nodo **lista){
    int salir = 0;
    int opcion;
    char palabra[20];
    while(salir == 0){
        opcion = -1;
        printf("Diccionario patito\n");
        printf("Buscar: Opcion 1\n");
        printf("Editar: Opcion 2\n");
        printf("Reemplazar: Opcion 3\n");
        printf("Salir: Opcion 4\n");
        fflush(stdin);
        scanf("%d",&opcion);
        if(opcion == 4)
            salir = 1;
        if(opcion == 1){
            printf("ingrese la palabra a buscar de maxino 20 caracteres\n");
            fflush(stdin);
            scanf("%s",&palabra);
            muestra(lista,palabra);
        }
        if(opcion == 2)
            printf("Editar\n");
        if(opcion == 3)
            printf("Reemplazar\n");
    }
}

void conv_min(char *s){
    int i = 0;
    while(s[i]){
        s[i++] = tolower(s[i]);
    }
}

int indice(char *pal){
    unsigned char index;
    int key;
    index = pal[0];
    key = index;
    if(isalpha(pal[0])){
        key -= 'a';
        return key+1;
    }
    else
        return 0;

}

void inicializa(nodo ***tbhash){    //inicializa el arreglo de apuntadores a listas DL
    int i;
    *tbhash = (nodo **)malloc(sizeof(nodo*)*27);  // le doy memoria al arreglo
    for(i = 0; i < 27; i++){
        (*tbhash)[i] = NULL; //señalo cada apuntador a NULL
    }
}

void inicia_lista(nodo **inicio, char *pal, char *desc){  //crea el primer nodo de una lista DL
	*inicio = (nodo *)malloc(sizeof(nodo));  // le asigno memoria al nodo que recibo y le doy sus valores
	strcpy((*inicio) ->palabra,pal);
	strcpy((*inicio) ->descrip,desc);
    (*inicio) ->next = NULL;  //al ser el primer nodo de la lista DL sus apuntadores a nodo van a NULL
    (*inicio) ->prev =NULL;
}

void push_hash(nodo ***tbhash, char *pal,char *desc){
    nodo *nuevo; //creo un apuntador nuevo a nodo
    if((*tbhash)[indice(pal)] == NULL){ //revisa si la lista está vacía y de ser cierto inicializa una lista
        inicia_lista(&nuevo,pal,desc); //inicializo el nodo
        (*tbhash)[indice(pal)] = nuevo; //es indice +1 por que tengo 2 elementos extras "¿,¡" en las posiciones 0,1.
    }
    else{
        agrega(&(*tbhash)[indice(pal)],pal,desc); //de lo contrario agrega un elemento a la lista
    }
}

void agrega(nodo **tabla,char *pal, char *desc){
    nodo *nuevo,*aux;
    nuevo = (nodo *)malloc(sizeof(nodo)); //siempre se asigna memoria y valores
    strcpy(nuevo->palabra,pal);  //se copia cada string leído en su respectivo elemento
    strcpy(nuevo->descrip,desc);

    if(strcmp((*tabla)->palabra,pal) == 0){ //si es una palabra igual, la agrega despues
        nuevo->next = (*tabla)->next;  //creo q está de más
        nuevo->prev = (*tabla);
        (*tabla)->next = nuevo;
    }
    else if(strcmp((*tabla)->palabra,pal) < 0){
            aux = (*tabla);
            while(aux->next != NULL && strcmp(aux->palabra,pal) < 0){
                aux = aux->next;
            }
            if(aux->next == NULL){ //si recorre todo y no encuentra un mayor y llega a NULL lo agrega al final
                aux->next = nuevo;
                nuevo->prev = aux;
                nuevo->next = NULL;
            }
            else{
                if(aux->prev == NULL){
                    nuevo->prev = aux;
                    nuevo ->next = aux ->next;
                    aux->next = nuevo;
                    nuevo->next->prev = nuevo;
                }
                else{
                    nuevo->prev = aux->prev; //inserta antes del auxiliar y despues del ultimo menor
                    nuevo->next = aux;
                    aux->prev = nuevo;
                }
            }
    }
    else{
        nuevo->next = (*tabla); //la nueva palabra es menor y va al inicio, se inserta al inicio y el apuntador del arreglo señala al nuevo
        (*tabla)->prev = nuevo;
        nuevo ->prev = NULL;
        (*tabla) = nuevo;
    }
}

nodo *busca(nodo **tbhash,char *pal){
    nodo *aux;
    aux = tbhash[indice(pal)];
    while(strcmp(aux->palabra,pal) != 0 && aux->next != NULL){
        aux = aux->next;
    }
    if(strcmp(aux->palabra,pal) == 0)
        return aux;
    else
        return NULL;

}

void muestra(nodo **tbhash, char *pal){
    nodo *aux;
    aux = busca(tbhash,pal);
    printf("%s%s\n",aux->palabra,aux->descrip);

}


void imprime(nodo **tbhash,FILE **archivo){
    int i;
    nodo *aux;
    for(i=0;i<27;i++){
        aux = tbhash[i];
        while(aux != NULL){
            fprintf(*archivo,"%s%s\n",aux->palabra,aux->descrip);
            aux = aux ->next;
        }
    }
}

void libera(nodo ***tbhash){
    nodo *tmp,*aux;
    int i;
    for(i=0;i<27;i++){
        aux = (*tbhash)[i];
        (*tbhash)[i] = NULL;
        while(aux != NULL){
            tmp = aux;
            aux = aux ->next;
            free(tmp);
        }
    }
    free(*tbhash);
}
