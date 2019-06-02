#include <stdio.h>
#include <math.h>
int main()
{
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%d %d %d %d %d %f\n", a+b, a-b, a/b, a*b, a%b,sqrt(a));
    return 0;
}
