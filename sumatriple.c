#include <stdio.h>
int main(){
    int i,n;
    long long int a[65];
    scanf("%d",&n);
    a[0]=1;
    a[1]=a[0];
    a[2]=a[0]+a[1];
    if(n>=4){
    for(i=2;i<n;i++){
        a[i+1]=a[i]+a[i-1]+a[i-2];
    }
    for(i=0;i<n;i++){
        printf("%lld ", a[i]);
        }
    }
    else{
        for(i=0;i<n;i++){
           printf("%lld ", a[i]);
        }
    }
return 0;
}
