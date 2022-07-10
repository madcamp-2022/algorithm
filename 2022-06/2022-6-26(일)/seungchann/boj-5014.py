from collections import deque
import sys
input = sys.stdin.readline

f, s, g, u, d = map(int, input().split())
dx = [u, -d]

def bfs(started):
    queue = deque([(started, 0)])
    visited = set([started])

    if s == g:
        return 0

    while queue:
        v, cnt = queue.popleft()

        for i in range(2):
            nv = v + dx[i]
            
            if 0 >= nv or nv > f or nv in visited:
                continue

            if nv == g:
                return cnt+1
            
            queue.append((nv, cnt+1))
            visited.add(nv)
    
    return -1

result = bfs(s)

if result == -1:
    print("use the stairs")
else:
    print(result)