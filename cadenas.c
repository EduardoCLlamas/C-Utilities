#include <stdio.h>

void print(const char *s){
	while(*s != '\0'){
		putchar(*s);
		s++;
	}
	return;
}

int main(){
	int a, b;
	const char *s = "hola mundo";
	char t[10000];
	/*toda cadena debe terminar con el caracter nulo '\0'*/
	printf("%c%c %s\n", *s, *(s+1), s);
	print(s);
	putchar('\n');
	print(s);
	putchar('\n');
	scanf("%d%d", &a, &b);
	gets(t);
	printf("(%s)\n", t);
	return 0;
}
