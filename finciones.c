#include <stdio.h>
void leer(char s[100][100], int n){
	int i;
	for(i = 0; i < n; i++){
		scanf("%s", &s[i]);
	}
	return;
}
void voltea(char s[]){
  int c, i, j;
  for (j = 0; s[j]; j++);
  for (i = 0, j--; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}
int revisa(char s[], char t[]){
  int i, j, k;
  for (i = 0; t[i]; i++) {
    for (j = 0, k = i; t[k] && (t[k] == s[j]); j++, k++);
    if (!s[j]){
        return 1;
    }
  }
  return 0;
}
void imprime_vector(int a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d\n", a[i]);
	}
	return;
}
void intercambio(int *a, int *b){
	int t;
	t = *a;
	*a = *b;
	*b = t;
	printf("%d %d %d %d\n", a, *a, &a, &(*a));
	return;
}
void imprime_matriz(int m[1000][2000], int filas, int columnas){
	int i, j;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			printf("%d ", m[i][j]);
		}
		printf("\n");
	}
	return;
}

void imprime_intercalada(int m[1000][2000], int filas, int columnas){
	int i, j;
	for(i = 0; i < filas; i++){
		if(i%2 != 0){
			for(j = columnas-1; j >= 0; j--){
				printf("%d ", m[i][j]);
			}
		}
		else{
			for(j = 0; j < columnas; j++){
				printf("%d ", m[i][j]);
			}
		}
		printf("\n");
	}
	return;
}
void matriz_volteada(int m[1000][2000], int *fil, int *col){
	int i, j, t, volt[1000][2000];
	for(i = 0; i < *fil; i++){
		for(j = 0; j < *col; j++){
			volt[i][j] = m[i][j];
		}
	}
	for(i = 0; i < *fil; i++){
		for(j = 0; j < *col; j++){
			m[j][i] = volt[i][j];
		}
	}
	t = *fil;
	*fil = *col;
	*col = t;
	return;
}
void imprime_cadenas(const char *s){
	while(*s != '\0'){
		putchar(*s);
		s++;
	}
	return;
}
void leer_matriz(int *n, char s[1000][100]){
	int i;
	scanf("%d", &(*n));
	for(i = 0; i < *n; i++){
		scanf("%s", s[i]);
		printf("%s\n", s[i]);
	}
	return;
}
void lectura(int mat[100][100], int filas, int columnas){
	int i, j;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			scanf("%d", &mat[i][j]);
		}
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
void suma2(int A[100][100], int B[100][100], int C[100][100], int filas, int columnas){
	int i, j;
	for(i = 0; i < filas; i++){
		for(j = 0; j < columnas; j++){
			C[i][j] = A[i][j]+B[i][j];
		}
	}
	return;
}
void unir(int a[], int n, int b[], int m, int res[]){
    int i;
    for( i = 0; i < n; i++){
        res[i] = a[i];
    }
    for( i = 0; i < m; i++){
        res[i + n] = b[i];
    }
return;
}
int ordena(int a[], int n){
  int j, i, temp;
  for (i=0;i<n;i++){
    for (j=i+1;j<n;j++){
      if (a[j] < a[i]){
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }
    }
    printf(" %d", a[i]);
  }
}

void insertionSort(int *a, int n){
    int i, aux, j;
   for (i = 1; i < n; i++)
   {
       aux = a[i];
       j = i-1;
       while (j >= 0 && a[j] > aux)
       {
           a[j+1] = a[j];
           j = j-1;
       }
       a[j+1] = aux;
   }
}

int binary_Search(int vec[], int n, int x){
    int inicio, fin, centro;

    inicio = 0;
    fin = n-1;

    while(inicio <= fin){
        centro = (inicio + fin)/2;

        if(x < vec[centro])
            fin = centro-1;
        else if(x > vec[centro])
            inicio = centro + 1;
        else{
            return centro;
        }
    }
    return (-1);
}
int binarySearchS(int *vec, int x,int n){
    int inicio, fin, centro;

    inicio = 0;
    fin = n-1;

    while(inicio <= fin){
        centro = (inicio + fin)/2;

        if(x < vec[centro])
            fin = centro-1;
        else if(x > vec[centro])
            inicio = centro + 1;
        else{
            printf("Existe una instancia de este numero en la posicion: ");
            return centro;
        }
    }
    return (-1); //No lo encontro
}

return;
}
int diferencias_arreglos(int a1[],int n){
    int i;
    for(i=0;i<n-1;i++){
        d[i]=abs(a1[i]-a1[i+1]);
    }
    return d[i];
}
int palindromo(char s[]){
	int i, n = longitud_hard(s);
	for(i = 0, n = n-1; i < n; i++, n--){
		if(s[i] != s[n])
			return 0;
	}
	return 1;
}
int suma_vectores( int a[], int n)
{

 int i;
 int suma;

 i = 0;
 suma = 0;
 while( i < n )
 {
    suma+=a[i];
    i++;
 }
 printf("%d\n", suma);
 return suma;
}
int descarta_repeticion(int o[],int n) {
        int aux[1000];
        int cont,num,i,j=0,k,l=0 ;
        for (i=0;i<n;i++) {
                cont=0;
                num=o[i];
                aux[j]=num;
                j++;
                for (k=0;k<n;k++)
                    if ( aux[k] == num )
                        cont++;
                        if(cont == 1 ){
                            fin[l]=num;
                            l++;
                }

        }

        return fin[i];
}

int sumas_arreglo_sin_repe( int a[], int n){
 int i=0,j, suma=0;

     for(j=1;j<=n;j++){
        b[j]=j;
    }

 while( i < n )
 {
     if(a[i]!=a[i+1]){
        suma+=a[i];
     }
        i++;
 }
 return suma;
}
