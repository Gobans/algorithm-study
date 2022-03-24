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
is_ans = False
while(time < 100):
    row_len = len(A[0])
    col_len = len(A)
    max_len = 0
    if row_len >= c - 1 and col_len >= r - 1:
        if A[r-1][c-1] == k:
            is_ans == True
            break

    #R연산 & C연산
    if row_len <= col_len and row_len < 100:
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
            sorted_list = sorted(dic.items())
            #배열 다시 넣기
            A[i].clear()
            for num1,num2 in sorted_list:
                A[i].append(num1)
                A[i].append(num2)
            if len(A[i]) > max_len:
                max_len = len(A[i])
        # 0채워주기
        for k in range(col_len):
            while(len(A[k]) < max_len):
                A[k].append(0)
    elif col_len < 100:
        for j in range(row_len):
            dic = {}
            for i in range(row_len):
                if A[i][j] == 0:
                    break
                elif dic[A[i][j]]:
                    dic[A[i][j]] += 1
                else:
                    dic[A[i][j]] = 0
            #딕셔너리 정렬
            sorted_list = sorted(dic.items())
            #배열 다시 넣기
            if j == 0:
                for num1,num2 in sorted_list:
                    A.append([num1])
                    A.append([num2])
            else:
                term = 0
                for num1,num2 in sorted_list:
                    A[col_len + term].append(num1)
                    A[col_len + term +1].append(num2)
                    term +=2
    
        # 0 채워주기
        for k in range(col_len, len(A)):
            while(len(A[k]) < row_len):
                A[k].append(0)

    time +=1
    if (time == 100):
        if len(A[0]) >= c - 1 and len(A) >= r - 1:
            if A[r-1][c-1] == k:
                is_ans == True
                break
        break

if is_ans:
    print(time)
else:
    print(-1)