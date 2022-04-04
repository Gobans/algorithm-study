import sys
r,c,k = map(int,sys.stdin.readline().split())
A = []
for _ in range(3):
    A.append(list(map(int,sys.stdin.readline().split())))

#r,c 하나씩 줄여야함 (인덱싱 1 부터 시작이라)
#정렬: 등장횟수가 커지는 순 -> 등장횟수 같으면 큰 수
#R연산: 모든 행
#C연산: 모든 열
print(A)
time = 0
is_ans = False
while(time < 100):
    row_len = len(A[0])
    col_len = len(A)
    max_len = 0

    if row_len > c - 1 and col_len > r - 1:
        if A[r-1][c-1] == k:
            is_ans = True
            break
 
    #R연산 & C연산
    if row_len <= col_len and row_len < 100:
        #R연산
        for i in range(col_len):
            #배열 정렬 후 다시 넣기
            dic = {}
            tmp_list = []
            for j in range(row_len):
                if A[i][j] == 0:
                    pass
                elif A[i][j] in tmp_list:
                    dic[A[i][j]] += 1
                else:
                    dic[A[i][j]] = 1
                    tmp_list.append(A[i][j])
            #딕셔너리 정렬
            sorted_list = sorted(dic.items(),key=lambda x:(x[1],x[0]))
            #배열 다시 넣기
            A[i].clear()
            for num1,num2 in sorted_list:
                A[i].append(num1)
                A[i].append(num2)
            if len(A[i]) > max_len:
                max_len = len(A[i])
        # 0채워주기
        for g in range(col_len):
            while(len(A[g]) < max_len):
                A[g].append(0)

    elif col_len < 100:
        row_len = len(A[0])
        col_len = len(A)
        max_len = col_len
        for j in range(row_len):
            dic = {}
            tmp_list = []
            for i in range(col_len):
                if A[i][j] == 0:
                    pass
                elif A[i][j] in tmp_list:
                    dic[A[i][j]] += 1
                else:
                    dic[A[i][j]] = 1
                    tmp_list.append(A[i][j])
            #딕셔너리 정렬
            sorted_list = sorted(dic.items(),key = lambda x:(x[1],x[0]))
            #배열 다시 넣기

            if len(sorted_list)*2 > max_len:
                for _ in range(max_len,len(sorted_list) * 2):
                    A.append([0])
                max_len = len(sorted_list)*2
            term = 0
            if time ==4:
                print (A)
                print (sorted_list)
                print("=============================")
            for num1,num2 in sorted_list:
                while(len(A[term]) <= j):
                    A[term].append(0)
                while(len(A[term+1]) <= j):
                    A[term+1].append(0)
                A[term][j] = num1
                A[term +1][j]= num2
                term +=2
        # 0 채워주기
        for g in range(col_len, len(A)):
            while(len(A[g]) < row_len):
                A[g].append(0)
    time +=1
    if (time == 100):
        if len(A[0]) >= c - 1 and len(A) >= r - 1:
            if A[r-1][c-1] == k:
                is_ans = True
                break
        break

if is_ans:
    print(time)
else:
    print(-1)