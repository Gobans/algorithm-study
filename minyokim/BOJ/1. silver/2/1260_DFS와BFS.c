#include <stdio.h>

int DFSvisit[1001];
int BFSvisit[1001];
int pair[1001][1001];
int queue[1001];

void DFS(int n, int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (pair[k][i] == 1 && DFSvisit[i] == 0)
        {
            DFSvisit[i] = 1;
            printf("%d ", i);
            DFS(n, i);
        }
    }
}

void BFS(int n, int k)
{
    int front = 0, rear = 1, Pop, i;
    queue[0] = k;

    while (front < rear)
    {
        Pop = queue[front];
        front++;

        for (int i = 1; i <= n; i++)
        {
            if (pair[Pop][i] == 1 && BFSvisit[i] == 0)
            {
                queue[rear] = i;
                printf("%d ", i);
                rear++;
                BFSvisit[i] = 1;
            }
        }
    }
}

int main(void)
{
    int N, M, V, x, y;

    scanf("%d", &N);
    scanf("%d", &M);
    scanf("%d", &V);
    for (int i = 0; i < M; i++)
    {
        scanf("%d %d", &x, &y);
        pair[x][y] = 1;
        pair[y][x] = 1;
    }

    DFSvisit[V] = 1;
    printf("%d ", V);
    DFS(N, V);

    BFSvisit[V] = 1;
    printf("\n%d ", V);
    BFS(N, V);
}