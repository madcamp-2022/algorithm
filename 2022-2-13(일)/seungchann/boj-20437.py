n = int(input())
answer_list = []

for _ in range(n):
    min_alpha_indices = [[] for _ in range(26)]
    max_alpha_indices = [[] for _ in range(26)]

    # min_str_start_idx = 0
    min_str_size = 10001
    
    # max_str_end_idx = 0
    max_str_size = 0

    temp_str = input()
    iter_num = int(input())

    if iter_num == 1:
        answer_list.append("1 1")
        continue

    for i in range(len(temp_str)):
        idx = ord(temp_str[i])-97
        
        if len(min_alpha_indices[idx]) < iter_num-1:
            min_alpha_indices[idx].append(i)
            max_alpha_indices[idx].append(i)
        else:
            min_alpha_indices[idx].append(i)
            temp_start_idx = min_alpha_indices[idx].pop(0)
            temp_size = i-temp_start_idx+1

            if(temp_size < min_str_size):
                min_str_size = temp_size
                # min_str_start_idx = temp_start_idx

            max_alpha_indices[idx].append(i)
            if (len(max_alpha_indices[idx]) > iter_num):
                max_alpha_indices[idx].pop(0)
            temp_size = i-max_alpha_indices[idx][0]+1

            if(temp_size > max_str_size):
                max_str_size = temp_size
                # max_str_end_idx = i

    if max_str_size == 0 or min_str_size == 10001:
        answer_list.append("-1")
    else:
        answer_list.append(str(min_str_size) + " " + str(max_str_size))

    # print(temp_str[min_str_start_idx:min_str_start_idx+min_str_size])
    # print(temp_str[max_str_end_idx-max_str_size+1:max_str_end_idx+1])
    # print()

for i in answer_list:
    print(i)