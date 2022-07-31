from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
grid = list(list(map(int, input().split())) for _ in range(n))

def bfs():
    global grid

    visited = [[False for _ in range(m)] for _ in range(n)]
    cheese = []

    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]

    q = deque([(0, 0)])
    visited[0][0] = True

    while q:
        cx, cy = q.popleft()

        for i in range(4):
            nx = cx + dx[i]
            ny = cy + dy[i]

            if nx < 0 or ny < 0 or nx >= m or ny >= n:
                continue

            if visited[ny][nx]:
                continue

            if grid[ny][nx] == 1:
                cheese.append((nx, ny))
                continue

            q.append((nx, ny))
            visited[ny][nx] = True
    
    return list(set(cheese))

def update_cheese(cheese):
    global grid
    for x, y in cheese:
        grid[y][x] = 0

cnt = 0
prev_cheese = []

while True:
    cheese = bfs()

    if not cheese:
        print(cnt)
        print(len(prev_cheese))
        break
    else:
        update_cheese(cheese)
        prev_cheese = cheese
        cnt += 1