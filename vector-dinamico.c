#include <stdio.h>
#include <string.h>

void imprime(int *v, int n){
	int i;
	printf("%d\n", &v);
	for(i = 0; i < n; i++, v++){
		printf("%d %d %d\n", *v, &(*v), v);
	}
	return;
}

void lectura(int **v, int n){
	int i;
	*v = (int*)malloc(n*sizeof(int));
	for(i = 0; i < n; i++){
		scanf("%d", &(*v)[i]);
	}
	return;
}

int main(){
	int i, *v, n;
	scanf("%d", &n);
	lectura(&v, n);
	printf("%d %d\n", v, &v);
	imprime(v, n);
	imprime(v, n);
	free(v);
	return 0;
}
