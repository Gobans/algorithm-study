A, B, C, D ,E = map(int, input().split())

F = A**2 + B**2 + C**2 + D**2 + E**2
print(F % 10)

'''
[더 간단히 하는 방법]
user_input = list(map(int, input().split))
res = 0
for n in user_input:
    res += n**2
print(res % 10)
'''