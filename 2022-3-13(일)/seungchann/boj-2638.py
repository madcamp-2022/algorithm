import sys
from collections import deque
input = sys.stdin.readline

n, m = map(int, input().split())
array = list(list(map(int, input().split())) for _ in range(n))
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def check_air():
    visited = [[False] * m for _ in range(n)]
    array[0][0] = 2
    visited[0][0] = True
    queue = deque([(0,0)])
    while queue:
        x, y = queue.popleft()
        for dir in range(4):
            nx = x + dx[dir]
            ny = y + dy[dir]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            elif visited[nx][ny] == True or array[nx][ny] == 1:
                continue

            queue.append((nx, ny))
            array[nx][ny] = 2
            visited[nx][ny] = True

result = 0
while True:
    check_air()
    melting_cheese = []
    for i in range(n):
        for j in range(m):
            if array[i][j] == 1:
                cnt = 0
                for dir in range(4):
                    nx = i + dx[dir]
                    ny = j + dy[dir]
                    if nx < 0 or ny < 0 or nx >= n or ny >= m:
                        continue

                    if array[nx][ny] == 2:
                        cnt += 1

                    if cnt >= 2:
                        array[i][j] = 3
                        melting_cheese.append((i, j))

    if melting_cheese == []:
        break

    result += 1

    for i, j in melting_cheese:
        array[i][j] = 2
    
    # print()
    # for i in range(n):
    #     for j in range(m):
    #         print(array[i][j], end=' ')
    #     print()

print(result)