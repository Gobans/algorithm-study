import sys
input = sys.stdin.readline


def findNum(arr, start, end, tf):
    if start > end:
        return -1
    mid = (start + end) // 2
    if arr[mid] == tf:
        return mid
    elif arr[mid] >= tf:
        return findNum(arr, start, mid-1, tf)
    else:
        return findNum(arr, mid+1, end, tf)


N = int(input())
arr = sorted(list(map(int, input().split())))
M = int(input())
toFind = list(map(int, input().split()))
answer = []

for tf in toFind:
    index = findNum(arr, 0, N - 1, tf)
    if index == -1:
        answer.append(0)
    else:
        num = 1
        temp = index - 1
        while temp >= 0 and arr[temp] == tf:
            num += 1
            temp -= 1
        temp = index + 1
        while temp <= len(arr) - 1 and arr[temp] == tf:
            num += 1
            temp += 1
        answer.append(num)

for v in answer:
    print(v, end=" ")
