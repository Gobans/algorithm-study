#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int	stored_food[10][10];
int	food[10][10];
vector<int> tree[10][10];


//양분을 먹고 부족하면 죽고나서 양분으로 추가된다.
void spring_summer(int N) 
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			int die = 0;
			int tmp_food = 0;
			for (int k = 0; k < tree[i][j].size(); k++)
			{
				if (tree[i][j][k] <= stored_food[i][j])//양분이 충분하면
				{
					stored_food[i][j] -= tree[i][j][k]; //나이만큼 양분을 먹고
					tree[i][j][k]++; //나이가 1증가.
				}
				else //양분이 부족하면
				{
					die++;  //죽은나무개수 추가
					tmp_food += tree[i][j][k] / 2; // 추가해줄 양분 계산
				}
			}
			while (die--)
				tree[i][j].pop_back(); //죽은나무 제거
			stored_food[i][j] += tmp_food; //양분 추가
		}
}

//나무의 나이가 5의 배수라면 인접한 8칸에 나이가 1인 나무가 생긴다.
void fall_winter(int N) 
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < tree[i][j].size(); k++)
			{
				if (tree[i][j][k] % 5 == 0 && tree[i][j][k] != 0)//나이가 5의 배수라면
				{
					if (i - 1 >= 0 && j - 1 >= 0)
						tree[i - 1][j - 1].push_back(1);
					if (i - 1 >= 0)
						tree[i - 1][j].push_back(1);
					if (i - 1 >= 0 && j + 1 < N)
						tree[i - 1][j + 1].push_back(1);
					if (j - 1 >= 0)
						tree[i][j - 1].push_back(1);
					if (j + 1 < N)
						tree[i][j + 1].push_back(1);
					if (i + 1 < N && j - 1 >= 0)
						tree[i + 1][j - 1].push_back(1);
					if (i + 1 < N)
						tree[i + 1][j].push_back(1);
					if (i + 1 < N && j + 1 < N)
						tree[i + 1][j + 1].push_back(1);
				}
			}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			if (tree[i][j].size() != 0)
				sort(tree[i][j].begin(), tree[i][j].end()); //어린나무가 앞에 오도록 정렬. 여기까지 가을
			stored_food[i][j] += food[i][j];//땅에 양분을 추가(겨울)
		}
}

int main()
{
	int N, M, K;
	int x, y, z;
	int ans = 0;

	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> food[i][j];
			stored_food[i][j] = 5;
		}

	for (int i = 0; i < M; i++)
	{
		cin >> x >> y >> z;
		tree[x - 1][y - 1].push_back(z);
	}
	
	for (int i = 0; i < K; i++)
	{
		spring_summer(N);
		fall_winter(N);
	}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			ans += tree[i][j].size();
	
	cout << ans;
}