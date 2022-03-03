import sys
from collections import deque

from collections import defaultdict


def role_dice(direction):
    global x, y
    if direction == 1:
        row.append(col[-1])
        col[-1] = row.popleft()
        col[1] = row[1]
        y += 1
    elif direction == 2:
        row.appendleft(col[-1])
        col[-1] = row.pop()
        col[1] = row[1]
        y -= 1
    elif direction == 3:
        row[1] = col[0]
        col.appendleft(col.pop())
        x -= 1
    else:
        row[1] = col[2]
        col.append(col.popleft())
        x += 1


input = sys.stdin.readline
N, M, x, y, K = map(int, input().split())
row = deque([4, 1, 3])
col = deque([2, 1, 5, 6])
value = defaultdict(int)
table = [[*map(int, input().split())] for _ in range(N)]
direction_table = [0, (0, 1), (0, -1), (-1, 0), (1, 0)]
for k in input().split():
    k = int(k)
    dx, dy = direction_table[k]
    if 0 <= x + dx < N and 0 <= y + dy < M:
        role_dice(k)
        if table[x][y] == 0:
            table[x][y] = value[row[1]]
        else:
            value[row[1]] = table[x][y]
            table[x][y] = 0
        print(value[col[-1]])
