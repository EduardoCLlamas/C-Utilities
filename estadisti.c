/*

Calculo de la moda, mediana y media de una
serie de números introducidos por teclado.
El planteamiento solicitado por uno de nuestros queridos
usuarios a www.aprendoencasa.com, ha sido el de solicitar
un programa que solicite una cantidad de números por teclado y
una vez finalizada la introducción por teclado de los números,
el ejercicio o practica con solución ha de visualizar como
resultado de la misma, los valores correspondientes
a la Moda,Mediana y Media.

    Indicaros que esperamos vuestras aportaciones en
    www.aprendoencasa.com, si teneis algun comentario, duda
    ,aclaración, o solución propuesta para los ejercicios
    estamos encantados de atenderla en la medida de nuestras
    posibilidades. Un saludo de nuevo y gracias por visitar
    www.aprendoencasa.com

*/

#include <stdio.h>
#include <stdlib.h>

// Definicion del numero de elementos maximos del vector
#define MAX 10

int main(int argc, char *argv[])
{
    // Variables a utilizar por el programa
    int numeros[MAX];
    int contador=0;
    int auxiliar[MAX];
    int posicion=0;
    int numero=0;
    int contador2=0;
    int mayor=0;
    int posicionmayor=0;
    int bandera=0;
    float suma=0;

    // Solicitar los numeros para rellenar el vector
    for(contador=0;contador<MAX;contador++) {
        printf("No. %d : ",contador+1);
        scanf(" %d",&numeros[contador]);
    }

    // Visualizar los elementos introducidos en el vector
    printf("\nElementos del vector : ");
    for(contador=0;contador<MAX;contador++) {
        printf(" %d",numeros[contador]);
    }

    // Calcular la moda
    // Rellenamos el vector auxiliar inicializandolo a valores 0
    for(contador=0;contador<MAX;contador++) {
        auxiliar[contador]=0;
    }
    // Recorrer el vector comprobando las repeticiones de cada numero
    // y almacenando las mismas en el vector auxiliar segun la posicion
    // del numero
    for(contador=0;contador<MAX;contador++) {
        numero = numeros[contador];
        posicion = contador;
        for(contador2=contador;contador2<MAX;contador2++) {
            if(numeros[contador2]==numero) auxiliar[posicion]++;
        }
    }
    // Una vez establecidas las repeticiones de cada numero se ha de establcer
    // cual es la posicion del vector que tiene un numero de repeticiones mayor
    // ya que esta es la posicion que se corresponde con el numero que se repite
    // mas veces el vector ( MODA )
    // se establece en primer lugar el mayor como el primer elemento del vector
    mayor=auxiliar[0];
    posicionmayor = 0;
    for(contador=0;contador<MAX;contador++) {
        if(auxiliar[contador]>mayor) {
            posicionmayor=contador;
            mayor=auxiliar[contador];
        }
    }
    // Visualizar el elemento con mas frecuencia de aparicion
    printf("\nMODA : %d",numeros[posicionmayor]);

    // CALCULO DE LA MEDIANA
    // en primer lugar se realiza la ordenacoin del vector de numeros
    bandera=0;
    for(contador=MAX;contador>0 && bandera==0;contador--) {
        bandera=1;
        for(contador2=0;contador2<contador;contador2++) {
            if(numeros[contador2]>numeros[contador2+1]) {
                numero = numeros[contador2];
                numeros[contador2] = numeros[contador2+1];
                numeros[contador2+1]=numero;
                bandera=0;
            }
        }
    }

    // Visualizar los elementos introducidos en el vector
    printf("\nElementos del vector : ");
    for(contador=0;contador<MAX;contador++) {
        printf(" %d",numeros[contador]);
    }
    // Dependiendo de si el numero d elementos del vector es par o impar
    // la mediana ha de ser el punto central del mismo o los dos puntos centrales
    // del mismo.
    if(MAX%2!=0) {
        printf("\nEL valor de la mediana es : %d",numeros[MAX/2]);
    } else {
        printf("\nEL valor 1 de la mediana es : %d",numeros[MAX/2]);
        printf("\nEL valor 2 de la mediana es : %d",numeros[(MAX/2)-1]);
    }

    // Calcular la media www.aprendoencasa.es
    suma = 0;
    for(contador=0;contador<MAX;contador++) {
        suma+=numeros[contador];
    }

    printf("\nMEDIA : %.2f\n",suma/MAX);

  return 0;

}
