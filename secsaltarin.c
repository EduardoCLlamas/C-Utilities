#include <stdio.h>
int a[1000], b[1000], di[1000], x[1000],fin[1000];
int no(int a[],int n){
    int j;
     for(j=1;j<=n;j++){/*rellena cada espacio del arreglo con todos los números de 1 hasta n "este es adicional"*/
        x[j]=j;
    }
}
int descarta(int o[],int n) {
        int aux[1000];
        int cont,num,i,j=0,k,l=0 ;
        for (i=0;i<n;i++) {
                cont=0;
                num=o[i];
                aux[j]=num;
                j++;
                for (k=0;k<n;k++)
                    if ( aux[k] == num )
                        cont++;
                        if(cont == 1 ){
                            fin[l]=num;
                            l++;
                }

        }

        return fin[i];
}
int ordena(int a[], int n)
{
  int j, i, temp;
  for (i=0;i<n;i++){
    for (j=i+1;j<n;j++){
      if (a[j] < a[i]){
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }
    }
    b[i]=a[i];
      printf("%d", b[i]);
  }


return b[i];
}
int difer(int a1[],int n){
    int i,j,suma;
    for(i=0;i<n-1;i++){/*hasta -n para que no entregue 0-n*/
        di[i]=abs(a1[i]-a1[i+1]);/*asigna las restas al arreglo di*/

    }
    return di[i];
}
int imprime(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf(" %d", a[i]);
    }
    return;
}
int main(){
    int i,n,j,k,r[1000];
    scanf("%d", &n);/*pide el tamaño del arreglo*/
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);/*solicita los datos hasta que el contador sea menor que el tamaño de arreglo*/
    }

    difer(a,n);
    descarta(di,n);
    ordena(fin,n);
return 0;
}


