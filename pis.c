#include <stdio.h>
int z[1000], d[1000], b[1000];
int dif(int a1[],int n){
    int i;
    for(i=0;i<n-1;i++){
        d[i]=abs(a1[i]-a1[i+1]);
    }
    return d[i];
}
int des( int a[], int n) {
        int aux[1000];
        int fin[1000];
        int cont,num,i,j=0,k,l=0;
        for (i=0;i<n-1;i++) {
                cont=0;
                num=a[i];
                aux[j]=num;
                j++;
                for (k=0;k<n;k++)
                        if ( aux[k] == num )
                                cont++;
                if ( cont == 1 ) {
                        fin[l]=num;
                        l++;
                }
        }
       for (i=0;i<l;i++){
                z[i]=fin[i];
                printf ("%d\n",z[i]);
       }
        return z[i];
}
int ord(int a[], int n)
{
  int j, i, temp;
  for (i=0;i<n;i++){
    for (j=i+1;j<n;j++){
      if (a[j] < a[i]){
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }

    }
b[i]=a[i];
      printf("%d", b[i]);
  }
return b[i];
}
int main(){
    int i,n,j,k,a[1000];
    scanf("%d", &n);
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);
    }

    dif(a,n);
    des(d,n);
    ord(z,n);
return 0;
}

