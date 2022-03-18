def solution(m, n, puddles):
    answer = 0
    matrix = [[0] * m for _ in range(n)]
    matrix[0][0] = 1
    for y, x in puddles:
        matrix[x - 1][y - 1] = None
    for i in range(n):
        for j in range(m):
            if i == 0 and j == 0:
                continue 
            if matrix[i][j] == None:
                matrix[i][j] = 0
                continue
            if i == 0:
                matrix[i][j] = matrix[i][j - 1]
            elif j == 0:
                matrix[i][j] = matrix[i - 1][j]
            else:
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1]
    print(matrix)
    answer = matrix[n-1][m-1] % 1000000007
    return answer 