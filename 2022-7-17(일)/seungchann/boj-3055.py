from collections import deque
import sys
input = sys.stdin.readline

r, c = map(int, input().split())
forest = list(list(list(input().rstrip())) for _ in range(r))
water = []
stone = []
hedgehog = (0, 0)
beaver = (0, 0)
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

for y in range(r):
    for x in range(c):
        if forest[y][x] == 'D':
            beaver = (x, y)
        elif forest[y][x] == 'S':
            hedgehog = (x, y)
        elif forest[y][x] == 'X':
            stone.append((x, y))
        elif forest[y][x] == '*':
            water.append((x, y))

def update_water(w):
    global beaver, stone, dx, dy, r, c
    ret = []
    for x, y in w:
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if nx < 0 or ny < 0 or nx >= c or ny >= r:
                continue
            if (nx, ny) in [beaver] + stone:
                continue
            ret.append((nx, ny))

    return list(set(ret+w))

def bfs(pos, water):
    global beaver, stone, dx, dy, r, c
    # 고슴도치의 위치, 시간
    queue = deque([[pos, 0]])
    visited = list(list(False for _ in range(c)) for _ in range(r))
    visited[pos[1]][pos[0]] = True
    next_cnt = 0

    while queue:
        cur, cnt = queue.popleft()
        x, y = cur

        if next_cnt == cnt:
            next_cnt += 1
            water = update_water(water)

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            if nx < 0 or ny < 0 or nx >= c or ny >= r:
                continue

            if visited[ny][nx]:
                continue

            if (nx, ny) in water + stone:
                continue

            if (nx, ny) == beaver:
                return cnt+1
            
            queue.append([(nx, ny), cnt+1])
            visited[ny][nx] = True

    return "KAKTUS"

print(bfs(hedgehog, water))