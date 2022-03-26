import sys
input = sys.stdin.readline

N = int(input())
array = list(list(map(int, input().split())) for _ in range(N))
array.sort(key= lambda x: (x[1], x[0]))

result = 0
min_dist, prev_dist = 1e9, 1e9
for idx, (val, color) in enumerate(array):
    if idx == len(array)-1:
        if color == array[idx-1][1]:
            result += prev_dist
        continue

    next_val, next_color = array[idx+1]

    if color == next_color:
        if idx == 0:
            prev_dist = (next_val - val)
            min_dist = prev_dist
            result += min_dist
            continue
        else:
            if color == array[idx-1][1]:
                min_dist = min(prev_dist, (next_val - val))
                result += min_dist
                prev_dist = (next_val - val)
                continue
            else:
                min_dist = next_val - val
                result += min_dist
                prev_dist = min_dist
                continue
    
    else:
        if idx == 0:
            continue
        elif color == array[idx-1][1]:
            result += prev_dist
            prev_dist = 1e9
        else:
            prev_dist = 1e9
        continue

if N == 1:
    result = 0

print(result)