def solution(m, n, puddles):
    answer = 0
    matrix = [[0] * m for _ in range(n)]
    for i in range(n):
        if [i +1, 0] in puddles:
            break
        matrix[i][0] = 1
    for i in range(m):
        if [0, i+1] in puddles:
            break
        matrix[0][i] = 1
        
    for i in range(1,n):
        for j in range(1,m):
            if [i+1, j+1] in puddles:
                continue
            matrix[i][j] = matrix[i-1][j] + matrix[i][j-1]
    answer = matrix[n-1][m-1]
    return answer