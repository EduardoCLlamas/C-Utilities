#include<stdio.h>
int primo(int v)
{
    int div;
    if(v<=1)
    {
        return 0;
    }
    else
    {
        for(div=3;div*div<=v;div++)
        {
            if(v%div==0)
            {
                return 0;
            }
        }
    if(v==2)
    {
        return 1;
	}
    else if(v%2==0)
    {
		return 0;
    }
    }
return 1;
}
int main()
{
	int n,p,q=0;
	scanf("%d", &n);
	while(q==0)
    {
        if(primo(n)&&primo(n+2))
        {
			q=n+2;
			p=n;
		}
		n++;
	}
	printf("%d %d\n", p, q);
return 0;
}
