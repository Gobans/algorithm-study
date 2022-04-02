#include <stdio.h>

int pair[100][100];
int visit[100];
int virus;

int DFS(int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (pair[k][i] == 1 && visit[i] == 0)
        {
            visit[i] = 1;
            DFS(n, i);
            virus++;
        }
    }
    return virus;
}

int main(void)
{
    int n;
    int p;
    int x;
    int y;

    scanf("%d", &n);
    scanf("%d", &p);
    for (int i = 0; i < p; i++)
    {
        scanf("%d %d", &x, &y);
        pair[x - 1][y - 1] = 1;
        pair[y - 1][x - 1] = 1;
    }

    visit[0] = 1;
    printf("%d", DFS(n, 0));

    return 0;
}