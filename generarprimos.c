#include <stdio.h>
int primo(int a){
    int i,c;
    for(c=0,i=1;i<=a;i++){
        if(a%i==0){
            c++;
        }
    }
    if(c==2){
        return 1;
        }
    else{
        return 0;
        }
}

int main(){
    int i,j,n,c;
    scanf("%d", &n);
    for(c=0,i=2;i<=n;i++){
        if(primo(i)==1){
            printf("%d ", i);
        }
    }
}
