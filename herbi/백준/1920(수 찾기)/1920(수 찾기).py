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

for tf in toFind:
    index = findNum(arr, 0, N - 1, tf)
    if index == -1:
        print(0)
    else:
        print(1)
