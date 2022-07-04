import sys
input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[] for _ in range(n)]
result = False

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(depth, v):
    global result
    if depth == 4:
        result = True
        return
    
    for i in graph[v]:
        if not visited[i]:
            visited[i] = True
            dfs(depth + 1, i)
            visited[i] = False

visited = [False] * (n)
for i in range(n):
    visited[i] = True
    dfs(0, i)
    visited[i] = False
    if result:
        break

print(int(result))