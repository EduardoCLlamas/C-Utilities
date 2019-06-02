#include <stdio.h>

int cubo[201][201][201];

void imprimeind0(int d[], int cubo[201][201][201]){
	int i, j, k;
	for(i = 1; i <= d[0]; i++){
		for(j = 1; j <= d[1]; j++){
			for(k = 1; k <= d[2]; k++){
				printf("%d ", cubo[i][j][k]);
			}
			printf("\n");
		}
		printf("--------------\n");
	}
	return;
}

void imprimeind2(int d[], int cubo[201][201][201]){
	int i, j, k;
	for(i = 1; i <= d[2]; i++){
		for(j = 1; j <= d[0]; j++){
			for(k = 1; k <= d[1]; k++){
				printf("%d ", cubo[j][k][i]);
			}
			printf("\n");
		}
		printf("--------------\n");
	}
	return;
}


int main(){
	int i, j, k, consultas, d[3], c[3], color;
	while(scanf("%d%d%d", &d[0], &d[1], &d[2])==3){
		for(i = 1; i <= d[0]; i++){
			for(j = 1; j <= d[1]; j++){
				for(k = 1; k <= d[2]; k++)
					cubo[i][j][k] = 0;
			}
		}
		scanf("%d", &consultas);
		for(i = 0; i < consultas; i++){
			scanf("%d%d%d%d", &c[0], &c[1], &c[2], &color);
			cubo[c[0]][c[1]][c[2]] = color;
		}
		imprimeind0(d, cubo);
		imprimeind2(d, cubo);
	}
	return 0;
}
