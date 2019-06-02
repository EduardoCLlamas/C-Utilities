#include <stdio.h>

void leer(int *n, char s[1000][100]){
	int i;
	scanf("%d", &(*n));
/*	while(getchar()!='\n');*/
	for(i = 0; i < *n; i++){
		scanf("%s", s[i]);
		printf("%s\n", s[i]);
	}
	return;
}

int longitud(char *s){
	int cont = 0;
	while(*s != '\0'){
		cont++;
		s++;
	}
	return cont;
}

int longitud_hard(char *s){
	char *t = s;
	while(*(t++) != '\0');
	return t-s-1;
}

int compara_hard(char *s, char *t){
	while(*s != '\0' && *t != '\0' && *(s++) == *(t++));
	return *(--s) == *(--t);
}

int compara_relax(char *s, char *t){
	int i;
	for(i = 0; s[i] != '\0' && t[i] != '\0'; i++){
		if(s[i] != t[i]){
			return 0;
		}
	}
	return s[i] == '\0' && t[i] == '\0';
}

/*
Compara(char *s, char *t): devuelve 1 si las
cadenas s y t son iguales y 0 en otro caso
*/
int compara(char *s, char *t){
	int i, n1 = longitud(s), n2 = longitud(t);
	if(n1 != n2)
		return 0;
	for(i = 0; i < n1; i++){
		if(s[i] != t[i]){
			return 0;
		}
	}
	return 1;
}

void buscar(int n, char s[1000][100], char *t){
	int i;
	for(i = 0; i < n; i++){
		if(compara_hard(s[i], t)){
			printf("Si esta!\n");
			return;
		}
	}
	printf("No esta!\n");
	return;
}

void imprimir_lista(int n, char s[1000][100]){
	int i;
	for(i = 0; i < n; i++){
		printf("%d) %s %d\n", i, s[i], longitud(s[i]));
	}
	return;
}

int main(){
	int n, i, con;
	char nombres[1000][100], nom[100];
	/*toda cadena debe terminar con el caracter nulo '\0'*/
	leer(&n, nombres);
	scanf("%d", &con);
	for(i = 0; i < con; i++){
		scanf("%s", nom);
		buscar(n, nombres, nom);
	}
	imprimir_lista(n, nombres);
	return 0;
}
