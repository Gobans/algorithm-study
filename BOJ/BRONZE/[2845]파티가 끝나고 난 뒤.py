m, n = input().split()
number_list = list(map(int, input().split()))
partici_ = int(m) * int(n)
diff = 0

for i in number_list:
    diff = i - partici_
    print(diff, end = ' ') #print함수에서 end인자를 사용하면 마지막 효과를 바꿀 수 있다.(기본값은 개행)