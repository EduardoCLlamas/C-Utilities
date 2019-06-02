void cambio(int*x, int*y)
    {
     int a;
     a=*x;
     *x=*y;
     *y=a;
     return;
     }
void imprime(int a[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\n", a[i]);
    }
    return;
}
          /*  for(j=0;j<n-1;j++){
                if(j>j+1){

                }

*/
