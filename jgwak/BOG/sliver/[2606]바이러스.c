#include <stdio.h>

int visit[101];
int virus[101][101];
int result = 0;

void dfs(int start, int n) //DFS 함수
{
    visit[start] = 1; //처음 시작하는 정점에 방문표시
    result++;
    int i;

    for(i = 1; i <= n; i++)
    {
        if(virus[start][i] == 1 && visit[i] == 0) //인접한 곳이 방문된 곳이고
        // 방문한 적이 없다면 다시 DFS함수로 넣기
        {
            dfs(i,n);
        }
    }

    return ;
}

int main(void)
{
    int a,b,x,y;
    scanf("%d", &a);
    scanf("%d", &b);

    while (b--)
    {
        scanf("%d %d",&x, &y);

        virus[x][y] = 1;
        virus[y][x] = 1;
    }

    dfs(1, a);
    printf("%d", result-1);
}
