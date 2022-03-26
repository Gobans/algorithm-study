from collections import deque

import sys
input = sys.stdin.readline

N, M, K = map(int,input().split())
feed = [list(map(int,input().split())) for _ in range(N)]
treemap = [[deque() for _ in range(N)] for __ in range(N)]
land = [[5] * N for _ in range(N)]

for _ in range(M):
    x,y,age = map(int,input().split())
    treemap[x-1][y-1].append(age)

for _ in range(K):

    # spring
    for x in range(N):
        for y in range(N):
            delidx = 0
            for i,tree in enumerate(treemap[x][y]):
                if land[x][y] >= tree:
                    land[x][y] -= tree
                    treemap[x][y][i] += 1
                    delidx += 1
                else:
                    break
            for _ in range(delidx, len(treemap[x][y])):
                # summer
                land[x][y] += treemap[x][y][-1] // 2
                treemap[x][y].pop()

    # fall
    for x in range(N):
        for y in range(N):
            for tree in treemap[x][y]:
                if tree % 5 == 0:
                    for tx in range(x-1,x+2):
                        for ty in range(y-1,y+2):
                            if 0 <= tx < N and 0 <= ty < N and (tx != x or ty != y):
                                treemap[tx][ty].appendleft(1)
            # winter
            land[x][y] += feed[x][y]

answer = 0
for x in range(N):
    for y in range(N):
        answer += len(treemap[x][y])
print(answer)