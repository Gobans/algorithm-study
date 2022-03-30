#include <cstdio>
#include <queue> // BFS 구현을 위해 Queue사용
#include <vector> // 나올수 있는 combination의 정보를 담고, 바이러스의 좌표를 담기 위해 vector사용
#include <climits> // 좌표에 Cost를 담는데, 빈 칸의 Cost로 초기에 큰 값(INT_MAX)를 담기 위한 값
#include <cstring> // memcpy를 통해 원본 좌표에서 BFS를 돌릴 좌표 배열로 복사한다.
#include <algorithm> // 정답으로 출력할 값을 구하기 위해 min()을 쓴다.
#define NMAX 50 // 좌표 길이의 최댓값
#define MMAX 10 // 활성화 바이러스 갯수로 들어오는 M의 최댓값
#define CLENGTH 252 // 나올 수 있는 조합의 최댓값 => 10C5 (10: 바이러스 개수의 최댓값 5: 조합값이 최대로 나오는 M의 값)
using namespace std; 

int matrix[NMAX][NMAX]; //연구실 좌표
vector<vector<pair<int,int>>> combination; //조합 결과를 담을 Vector
vector<pair<int, int>> vcandidate; //바이러스 정보 (활성화 바이러스 후보)
vector<bool> check(MMAX, false); //해당 바이러스를 활성화 됐다고 처리했는 지

// 출력 함수(안쓰임) 
void printCombination();
void printMatrix(int matrix[], int size);
// 출력 함수 끝

void setCombination(const int M, const int fillNum, const int sIdx) // M:활성화 바이러스 갯수 // fillNum: 현재 check에 몇개 채웠는지 // sIdx: 채울때 몇번째 idx부터 채워야하는 지
{
	if (M == fillNum) //M까지 다 채웟을 때
	{
		vector<pair<int,int>> &newvec = *(new vector<pair<int,int>>); //좌표 정보를 담을 Vector 동적할당
		newvec.reserve(MMAX); //10만큼의 공간을 벡터에 할당
 
		for (int i = 0; i < vcandidate.size(); i++)
		{
			if (check[i] == true) //check Vector를 돌면서 선택된 바이러스이면
				newvec.push_back(vcandidate[i]); //동적할당한 Vector에 바이러스 정보 추가
		}
		combination.push_back(newvec); //만들어진 Vector를 Combination Vector에 추가
	}

	else
	{
		for (int i = sIdx; i < vcandidate.size(); i++) //현재위치에서 바이러스 벡터의 끝까지
		{
			if (check[i] == false) //현재 위치가 선택되지 않았다면
			{
				check[i] = true; //선택하고
				setCombination(M, fillNum + 1, i + 1); //나머지 바이러스를 선택
				check[i] = false; //초기화
			}
		}
	}
}

int main(void) {
	int N, M;
	int zeroNum; //입력 받은 좌표에서 빈칸(0)의 갯수 
	int answer; //정답 값 저장

	combination.reserve(CLENGTH); // combination Vector에 나올 수 있는 최대 크기 할당
	vcandidate.reserve(MMAX); // 바이러스 정보를 담을 Vector 크기를 10으로 할당

	zeroNum = 0;
	answer = INT_MAX;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
		{
			/*
			좌표 정보에 (0, 1, 2) 들어오는 것을 (INT_MAX, -1, -2)로 바꿈
			=> Cost정보를 저장하기 위함
			*/
			int temp;
			scanf("%d", &temp);
			if (temp == 1)
				matrix[i][j] = -1;
			else if (temp == 0)
			{
				zeroNum++; //0으로 값이 들어오면 0의 갯수 증가
				matrix[i][j] = INT_MAX;
			}
			else if (temp == 2)
			{
				vcandidate.push_back(make_pair(i, j)); //2로 값이 들어오면 바이러스 정보 벡터에 값 추가
				matrix[i][j] = -2;
			}
		}
	setCombination(M, 0, 0); //조합의 정보를 구해서 combination Vector에 입력

	for (vector<pair<int, int>> cVal : combination) //combination Vector에 들어있는 조합들을 차례로 꺼냄
	{
		int tMatrix[NMAX][NMAX]; //연구실좌표를 복사할 배열
		queue<pair<pair<int, int>, int>> q; //BFS를 돌리기 위한 Queue, Queue의 정보는 ((x좌표, y좌표),현재까지의비용) 으로 이루어짐
		int xarr[4] = { -1,1,0,0 }; // 상하좌우 좌표 (X)
		int yarr[4] = { 0,0,-1,1 }; // 상하좌우 좌표 (Y)
		int fillZero = 0; //BFS를 통해 빈좌표를 채운 개수
		int costMax = -1; //BFS를 통해 빈좌표를 채우는데 소요된 시간의 최댓값 (현재 조합 순서에서)

		memcpy(tMatrix, matrix, sizeof(int) * NMAX * NMAX); //연구실좌표 배열을 복사
		for (pair<int, int> pVal : cVal)
			q.push(make_pair(pVal, 0)); //조합에 있는 벡터의 원소(활성화 된 바이러스)들을 Queue에 담음

		while (!q.empty())  //BFS코드 (Queue가 비어있을 때까지 or 빈 좌표를 다 채웠을 때까지 반복)
		{
			int x, y, cost;

			x = q.front().first.first; //현재의 x좌표
			y = q.front().first.second; //현재의 y좌표
			cost = q.front().second; //현재까지의 비용
			q.pop(); 

			if (tMatrix[x][y] == -1 || (tMatrix[x][y] >= 0 && tMatrix[x][y] <= cost)) //현재 좌표가 벽 or 이미 다녀간 좌표면
				continue; 
			if (tMatrix[x][y] > 0) //현재 좌표가 빈 좌표면
				fillZero++; 
			tMatrix[x][y] = cost; //좌표에 비용 update
			
			if (fillZero == zeroNum) //빈좌표를 채운 것의 갯수가 처음 입력받은 빈 좌표의 갯수와 동일할 때(다 채웠을때)
			{
				costMax = cost; //현재까지의 비용이 가장 큰 비용
				break;
			}

			for(int i=0; i<4; i++) //상하 좌우의 좌표를 Queue에 추가
			{
				if (x + xarr[i] >= 0 && x + xarr[i] < N && y + yarr[i] >= 0 && y + yarr[i] < N) //좌표 경계를 넘어가는 값이 아니면 추가
				{
					q.push(make_pair(make_pair(x + xarr[i], y + yarr[i]), cost + 1));
				}
			}
		}
		if (costMax != -1) //costMax가 초기값에서 안바뀐 경우가 아니라면 (costMax가 초기값으로 남았음 =>빈 좌표를 다 못채우고 Queue가 빈 경우 ==> 즉, 채우지 못한 좌표가 있는경우)
			answer = min(answer, costMax); //빈 좌표를 다 채웠으므로 answer update
	}
	if (answer == INT_MAX) //answer가 update되지 않은경우 (조합에서 빈 좌표를 모두 채운 경우가 없을 때)
		printf("-1\n"); 
	else
		printf("%d\n", answer);
}

void printMatrix(int matrix[], int size) //연구실 좌표 출력 (연구실은 2차원좌표지만 실제 저장되는 크기를 Runtime때 알 수 있으므로 1차원 배열로 받아옴)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			printf("%d ", matrix[NMAX* i + j]);
		printf("\n");
	}
}

void printCombination() //조합 경우의 수 출력
{
	for (vector<pair<int, int>> temp : combination) 
	{
		for (pair<int, int> val : temp)
			printf("(%d, %d) ", val.first, val.second);
		printf("\n");
	}
}