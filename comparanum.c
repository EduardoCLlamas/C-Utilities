#include <stdio.h>

int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    if(a==b){
        printf("iguales");
    }
    else if(a<b){
        printf("menor");
    }
    else if(a>b){
        printf("mayor");
    }

return 0;
}
