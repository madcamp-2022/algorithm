from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
relationships = list(map(int, input().split()))
graph = [[] for _ in range(n)]
removed = int(input())

for num, parent in enumerate(relationships):
    if parent == -1:
        continue
    graph[parent].append(num)

def bfs(started):
    global graph
    queue = deque([graph[started]])
    visited = [False for _ in range(n)]
    visited[started] = True

    while queue:
        vertices = queue.popleft()
        for v in vertices:
            if visited[v]:
                continue
            queue.append(graph[v])
            visited[v] = True
    return visited

result = 0
if relationships[removed] != -1:
    graph[relationships[removed]].remove(removed)

removed = bfs(removed)

for num in range(n):
    if not removed[num] and len(graph[num]) == 0:
        result += 1
        continue

print(result)