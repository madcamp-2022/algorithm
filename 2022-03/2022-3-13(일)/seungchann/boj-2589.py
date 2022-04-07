from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
array = [input() for _ in range(n)]

# 4 방향 모두 체크
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
land = []

for i in range(n):
    for j in range(m):
        if array[i][j] == 'L':
            land.append((i,j))


def bfs(i, j):
    visited = [[False] * m for _ in range(n)]
    visited[i][j] = True
    dist = [[0] * m for _ in range(n)]
    queue = deque([(i,j)])
    while queue:
        x, y = queue.popleft()
        for dir in range(4):
            nx = x + dx[dir]
            ny = y + dy[dir]
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue
            elif visited[nx][ny] == True or array[nx][ny] == 'W':
                continue

            queue.append((nx, ny))
            dist[nx][ny] = dist[x][y] + 1
            visited[nx][ny] = True
    
    return max(map(max, dist))

max_dist = 0
for i, j in land:
    max_dist = max(bfs(i, j), max_dist)

print(max_dist)