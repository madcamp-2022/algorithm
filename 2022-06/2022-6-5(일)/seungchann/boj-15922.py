import sys
input = sys.stdin.readline

n = int(input())

prev_x, prev_y = map(int, input().split())
result = 0

for _ in range(n-1):
    cur_x, cur_y = map(int, input().split())

    if cur_x <= prev_y:
        if cur_y <= prev_y:
            continue
        else:
            prev_y = cur_y
    else:
        result += prev_y - prev_x
        prev_x = cur_x
        prev_y = cur_y

result += prev_y - prev_x
print(result)