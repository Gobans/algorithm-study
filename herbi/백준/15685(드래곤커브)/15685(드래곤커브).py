N = int(input())
valid = set()
answer = 0
for _ in range(N):
    sx, sy, ex, ey = 0, 0, 0, 0
    dragon = set()
    sy, sx, direction, gen = map(int,input().split())
    ex, ey = sx, sy
    if direction == 0:
        ey += 1
    elif direction == 1:
        ex -= 1
    elif direction == 2:
        ey -= 1
    elif direction == 3:
        ex += 1
    dragon.add((sx, sy))

    for _ in range(gen):
        temp = set()
        for x, y in dragon:
            temp.add((ex + (y - ey), ey - (x - ex)))
        temp.add((ex, ey))
        dragon |= temp
        ex, ey = ex + (sy - ey), ey - (sx - ex)
    if gen == 0:
        dragon.add((ex, ey))
    valid |= dragon

for i in range(100):
    for j in range(100):
        if (i,j) in valid and (i + 1, j) in valid and (i, j + 1) in valid and (i + 1, j + 1) in valid:
            answer += 1
print(answer)

