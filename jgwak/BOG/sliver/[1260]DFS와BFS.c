#include <stdio.h>

int Graph[1001][1001];
int Dvisit[1001];
int Bvisit[1001];
int queue[1001];

void DFS(int start, int node)
{
    int i;

    Dvisit[start] = 1;
    printf("%d ",start);
    for(i = 1; i<= node; i++)
    {
        if(Graph[start][i] == 1 && Dvisit[i] == 0)
        {
            DFS(i,node);
        }
    }
    return ;
}

void BFS(int start, int node)
{
    int front = 0;
    int rear = 0;
    int pop;
    int i;

    printf("%d ",start);
    queue[0] = start;
    rear++;
    Bvisit[start] = 1;

    while (front < rear)
    {
        pop = queue[front];
        front++;

        for(i = 1; i<=node; i++)
        {
            if (Graph[pop][i] == 1 && Bvisit[i] == 0)
            {
                printf("%d ", i);
                queue[rear] = i;
                rear++;
                Bvisit[i] = 1;
            }
        }
    }
    return ;
}

int main(void)
{
    int x,y;
    int node,line,start;
    scanf("%d %d %d", &node, &line, &start);

    for(int i = 0; i < line; i++)
    {
        scanf("%d %d", &x, &y);
        Graph[x][y] = 1;
        Graph[y][x] = 1;
    }

    DFS(start,node);
    printf("\n");
    BFS(start,node);

    return 0;
}
