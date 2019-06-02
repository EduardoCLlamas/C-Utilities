#include <stdio.h>
int creciente(long long int a[],int n){
    int i,c,r;
    for(c=0,i=0;i<=n;i++){
        if(a[i]<=a[i+1]){
            c++;
        }
     }
     if(c==n){
        r=1;
        printf("CRECIENTE\n");
        }
        else{
            r=0;
        }
 return r;
}
void decreciente(long long int a[],int n){
    int i,c;
    for(c=0,i=0;i<n;i++){
        if(a[i]>=a[i+1]){
            c++;
        }
     }
     if(c==n){
            printf("DECRECIENTE\n");
        }
        else{
            printf("NO ORDENADA\n");
        }
 return;
}
int main(){
    int i,n,r;
    long long int a[1000];
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    r=creciente(a,n);
    if(r==0){
        decreciente(a,n);
    }
    return 0;
}
