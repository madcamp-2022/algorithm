from collections import deque
from operator import is_
import sys
input = sys.stdin.readline

n = int(input())
my_map = [[0 for _ in range(n)] for _ in range(n)]
k = int(input())
k_array = list(list(map(int, input().split())) for _ in range(k))
l = int(input())
l_array = list(list(input().split()) for _ in range(l))

# 0 -> right, 1 -> down, 2 -> left, 3 -> up
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def change_direction(m_dir, character):
    if character == 'L':
        m_dir -= 1
    if character == 'D':
        m_dir += 1

    if m_dir == 4:
        m_dir = 0
    if m_dir == -1:
        m_dir = 3
    
    return m_dir

for i in k_array:
    y, x = i
    my_map[x-1][y-1] = 2

x, y, direction = 0, 0, 0
queue = deque([[x, y]])
my_map[x][y] = 1
result = 0
is_ended = False
is_last = False

for idx in range(len(l_array)):

    i_x, c = l_array[idx]
    if idx == len(l_array)-1:
        is_last = True
    
    while 1:
        result += 1
        nx = x + dx[direction]
        ny = y + dy[direction]
        # print("nx: ", nx)
        # print("ny: ", ny)
        # print("result: ", result)
        # print("queue: ", queue)
        # print("i_x: ", i_x)
        # print()
        # for i in range(n):
        #     for j in range(n):
        #         print(my_map[i][j], end=' ')
        #     print()
        # print()

        if direction == 0 and nx >=n:
            is_ended = True
            break

        if direction == 1 and ny >=n:
            is_ended =True
            break
        
        if direction == 2 and nx <0:
            is_ended = True
            break

        if direction == 3 and ny <0:
            is_ended = True
            break

        if my_map[nx][ny] == 1:
            is_ended = True
            break

        if my_map[nx][ny] != 2:
            q_x, q_y = queue.popleft()
            my_map[q_x][q_y] = 0
        
        my_map[nx][ny] = 1
        queue.append([nx, ny])

        x = nx
        y = ny
        
        if result == int(i_x):
            direction = change_direction(direction, c)
            # print("direction: ", direction)
            if not is_last:
                break
        
    if is_ended:
        break

print(result)