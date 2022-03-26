from collections import deque

def solution(maps):
    answer = -1
    rown = len(maps)
    coln = len(maps[0])
    queue = deque()
    queue.append((1,(0,0)))
    while len(queue) > 0:
        cost , (x,y) = queue.popleft()
        print(x,y, cost)
        if maps[x][y] == 0:
            continue
        if x == rown - 1 and y == coln - 1 and maps[x][y] == 1:
            answer = cost
            break
        maps[x][y] = 0
        if x > 0 and maps[x - 1][y] == 1:
            queue.append((cost + 1, (x - 1, y)))
        if y > 0 and maps[x][y - 1] == 1:
            queue.append((cost + 1, (x, y - 1)))
        if x < rown - 1 and maps[x + 1][y] == 1:
            queue.append((cost + 1, (x + 1, y)))
        if y < coln - 1 and maps[x][y + 1] == 1:
            queue.append((cost + 1, (x, y + 1)))
    return answer