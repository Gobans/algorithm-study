# r,c 는 1부터 시작.
# 양분은 5 부터 시작.
# m : 나무의 갯수.
# 같은칸에 여러개 나무 심기 가능
# -------봄----------  
# 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. 
# 각각의 나무는 나무가 있는 1×1 크기의 칸에 있는 양분만 먹을 수 있다. 
# 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다. 
# 만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.
# ------여름----------
# 봄에 죽은 나무가 양분으로 변하게 된다. 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는 버린다.
# ------가울----------
#나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8개의 칸에 나이가 1인 나무가 생긴다. 
# 어떤 칸 (r, c)와 인접한 칸은 (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1)
# 상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다.
#-------겨울---------
#S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다. 각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다.
# k년이 지난 후 살아있는 나무의 개수를 구하라

#인접한 칸
adjx = [-1,-1,-1,0,0,1,1,1]
adjy = [-1,0,1,-1,1,-1,0,1]

import sys
from collections import deque
n,m,k = map(int, sys.stdin.readline().split())
A = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
tree_info = [list(map(int,sys.stdin.readline().split())) for _ in range(m)]
food = [[5 for _ in range(n)] for col in range(n)]
tree_dead = []
tree_info = deque(sorted(tree_info,key= lambda x : x[2], reverse=True))

for i in range(k):
    #봄
    for j in range(len(tree_info)):
        x,y,z = tree_info.pop()
        if food[x-1][y-1] >= z:
            food[x-1][y-1] -= z
            tree_info.appendleft((x,y,z+1))
        else:
            tree_dead.append((x,y,z))
    #여름
    while(tree_dead):
        x,y,z = tree_dead.pop()
        food[x-1][y-1] += z // 2
    #가을
    if tree_info:
        t_len = len(tree_info)
        for s in range(t_len):
            x,y,z = tree_info[s]
            if z % 5 == 0:
                for idx in range(8):
                    mx,my = x + adjx[idx], y + adjy[idx]
                    if 0 <= mx -1 < n and 0 <= my -1 < n:
                        tree_info.append((mx,my,1))
            elif z < 5:
                break
    #겨울
    if i == k-1:
        break
    for row in range(n):
        for col in range(n):
            food[row][col] += A[row][col]
print(len(tree_info))
#시간초과.. 다른 방법을 강구해야한다.