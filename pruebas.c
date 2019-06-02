#include <stdio.h>
#include <ctype.h>

void conv_min(char *s){
    int i = 0;
    while(s[i]){
        s[i++] = tolower(s[i]);
}
}
int main(){
   char palabra[100];
   scanf("%s",&palabra);
   conv_min(palabra);
   if(isalpha(palabra[0])){
    printf("%c\n",palabra[0]);
    printf("%c\n",palabra[0]);
    printf("%c\n",palabra[0]);
}
   printf("%d\n",palabra[0]);
   return 0;
}

