def sort_word() :
    word = []

    # 단어 N개 입력받기
    N = int(input())
    for i in range(N) :
        word.append(str(input()))

    # 중복된 단어 제거
    word = list(set(word))
 
    # 1. 길이가 짧은 것부터 정렬
    # 2. 길이가 같으면 사전 순으로
    N = len(word)
    word.sort(key= lambda x: (len(x), x))

    # 출력
    for w in word :
        print(w)

    return ;

sort_word()