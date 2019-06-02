#include <stdio.h>
#include <string.h>

void imprime_matriz(int mat[100][100], int filas, int columnas){
	int i, j;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	return;
}

void lectura(int mat[100][100], int filas, int columnas){
	int i, j;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			scanf("%d", &mat[i][j]);
		}
	}
	return;
}

void suma2(int A[100][100], int B[100][100], int C[100][100], int filas, int columnas){
	int i, j;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			C[i][j] = A[i][j]+B[i][j];
		}
	}
	return;
}

int main(){
	int i, A[100][100], B[100][100], C[100][100], filas, columnas;
	scanf("%d%d", &filas, &columnas);
	lectura(A, filas, columnas);
	lectura(B, filas, columnas);
/*	C = suma(A, B, filas, columnas);*/
	suma2(A, B, C, filas, columnas);
	imprime_matriz(C, filas, columnas);
	return 0;
}
