import sys
input = sys.stdin.readline
M = int(input())
matrix = list(map(int,input().split()))
N = int(input())
case = [list(map(int,input().split())) for _ in range(N)]
dp = [[0]*M for _ in range(M)]


for i in range(M):
    for j in range(0,M-i):
        if i == 0:
            dp[j][j+i] = 1
        else:
            if matrix[j] == matrix[j+i]:
                if i == 1:
                    dp[j][j+i] = 1
                else:
                    dp[j][j+i] = dp[j+1][j+i-1]
# print(case)
# print(dp)
for i in range(N):
    print(dp[case[i][0] - 1][case[i][1] - 1])


