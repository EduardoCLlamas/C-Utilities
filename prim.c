#include <stdio.h>
void pri(long long int v){
    long long int div,r;
    scanf("%lld",&v);
    if(v<=1){
        r=0;
    }
    else{
        for(div=2;div*div<=v;div++){
            if(v%div==0){
                r=0;
                break;
           }
        }
        if(div*div>v){
            r=1;
        }
    }
    return;
}
int main(){
long long int n, p, q=0;
scanf("%lld", &n);
if(pri(n)==0){
while(q==0){
if(pri(n)&&pri(n+2)){
 p=n;
 q=n+2;
}
n++;
}
printf("%lld %lld", p,q);
}

return 0;
}
