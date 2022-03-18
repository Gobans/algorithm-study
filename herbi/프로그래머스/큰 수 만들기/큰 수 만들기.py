from collections import deque


def solution(number, k):
    answer = ''
    q = deque()
    select = len(number) - k
    for (i,a) in enumerate(number[::-1]):
        if len(q) == 0 or q[0][0] != a:
            q.appendleft([a,1])
        else:
            q[0][1] += 1
            
        if i < select:
            continue
        else:
            for (j,(val, num)) in enumerate(q):
                if j == len(q) - 1:
                    if q[j][1] == 1:
                        q.pop()
                    else:
                        q[j][1] -= 1
                    break
                elif val < q[j+1][0]:
                    if q[j][1] == 1:
                        q.remove(q[j])
                    else:
                        q[j][1] -= 1
                    break
                    
    answer = ''.join([a * num for a,num in q])
    return answer