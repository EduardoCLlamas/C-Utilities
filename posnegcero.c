#include <stdio.h>

int main(){
    int n;
    scanf("%d",&n);
    if(n<0){
        printf("NEGATIVO\n");
    }
    else if(n==0){
        printf("CERO\n");
    }
    else if(n>0){
        printf("POSITIVO\n");
    }
return 0;
}
