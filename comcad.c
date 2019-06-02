#include <stdio.h>
#include <string.h>
int intercambia_cadenas(char s[], char t[]){
    char aux[100];
    strcpy(aux, s);
    strcpy(s, t);
    strcpy(t, aux);
    return;
}
int main ()
{
char a[10],b[10];
int val;
scanf("%s%s",&a,&b);
val=strcmp(a,b);
printf("%d\n",val);
if(val>0){
    intercambia_cadenas(a,b);
    printf("%s %s",a,b);
}
  return 0;
}
