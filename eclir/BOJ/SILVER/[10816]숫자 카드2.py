'''
{입력}

'''
import sys
input = sys.stdin.readline

origin_number = int(input()) #상근이가 가지고 있는 카드 개수
card_origin = sorted(list(map(int, input().split()))) #상근이가 가지고 있는 카드들
compare_number = int(input()) #비교해볼 카드의 개수
card_compare = list(map(int, input().split())) #각각 비교해볼 카드들



'''
{이분 탐색 재귀 함수}

상근이가 가지고 있는 카드가 target값을 포함할 때 개수를 반환.
'''
def binarySearch(array, target, left, right):
    if left > right: #예외 경우 처리
        return 0
    middle_idx = (left + right) // 2
    middle = array[middle_idx]
   
    if middle < target:
        return(binarySearch(array, target, middle_idx + 1, right))
    elif middle > target:
        return(binarySearch(array, target, left, middle_idx - 1))
    else: #middle = target 인 경우
        return array[left:right+1].count(target) #middle(=target) 값을 포함하는 그 때의 범위(인덱스 : left ~ right) 안에서 target과 같은 값의 개수를 세준다. 



'''
{메인}

비교할 카드 각각마다의 개수를 저장하는 딕셔너리를 만든다.
'''
dic = {}
for i in sorted(card_compare): #
    if i not in dic: #아직 이 카드의 개수가 딕셔너리에 저장되지 않았을 때.
        dic[i] = binarySearch(card_origin, i, 0, origin_number - 1)


'''
{출력}

비교할 카드들 순서대로 돌아가는 for문 :
    if 우리가 만든 딕셔너리 안에 그 카드의 숫자가 있다면, 그 때의 값(숫자의 개수)을 출력
    else 딕셔너리 안에 해당값이 존재하지 않는다면, '0'을 출력
'''
print(' '.join(str(dic[x]) if x in dic else "0" for x in card_compare))