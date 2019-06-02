#include <stdio.h>
int indice(char *pal){
    printf("%s\n",pal);
    unsigned char index;
    int key;
    index = pal[1];
    printf(" la primera letra %c\n",index);
    key = index;
    printf("%d\n",key);
    if(strchr(pal,'!') != 0){
        return 0;
    }
    else if(strchr(pal,'?') != 0){
        return 1;
    }
    else{
        key -= 'a';
        return key+2;
    }

}
int main(int argc, char **argv){
//    int termino = 0;
    char word[20];
    char conten[1000];
    scanf("%s%s",&word,&conten);
    printf("%d\n",strcmp(word,conten));
//    FILE *arch_dic,*arch_sal;
//    arch_dic = fopen(argv[1],"r");
//    arch_sal = fopen(argv[2],"w");
//
//    termino = fscanf(arch_dic,"%[^:]%[^\n]", &word, &conten);
//    //printf("%d\n",indice(word));
//    while(termino != EOF){
//        fprintf(arch_sal,"%s%s\n",word,conten);
//        printf("%d\n",indice(word)); //aqui van las acciones
//        termino = fscanf(arch_dic,"%[^:]%[^\n]", &word, &conten);
//
//    }
//
//    fclose(arch_dic);
//    fclose(arch_sal);
return 0;
}
/*
void agrega(nodo **tabla,char *pal, char *desc){//creo que aqui es el ERROR
    //printf("entra en agregar\n");
    nodo *nuevo,*aux;
    nuevo = (nodo *)malloc(sizeof(nodo)); //siempre se asigna memoria y valores
    strcpy(nuevo->palabra,pal);  //se copia cada string leído en su respectivo elemento
    strcpy(nuevo->descrip,desc);

    if(strcmp((*tabla)->palabra,pal) == 0){ //si es una palabra igual, la agrega despues
            //printf("la agrega despues\n");
        nuevo->next = (*tabla)->next;  //agregar mensaje de palabra repetida
        nuevo->prev = (*tabla);
        (*tabla)->next = nuevo;
    }
    else if(strcmp(pal,(*tabla)->palabra) > 0){
        //aux = recorre((*tabla),pal);
            //printf("%s\n",aux->palabra);
            aux = (*tabla);
            while(strcmp(aux->palabra,pal) > 0 && aux != NULL){
                aux = aux->next;
            }

            if(aux->next == NULL){ //si recorre todo y no encuentra un mayor y llega a NULL lo agrega al final
                //printf("la agrega cuando es el ultimo elemento\n");
                aux->next = nuevo;
                nuevo->prev = aux;
                nuevo->next = NULL;
            }
            else{
                //printf("la inserta\n");
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
void busca(nodo *lista,char *pal){
    if(strcmp(lista->palabra,pal) == 0 || lista == NULL){
        if(strcmp(lista->palabra,pal) == 0){

            printf("%s\n significado\n%s\n",lista->palabra,lista->descrip);
        }
        else
            printf("no lo encontre\n");
    }
    else
        busca(lista->next,pal);
}

void muestra(nodo **tbhash, char *pal){
    nodo *aux;
    printf("%d\n",indice(pal));
    aux = tbhash[indice(pal)];
    busca(aux,pal);

}


        nuevo = (nodo *)malloc(sizeof(nodo));
        strcpy(nuevo ->palabra,pal);
        strcpy(nuevo ->descrip,desc);
        nuevo->next = nuevo->prev = NULL;
        //printf("da memoria \n");
        aux = (*tbhash)[indice(pal)];
        //printf("asigna al aux \n");
//        if(busca(aux,pal) != NULL){
//            //printf("opc 1 \n");
//            printf("%s\n",aux->palabra);
//           printf("Esta palabra ya existe en el diccionario, no se agregara\n");
//        }
//        else{
            //printf("opc 2 \n");
            if(strcmp(pal,aux->palabra) < 0){
                //printf("opc 2.1 \n");
                nuevo->next = aux;
                aux->prev = nuevo;
                (*tbhash)[indice(pal)] = nuevo;
            }
            else{
                //printf("opc 2.2 \n");
                while(aux->next != NULL && strcmp(aux->palabra,pal) < 0){
                    //printf("entra al ciclo \n");
                    aux = aux->next;
                }
                //printf("%s\n",aux->palabra);
                if(strcmp(aux->palabra,pal) < 0 && aux->next == NULL){
                    //printf("opc 2.2.1 \n");
                    aux->next = nuevo;
                    nuevo->prev = aux;
                }
                else{
                    //printf("opc 2.2.2 \n");
                    nuevo->prev = aux->prev;
                    nuevo->next = aux;
                    aux->prev = nuevo;
                }
            }
//        }


*/
