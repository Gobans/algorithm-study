def solution(m, n, puddles):
    answer = 0
    matrix = [[0] * (m + 1) for _ in range(n + 1)]
    matrix[1][1] = 1
    for y, x in puddles:
        matrix[x][y] = -1
    for i in range(1,n + 1):
        for j in range(1,m + 1):
            if matrix[i][j] == -1:
                matrix[i][j] = 0
            elif not i == j == 1 : 
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1]
    answer = matrix[n][m] % 1000000007
    return answer