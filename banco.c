#include <string.h>
#include <stdio.h>

typedef struct _cliente{
    char nombre[11];
    int monto,numcli;
}cliente;

int main(){
    int n,i,nc,p;
    char mov;
    cliente cli[11];
    scanf("%d", &n);
    for(i=1;i<11;i++){
        cli[i].numcli=0;
    }

    for(i=0;i<n;i++){
    while(getchar()!='\n');
    scanf("%c%d",&mov,&nc);
    switch(mov){
        case'A':{
            if(cli[nc].numcli!=nc){
                    cli[nc].numcli=nc;
                    scanf("%s%d",cli[nc].nombre,&cli[nc].monto);
                    printf("OK\n");
            }
            else{
                printf("ERROR\n");
            }

            break;
        }
        case'B':{
            if(cli[nc].numcli==nc){
            cli[nc].numcli=0;
            printf("OK\n");
            }
            else{
                printf("ERROR\n");
            }
            break;
        }
        case 'C':{
            if(cli[nc].numcli==nc){
                printf("%s %d\n",cli[nc].nombre,cli[nc].monto);

            }
            else{
                printf("ERROR\n");
            }
            break;
        }
        case 'D':{
            if(cli[nc].numcli==nc){
                    scanf("%d",&p);
                    cli[nc].monto+=p;
                printf("%s %d\n",cli[nc].nombre,cli[nc].monto);
            }
            else{
                printf("ERROR\n");
            }
            break;
        }
        case 'E':{
            if(cli[nc].numcli==nc){
                    scanf("%d",&p);
                    if (cli[nc].monto>=p){
                    cli[nc].monto-=p;
                printf("%s %d\n",cli[nc].nombre,cli[nc].monto);
            }
            else{
                printf("ERROR\n");
            }
            }
            else{
                printf("ERROR\n");
            }
            break;
        }
        default:{
            printf("ERROR\n");
        }
    }

    }
return 0;

}
