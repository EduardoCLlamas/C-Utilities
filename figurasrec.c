#include<stdio.h>
#include<math.h>

int main(){
    double p,q,ent;
    unsigned int flag=0,n,i;
    scanf("%d",&n);
    q=sqrt(n);
    modf(q,&ent);
    
    if(ent*ent == n)
        flag++;
    
    for(i=2;i<n;i++){
        if((n%i == 0) && ((n/i)*i == n) && (n/i) != i){
            flag += 2;
            break;
            }
        }
    if(flag == 1){
        printf("cuadrado");
        }else if(flag == 2){
            printf("rectangulo");
            }else if(flag == 3){
                printf("ambos");
                }else{
                    printf("ninguno");
                    }
    return 0;    
}
