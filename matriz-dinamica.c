#include <stdio.h>
#include <string.h>

void imprime_matriz(int **mat, int filas, int columnas){
	int i, j;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			printf("%d ", mat[i][j]);
		}
		printf("\n");
	}
	return;
}

void lectura(int ***mat, int filas, int columnas){
	int i, j;
	*mat = (int**)malloc(filas*sizeof(int*));
	for(i = 0; i < filas; i++){
		(*mat)[i] = (int*)malloc(columnas*sizeof(int));
		for(j = 0; j < columnas; j++){
			scanf("%d", &(*mat)[i][j]);
		}
	}
	return;
}

int** suma(int **A, int **B, int filas, int columnas){
	int i, j, **C;
	C = (int**)malloc(filas*sizeof(int*));
	for(i = 0; i < filas; i++){
		C[i] = (int*)malloc(columnas*sizeof(int));
		for(j = 0; j < columnas; j++){
			C[i][j] = A[i][j]+B[i][j];
		}
	}
	return C;
}

void suma2(int **A, int **B, int ***C, int filas, int columnas){
	int i, j;
	*C = (int**)malloc(filas*sizeof(int*));
	for(i = 0; i < filas; i++){
		(*C)[i] = (int*)malloc(columnas*sizeof(int));
		for(j = 0; j < columnas; j++){
			(*C)[i][j] = A[i][j]+B[i][j];
		}
	}
	return;
}

int** resta(int **A, int **B, int filas, int columnas){
	int i, j, **C;
	C = (int**)malloc(filas*sizeof(int*));
	for(i = 0; i < filas; i++){
		C[i] = (int*)malloc(columnas*sizeof(int));
		for(j = 0; j < columnas; j++){
			C[i][j] = A[i][j]-B[i][j];
		}
	}
	return C;
}

void imprime_diagonal(int **mat, int filas, int columnas){
	int i, j;
	for(i = filas-1; i >= 0; i--){
		for(j = 0; (i+j) < filas && j < columnas; j++){
			printf("%d ", mat[i+j][j]);
		}
	}
	for(j = 1; j < columnas; j++){
		for(i = 0; i < filas && (j+i) < columnas; i++){
			printf("%d ", mat[i][j+i]);
		}
	}
	return;
}

void liberar(int ***mat, int filas){
	int i;
	for(i = 0; i < filas; i++)
		free((*mat)[i]);
	free(*mat);
	return;
}

int main(){
	int i, **A, **B, **C, filas, columnas;
	scanf("%d%d", &filas, &columnas);
	lectura(&A, filas, columnas);
	//imprime_diagonal(A, filas, columnas);
	imprime_matriz(A, filas, columnas);

/*	lectura(&B, filas, columnas);
	C = suma(A, B, filas, columnas);
	imprime_matriz(C, filas, columnas);
	C = resta(A, B, filas, columnas);
	imprime_matriz(C, filas, columnas);
	liberar(A);
	liberar(B);
	liberar(C);*/
	return 0;
}
