from collections import deque
import sys
input = sys.stdin.readline

def bfs():
    global num, k

    if 1 not in num:
        return "jjaksoon win at 0"

    q = deque([(0, 0)])
    visited = [False for _ in range(1001)]

    while q:
        pos, cnt = q.popleft()
        for n in num:
            if visited[pos+n] or cnt+1 > k:
                continue
            visited[pos+n] = True
            q.append((pos+n, cnt+1))

    for (idx, val) in enumerate(visited):
        if idx == 0:
            continue
        if val == 0:
            break
    
    name = "holsoon" if idx % 2 == 0 else "jjaksoon"
    return name + " win at " + str(idx)

n = int(input())
num = list(map(int, input().split()))
k = int(input())

print(bfs())