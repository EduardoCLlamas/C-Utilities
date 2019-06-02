#include <stdio.h>
#define MAX 100000

int a[100000000], mat[1000][2000];

void imprime_matriz(int m[1000][2000], int filas, int columnas){
	int i, j;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	return;
}

void imprime_intercalada(int m[1000][2000], int filas, int columnas){
	int i, j;
	for(i = 0; i < filas; i++){
		if(i%2 != 0){
			for(j = columnas-1; j >= 0; j--){
				printf("%d ", m[i][j]);
			}
		}
		else{
			for(j = 0; j < columnas; j++){
				printf("%d ", m[i][j]);
			}
		}
		printf("\n");
	}
	return;
}


int volt[1000][2000];

void volteada(int m[1000][2000], int *fil, int *col){
	int i, j, t, volt[1000][2000];
	for(i = 0; i < *fil; i++){
		for(j = 0; j < *col; j++){
			volt[i][j] = m[i][j];
		}
	}
	for(i = 0; i < *fil; i++){
		for(j = 0; j < *col; j++){
			m[j][i] = volt[i][j];
		}
	}
	t = *fil;
	*fil = *col;
	*col = t;
	return;
}

void imprime(int a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d\n", a[i]);
	}
	return;
}

int a1[1000000];

int main(){
	int i, j, n, filas, columnas, lista[100000];
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	imprime(a, n);
	scanf("%d%d", &filas, &columnas);
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	volteada(mat, &filas, &columnas);
	printf("%d %d\n", filas, columnas);
	imprime_matriz(mat, filas, columnas);
	imprime_intercalada(mat, filas, columnas);
	return 0;
}
