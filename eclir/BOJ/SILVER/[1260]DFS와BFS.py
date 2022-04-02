'''
{입력}

첫째 줄: 정점의 개수, 간선의 개수, 시작 정점 번호
나머지 : 간선이 연결하는 두 정점의 번호

input값으로 그래프를 만든 뒤 오름차순으로 정렬해주었다.(위의 규칙 참고)
'''
import sys
input = sys.stdin.readline

total_node, node_pairs, start_node = map(int, input().split())
graph = [[] for _ in range(total_node + 1)] #딕셔너리 내부에 딕셔너리를 만듦.
for _ in range(node_pairs):
    n, m = map(int, input().split())
    graph[n].append(m)
    graph[m].append(n)
    graph[n].sort()
    graph[m].sort()



'''
{dfs와 bfs 함수 정의}

두 함수에서 공통적으로 visited 리스트를 써서 노드를 재방문하지 않도록 했다.

1. dfs
재귀로 구현하였다.
시작점(start_node)에서 한 번에 갈 수 있는 다른 노드들을 확인하는 for문을 돌렸다.
for문 안에서 if조건을 만족시 그 노드로 이동하고(dfs 호출)
호출한 dfs함수 안에서 다시 dfs함수를 호출하며. 갈 수 있는 끝까지 탐색한다.
탐색이 종료되면 상위의 for문이 돌아간다.

2. bfs
시작점(start_node)에서 한 번에 갈 수 있는 다른 노드들을 확인하는 for문을 돌린다.
이때 이 경로가 queue에 다 쌓이면 for문이 종료된다.(이동하지 x)
그리고 queue 가장 아래에 쌓인 값으로 기준점이 이동하여 for문이 돌아가고
그곳에서의 경로를 탐색한다. 이 값들도 queue에 쌓인다.
이 과정이 반복된다.
'''
def dfs(graph, start_node, visited):
    visited[start_node] = True
    print(start_node, end = ' ') #방문한 노드 출력
    
    for i in graph[start_node]:
        if not visited[i]:
            dfs(graph, i, visited)


from collections import deque

def bfs(graph, start_node):
    visited[start_node] = True
    queue = deque([start_node])

    while queue:
        node = queue.popleft() #가장 아래에 있는 값 빼내기
        print(node, end = ' ')
        for i in graph[node]:
            if not visited[i]:
                queue.append(i) #queue에 값 넣기
                visited[i] = True



'''
{메인}

노드 방문 여부를 포함하는 리스트 visited를 초기화하고
dfs와 bfs를 돌렸다.
'''
visited = [False] * (total_node + 1) #노드 개수가 8개라면 8번칸까지 필요하므로  0~8 즉, 9칸을 만듦.
dfs(graph, start_node, visited)
print()
visited = [False] * (total_node + 1) #visited 리스트 다시 초기화
bfs(graph, start_node)