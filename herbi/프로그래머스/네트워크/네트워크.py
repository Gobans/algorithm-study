from collections import deque
def solution(n, computers):
    answer = 0
    visit = [0] * n
    for i in range(n):
        if visit[i] == 1:
            continue
        answer += 1
        q = deque()
        q.append(i)
        while len(q) > 0:
            now = q[0]
            q.popleft()
            if visit[now] == 1:
                continue
            visit[now] = 1
            for i in range(n):
                if now != i and computers[now][i] == 1:
                    q.append(i)       
    return answer