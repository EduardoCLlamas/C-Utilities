#include <stdio.h>

int main()
{
    int s, m;
    scanf("%d", &m);
    m>=1&&m<=100?(s=m*60):(s=0);
    printf("%d\n", s);

        return 0;
}
