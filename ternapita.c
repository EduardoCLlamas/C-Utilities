#include <stdio.h>

int main(){
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    a*=a;
    b*=b;
    c*=c;
    if(a+b==c){
        printf("SI");
    }
    else{
        printf("NO");
    }
return 0;
}
