#include <stdio.h>
void ordena(int a[])
{
  int j, i, temp;
  for (i=0;i<3;i++){
    for (j=i+1;j<3;j++){
      if (a[j] > a[i]){
        temp = a[j];
        a[j] = a[i];
        a[i] = temp;
      }
    }
   }
}

int main(){
    int a[3];
    int i;
    for(i=0;i<3;i++){
    scanf("%d", &a[i]);
    }
    ordena(a);
    printf("%d", a[0]);

return 0;
}
