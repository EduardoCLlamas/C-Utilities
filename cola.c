#include <stdio.h>
#define MAX 6

typedef struct _cola{
    int final;
    int arreglo[MAX];
}cola;



void gen(cola *colaN){
    (*colaN).final = 0;
}


void push(cola *colaN, int n){
    if((*colaN).final > MAX){
            printf("Cola LLenaNo se puede agregar mas elementos");
    }
    else{
        (*colaN).arreglo[(*colaN).final] = n;
        (*colaN).final++;
    }


}
void pop_cola(cola *colaN){
    int aux,i;
	if ((*colaN).final == 0){
		printf("Cola vacia, no se pueden eliminar mas elementos");

	}
	else{
		for(i = 0;i < colaN->final;i++){
            aux = colaN->arreglo[i];
            colaN->arreglo[i] = colaN->arreglo[i + 1];
            colaN->arreglo[i + 1] = aux;
		}
		(*colaN).final--;
	}

}

void show_cola(cola *colaN){
    int i;
    for(i = 0;i < colaN->final;i++){
        printf("%d\n",colaN->arreglo[i]);
    }
}
int main(){
cola colota;
gen(&colota);
push(&colota,1);
push(&colota,10);
push(&colota,100);
push(&colota,1000);
show_cola(&colota);
pop_cola(&colota);
pop_cola(&colota);
pop_cola(&colota);
pop_cola(&colota);
pop_cola(&colota);
show_cola(&colota);
return 0;
}
