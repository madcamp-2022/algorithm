from collections import deque
import sys
input = sys.stdin.readline

a, b = map(int, input().split())
n, m = map(int, input().split())

def bfs(start, end):
    if start == end:
        return 0
        
    global graph, n
    visited = [False] * (n+1)
    queue = deque([[start, 0]])
    visited[start] = True

    while queue:
        v, cnt = queue.popleft()
        for i, _ in graph[v]:
            if not visited[i]:
                if i == end:
                    return cnt+1
                queue.append([i, cnt+1])
                visited[i] = True 
    return -1

graph = list([] for _ in range(n+1))

for _ in range(m):
    i, j = map(int, input().split())
    graph[i].append([j, 0])
    graph[j].append([i, 0])

print(bfs(a, b))