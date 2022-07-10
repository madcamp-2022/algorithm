import sys
input = sys.stdin.readline

n = int(input())
alpha_dict = {}
word_list = []

# 제일 높은 자리수, 시작하는 숫자인지 여부
for i in range(65, 91):
    alpha_dict[chr(i)] = [0, False]

for _ in range(n):
    string = input().rstrip()
    word_list.append(string)

    string = list(string)

    for idx, val in enumerate(string[::-1]):
        # 시작하는 숫자일 경우
        if idx == len(string)-1:
            alpha_dict[val][1] = True
        alpha_dict[val][0] += (10**(idx))

alpha_list = list(filter(lambda x: x[1][0], alpha_dict.items()))
alpha_list.sort(key= lambda x: x[1][0])

cnt = 10-len(alpha_list)
result_dict = {}
temp_val = []

for val, info in alpha_list:
    _, is_initial = info
    
    if cnt == 0:
        if is_initial:
            temp_val.append(val)
            continue
        else:
            result_dict[val] = str(cnt)
            
            if temp_val:
                for idx, v in enumerate(temp_val):
                    result_dict[v] = str(idx+1)
                cnt = len(temp_val)+1
            
            else:
                cnt += 1
            continue
    
    result_dict[val] = str(cnt)
    cnt += 1

for idx, s in enumerate(word_list):
    temp = ""
    for ch in s:
        temp += result_dict[ch]
    
    word_list[idx] = int(temp)

# print(result_dict)
print(sum(word_list))