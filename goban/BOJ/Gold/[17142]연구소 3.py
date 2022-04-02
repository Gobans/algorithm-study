#상하좌우
dr = [-1,1,0,0]
dc = [0,0,-1,1]

import sys
from itertools import combinations
import copy
from collections import deque
N,M = map(int,sys.stdin.readline().split())
lab = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]
virus_position = []
for r in range(N):
    for c in range(N):
        if lab[r][c] == 2:
            virus_position.append((r,c))

virus_comb = list(combinations(virus_position,M))
time_line = [ -1 for _ in range(len(virus_comb))]

def check_lab(lab_copy):
    for i in range(N):
        for j in range(N):
            if lab_copy[i][j] == 0:
                return -1
    return 1

for k in range(len(virus_comb)):
    visited = [[0 for _ in range(N)] for _ in range(N)]
    lab_copy = copy.deepcopy(lab)
    setted_virus_position = deque()
    for z in virus_comb[k]:
        r,c = z
        setted_virus_position.append((r,c,0))
    #바이러스 채우기 시작
    time = 0
    while setted_virus_position:
        r,c,cnt = setted_virus_position.popleft()
        lab_copy[r][c] = 3
        for direction in range(4):
            y,x = r + dr[direction], c + dc[direction]
            if 0<= y < N and 0<= x < N and not visited[y][x] and lab_copy[y][x] != 1:
                visited[y][x] = 1
                if lab_copy[y][x] == 0:
                    lab_copy[y][x] = 2
                    time = cnt + 1
                setted_virus_position.append((y,x,cnt+1))
    if check_lab(lab_copy) == 1:
        time_line[k] = time
ans = -1
for i in time_line:
    if i != -1 and (ans >= i or ans == -1):
        ans = i
print(ans)
#파이썬 시간초과 pypy3 통과ㅜ