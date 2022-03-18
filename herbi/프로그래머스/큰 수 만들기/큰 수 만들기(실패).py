from collections import deque
def solution(number, k):
    answer = ''
    q = deque()
    select = len(number) - k
    for a in number[::-1]:
        q.appendleft(a)
        if len(q) <= select:
            continue
        else:
            for (i,val) in enumerate(q):
                if i == len(q) - 1:
                    q.pop()
                    break
                elif val < q[i+1]:
                    q.remove(val)
                    break
                    
    answer = ''.join(q) 
    return answer