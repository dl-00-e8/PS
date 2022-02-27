try:
    voca = input().upper()
    unique_voca = list(set(voca))

    cnt_list = []
    for word in unique_voca:
        cnt = voca.count(word)
        cnt_list.append(cnt)

    if cnt_list.count(max(cnt_list)) > 1:
        print('?')
    else:
        max_index = cnt_list.index(max(cnt_list))
        print(unique_voca[max_index])

except KeyboardInterrupt:
    pass