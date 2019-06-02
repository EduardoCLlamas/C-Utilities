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
    int i, j, k, m, n, o, p, q, mult;
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
    for(i=0;i<=o;i++){
        for(j=0;j<=m;j++){
            for(k=0, mult=0;k<=n;k++){
                p=m1[j][k];
                q=m2[k][i];
                mult+=p*q;
            }
            m3[j][i]=mult;

            }
        }
    imprime_matriz(m3,m,o);
return 0;
}

