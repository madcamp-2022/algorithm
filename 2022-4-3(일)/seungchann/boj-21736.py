from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
array = [list(input().rstrip()) for _ in range(n)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

cur_x, cur_y = -1, -1

for y in range(n):
    for x in range(m):
        if array[y][x] == 'I':
            cur_x = x
            cur_y = y
            break

def bfs():
    global cur_x, cur_y
    queue = deque([(cur_x, cur_y)])
    visited = [[False for _ in range(m)] for _ in range(n)]
    visited[cur_y][cur_x] = True
    result = 0
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            if nx < 0 or ny < 0 or nx >= m or ny >= n:
                continue
            if array[ny][nx] == 'X':
                continue
            if visited[ny][nx]:
                continue
            if array[ny][nx] == 'P':
                result += 1

            queue.append((nx, ny))
            visited[ny][nx] = True


    return result

result = bfs()
if result == 0:
    result = 'TT'

print(result)
