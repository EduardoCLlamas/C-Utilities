#include <stdio.h>
int a[100000000];
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
    int n,i,j;
    scanf("%d", &n);
    for(j=0,i=2;i<=n;i++,j++){
        if(primo(i)==1){
            a[j]=i;
        }
    }
    for(i=0;i<=n;i++){
        for(j=i;j<=n;j++){
            if(a[i]+a[j]==n){
                printf("%d %d\n", a[i],a[j]);
            }
        }
    }
return 0;
}
