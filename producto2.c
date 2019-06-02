#include <stdio.h>
int m1[100][100],m2[100][100],m3[100][100];
void imprime_matriz(int m[100][100], int f, int c){
	int i, j;
	for(i = 0; i < f; i++){
		for(j = 0; j < c; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	return;
}
int main(){
    int m, n, o, i, j, k, p, q, suma;
    scanf("%d%d%d", &m,&n,&o);
    for(i = 0; i < m; i++){
		for(j = 0; j < n; j++){
			scanf("%d", &m1[i][j]);
		}
	}
    for(i = 0; i < n; i++){
		for(j = 0; j < o; j++){
			scanf("%d", &m2[i][j]);
		}
	}
    for(i=0;i<=m;i++){
        for(j=0;j<=n;j++){
            for(k=0, suma=0;k<=o;k++){
                p=m1[i][k];
                q=m2[k][j];
                suma+=p*q;
            }
            m3[i][j]=suma;

            }
        }
    imprime_matriz(m3,m,o);
return 0;
}
