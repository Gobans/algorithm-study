import sys
input = sys.stdin.readline

N, M, K = map(int,input().split())
feed = [list(map(int,input().split())) for _ in range(N)]
matrix = [[[5,[]] for _ in range(N)] for __ in range(N)]

for _ in range(M):
    x,y,age = map(int,input().split())
    matrix[x-1][y-1][1].append(age)

for x in range(N):
    for y in range(N):
        matrix[x][y][1].sort()

for _ in range(K):
    # spring
    for x in range(N):
        for y in range(N):
            todel = []
            for i,tree in enumerate(matrix[x][y][1]):
                if matrix[x][y][0] >= tree:
                    matrix[x][y][0] -= tree
                    matrix[x][y][1][i] += 1
                else:
                    todel.append(i)
            for td in todel[::-1]:
                # summer
                matrix[x][y][0] += matrix[x][y][1][td] // 2
                del matrix[x][y][1][td]
            matrix[x][y][1].sort()
    # fall
    for x in range(N):
        for y in range(N):
            for tree in matrix[x][y][1]:
                if tree % 5 == 0:
                    for tx in range(x-1,x+2):
                        for ty in range(y-1,y+2):
                            if 0 <= tx < N and 0 <= ty < N and (tx != x or ty != y):
                                matrix[tx][ty][1].insert(0,1)
            # winter
            matrix[x][y][0] += feed[x][y]

answer = 0
for x in range(N):
    for y in range(N):
        answer += len(matrix[x][y][1])
print(answer)