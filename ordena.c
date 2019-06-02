#include <stdio.h>


int ordena(int a[], int n)
{
  int j, i, temp;

  for (i=0;i<n;i++)
  {
    for (j=i+1;j<n;j++)
    {
      if (a[j] < a[i])
      {
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }
    }
    printf("%d", a[i]);
  }

return;
}
int main()
{

    int i,n,a[100];
   scanf("%d", &n);/*pide el tamaño del arreglo*/
    for(i=0;i<n;i++){
        scanf("%d", &a[i]);/*solicita los datos hasta que el contador sea menor que el tamaño de arreglo*/
    }


    ordena(a,n);
return 0;
}
