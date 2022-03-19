test_nb = int(input())

for _ in range(test_nb):
    x1, y1, r1, x2, y2, r2 = map(int, input().split())

    x_diff = x1 - x2
    y_diff = y1 - y2
    d = (x_diff**2 + y_diff**2) ** 0.5
    r_diff = r1 - r2 if (r1 - r2) > 0 else (r2 - r1)
    r_sum = r1 + r2

    if(d == 0): #동심원인 경우로 먼저 if문 사용. 런타임 에러를 피하기 위함.
        if(r_diff == 0): #동심원이고 반지름의 길이 같을 때. 무한 개의 해를 갖는다.
            print(-1)
        else:
            print(0)
    else:
        if (r_diff < d < r_sum):
            print(2)
        elif (r_sum == d or r_diff == d):
            print(1)
        else:
            print(0)



'''
#test case 숫자만큼 for문 돌리기
array = [0 for _ in range(test_nb)]

for i in range(test_nb):
    array[i] = list(map(int, input().split()))
    d_2 = array[i][]


[2차원 리스트 입력받는 방법]
 array[]
 for i in range(test_nb):
     array.append(list(map(int, input().split())))
이렇게 해도 된다!
 '''
