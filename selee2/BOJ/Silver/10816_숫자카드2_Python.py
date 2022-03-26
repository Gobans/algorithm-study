from sys import stdin

def number_card2() :
    A = []
    find = []
    binary_dict= {}

    # 입력받기
    for _ in range(4) :
        A.append(list(map(int, stdin.readline().split())))

    find = A[3]         # 찾을 수
    A = sorted(A[1])    # 이진 탐색할 수

    for a in A :
        if a not in binary_dict.keys() :
            binary_dict[a] = 1
        else :
            binary_dict[a] += 1

    for f in find :
        if f in binary_dict.keys() : 
            print(binary_dict[f])
        else : print(0)

number_card2()