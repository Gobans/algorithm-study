### 깊이/너비 우선 탐색 - 단어 변환
___

[링크]:(https://programmers.co.kr/learn/courses/30/lessons/43163#)

시간복잡도 : O(N * M)

1. begin단어를 words문자열배열에 넣는다.
2. 연결되는 단어들을 저장하기위해 크기가 단어의 길이인 path배열을 선언후 words에 있는 모든 문자열에 대해 두 문자열간 알파벳 차이가 1인경우 각 path배열 idx에 상대 idx를 추가한다.
3. 이러면 각 단어가 정점이 되고, path가 간선이 되는 그래프가 만들어진다.
4. 이후 다익스트라 알고리즘으로 시작정점에서 끝 정점까지의 거리를 구한다.
5. 결과값을 반환한다.


___
참고


___
## 이전 버전
1. words안에서 begin이 될 수 있는 word(차이가 0 또는 1)의 index, target의 index을 찾음

2. 플로이드-와셜 알고리즘으로 words 각 element들의 거리를 구함

3. begin이 될 수 있는 index 들과 target index간의 최단거리의 최솟값을 구함

4. 해당 값을 반환함

5. begin이나 target이 될 수 있는 값이 words안에 없거나, words안에서 begin과 target의 index 간의 경로가 존재하지 않는 경우 0을 반환함


