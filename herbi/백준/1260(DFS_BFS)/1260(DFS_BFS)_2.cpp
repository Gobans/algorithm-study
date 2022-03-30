#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;
int N, V;
bool visit[MAX];
vector<int> matrix[MAX];
int rt[MAX];
int rtindex = 0;
void DFS(int x) {
	if (visit[x] == true)
		return;
	rt[rtindex++] = x;
	visit[x] = true;

	for (int i = 0; i < matrix[x].size(); i++) {
		DFS(matrix[x][i]);
	}
}
void BFS(int x) {
	queue<int>que;
	que.push(x);
	while (!que.empty()) {
		int cur = que.front();
		que.pop();
		if (visit[cur] == true)
			continue;
		visit[cur] = true;
		rt[rtindex++] = cur;
		for (int i = 0; i < matrix[cur].size(); i++) {
			que.push(matrix[cur][i]);
		}
	}
}
void printRT() {
	for (int i = 0; i < rtindex; i++)
		printf("%d ", rt[i]);
	printf("\n");
}
int main(void) {
	int M;
	int a, b;
	scanf("%d %d %d", &N, &M, &V);

	memset(visit, 0, MAX);
	
	for (int i = 0; i < M; i++)
	{
		scanf("%d %d", &a, &b);
		matrix[a].push_back(b);
		matrix[b].push_back(a);
	}
	
	for (int i = 1; i <= N; i++) {
		sort(matrix[i].begin(), matrix[i].end());
	}


	rtindex = 0;
	DFS(V);
	printRT();

	memset(visit, 0, MAX);
	rtindex = 0;
	BFS(V);
	printRT();
}