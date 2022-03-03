from array import array
import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in graph:
    i.sort()

def bfs(graph, start):
    queue = deque([start])
    result_array = [0] * (n+1)
    visited = [False] * (n+1)
    visited[start] = True

    while queue:
        v = queue.popleft()
        for i in graph[v]:
            if not visited[i]:
                result_array[i] += result_array[v] + 1
                queue.append(i)
                visited[i] = True
    
    return sum(result_array)

result = []
for i in range(1, n+1):
    result.append(bfs(graph, i))

print(result.index(min(result))+1)