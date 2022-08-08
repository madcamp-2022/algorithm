from collections import deque
import sys
input = sys.stdin.readline

n, m = map(int, input().split())
ladder_snake_dict = {}
INF = 10e9

for _ in range(n+m):
    cur, next = map(int, input().split())
    ladder_snake_dict[cur] = next

def bfs():
    global ladder_snake_dict, INF
    queue = deque([1])
    visited = [INF] * 101
    visited[1] = 0

    while queue:  
        v = queue.popleft()

        for d in range(1, 7):
            nx = v + d
            if nx in ladder_snake_dict:
                nx = ladder_snake_dict[nx]
            
            if nx == 100:
                return visited[v]+1

            # 주사위 최소 횟수 update            
            if visited[nx] > visited[v]+1:
                visited[nx] = visited[v] + 1
                queue.append(nx)

print(bfs())