#include <stdio.h>
void suma(int A[], int B[], int filas){
	int i;
	int C[202];
	for(i = 0; i < filas; i++){
		C[i]= A[i]+B[i];
		printf("%d ", C[i]);
		}
    return;
}

int main(){
    int i,n;
    int a[101],b[101];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d",&b[i]);
    }
    suma(a,b,n);

return 0;
}
