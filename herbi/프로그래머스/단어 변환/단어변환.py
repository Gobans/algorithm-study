from collections import deque
def solution(begin, target, words):
    answer = 0
    words.append(begin)
    if target not in words:
        return 0
    wdict = {word: i for i, word in enumerate(words)}
    path = [[] for _ in range(len(words))]
    for i in range(len(words) - 1):
        for j in range(i+1, len(words)):
            w1, w2 = words[i], words[j]
            diff = 0
            for a, b in zip(w1, w2):
                if a != b:
                    diff += 1
            if diff == 1:
                path[i].append(j)
                path[j].append(i)
    
    q = deque()
    cost = [987654321] * len(words)
    q.append((0, wdict[begin]))
    while len(q) > 0:
        ccost, cwidx = q[0]
        q.popleft()
        if cost[cwidx] < 987654321:
            continue
        cost[cwidx] = ccost
        for nwidx in path[cwidx]:
            q.append((ccost + 1, nwidx))
            
    if cost[wdict[target]] == 987654321:
        answer = 0
    else:
        answer = cost[wdict[target]]
    return answer