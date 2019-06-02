#include <stdio.h>
#include <ctype.h>
#include <string.h>
void conv_may(char s[]){
    int i = 0;
    while(s[i]){
        s[i++] = toupper(s[i]);
    }
return;
}
int main(int argc, char **argv){
    FILE *arch_candi, *arch_salida;
    int i,j,n,m,con, nul, sum1=0;
    char cand[101][11];
    char votos[1001][11];
    arch_candi=fopen(argv[1], "r");
    fscanf(arch_candi,"%d %d",&n, &m);
    for(i = 0;i < n; i++){
        fscanf(arch_candi,"%s", cand[i]);
        conv_may(cand[i]);
    }
    for(i = 0;i < m; i++){
        fscanf(arch_candi,"%s",votos[i]);
        conv_may(votos[i]);
    }
    arch_salida=fopen(argv[2], "w");
    for(i = 0; i < n; i++){
        for(nul = 0, con = 0, j = 0; j < m; j++){
            if((strcmp(cand[i],votos[j]))==0){
                con++;
            }
            else if((strcmp(cand[i],votos[j]))!=0){
                nul++;
            }
        }
        fprintf(arch_salida,"%s %d\n",cand[i], con);
        sum1+=con;
    }
    fprintf(arch_salida,"NULOS %d\n", m-sum1);
    fclose(arch_candi);
    fclose(arch_salida);
return 0;
}
