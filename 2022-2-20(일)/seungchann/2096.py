import sys
input = sys.stdin.readline

n = int(input())

# index 0 -> l, 1 -> m, 2 -> r
prev_max = [0, 0, 0]
curr_max = [0, 0, 0]

prev_min = [0, 0, 0]
curr_min = [0, 0, 0]

for i in range(n):
    l, m, r = map(int, input().split())

    curr_max[0] = max(prev_max[0], prev_max[1]) + l
    curr_min[0] = min(prev_min[0], prev_min[1]) + l

    curr_max[1] = max(prev_max[0], prev_max[1], prev_max[2]) + m
    curr_min[1] = min(prev_min[0], prev_min[1], prev_min[2]) + m

    curr_max[2] = max(prev_max[1], prev_max[2]) + r
    curr_min[2] = min(prev_min[1], prev_min[2]) + r

    prev_max = curr_max[:]
    prev_min = curr_min[:]

print(max(curr_max), min(curr_min))