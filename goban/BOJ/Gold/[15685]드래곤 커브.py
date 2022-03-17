import sys

#우상좌하
dx = [1,0,-1,0]
dy = [0,-1,0,1]

n = int(sys.stdin.readline())
command = [list(map(int,sys.stdin.readline().split())) for _ in range(n)]
board = [[False] * 101 for row in range(101)]

#make & allign curve
draPattern = [[] for _ in range(n)]
for i in range(n):
    x,y,d,g = command[i]
    draPattern[i].append(d)
    for _ in range(g):
        reverse_pattern = list(reversed(draPattern[i]))
        for k in reverse_pattern:
            if k + 1 == 4:
                draPattern[i].append(0)
            else:
                draPattern[i].append(k+1)

for i in range(n):
    x,y,d,g = command[i]
    board[y][x] = True
    for j in draPattern[i]:
        x,y = x + dx[j], y + dy[j]
        board[y][x] = True

ans = 0
for i in range(100):
    for j in range(100):
        if board[i][j] and board[i][j+1] and board[i+1][j] and board[i+1][j+1] :
            ans +=1
print(ans)