#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

void heapSort(int *, int);
void merge(int *, int,int, int);
void mergeSort(int *, int, int);
void insert(int *,int ,int );
int del(int *,int ,int );
void update(int *,int ,int, int );
void bubbleSort(int *,int);
void selectionSort(int *,int);
void insertionSort(int *,int);
int binarySearch(int *, int , int);
void swap(int *, int *);
void imprimir(int *,int);
void menu(int *);


int main(){

    int a[MAX];
    int i;
    for(i = 0; i < MAX; i++){
        a[i] = rand() % 100;
    }
    menu(a);
    return 0;
}

void menu(int *a){
int salir = 0;
int x, val;
clock_t start;

    int opcion;
    while(!salir){
        opcion = -1;
        printf("Funciones\n");
        printf("Sort: 1\n");
        printf("Insert: Opcion 2\n");
        printf("Delete: Opcion 3\n");
        printf("Update: Opcion 4\n");
        printf("Binary Search: Opcion 5\n");
        printf("Insertion Sort: Opcion 6\n");
        printf("Selection Sort: Opcion 7\n");
        printf("Bubble Sort: Opcion 8\n");
        printf("Salir: Opcion 9\n");
        fflush(stdin);
        scanf("%d",&opcion);
        if(opcion == 9)
            salir = 1;
        if(opcion == 1){
            fflush(stdin);
            imprimir(a,MAX);
            start = clock();
            insertionSort(a,MAX);
            printf("Tiempo transcurrido: %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
            imprimir(a,MAX);
        }
        if(opcion == 2){
            fflush(stdin);
            printf("Ingrese el valor a insertar: ");
            scanf("%d", &val);
            imprimir(a,MAX);
            start = clock();
            insert(a,MAX,val);
            printf("Tiempo transcurrido: %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
            imprimir(a,MAX);
        }
        if(opcion == 3){
            fflush(stdin);
            imprimir(a,MAX);
            printf("Ingrese el valor a eliminar: ");
            scanf("%d", &val);
            start = clock();
            printf("Elemento de la posicion %d eliminado \n",del(a,MAX,val));
            printf("Tiempo transcurrido: %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
        }
        if(opcion == 4){
            fflush(stdin);
            imprimir(a,MAX);
            printf("Ingrese el valor a sustituir: ");
            scanf("%d", &val);
            printf("Ingrese el nuevo valor: ");
            scanf("%d", &x);
            start = clock();
            update(a,MAX,val,x);
            printf("Tiempo transcurrido: %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
            imprimir(a,MAX);
        }
        if(opcion == 5){
            fflush(stdin);
            printf("Ingrese el valor a buscar: ");
            scanf("%d", &val);
            imprimir(a,MAX);
            start = clock();
            printf("Resultado: %d\n",binarySearch(a,MAX,val));
            printf("Tiempo transcurrido: %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
        }
        if(opcion == 6){
            fflush(stdin);
            imprimir(a,MAX);
            start = clock();
            mergeSort(a,0,MAX-1);
            printf("Tiempo transcurrido: %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
            printf("arreglo ordenado: \n");
            imprimir(a,MAX);
        }
        if(opcion == 7){
            fflush(stdin);
            imprimir(a,MAX);
            start = clock();
            selectionSort(a,MAX);
            printf("Tiempo transcurrido: %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
            printf("arreglo ordenado: \n");
            imprimir(a,MAX);
        }
        if(opcion == 8){
            fflush(stdin);
            imprimir(a,MAX);
            start = clock();
            bubbleSort(a,MAX);
            printf("Tiempo transcurrido: %f\n",((double)clock()-start)/CLOCKS_PER_SEC);
            printf("arreglo ordenado: \n");
            imprimir(a,MAX);
        }
    }
}

void insert(int *a, int n, int val){

}

int del(int *a, int n, int val){
    insertionSort(a,n);
    int i = binarySearch(a,n,val);
    int j;
    if(i != -1){
        for(j = i;j < n - 1;j++){
            a[j] = a[j+1];
        }
    }
    a[n-1] = 0;
    return (i);
}

void update(int *a, int n, int val, int nval){
    insertionSort(a,n);
    int i = binarySearch(a,n,val);
    a[i] = nval;
    insertionSort(a,n);
}

void merge(int *a,int l, int m, int r){
    int i,j,k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for(i = 0; i < n1; i++)
        L[i] = a[l+i];

    for(j = 0; j < n2; j++)
        R[j] = a[m + 1 + j];

    i = j = 0;
    k = 1;
    while(i<n1 && j < n2){
        if(L[i] <= R[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = R[j];
            j++;
        }
        k++;
    }
}

void mergeSort(int *a, int l, int r){
    if(l < r){
        int m = l + (r - l) / 2;
        mergeSort(a, l, m);
        mergeSort(a,m + 1, r);
        merge(a, l, m, r);

    }
}

void bubbleSort(int a[], int n){
  int j, i, temp;
  for (i=0;i<n;i++){
    for (j=i+1;j<n;j++){
      if (a[j] < a[i]){
        swap(&a[j], &a[i]);
      }
    }
  }
}

void selectionSort(int *a, int n){
    int i, j, min;

    for (i = 0; i < n-1; i++)
    {
        min = i;
        for (j = i+1; j < n; j++)
          if (a[j] < a[min])
            min = j;
        swap(&a[min], &a[i]);
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


int binarySearch(int *a, int n, int val){
    int mid, low = 0,hig = n;
    while (low <= hig)
    {
        mid = (low + hig) / 2;
        if (val == a[mid])
            return mid;
        else if (val < a[mid])
            hig = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void imprimir(int *a,int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d | ", a[i]);
	}
        printf("\n");
}

