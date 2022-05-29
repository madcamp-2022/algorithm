from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[[0, 0]] for _ in range(n+1)]

def bfs(graph, start, end):
    queue = deque(graph[start])
    visited = [False] * (n+1)
    visited[start] = True

    while queue:
        v, d = queue.popleft()
        if v == end:
            return d

        for nv, nd in graph[v]:
            if not visited[nv]:
                visited[nv] = True
                queue.append([nv, nd+d])


for _ in range(n-1):
    a, b, l = map(int, input().split())
    graph[a].append([b, l])
    graph[b].append([a, l])


for _ in range(m):
    st, en = map(int, input().split())
    visited = [False] * (n+1)
    result = bfs(graph, st, en)
    print(result)