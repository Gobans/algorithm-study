#include <stdio.h>

int DFSvisit[1001];
int pair[1001][1001];

int BFSvisit[1001];
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

    printf("%d", k);
    queue[0] = k;
    BFSvisit[k] = 1;

    while (front < rear)
    {
        Pop = queue[front]; //front에 있는 정점을 저장하고
        front++;            //front 인덱스를 뒤로 보낸다. =dequeue

        for (int i = 1; i <= n; i++)
        { //front에 있는 정점과 인접하지만 방문하지 않은 정점이 있으면
            if (pair[Pop][i] == 1 && BFSvisit[i] == 0)
            {
                queue[rear] = i; //rear에
                printf("%d", i); //그 정점 출력
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
    //DFS
    DFSvisit[V] = 1;
    printf("%d ", V);
    DFS(N, V);
    BFS(N, V);
}