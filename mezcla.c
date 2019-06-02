#include <stdio.h>
void unir(int a[], int n, int b[], int m, int res[]){
int i;
for( i = 0; i < n; i++){
res[i] = a[i];
}
for( i = 0; i < m; i++){
res[i + n] = b[i];
}
return;
}
int ordena(int a[], int n){
  int j, i, temp;
  for (i=0;i<n;i++){
    for (j=i+1;j<n;j++){
      if (a[j] < a[i]){
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }
    }
    printf(" %d", a[i]);
  }

return;
}
int main(){
    int i,j,n,m;
    int a[10000],b[10000], c[1000];
    scanf("%d%d", &n,&m);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(j=0;j<m;j++){
        scanf("%d", &b[j]);
    }
    unir(a,n,b,m,c);
    ordena(c,n+m);
    return 0;
}
