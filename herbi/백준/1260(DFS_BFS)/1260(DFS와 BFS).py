from collections import deque


def dfs(V, Edge, check):
    dq = deque()
    dq.append(V)

    while len(dq) > 0:
        cur = dq[-1]
        dq.pop()
        if check[cur] == 1:
            continue
        print(cur, end=" ")
        check[cur] = 1
        for nidx in Edge[cur][::-1]:
            dq.append(nidx)


def bfs(V, Edge, check):
    dq = deque()
    dq.append(V)

    while len(dq) > 0:
        cur = dq[0]
        dq.popleft()

        if check[cur] == 1:
            continue
        print(cur, end=" ")
        check[cur] = 1
        for nidx in Edge[cur]:
            dq.append(nidx)


N, M, V = map(int, input().split())
Edge = [[] for _ in range(N + 1)]
for _ in range(M):
    s, e = map(int, input().split())
    Edge[s].append(e)
    Edge[e].append(s)

for i in range(N + 1):
    Edge[i].sort()

check = [0] * (N + 1)
dfs(V, Edge, check)
print("")
check = [0] * (N + 1)
bfs(V, Edge, check)
