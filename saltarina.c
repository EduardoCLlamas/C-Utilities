#include <stdio.h>

int main(){

	int ari[999], arf[999];
    int n, i, j, c1 = 0, c2 = 0, c3 = 0, min = 0;
    scanf("%d", & n);
    for(i = 0; i != n; i++){
    	scanf("%d", & ari[i]);
    }

    for(i = 0; i != n-1; i++){
    	if(ari[i] >= ari[i  + 1]){
    	    arf[i] = ari[i] - ari[i+1];
    	    c1++;
    	}
        else{
        	arf[i] = ari[i+1] - ari[i];
        	c1++;
        }
    }
    for(i = 1; i < n + 1; i++){
    	for(j = 0; j < c1; j++){
    		if(arf[j] == i){
    			c2 ++;
    		}
    	}
    	if(c2 > 0){
    		c3 ++;
    	}
    	else{
    		if(min == 0){
               min = i;
    		}
    		if(i < min){
    			min = i;
    		}
    	}
    	c2 = 0;
    }
    if(c3 == n - 1){
    	printf("%d\n",0);
    }
    else{
    	printf("%d\n",min);
    }
    return 0;
}
