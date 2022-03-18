def solution(begin, target, words):
    answer = 100
    sindexs = []
    eindex = -1
    for i,word in enumerate(words):
        bdiff = getdiff(begin,word)
        if bdiff <= 1:
            sindexs.append((i,bdiff))
        if getdiff(target,word) == 0:
            eindex = i
    if len(sindexs) == 0 or eindex == -1:
        return 0
    
    path = getPath(words)
    cost = getCost(len(words),path)
    for sindex, bdiff in sindexs:
        answer = min(answer,cost[sindex][eindex]+bdiff)
    if answer >= 100:
        answer = 0
    return answer

def getPath(words):
    rt = [[] for i in range(len(words))]
    for i in range(len(words)):
        for j in range(i+1,len(words)):
            if getdiff(words[i],words[j]) == 1:
                rt[i].append(j)
                rt[j].append(i)
    return rt
                
            
def getdiff(s1, s2):
    return  sum([1 for a1,a2 in zip(s1,s2) if a1!=a2])

def getCost(length,path):
    rt = [[100] * length for _ in range(length)] # 100 : intMAX
    for (i,plist) in enumerate(path):
        for j in plist:
            rt[i][j] = 1
    for k in range(length):
        for i in range(length):
            if k == i:
                continue
            for j in range(length):
                if k== j or i ==j:
                    continue
                rt[i][j] = min(rt[i][j],rt[i][k]+rt[k][j])
    return rt