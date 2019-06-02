#include <stdio.h>

int main (void) {
        int v_original [10];
        int v_aux [10];
        int v_final [10];
        int cont,num,i,j=0,k,z=0 ;

        for (i=0; i<10; i++) {
                printf("Introduce el valor del array incial %d: ", i+1);
                scanf("%d",&v_original[i]);
        }


        for (i=0;i<10;i++) {
                cont=0;
                num=v_original[i];
                v_aux[j]=num;
                j++;
                for (k=0;k<10;k++)
                        if ( v_aux[k] == num )
                                cont++;

                if ( cont == 1 ) {
                        v_final[z]=num;
                        z++;
                }
        }


        printf("El array simplificado es: \n");
        for (i=0;i<z;i++)
                printf ("%d \n",v_final[i]);

        return 0;
}
