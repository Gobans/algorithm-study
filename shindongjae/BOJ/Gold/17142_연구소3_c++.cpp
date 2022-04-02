# [shindongjae] 17142_연구소3

문제

```
n*n 배열에 빈칸, 벽, 바이러스를 입력받는다.
바이러스는 매 초마다 상하좌우로 1초에 한번 퍼진다. 벽으로는 퍼지지 못한다.
바이러스가 퍼지게 되는 최소 시간을 구해라.
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second

vector<pair<int, int>> initial_virus;

int field[51][51];
int visited[51][51];
int n, m;
int ans = 9999;
int blank = 0;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

//배열인덱스 넘어가지 않는지 확인
int bound(int i, int j)
{
	if (i >= 0 && i < n && j >= 0 && j < n)
		return 1;
	return 0;
}

//combination함수에서 찾은 조합들로 걸리는 시간 계산
void bfs(vector<int> vec)
{
	//배열 초기화
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = -1;

	int time = 0, cnt = 0;
	queue<pair<int, int>> q;
	//vec에서 받은 조합으로 활성화할 바이러스 queue에 push
	for (int i = 0; i < vec.size(); i++)
	{
		q.push({ initial_virus[vec[i]].X, initial_virus[vec[i]].Y });
		visited[initial_virus[vec[i]].X][initial_virus[vec[i]].Y] = 0;
	}

	//q가 빌때까지 bfs
	while (!q.empty())
	{
		int x = q.front().X;
		int y = q.front().Y;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!bound(nx, ny))
				continue;
			if (field[nx][ny] != 1 && visited[nx][ny] == -1)
			{
				visited[nx][ny] = visited[x][y] + 1;
				q.push({ nx,ny });
				//빈칸이었던 경우 시간, cnt업데이트
				if (field[nx][ny] == 0) {
					cnt++;
					time = visited[nx][ny];
				}
			}
		}
	}

	//bfs를 모두 돌았는데 빈칸이 모두 채워진 경우 ans업데이트
	if (blank == cnt) ans = min(ans, time);
}

//조합을 만드는 문제 nCm에 해당하는 조합들을 생성해서
//생성될때마다 bfs함수에 vec를 넣어서 바이러스 전파시간 계산.
void combination(int m, vector<int> vec, int current)
{
	if (vec.size() == m)
	{
		bfs(vec);
	}
	else
	{
		for (int i = current; i < initial_virus.size(); i++)
		{
			vec.push_back(i);
			combination(m, vec, i + 1);
			vec.pop_back();
		}
	}
}

int main()
{
	vector<int> vec;

	//각 칸을 입력받고 바이러스는 바이러스 리스트에 저장
	//빈칸의 개수도 저장
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> field[i][j];
			if (field[i][j] == 2)
				initial_virus.push_back(make_pair(i, j));
			if (field[i][j] == 0)
				blank++;
		}

	//만약에 모든 칸이 이미 바이러스면 flag를 이용해서 0출력하고 리턴
	int flag = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (field[i][j] == 0)
				flag = 1;
		}
	}
	if (!flag)
	{
		cout << 0;
		return 0;
	}

	//조합을 구하는 함수
	combination(m, vec, 0);

	//채우는 경우가 없어서 초기값 9999인경우 cout<<-1
	if (ans == 9999)
		cout << -1;
	else
		cout << ans;
}