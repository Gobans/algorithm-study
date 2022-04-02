//∫£≥¶
//√‚√≥: https://blog.naver.com/hwasub1115/221183031039

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define MAX 1001
using namespace std;

bool visit[MAX];
vector<int> adj[MAX];
queue<int> Q;

void DFS(int x) {
	visit[x] = true;
	printf("%d ", x);
	for (int y : adj[x]) {
		if (!visit[y])
			DFS(y);
	}
}

void BFS(int x) {
	Q.push(x);
	visit[x] = true;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		printf("%d ", x);
		for (int y : adj[x]) {
			if (!visit[y]) {
				Q.push(y);
				visit[y] = true;
			}
		}
	}
}


int main(void) {
	int n, m, v;
	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; i++) {
		int s, e;
		scanf("%d %d", &s, &e);
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	for (int i = 1; i < n; i++) {
		sort(adj[i].begin(), adj[i].end());
	}

	DFS(v);
	puts("");
	memset(visit, 0, sizeof(visit));
	BFS(v);
	puts("");
}
