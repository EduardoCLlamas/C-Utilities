#include <stdio.h>
#define MAX 100000
int a[100000000], mat[1000][2000];
void imprime_matriz(int m[1000][2000],int filas,int columnas){
    int i, j;
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            printf("%d", m[i][j]);
        }
        printf("\n");
    }
    return;
}
void imprime(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\n", a[i]);
    }
    return;
}
int a1[10000000];
int main(){
    int i,j,n, filas, columnas, lista[100000];
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    imprime(a,n);
    scanf("%d%d", &filas, &columnas);
    for(i=0;i<filas;i++){
        for(j=0;j<columnas;j++){
            scanf("%d", &mat[i][j]);
        }
    }
    imprime_matriz(mat,filas,columnas);

    return 0;

}
