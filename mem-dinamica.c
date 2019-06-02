#include <stdio.h>
#include <stdlib.h>

void imprime(int v[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d %d\n", v[i], *(v+i));
	}
	return;
}

int main(){
	int i, *v, n, w[100];
	scanf("%d", &n);
	v = (int*)malloc(n*sizeof(int));
	for(i = 0; i < n; i++){
		scanf("%d", &w[i]);
/*		scanf("%d", (v+i*sizeof(int)));*/
	}
	imprime(w, n);
	imprime(w, n);
	free(v);
	return 0;
}
