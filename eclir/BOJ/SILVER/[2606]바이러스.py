'''
{입력}

첫째 줄 : 컴퓨터의 수, 둘쨰 줄 : 직접 연결되어 있는 컴퓨터 쌍의 수
나머지 줄: (둘째 줄 수만큼) 한 쌍씩 직접 연결되어 있는 컴퓨터 번호


'''
import sys
input = sys.stdin.readline

total_node = int(input())
node_pairs = int(input())    
graph = [[] for _ in range(total_node + 1)] #딕셔너리 내부에 딕셔너리를 만듦
for _ in range(node_pairs):
    n, m = map(int, input().split())
    graph[n].append(m)
    graph[m].append(n)



'''
{dfs 함수(재귀) 정의}

먼저 visited 리스트를 써서 노드를 재방문하지 않도록 했다.

그리고 시작점(start_node)에서 한 번에 갈 수 있는 다른 노드들을 확인하는 for문을 돌렸다.
for문 안에서 if조건을 만족시 그 노드로 이동하고(dfs 호출)
호출한 dfs함수 안에서 다시 dfs함수를 호출하며. 갈 수 있는 끝까지 탐색한다.
탐색이 종료되면 상위의 for문이 돌아간다.

리턴값은 방문한 노드의 정보를 담고 있는 visited 리스트.
'''
def dfs(graph, start_node, visited):
    visited[start_node] = True
    
    for i in graph[start_node]:
        if not visited[i]:
            dfs(graph, i, visited)
    return visited



'''
{메인}

노드 방문 여부를 포함하는 리스트 visited를 초기화하고
dfs를 돌렸다.
dfs가 반환하는 visited 리스트에서 count함수로
방문 노드의 개수를 추출하였다.(단, 첫번째 시작 노드는 제외)
'''
visited = [False] * (total_node + 1)
print(dfs(graph, 1, visited).count(True) - 1)