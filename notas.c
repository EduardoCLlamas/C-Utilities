#include <stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    if(n==10){
        printf("Excelente\n");
    }
    else if(n==9){
        printf("Muy bien\n");
    }
        else if(n==8){
        printf("Bien\n");
    }
        else if(n==7){
        printf("Regular\n");
    }
        else if(n==6){
        printf("Suficiente\n");
    }
        else if(n<=5){
        printf("No acredita\n");
    }
return 0;
}
