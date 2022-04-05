#include <stdio.h>

#define MSIZE 2001 //수열의 최대크기인 2000에 1을 더한 값

int input[MSIZE] = { 0 }; //수열
int matrix[MSIZE][MSIZE] = { 0 }; //수열의 모든 부분수열 (S,E)쌍에데해 팰린드롬인지 아닌지 저장할 값 (0:팰린드롬 -1: X)

int main(void)
{
	int N; //수열의 크기
	int M; //검사할 갯수

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)scanf("%d", &input[i]); //수열 값 설정
	scanf("%d", &M);
	
	for (int i = 0; i < N; i++) { //설정할 matrix에서 E - S
		for (int j = 1; i + j<= N; j++) //설정할 matrix에서 S의 값
		{
			if (matrix[j + 1][i + j - 1] == 0 && input[j] == input[i + j]) // matrix에서 (x+1, y-1)의 값이 0(팰린드롬)이고, 수열[x] 와 수열[y]값이 같으면
				matrix[j][i + j] = 0; //해당 값은 팰린드롬
			else
				matrix[j][i + j] = -1; //해당 값은 팰린드롬 X
		}
	}

	for (int i = 0; i < M; i++)
	{
		int s, e; //(S, E) 쌍
		scanf("%d %d", &s, &e);
		printf("%d\n", matrix[s][e] == 0); //팰린드롬이면 1출력, 아니면 0출력
	}
}