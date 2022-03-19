A, B = map(int, input().split())

print(A // B) # //연산자: 나누기 연산 후 소수점 이하의 수를 버리고, 정수 부분의 수만 구함.
#그냥 int (A / B) 를 안에 넣었더니 런타임 에러 뜸.

print(A % B)