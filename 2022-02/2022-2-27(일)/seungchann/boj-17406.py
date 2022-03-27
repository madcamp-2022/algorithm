import sys
# import copy
from itertools import permutations
input = sys.stdin.readline

N, M, K = map(int, input().split())
array = list(list(map(int, input().split())) for _ in range(N))
rotation = list(list(map(int, input().split())) for _ in range(K))
answer_list = []

def my_deepcopy(arr):
    new = []
    for a in range(N):
        new_item = []
        for b in range(M):
             new_item.append(arr[a][b])
        new.append(new_item)
    return new

def rotate_array(arr, r, c, s):
    min_a = r-s-1
    min_b = c-s-1
    max_a = r+s-1
    max_b = c+s-1
    # new_array = copy.deepcopy(arr)
    new_array = my_deepcopy(arr)
    start_a = min_a
    start_b = min_b

    while 1:
        for a in range(start_a, max_a+1):
            for b in range(start_b, max_b+1):
                if (a == min_a) and (b == min_b):
                    new_array[a][b] = arr[a+1][b]
                elif (a == min_a):
                    new_array[a][b] = arr[a][b-1]
                elif (a == max_a) and (b == max_b):
                    new_array[a][b] = arr[a-1][b]
                elif (a == max_a):
                    new_array[a][b] = arr[a][b+1]
                else:
                    if (b == min_b) and (a != max_a):
                        new_array[a][b] = arr[a+1][b]
                    if (b == max_b) and (a != min_a):
                        new_array[a][b] = arr[a-1][b]
        
        min_a += 1
        start_a = min_a
        max_a -= 1

        min_b += 1
        start_b = min_b
        max_b -= 1
        # arr = copy.deepcopy(new_array)
        arr = my_deepcopy(new_array)

        if min_a == max_a:
            break
    
    # for a in range(N):
    #     print(new_array[a])
    # print()
    
    return new_array

def find_min_value(arr, rot_arr):
    # new_array = copy.deepcopy(arr)
    new_array = my_deepcopy(arr)
    for i in rot_arr:
        r, c, s = i
        new_array = rotate_array(new_array, r, c, s)
    
    result = []
    for i in range(N):
        result.append(sum(new_array[i]))
    
    return min(result)

rotation_array = list(permutations(rotation, len(rotation)))

result = []
for i in rotation_array:
    result.append(find_min_value(array, list(i)))

print(min(result))