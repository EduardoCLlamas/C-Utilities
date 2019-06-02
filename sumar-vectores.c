#include <stdio.h>
int suma(int a[]){
    int i,b[100];
    for(i=0;i<100;i++){
        b[i]=a[i]+a[i+1];
    }
    return b[i];
}
