import sys
input = sys.stdin.readline

num, e, w, s, n = map(int, input().split())
poss = [e/100, w/100, s/100, n/100]
dx = [1, -1, 0, 0]
dy = [0, 0, -1, 1]

visited = [[0 for _ in range((num*2)+1)] for _ in range((num*2)+1)]
result = 0

def dfs(x, y, step, val):
    global visited, result
    if step == num:
        result += val
        return

    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]

        if nx < 0 or ny < 0 or nx >= (num*2)+1 or ny >= (num*2)+1:
            continue
        
        if visited[ny][nx] == 1:
            continue
        
        # 방문한 곳은 1로 처리
        visited[ny][nx] = 1
        dfs(nx, ny, step+1, val*poss[i])

        # dfs를 끝난 후에 다음 i 탐색을 위해서 0으로 처리
        visited[ny][nx] = 0


visited[num][num] = 1
dfs(num, num, 0, 1)

print(result)
