#include <stdio.h>
int tamanio(char *s){
	int cont = 0;
	while(*s != '\0'){
		cont++;
		s++;
	}
return cont;
}
void intercambia(char n[], char m[]){
     int aux;
     aux = *n;
     *n = *m;
     *m = aux;
}
void voltea(char a[100]){
     int i, n = tamanio(a);
     for(i=0, n= n-1; i<n; i++, n--){
              intercambia(&a[i],&a[n]);
     }
}
int buscar(char a[100], char b[100][100],int n,int m){
     int i,j,k, t=tamanio(a), contador;
     for(k=0;k<n;k++){
        for(i=0;i<m-t+1;i++){
            for(j=0, contador=0;j<t;j++){
                if(a[j]==b[k][j+i])
                contador++;
            }
            if(contador==t)
                return 1;
     }
    }
    for(k=0;k<m;k++){
        for(i=0;i<n-t+1;i++){
            for(j=0, contador=0;j<t;j++){
                if(a[j]==b[j+i][k])
                contador++;
            }
            if(contador==t)
                return 1;
     }
    }
return 0;
}

int main (){
    char p[100][100], s[100];
    int i,n,m,q,r[1000];
    scanf("%d%d", &n,&m);
    for(i = 0; i < n; i++){
		scanf("%s", &p[i]);
	}
        scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%s",s);
        r[i]=buscar(s,p,n,m);
        if(r[i]==0){
        voltea(s);
        r[i]=buscar(s,p,n,m);
        }
    }
    for(i=0;i<q;i++){
        if(r[i]==0){
            printf("no\n");
        }else{
            printf("si\n");
            }
     }
return 0;
}
