n = int(input())
word_list = []

for _ in range(n): #값을 무시하고자 언더바 _ 를 사용한다.
    word = str(input())
    word_count = len(word) 
    word_list.append((word_count, word)) #append로 데이터 추가
word_set = set(word_list) #집합 set 으로 변환. 중복 제거
word_set = list(word_set) #list로 변환

word_set.sort() #길이순, 오름차순 정렬
#앞에서 정렬 요소를 만들었기 떄문에 바로 튜플의 요소를 기준으로 정렬한다.
#첫번쨰 요소 우선.

'''
두번째 방법 : for문 안에서 len을 만들지 않는 방법

sort(lambda x : len(x), x) 이렇게


'''

#앞을 먼저 정렬 후 앞의 조건이 일치하면 뒤를 정렬

for word_len, word in word_set: #여기서 word_len, word는 임의로 선정한 변수
    print(word)