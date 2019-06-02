#include <stdio.h>

//int variable = 0;


int sumaFuncion(int *a,int *b){
    *a = *a + *b;

   return *a;
}
void sumaProced(int a,int b){
    printf("resultado del procedimiento: %d\n", a+b);
}

int main(){
int a,b;
scanf("%d%d",&a,&b);

printf("%d",sumaFuncion(&a,&b));



return 0;

}
