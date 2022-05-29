from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().rstrip().split(' '))
array = [list(input().rstrip()) for _ in range(m)]

def bfs():
    visited = [[-1 for _ in range(n)] for _ in range(m)]
    queue = deque([(0, 0)])
    visited[0][0] = 0
    dx = [-1, 0, 1, 0]
    dy = [0, 1, 0, -1]

    while queue:
        x, y = queue.popleft()
        for i in range(4):
            nx, ny = x+dx[i], y+dy[i]
            
            if nx < 0 or ny < 0 or nx >= n or ny >= m:
                continue

            if visited[ny][nx] == -1:
                if array[ny][nx] == '1':
                    visited[ny][nx] = visited[y][x] + 1
                    queue.append((nx, ny))
                else:
                    visited[ny][nx] = visited[y][x]
                    queue.appendleft((nx, ny))
            
    return visited[m-1][n-1]

print(bfs())