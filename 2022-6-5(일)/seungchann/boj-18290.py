from itertools import combinations
import sys
input = sys.stdin.readline

n, m, k = map(int, input().split())
array = list(list(map(int, input().split())) for _ in range(n))
val_pos = []

for x in range(n):
    for y in range(m):
        val_pos.append([array[x][y], (x, y)])


result = -99999999999999
for comb in list(combinations(val_pos, k)):
    pos = []
    temp_sum = 0
    
    is_adjacent = False
    for val, (x, y) in comb:
        temp_sum += val
        pos.append((x, y))
        if ((x+1, y) in pos) or ((x-1, y) in pos) or ((x, y+1) in pos) or ((x, y-1) in pos):
            is_adjacent = True
            break
    
    if is_adjacent:
        continue
    
    result = max(result, temp_sum)

print(result)