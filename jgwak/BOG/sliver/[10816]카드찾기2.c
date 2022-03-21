#include <stdio.h>

int N[20000001];

int main(void)
{
    int n,m,a,b;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a);
        N[10000000 + a] += 1;
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &b);
        printf("%d ", N[10000000 + b]);
    }
}
