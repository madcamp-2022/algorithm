from collections import deque
import sys
input = sys.stdin.readline

n = int(input())
graph = [[] for _ in range(n+1)]
visited = [False] * (n+1)

def bfs():
    global graph, visited
    # 1부터 이어진 다리 체크
    queue = deque([1])
    visited[1] = True

    while queue:
        v = queue.popleft()
        for i in graph[v]:
            if not visited[i]:
                queue.append(i)
                visited[i] = True


for _ in range(n-2):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

if n == 2:
    print("1 2")

else:
    bfs()
    another_bridge = 0
    
    idx = 1
    while True:
        if visited[idx] == False and another_bridge == 0:
            another_bridge = idx
            break

        idx += 1
    
    print(1, another_bridge)