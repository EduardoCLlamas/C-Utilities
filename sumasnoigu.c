int a[1000],b[1000];
int sumas( int a[], int n){
 int i=0,j, suma=0;

     for(j=1;j<=n;j++){
        b[j]=j;
    }

 while( i < n )
 {
     if(a[i]!=a[i+1]){
        suma+=a[i];
     }
        i++;
 }
 return suma;
}
/*suma los elementos de un arreglo siempre y cuando no sean iguales*/
