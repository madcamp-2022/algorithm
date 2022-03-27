from sys import stdin
n, m, k = map(int, stdin.readline().split())
castle_list = list(map(int, stdin.readline().split()))
stone_list = list(map(int, stdin.readline().split()))

answer_list = []

for i in range(len(stone_list)):
    temp_sum = 0
    if i == len(stone_list) - 1:
        temp_sum = sum(castle_list[stone_list[i]-1:])
    else:
        temp_sum = sum(castle_list[stone_list[i]-1:stone_list[i+1]-1])
    
    answer_list.append((stone_list[i], temp_sum))
    
answer_list.sort(key= lambda x:-x[1])
answer_list = answer_list[:m]
answer_list.sort(key= lambda x: x[0])

for i in range(m):
    print(str(answer_list[i][0]))