#include <stdio.h>

int revisa(char s[], char t[]){
  int i, j, k;
  for (i = 0; t[i]; i++) {
    for (j = 0, k = i; t[k] && (t[k] == s[j]); j++, k++);
    if (!s[j]){
        return 1;
    }
  }
  return 0;
}

void voltea(char s[]){
  int c, i, j;
  for (j = 0; s[j]; j++);
  for (i = 0, j--; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

int main(){
  char p[100], s[100];
  int d, r;
  gets(p);
  gets(s);
  d = revisa(p, s);
  voltea(p);
  r = revisa(p, s);
  printf("%d %d\n", d, r);
  return 0;
}
