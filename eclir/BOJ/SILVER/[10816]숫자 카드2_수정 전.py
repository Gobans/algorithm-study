from sys import stdin
origin_number = int(stdin.readline())
card_origin = sorted(list(map(int, stdin.readline().split())))
compare_number = int(stdin.readline())
card_compare = list(map(int, stdin.readline().split()))

def binarySearch(array, target, left, right):
    if left > right:
        return 0
    middle_idx = (left + right) // 2
    middle = array[middle_idx]
   
    if middle < target:
        return(binarySearch(array, target, middle_idx + 1, right))
    elif middle > target:
        return(binarySearch(array, target, left, middle_idx - 1))
    else:
        return array[left:right+1].count(target)

dic = {}
for i in card_origin:
    if i not in dic:
        dic[i] = binarySearch(card_origin, i, 0, origin_number)

for i in range(compare_number):
    if card_compare[i] in dic:
        print(dic[card_compare[i]], end = ' ')
    else:
        print(0, end = ' ')