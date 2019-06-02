#include <stdio.h>
int main () {
	int a, b, c, m, n, suma=0;
	scanf("%d%d", &m, &n);
    for(a=m,b=m,c=m; a<=n; a++){
        for(b=a;b<=n;b++){
                for(c=b;c<=n;c++){
                    if(a+b>c&&b+c>a&&c+a>b){
                        if((a==b&&a<c&&b<c)||(b==c&&a<b&&a<c)){
                            suma+=1;
                        }
                    }
                }
        }
    }
    printf("%d\n",suma);
    return 0;
}
