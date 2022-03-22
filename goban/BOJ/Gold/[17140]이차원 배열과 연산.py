import sys
from collections import defaultdict
r,c,k = map(int,sys.stdin.readline().split())
A = []
for _ in range(3):
    A.append(list(map(int,sys.stdin.readline().split())))
print(A)
#r,c 하나씩 줄여야함 (인덱싱 1 부터 시작이라)
#정렬: 등장횟수가 커지는 순 -> 등장횟수 같으면 큰 수
#R연산: 모든 행
#C연산: 모든 열
time = 0
while(time):
    row_len = len(A[0])
    col_len = len(A)
    
    #R연산 & C연산
    if row_len >= col_len:
        #R연산
        for i in range(row_len):
            #배열 정렬 후 다시 넣기
            dic = {}
            for j in range(col_len):
                if A[i][j] == 0:
                    break
                elif dic[A[i][j]]:
                    dic[A[i][j]] += 1
                else:
                    dic[A[i][j]] = 0
            #딕셔너리 정렬
            #배열 다시 넣기
    else:
        pass
        #C연산


    if (time == 100):
        break
    time -=1