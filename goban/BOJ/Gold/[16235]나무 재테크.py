#인접한 칸
adjx = [-1,-1,-1,0,0,1,1,1]
adjy = [-1,0,1,-1,1,-1,0,1]

import sys
from collections import deque
n,m,k = map(int, sys.stdin.readline().split())
A = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
tree_info = [[deque() for _ in range(n)] for _ in range(n)]
for _ in range(m):
    r, c, age = map(int, sys.stdin.readline().split())
    tree_info[r - 1][c - 1].append(age)
food = [[5 for _ in range(n)] for col in range(n)]

# k년 반복
for _ in range(k):
    #봄 여름
    for r in range(n):
        for c in range(n):
            trees = deque()
            dead_tree = 0
            for age in tree_info[r][c]:
                if food[r][c] >= age:
                    food[r][c] -= age
                    trees.append(age + 1)
                else:
                    dead_tree += age//2
            food[r][c] += dead_tree
            tree_info[r][c] = trees
    #가을 겨울
    tmp_trees = []
    for r in range(n):
        for c in range(n):
            for age in tree_info[r][c]:
                if age % 5 == 0:
                    for idx in range(8):
                        mx,my = r + adjx[idx], c + adjy[idx]
                        if 0 <= mx < n and 0 <= my < n:
                            tmp_trees.append((mx,my))
            food[r][c] += A[r][c]

    for tree in tmp_trees:
        r,c = tree
        tree_info[r][c].appendleft(1)

trees_len = 0
for r in range(n):
    for c in range(n):
        trees_len += len(tree_info[r][c])
print(trees_len)

# 입력으로 주어지는 나무의 위치가 모두 서로 다르기 때문에 이 방식으로는 처음에 정렬을 해줄 필요가 없다.
