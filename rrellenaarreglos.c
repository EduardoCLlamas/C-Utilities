#include <stdio.h>

int main()
{

    int j,n,a[100];
    scanf("%d", &n);
    for(j=1;j<=n;j++){/*rellena cada espacio del arreglo con todos los números de 1 hasta n*/
        a[j]=j;
     printf("%d\n", a[j]);
    }


return 0;
}
