#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findnum(int *N, int k, int n) 
{
    int start = 0;
    int end = n - 1;
    int mid;

    while ((end - start) >= 0)
    {
        mid = (end + start) / 2;
        if (k == N[mid])
            return (1);
        else if (k > N[mid]) 
            start = mid + 1;
        else
            end = mid - 1;
    }
    return (0);
}

int compare(const void *a, const void *b) 
{
     if (*(int*)a > *(int*)b)
        return 1;
    else if (*(int*)a < *(int*)b)
        return -1;
    else
        return 0;
}

int main(void)
{
    int n, m, k;
    int N[100001];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &N[i]);
    }

    qsort(N, n, sizeof(N[0]), compare);

    scanf("%d", &m);
    for (int j = 0; j < m; j++)
    {
        scanf("%d", &k);
        printf("%d\n",findnum(N,k,n));
    }
}
