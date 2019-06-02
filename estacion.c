#include <stdio.h>
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
    return;
  }
}
void imprime_vector(int a[], int n){
	int i;
	for(i = 0; i < n; i++){
		printf("%d\n", a[i]);
	}
	return;
}
  int main(){
      int i,n;
      int est[]={580,980,1190,1250,1420};
      int aux[5];
      scanf("%d", &n);
      if(n>=580&&n<=1520){
        for(i=0;i<5;i++){
            aux[i]=est[i]-n;
        }
        ordena(aux,5);
        imprime_vector(aux,5);
        if((aux[0])<0&&abs(aux[0])<abs(aux[1])){
            printf("atras %d",abs(aux[0]));
        }
        else if(abs(aux[0])>abs(aux[1])){
            printf("adelante %d", aux[1]);
        }
        else{
            printf("adelante %d",aux[0]);
        }
      }
      else{
        printf("error");
      }
  return 0;
  }
