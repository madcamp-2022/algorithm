import sys
from collections import deque

input = sys.stdin.readline

_ = input()
# 창영 list
c_list = list(map(int, input().split()))
# 현우 list
h_list = list(map(int, input().split()))
possible_angles = [False] * 360
possible_angles[0] = 1

queue = deque([0])
while queue:
    v = queue.popleft()
    for i in c_list:
        minus, plus = i-v, i+v
        if minus < 0:
            minus += 360
        if plus >= 360:
            plus -= 360

        if possible_angles[minus] == False:
            possible_angles[minus] = True
            queue.append(minus)
        if possible_angles[plus] == False:
            possible_angles[plus] = True
            queue.append(plus)

for i in h_list:
    if possible_angles[i]:
        print("YES")
    else:
        print("NO")