a = int(input())
b = int(input())
c = int(input())
d = int(input())
'''
input 다른 방법으로

for i in range(4)
    a += int(input())

이 있음
'''

print((a + b + c + d) // 60)
print((a + b + c + d) % 60)