#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define COM 101
using namespace std;
bool visit[COM];
vector<int> c[COM];
int ct = -1;

void DFS(int x) {
	if (visit[x] == true)
		return;
	ct += 1;
	visit[x] = true;

	for (int y : c[x]) {
		DFS(y);
	}
}



int main(void) {
	int M, N = 0;
	scanf("%d", &M);
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		c[a].push_back(b);
		c[b].push_back(a);
	}
	DFS(1);
	printf("%d\n", ct);
}