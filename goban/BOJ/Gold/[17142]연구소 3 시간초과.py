#상하좌우
dr = [-1,1,0,0]
dc = [0,0,-1,1]

import sys
from itertools import combinations
import copy
N,M = map(int,sys.stdin.readline().split())
lab = [list(map(int,sys.stdin.readline().split())) for _ in range(N)]
virus_position = []
for r in range(N):
    for c in range(N):
        if lab[r][c] == 2:
            virus_position.append((r,c))

virus_comb = list(combinations(virus_position,M))
time_line = [ -1 for _ in range(len(virus_comb))]
for k in range(len(virus_comb)):
    lab_copy = copy.deepcopy(lab)
    setted_virus_position = []
    for z in virus_comb[k]:
        setted_virus_position.append(z)
    #바이러스 채우기 시작
    time = 0
    is_full = False
    while(is_full == False):
        tmp_list = []
        for r,c in setted_virus_position:
            #tmp_list 가 공백인데 lab에 0이 존재할경우 채울 수 없는 것
            lab_copy[r][c] = 3
            for direction in range(4):
                y,x = r + dr[direction], c + dc[direction]
                if 0<= y < N and 0<= x < N and (lab_copy[y][x] == 0 or lab_copy[y][x] == 2):
                    tmp_list.append((y,x))
        is_full = True
        for i in range(N):
            for j in range(N):
                if lab_copy[i][j] == 0:
                    is_full = False
                    break
            if is_full == False:
                break
        if is_full == False and len(tmp_list) == 0:
            break
        if is_full:
            time_line[k] = time
            break
        setted_virus_position = tmp_list
        time +=1
ans = -1
for i in time_line:
    if i != -1 and (ans >= i or ans == -1):
        ans = i
print(ans)
#답은 나오는데 시간초과