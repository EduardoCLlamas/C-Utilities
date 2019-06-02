#include<stdio.h>
void imprime(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\n", a[i]);
    }
    return;
}

int main(){

int cad[], inter, i, n, j, k;
scanf("%d", &n)
for(i=0;i<8;i++){
for(k=8; k>0; k--){
for(j=0; j<8; j++){
if(cad[j] >= cad[k]){
inter = cad[j];
cad[j] = cad[k];
cad[k] = inter;
}
}
}
}
for(k=0; k<8; k++){

for(j=0; j<2; j++){

if(cad[k] > cad[k+1]){

temp = cad[k+1];
cad[k+1] = cad[k];
cad[k] = temp;
}
}
}
for(i=0;i<8;i++)
printf("%d, ", cad[i]);
return 0;
}

