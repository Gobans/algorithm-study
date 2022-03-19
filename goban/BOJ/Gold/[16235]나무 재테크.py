#인접한 칸
adjx = [-1,-1,-1,0,0,1,1,1]
adjy = [-1,0,1,-1,1,-1,0,1]

import sys
from collections import deque
n,m,k = map(int, sys.stdin.readline().split())
A = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
tree_info = [list(map(int,sys.stdin.readline().split())) for _ in range(m)]
