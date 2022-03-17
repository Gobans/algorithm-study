def sort_word() :
    word = []
    word_dict = {}
    answer = []
    len_max = 0

    # 단어 N개 입력받기
    N = int(input())
    for i in range(N) :
        word.append(str(input()))
    # print(word)

    # 중복된 단어 제거
    word = list(set(word))
    # print("set : ", word)
 
    # 1. 길이가 짧은 것부터 정렬
    # 키: 단어, 값: 단어 길이 -> dictionary 생성
    N = len(word)
    for i in range(N) :
        word_dict[word[i]] = len(word[i])
    # print(word_dict)

    # 단어 길이(value값)별로 정렬
    word_dict
    word_dict = list(sorted(word_dict.items(), key= lambda x: x[1]))
    # print(word_dict)

    # 2. 길이가 같으면 사전 순으로 정렬
    # 같은 길이의 단어가 몇 개인지 체크 -> 가장 긴 단어의 길이만큼 0값을 가진 리스트 생성
    # index: 단어 길이, 값: 같은 길이의 단어 개수
    len_max = word_dict[-1][1]
    # print(f"len_max: {len_max}")

    len_count_list = [0 for _ in range(len_max)]
    # print(len_count_list)

    word = []
    for i in range(N) :
        word.append(word_dict[i][0])
        index = word_dict[i][1] - 1
        len_count_list[index] += 1
    # print(word)
    # print(len_count_list)
    
    # 길이가 같은 단어들을 슬라이싱해서 정렬 후 새 리스트에 담기
    start_index = 0
    next_index = 0
    for i in range(len(len_count_list)) :
        if len_count_list[i] == 0 :
            pass
        elif len_count_list[i] == 1 :
            answer.append(word[start_index])
            start_index += 1
        elif len_count_list[i] > 1 :
            next_index = start_index + len_count_list[i]
            temp = word[start_index : next_index]
            # print(f"temp::: {temp}")
            for _ in range(len_count_list[i] - 1) :
                for j in range(len_count_list[i] -1) :
                    if (temp[j] > temp[j+1]) == True :
                        temp[j], temp[j+1] = temp[j+1], temp[j]
                    # print(f"temp : {temp}")
            answer[start_index : next_index] = temp[:]
            start_index = next_index
        # print(f"i: {i}, answer : {answer}, start_index: {start_index}")

    # 출력
    for word in answer :
        print(word)

    return ;

sort_word()