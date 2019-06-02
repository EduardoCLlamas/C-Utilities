#include <stdio.h>

int main(){

	int pant[999], pantr[999];
    int tam, i, j, cont = 0, cont2 = 0, cont3 = 0, menor = 0;

    scanf("%d", & tam);

    for(i = 0; i != tam; i++){
    	scanf("%d", & pant[i]);
    }

    for(i = 0; i != tam-1; i++){


    	if(pant[i] >= pant[i  + 1]){
    	   pantr[i] = pant[i] - pant[i+1];
    	    cont++;
    	}
        else{
        	pantr[i] = pant[i+1] - pant[i];
        	cont++;
        }

    }



    for(i = 1; i < tam + 1; i++){
    	for(j = 0; j < cont; j++){

    		if(pantr[j] == i){


    			cont2 ++;

    		}
    	}
    	if(cont2 > 0){
    		cont3 ++;
    	}
    	else{
    		if(menor == 0)
               menor = i;
    		if(i < menor)
    			menor = i;
    	}
    	cont2 = 0;
    }


    if(cont3 == tam - 1)
    	printf("%d\n",0);
    else
    	printf("%d\n",menor);
    return 0;

}
