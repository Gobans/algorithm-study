### 깊이/너비 우선 탐색(DFS/BFS)-네트워크
___

- 시간복잡도: O(NlogN)

1.  queue를 활용한 BFS를 통해 0번 정점에서부터 네트워크를 구한다. 방문한 정점은 visit 배열을 만들어 관리한다.
2.  네트워크 순환을 마치면 visit배열에서 방문하지 않는 노드가 있는 지 확인한다. 있다면 첫번째 노드를 다시 queue에 넣고 새로운 네트워크를 찾는다
3.  1~2를 반복한다.


[링크](https://programmers.co.kr/learn/courses/30/lessons/43162?language=cpp)

