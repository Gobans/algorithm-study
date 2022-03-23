import sys
input = sys.stdin.readline
answer = []
bucket = [0] * 20000001

int(input())
for v in list(map(int, input().split())):
    bucket[v + 10000000] += 1

int(input())
for v in list(map(int, input().split())):
    answer.append(bucket[v + 10000000])

for v in answer:
    print(v, end=" ")
