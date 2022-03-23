from collections import deque

import sys
input = sys.stdin.readline

N, M, K = map(int,input().split())
feed = [list(map(int,input().split())) for _ in range(N)]
matrix = [[[5,deque()] for _ in range(N)] for __ in range(N)]
treemap = set()
for _ in range(M):
    x,y,age = map(int,input().split())
    matrix[x-1][y-1][1].append(age)
    treemap.add((x-1,y-1))

for _ in range(K):

    # spring
    temp = set()
    for x,y in treemap:
        delidx = len(matrix[x][y][1])
        for i,tree in enumerate(matrix[x][y][1]):
            if matrix[x][y][0] >= tree:
                matrix[x][y][0] -= tree
                matrix[x][y][1][i] += 1
            else:
                delidx = i
                break
        for _ in range(delidx, len(matrix[x][y][1])):
            # summer
            matrix[x][y][0] += matrix[x][y][1][-1] // 2
            matrix[x][y][1].pop()
        if len(matrix[x][y][1]) == 0:
            temp.add((x,y))
    treemap -= temp

    # fall
    temp = set()
    for x,y in treemap:
        for tree in matrix[x][y][1]:
            if tree % 5 == 0:
                for tx in range(x-1,x+2):
                    for ty in range(y-1,y+2):
                        if 0 <= tx < N and 0 <= ty < N and (tx != x or ty != y):
                            matrix[tx][ty][1].appendleft(1)
                            temp.add((tx,ty))
    treemap |= temp

    # winter
    for x in range(N):
        for y in range(N):
            matrix[x][y][0] += feed[x][y]

answer = 0
for x, y in treemap:
        answer += len(matrix[x][y][1])
print(answer)