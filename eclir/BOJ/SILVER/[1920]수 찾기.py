'''
{이분 탐색 재귀 함수}

middle:중간값과 타겟의 크기를 비교하여 비교 범위를 줄여나간다.
만약 타겟값이 array에 존재한다면 1을 반환하고
그렇지 않다면 0을 반환한다.
'''

def binarySearch(array, target, left, right):
    if left > right: #예외 처리. target값이 array에 없을 때 0을 반환.
        return(0)
    middle_idx = (left + right) // 2
    middle = array[middle_idx]

    #array는 오름차순으로 정렬된 상태. 중간값을 기준으로 비교할 범위를 새로 선정.       
    if middle < target: 
        return(binarySearch(array, target, middle_idx + 1, right))
    elif middle > target:
        return(binarySearch(array, target, left, middle_idx - 1))
    else:
        return (1)



'''
{입력}

'''
list_origin = []
list_compare = []

length_origin = int(input())
list_origin = list(map(int, input().split()))
list_origin.sort() #오름차순으로 정렬

length_compare = int(input())
list_compare = list(map(int, input().split()))



'''
{출력}


'''
for i in range(length_compare):
    print(binarySearch(list_origin, list_compare[i], 0, length_origin - 1))