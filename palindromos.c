#include <stdio.h>

int longitud_hard(char *s){
	char *t = s;
	while(*(t++) != '\0');
	return t-s-1;
}

/*
palindromo devuelve 1 si es pal 0 en otro caso
*/
int palindromo(char s[]){
	int i, n = longitud_hard(s);
	for(i = 0, n = n-1; i < n; i++, n--){
		if(s[i] != s[n])
			return 0;
	}
	return 1;
}

/*
palindromo devuelve 1 si es pal 0 en otro caso
*/
int palindromo_v2(char s[]){
	int i, n = longitud_hard(s);
	for(i = 0, n = n-1; i < n && s[i] == s[n]; i++, n--);
	return i >= n;
}


int main(){
	char palabra[100];
	/*toda cadena debe terminar con el caracter nulo '\0'*/
	while(scanf("%s", palabra)==1){
		printf("%d\n", palindromo(palabra));

	}
	return 0;
}
