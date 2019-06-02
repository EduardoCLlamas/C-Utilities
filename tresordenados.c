#include <stdio.h>
int main(){
    int a[3];
    int i,c;
    for(i=0;i<3;i++){
        scanf("%d",&a[i]);
    }
    for(c=0,i=0;i<=3;i++){
        if(a[i]<=a[i+1]){
            c++;
        }
     }
     if(c==3){
        printf("SI");
        }
        else{
            printf("NO");
        }
 return 0;
}
