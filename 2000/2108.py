from collections import Counter

def mean(n_list):
    result = 0
    for i in n_list:
        result += i
    
    return round(result / len(n_list))
    
    
def medium(n_list):
    n_list.sort()
    return n_list[len(n_list) // 2]


def mode(n_list):
    c = Counter(n_list)
    order = c.most_common()
    maximum = order[0][1]
    
    modes = []
    for num in order:
        if num[1] == maximum:
            modes.append(num[0])
    if len(modes) >= 2:
        modes.sort()
        return modes[1]
    return modes[0]

def max_min_range(n_list):
    return max(n_list) - min(n_list)
    

n = int(input())

data = []
for _ in range(n):
    data.append(int(input()))

print(mean(data))
print(medium(data))
print(mode(data))
print(max_min_range(data))

    
'''
최빈값 구할 때 쓰는 모듈은 from collections import Counter 이며
해당 함수는 def mode(n_list): 부분을 참고할 것'''
