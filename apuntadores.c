#include <stdio.h>

void inter(int *a, int *b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
	printf("%d %d %d %d\n", a, *a, &a, &(*a));
	return;
}

int main(){
	int hola = 9, mundo = 12, *pointer, dos = 9;
	*pointer = 7;
	printf("%d\n", pointer);
	printf("%d %d\n", *pointer, hola+mundo+dos);
	printf("%d %d %d %d\n", &hola, &mundo, &(*pointer), &dos);
	inter(&hola, &mundo);
	return 0;
}
