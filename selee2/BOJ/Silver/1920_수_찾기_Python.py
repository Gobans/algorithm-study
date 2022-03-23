from sys import stdin

def find_number() :
    A = []
    find = []

    # 입력받기
    for _ in range(4) :
        A.append(list(map(int, stdin.readline().split())))

    find = A[3]         # 찾을 수
    A = sorted(A[1])    # 이진 탐색할 수

    # find 내의 원소가 A 내에 존재하는지 확인
    len_A = len(A)
    for a in find :
        start = 0
        end = len_A -1 
        if (a < A[start]) or (A[end] < a) : print(0); continue
        while (end - start) > 0 :
            idx = (end + start) // 2      # 이분할 기준이 될 가운데 인덱스
            if a == A[idx] : start = idx; break
            elif a < A[idx] : end = idx
            elif a > A[idx] : start = idx + 1
        if a == A[start] : print(1)
        else : print(0)

find_number()