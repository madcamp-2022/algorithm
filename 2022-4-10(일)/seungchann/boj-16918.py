from collections import deque
import sys
input = sys.stdin.readline

r, c, n = map(int, input().split())
bombs = [list(input().rstrip()) for _ in range(r)]
queue = deque([])

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def bfs(queue, bombs):
    while queue:
        x, y = queue.popleft()
        bombs[y][x] = '.'
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= c or ny >= r:
                continue
            bombs[ny][nx] = '.'

def simulate(time):
    global bombs, queue

    if time == 1:
        for y in range(r):
            for x in range(c):
                if bombs[y][x] == 'O':
                    queue.append((x, y))
    elif time % 2 == 1:
        bfs(queue, bombs)
        for y in range(r):
            for x in range(c):
                if bombs[y][x] == 'O':
                    queue.append((x, y))
    else:
        bombs = list(list('O' for _ in range(c)) for _ in range(r))

for i in range(1, n+1):
    simulate(i)

for row in bombs:
    print(''.join(row))
